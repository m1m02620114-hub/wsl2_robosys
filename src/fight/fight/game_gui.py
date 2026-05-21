#!/usr/bin/env python3
"""
ROBOSYS FIGHT - ゲームGUIクライアント
ROS2サーバ(fightServer2.py)と通信するtkinterゲーム画面

通信仕様:
  - name_srv  (Name.srv)  : プレイヤー名登録サービス
  - name       (String)   : 名前トピック(旧サーバ互換)
  - monster_select (Num)  : モンスター選択要求トピック
"""

import tkinter as tk
from tkinter import scrolledtext
import threading
import queue
import time
import sys
import random

# ───────────────────────────── ROS2 接続 ─────────────────────────────
ROS2_AVAILABLE = False
try:
    import rclpy
    from rclpy.node import Node
    from std_msgs.msg import String
    from rsysmsg.msg import Num
    from rsysmsg.srv import Name
    ROS2_AVAILABLE = True
except ImportError:
    pass

# ───────────────────────────── ゲームデータ ─────────────────────────────
MONSTERS = {
    "Type-A": {"hp": 50, "speed": 5, "atk": 10, "def": 10, "color": "#ff6b6b"},
    "Type-B": {"hp": 70, "speed": 3, "atk":  8, "def": 15, "color": "#4ecdc4"},
    "Type-C": {"hp": 40, "speed": 8, "atk": 12, "def":  5, "color": "#f9ca24"},
    "Type-D": {"hp": 60, "speed": 6, "atk":  9, "def": 12, "color": "#6c5ce7"},
    "Type-E": {"hp": 35, "speed": 10,"atk": 15, "def":  3, "color": "#fd79a8"},
}

# ───────────────────────────── カラーテーマ ─────────────────────────────
C = {
    "bg":     "#0d1117",
    "panel":  "#161b22",
    "border": "#30363d",
    "accent": "#58a6ff",
    "text":   "#c9d1d9",
    "sub":    "#8b949e",
    "green":  "#3fb950",
    "red":    "#f85149",
    "yellow": "#d29922",
    "purple": "#a371f7",
}

FONT_TITLE  = ("Helvetica", 22, "bold")
FONT_LARGE  = ("Helvetica", 14, "bold")
FONT_MEDIUM = ("Helvetica", 11)
FONT_SMALL  = ("Helvetica", 9)
FONT_MONO   = ("Courier", 10)


# ═══════════════════════════════════════════════════════════════════════
# ROS2 クライアントノード
# ═══════════════════════════════════════════════════════════════════════
class FightClientNode(Node):
    def __init__(self, event_queue: queue.Queue):
        super().__init__("fight_gui_client")
        self.q = event_queue
        self.player_id = -1

        # Publisher: 名前トピック (旧サーバ互換)
        self.name_pub = self.create_publisher(String, "name", 10)
        # Publisher: モンスター選択トピック
        self.monster_pub = self.create_publisher(Num, "monster_select", 10)
        # Service client: 名前登録
        self.name_cli = self.create_client(Name, "name_srv")

        self.get_logger().info("FightGUIクライアント起動")

    def register_name(self, name: str):
        # トピック送信 (旧サーバ互換)
        msg = String()
        msg.data = name
        self.name_pub.publish(msg)

        if self.name_cli.service_is_ready():
            req = Name.Request()
            req.name = name
            future = self.name_cli.call_async(req)
            future.add_done_callback(self._on_name_response)
        else:
            # サービス未起動 → デモ動作
            self.q.put(("name_ok", 0, f"[デモ] {name} として P1 に登録しました"))

    def _on_name_response(self, future):
        try:
            res = future.result()
            self.q.put(("name_ok", 0, res.response))
        except Exception as e:
            self.q.put(("error", str(e)))

    def send_monster_request(self, player_id: int):
        msg = Num()
        msg.num = player_id
        self.monster_pub.publish(msg)

    def send_monster_choice(self, idx: int):
        msg = Num()
        msg.num = idx
        self.monster_pub.publish(msg)


# ═══════════════════════════════════════════════════════════════════════
# バトル計算
# ═══════════════════════════════════════════════════════════════════════
class BattleSim:
    """Field.battle() ロジックに基づくローカルシミュレーション"""

    @staticmethod
    def battle_round(a: dict, b: dict) -> tuple[int, int, str]:
        """1ラウンド計算. returns (a_hp_new, b_hp_new, log_text)"""
        log = []
        a_hp, b_hp = a["hp"], b["hp"]
        if a["speed"] >= b["speed"]:
            F, S = a, b
            fn, sn = "自分", "相手"
        else:
            F, S = b, a
            fn, sn = "相手", "自分"

        dmg1 = max(0, F["atk"] - S["def"])
        S["hp"] = S["hp"] - dmg1
        log.append(f"【{fn}】が先攻！ → {sn}に {dmg1} ダメージ")
        if S["hp"] <= 0:
            log.append(f"  {sn}の {S['name']} が倒れた！")
            return a["hp"], b["hp"], "\n".join(log)

        dmg2 = max(0, S["atk"] - F["def"])
        F["hp"] = F["hp"] - dmg2
        log.append(f"【{sn}】が反撃！ → {fn}に {dmg2} ダメージ")
        if F["hp"] <= 0:
            log.append(f"  {fn}の {F['name']} が倒れた！")

        return F["hp"] if F is a else S["hp"], S["hp"] if S is b else F["hp"], "\n".join(log)


# ═══════════════════════════════════════════════════════════════════════
# ゲームアプリ
# ═══════════════════════════════════════════════════════════════════════
class FightGameApp:
    def __init__(self, root: tk.Tk):
        self.root = root
        self.root.title("ROBOSYS FIGHT")
        self.root.configure(bg=C["bg"])
        self.root.resizable(False, False)

        self.event_queue: queue.Queue = queue.Queue()
        self.ros_node = None
        self.ros_thread = None

        # ゲーム状態
        self.player_name = ""
        self.player_id = -1
        self.selected: list[str] = []   # 選んだモンスター名
        self.my_mons = []               # 戦闘中モンスターデータ(コピー)
        self.en_mons = []
        self.my_idx = 0
        self.en_idx = 0

        self._build_ui()
        self._start_ros()
        self._show("name")
        self._poll()

    # ─────────────────────────────── UI構築 ───────────────────────────────
    def _build_ui(self):
        self.frames: dict[str, tk.Frame] = {}
        self._build_name_screen()
        self._build_select_screen()
        self._build_ready_screen()
        self._build_battle_screen()

    def _show(self, key: str):
        for f in self.frames.values():
            f.pack_forget()
        self.frames[key].pack(fill="both", expand=True)

    # ────────────── 画面1: 名前入力 ──────────────
    def _build_name_screen(self):
        f = tk.Frame(self.root, bg=C["bg"], width=600, height=500)
        self.frames["name"] = f

        tk.Label(f, text="ROBOSYS FIGHT", font=("Helvetica", 30, "bold"),
                 bg=C["bg"], fg=C["accent"]).pack(pady=(60, 4))
        tk.Label(f, text="モンスターで戦え！", font=FONT_MEDIUM,
                 bg=C["bg"], fg=C["sub"]).pack(pady=(0, 40))

        # ROS2 状態バッジ
        ros_txt = "ROS2: 接続中" if ROS2_AVAILABLE else "ROS2: 未接続 (デモモード)"
        ros_color = C["green"] if ROS2_AVAILABLE else C["yellow"]
        tk.Label(f, text=ros_txt, font=FONT_SMALL,
                 bg=C["panel"], fg=ros_color, padx=10, pady=4,
                 relief="flat").pack(pady=(0, 30))

        tk.Label(f, text="プレイヤー名を入力", font=FONT_MEDIUM,
                 bg=C["bg"], fg=C["text"]).pack()

        self.name_var = tk.StringVar()
        entry = tk.Entry(f, textvariable=self.name_var, font=FONT_LARGE,
                         bg=C["panel"], fg=C["text"], insertbackground=C["text"],
                         relief="flat", width=20, justify="center")
        entry.pack(pady=10, ipady=8)
        entry.focus()
        entry.bind("<Return>", lambda e: self._on_join())

        self.name_status = tk.Label(f, text="", font=FONT_SMALL,
                                    bg=C["bg"], fg=C["sub"])
        self.name_status.pack(pady=6)

        self._btn(f, "参加する", self._on_join).pack(pady=10, ipadx=20, ipady=6)

    def _on_join(self):
        name = self.name_var.get().strip()
        if not name:
            self.name_status.config(text="名前を入力してください", fg=C["red"])
            return
        self.player_name = name
        self.name_status.config(text="登録中...", fg=C["sub"])

        if self.ros_node:
            self.ros_node.register_name(name)
        else:
            # デモモード
            self.event_queue.put(("name_ok", 0, f"[デモ] {name} として P1 に登録しました"))

    # ────────────── 画面2: モンスター選択 ──────────────
    def _build_select_screen(self):
        f = tk.Frame(self.root, bg=C["bg"], width=600, height=500)
        self.frames["select"] = f

        tk.Label(f, text="モンスターを選べ！", font=FONT_TITLE,
                 bg=C["bg"], fg=C["accent"]).pack(pady=(20, 4))
        tk.Label(f, text="3体選択してください", font=FONT_MEDIUM,
                 bg=C["bg"], fg=C["sub"]).pack(pady=(0, 12))

        # モンスターカード一覧
        card_frame = tk.Frame(f, bg=C["bg"])
        card_frame.pack()
        self.monster_btns: dict[str, tk.Button] = {}
        for i, (mname, mdata) in enumerate(MONSTERS.items()):
            col = i % 3
            row = i // 3
            card = self._monster_card(card_frame, mname, mdata)
            card.grid(row=row, column=col, padx=8, pady=6)

        # 選択スロット
        slot_frame = tk.Frame(f, bg=C["bg"])
        slot_frame.pack(pady=14)
        tk.Label(slot_frame, text="選択中:", font=FONT_MEDIUM,
                 bg=C["bg"], fg=C["text"]).pack(side="left", padx=(0, 10))
        self.slots: list[tk.Label] = []
        for i in range(3):
            lbl = tk.Label(slot_frame, text=f"[{i+1}]", font=FONT_MEDIUM,
                           bg=C["panel"], fg=C["sub"], width=10, pady=4,
                           relief="flat")
            lbl.pack(side="left", padx=4)
            self.slots.append(lbl)

        self.select_status = tk.Label(f, text="", font=FONT_SMALL,
                                      bg=C["bg"], fg=C["sub"])
        self.select_status.pack()

        self.confirm_btn = self._btn(f, "決定！", self._on_confirm_select,
                                     state="disabled")
        self.confirm_btn.pack(pady=8, ipadx=20, ipady=6)

    def _monster_card(self, parent, mname: str, mdata: dict) -> tk.Frame:
        card = tk.Frame(parent, bg=C["panel"], relief="flat",
                        width=150, height=130)
        card.pack_propagate(False)

        # 色帯
        bar = tk.Frame(card, bg=mdata["color"], height=5)
        bar.pack(fill="x")

        tk.Label(card, text=mname, font=FONT_LARGE,
                 bg=C["panel"], fg=mdata["color"]).pack(pady=(8, 2))

        stats = (f"HP:{mdata['hp']}  SPD:{mdata['speed']}\n"
                 f"ATK:{mdata['atk']}  DEF:{mdata['def']}")
        tk.Label(card, text=stats, font=FONT_SMALL,
                 bg=C["panel"], fg=C["sub"], justify="center").pack()

        btn = tk.Button(card, text="選択", font=FONT_SMALL,
                        bg=C["accent"], fg=C["bg"], relief="flat",
                        command=lambda n=mname: self._toggle_monster(n),
                        cursor="hand2")
        btn.pack(pady=6, ipadx=8)
        self.monster_btns[mname] = btn
        return card

    def _toggle_monster(self, name: str):
        if name in self.selected:
            self.selected.remove(name)
            self.monster_btns[name].config(text="選択", bg=C["accent"])
        elif len(self.selected) < 3:
            self.selected.append(name)
            self.monster_btns[name].config(text="✓ 選択済", bg=C["green"])

        # スロット更新
        for i, slot in enumerate(self.slots):
            if i < len(self.selected):
                slot.config(text=self.selected[i], fg=C["text"])
            else:
                slot.config(text=f"[{i+1}]", fg=C["sub"])

        self.confirm_btn.config(
            state="normal" if len(self.selected) == 3 else "disabled"
        )

    def _on_confirm_select(self):
        if self.ros_node:
            self.ros_node.send_monster_request(self.player_id)
            for i, mname in enumerate(self.selected):
                self.ros_node.send_monster_choice(list(MONSTERS.keys()).index(mname))
        self._show("ready")
        self.ready_log.config(state="normal")
        self.ready_log.insert("end", f"モンスター選択完了: {', '.join(self.selected)}\n")
        self.ready_log.config(state="disabled")

    # ────────────── 画面3: 準備 ──────────────
    def _build_ready_screen(self):
        f = tk.Frame(self.root, bg=C["bg"], width=600, height=500)
        self.frames["ready"] = f

        tk.Label(f, text="準備完了", font=FONT_TITLE,
                 bg=C["bg"], fg=C["accent"]).pack(pady=(40, 10))

        self.ready_log = scrolledtext.ScrolledText(
            f, width=50, height=8, font=FONT_MONO,
            bg=C["panel"], fg=C["text"], relief="flat", state="disabled"
        )
        self.ready_log.pack(pady=10, padx=20)

        self.ready_status = tk.Label(f, text="相手の準備を待っています...",
                                     font=FONT_MEDIUM, bg=C["bg"], fg=C["sub"])
        self.ready_status.pack(pady=8)

        btn_row = tk.Frame(f, bg=C["bg"])
        btn_row.pack(pady=10)
        self._btn(btn_row, "準備完了！", self._on_ready).pack(side="left", padx=8,
                                                              ipadx=16, ipady=6)
        self._btn(btn_row, "バトル開始(デモ)", self._start_battle,
                  bg=C["yellow"]).pack(side="left", padx=8, ipadx=16, ipady=6)

    def _on_ready(self):
        self.ready_status.config(text="準備完了！相手を待っています...", fg=C["green"])
        self._log_ready("準備完了を送信しました\n")

    def _log_ready(self, text: str):
        self.ready_log.config(state="normal")
        self.ready_log.insert("end", text)
        self.ready_log.see("end")
        self.ready_log.config(state="disabled")

    # ────────────── 画面4: バトル ──────────────
    def _build_battle_screen(self):
        f = tk.Frame(self.root, bg=C["bg"], width=600, height=500)
        self.frames["battle"] = f

        tk.Label(f, text="⚔  BATTLE ⚔", font=FONT_TITLE,
                 bg=C["bg"], fg=C["red"]).pack(pady=(16, 10))

        # ── ステータスエリア ──
        status_row = tk.Frame(f, bg=C["bg"])
        status_row.pack(fill="x", padx=20)

        # 自分側
        self.my_frame = tk.Frame(status_row, bg=C["panel"], relief="flat",
                                 width=220, height=120)
        self.my_frame.pack(side="left", padx=4)
        self.my_frame.pack_propagate(False)
        self.my_name_lbl  = tk.Label(self.my_frame, text="自分", font=FONT_LARGE,
                                     bg=C["panel"], fg=C["accent"])
        self.my_name_lbl.pack(pady=(10, 2))
        self.my_hp_lbl    = tk.Label(self.my_frame, text="HP: -",
                                     font=FONT_MEDIUM, bg=C["panel"], fg=C["text"])
        self.my_hp_lbl.pack()
        self.my_hp_canvas = tk.Canvas(self.my_frame, width=180, height=16,
                                      bg=C["border"], highlightthickness=0)
        self.my_hp_canvas.pack(pady=6)
        self.my_mons_lbl  = tk.Label(self.my_frame, text="", font=FONT_SMALL,
                                     bg=C["panel"], fg=C["sub"])
        self.my_mons_lbl.pack()

        # VS
        tk.Label(status_row, text="VS", font=("Helvetica", 18, "bold"),
                 bg=C["bg"], fg=C["sub"], width=6).pack(side="left")

        # 相手側
        self.en_frame = tk.Frame(status_row, bg=C["panel"], relief="flat",
                                 width=220, height=120)
        self.en_frame.pack(side="left", padx=4)
        self.en_frame.pack_propagate(False)
        self.en_name_lbl  = tk.Label(self.en_frame, text="相手", font=FONT_LARGE,
                                     bg=C["panel"], fg=C["red"])
        self.en_name_lbl.pack(pady=(10, 2))
        self.en_hp_lbl    = tk.Label(self.en_frame, text="HP: -",
                                     font=FONT_MEDIUM, bg=C["panel"], fg=C["text"])
        self.en_hp_lbl.pack()
        self.en_hp_canvas = tk.Canvas(self.en_frame, width=180, height=16,
                                      bg=C["border"], highlightthickness=0)
        self.en_hp_canvas.pack(pady=6)
        self.en_mons_lbl  = tk.Label(self.en_frame, text="", font=FONT_SMALL,
                                     bg=C["panel"], fg=C["sub"])
        self.en_mons_lbl.pack()

        # ── バトルログ ──
        self.battle_log = scrolledtext.ScrolledText(
            f, width=62, height=9, font=FONT_MONO,
            bg=C["panel"], fg=C["text"], relief="flat", state="disabled"
        )
        self.battle_log.pack(pady=10, padx=10)

        # ── 操作ボタン ──
        btn_row = tk.Frame(f, bg=C["bg"])
        btn_row.pack(pady=6)
        self._btn(btn_row, "攻撃！", self._on_attack,
                  bg=C["red"]).pack(side="left", padx=8, ipadx=16, ipady=6)
        self._btn(btn_row, "次のラウンド", self._on_next_round,
                  bg=C["purple"]).pack(side="left", padx=8, ipadx=16, ipady=6)
        self._btn(btn_row, "タイトルへ", lambda: self._show("name"),
                  bg=C["border"]).pack(side="left", padx=8, ipadx=16, ipady=6)

    def _draw_hp_bar(self, canvas, current, max_hp, color_ok, color_low):
        canvas.delete("all")
        ratio = max(0, current / max_hp)
        width = int(180 * ratio)
        color = color_ok if ratio > 0.3 else color_low
        if width > 0:
            canvas.create_rectangle(0, 0, width, 16, fill=color, outline="")

    def _update_battle_ui(self):
        if not self.my_mons or not self.en_mons:
            return
        my = self.my_mons[self.my_idx]
        en = self.en_mons[self.en_idx]
        max_hp_my = MONSTERS[my["name"]]["hp"]
        max_hp_en = MONSTERS[en["name"]]["hp"]

        self.my_name_lbl.config(text=f"{self.player_name}")
        self.my_hp_lbl.config(text=f"HP: {my['hp']} / {max_hp_my}  [{my['name']}]")
        self._draw_hp_bar(self.my_hp_canvas, my["hp"], max_hp_my, C["green"], C["red"])
        alive_my = sum(1 for m in self.my_mons if m["hp"] > 0)
        self.my_mons_lbl.config(text=f"残: {alive_my}/3体")

        self.en_hp_lbl.config(text=f"HP: {en['hp']} / {max_hp_en}  [{en['name']}]")
        self._draw_hp_bar(self.en_hp_canvas, en["hp"], max_hp_en, C["green"], C["red"])
        alive_en = sum(1 for m in self.en_mons if m["hp"] > 0)
        self.en_mons_lbl.config(text=f"残: {alive_en}/3体")

    def _add_battle_log(self, text: str):
        self.battle_log.config(state="normal")
        self.battle_log.insert("end", text + "\n")
        self.battle_log.see("end")
        self.battle_log.config(state="disabled")

    def _on_attack(self):
        if not self.my_mons or not self.en_mons:
            return
        my = self.my_mons[self.my_idx]
        en = self.en_mons[self.en_idx]

        if my["hp"] <= 0 or en["hp"] <= 0:
            self._add_battle_log("次のモンスターに交代が必要です")
            return

        # ラウンド実行
        self._add_battle_log(f"─── ラウンド開始 [{my['name']} vs {en['name']}] ───")
        if my["speed"] >= en["speed"]:
            dmg = max(0, my["atk"] - en["def"])
            en["hp"] -= dmg
            self._add_battle_log(f"  あなたが先攻！ → 相手に {dmg} ダメージ")
            if en["hp"] > 0:
                dmg2 = max(0, en["atk"] - my["def"])
                my["hp"] -= dmg2
                self._add_battle_log(f"  相手が反撃！ → あなたに {dmg2} ダメージ")
        else:
            dmg = max(0, en["atk"] - my["def"])
            my["hp"] -= dmg
            self._add_battle_log(f"  相手が先攻！ → あなたに {dmg} ダメージ")
            if my["hp"] > 0:
                dmg2 = max(0, my["atk"] - en["def"])
                en["hp"] -= dmg2
                self._add_battle_log(f"  あなたが反撃！ → 相手に {dmg2} ダメージ")

        self._update_battle_ui()
        self._check_ko()

    def _on_next_round(self):
        """倒れたモンスターを次のモンスターに交代"""
        changed = False
        my = self.my_mons[self.my_idx]
        if my["hp"] <= 0:
            for i, m in enumerate(self.my_mons):
                if m["hp"] > 0:
                    self.my_idx = i
                    self._add_battle_log(f"  ▶ {m['name']} 登場！")
                    changed = True
                    break

        en = self.en_mons[self.en_idx]
        if en["hp"] <= 0:
            for i, m in enumerate(self.en_mons):
                if m["hp"] > 0:
                    self.en_idx = i
                    self._add_battle_log(f"  ▶ 相手の {m['name']} 登場！")
                    changed = True
                    break

        if changed:
            self._update_battle_ui()
        else:
            self._add_battle_log("交代できるモンスターがいません")

    def _check_ko(self):
        my_all_dead = all(m["hp"] <= 0 for m in self.my_mons)
        en_all_dead = all(m["hp"] <= 0 for m in self.en_mons)
        if my_all_dead:
            self._add_battle_log("━━━ 敗北... あなたの全モンスターが倒れました ━━━")
        elif en_all_dead:
            self._add_battle_log("━━━ 勝利！！ 相手の全モンスターを倒しました！ ━━━")

    def _start_battle(self):
        # モンスターデータを初期化してバトル開始
        if not self.selected:
            self.selected = list(MONSTERS.keys())[:3]

        self.my_mons = [
            {**MONSTERS[n], "name": n} for n in self.selected
        ]
        enemy_names = random.sample(list(MONSTERS.keys()), 3)
        self.en_mons = [
            {**MONSTERS[n], "name": n} for n in enemy_names
        ]
        self.my_idx = 0
        self.en_idx = 0

        self._show("battle")
        self._update_battle_ui()

        self.battle_log.config(state="normal")
        self.battle_log.delete("1.0", "end")
        self.battle_log.config(state="disabled")

        self._add_battle_log(f"━━━ バトル開始！ ━━━")
        self._add_battle_log(f"あなた: {', '.join(self.selected)}")
        self._add_battle_log(f"相手:   {', '.join(enemy_names)}")
        self._add_battle_log("")

    # ─────────────────────────────── ユーティリティ ───────────────────────────────
    def _btn(self, parent, text, command, bg=None, state="normal") -> tk.Button:
        return tk.Button(
            parent, text=text, command=command,
            font=FONT_MEDIUM,
            bg=bg or C["accent"], fg=C["bg"],
            relief="flat", cursor="hand2",
            activebackground=C["sub"],
            state=state,
        )

    # ─────────────────────────────── ROS2 ───────────────────────────────
    def _start_ros(self):
        if not ROS2_AVAILABLE:
            return
        try:
            rclpy.init()
            self.ros_node = FightClientNode(self.event_queue)
            self.ros_thread = threading.Thread(
                target=rclpy.spin,
                args=(self.ros_node,),
                daemon=True,
            )
            self.ros_thread.start()
        except Exception as e:
            print(f"[ROS2] 起動失敗: {e}", file=sys.stderr)

    def _poll(self):
        """GUIスレッドからキューを監視してROS2イベントを処理"""
        try:
            while True:
                event = self.event_queue.get_nowait()
                self._handle_event(event)
        except queue.Empty:
            pass
        self.root.after(100, self._poll)

    def _handle_event(self, event):
        tag = event[0]
        if tag == "name_ok":
            _, pid, msg = event
            self.player_id = pid
            self.name_status.config(text=msg, fg=C["green"])
            self.root.after(800, lambda: self._show("select"))
        elif tag == "error":
            self.name_status.config(text=f"エラー: {event[1]}", fg=C["red"])

    def on_close(self):
        if self.ros_node:
            self.ros_node.destroy_node()
        if ROS2_AVAILABLE:
            try:
                rclpy.shutdown()
            except Exception:
                pass
        self.root.destroy()


# ═══════════════════════════════════════════════════════════════════════
# エントリポイント
# ═══════════════════════════════════════════════════════════════════════
def main(args=None):
    root = tk.Tk()
    root.geometry("620x520")
    app = FightGameApp(root)
    root.protocol("WM_DELETE_WINDOW", app.on_close)
    root.mainloop()


if __name__ == "__main__":
    main()
