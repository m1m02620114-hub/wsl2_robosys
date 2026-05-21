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
import tkinter.font as tkfont
import threading
import queue
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

# ───────────────────────────── フォント検出 ─────────────────────────────
def _detect_jp_font() -> str:
    """日本語対応フォントをシステムから自動検出する (Linux/WSL2優先)"""
    root = tk.Tk()
    root.withdraw()
    available = set(tkfont.families())
    root.destroy()
    for candidate in [
        # Linux / WSL2
        "Noto Sans CJK JP",
        "IPAGothic",
        "IPAPGothic",
        "VL Gothic",
        "VL PGothic",
        "TakaoGothic",
        "TakaoPGothic",
        "Sazanami Gothic",
        # Windows
        "Yu Gothic",
        "Meiryo",
        "MS Gothic",
        # macOS (最後の手段)
        "Hiragino Sans",
        "AppleGothic",
    ]:
        if candidate in available:
            return candidate
    return "TkDefaultFont"


_JP_FONT = _detect_jp_font()

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
    "tip":    "#1c2633",
}

FONT_TITLE  = (_JP_FONT, 22, "bold")
FONT_LARGE  = (_JP_FONT, 14, "bold")
FONT_MEDIUM = (_JP_FONT, 11)
FONT_SMALL  = (_JP_FONT, 9)
FONT_MONO   = (_JP_FONT, 10)
FONT_TIP    = (_JP_FONT, 9)


# ═══════════════════════════════════════════════════════════════════════
# ROS2 クライアントノード
# ═══════════════════════════════════════════════════════════════════════
class FightClientNode(Node):
    def __init__(self, event_queue: queue.Queue):
        super().__init__("fight_gui_client")
        self.q = event_queue
        self.player_id = -1

        self.name_pub    = self.create_publisher(String, "name", 10)
        self.monster_pub = self.create_publisher(Num, "monster_select", 10)
        self.name_cli    = self.create_client(Name, "name_srv")

        self.get_logger().info("FightGUIクライアント起動")

    def register_name(self, name: str):
        msg = String()
        msg.data = name
        self.name_pub.publish(msg)

        if self.name_cli.service_is_ready():
            req = Name.Request()
            req.name = name
            future = self.name_cli.call_async(req)
            future.add_done_callback(self._on_name_response)
        else:
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
# ゲームアプリ
# ═══════════════════════════════════════════════════════════════════════
class FightGameApp:
    def __init__(self, root: tk.Tk):
        self.root = root
        self.root.title("ROBOSYS FIGHT")
        self.root.configure(bg=C["bg"])
        self.root.resizable(False, False)

        self.event_queue: queue.Queue = queue.Queue()
        self.ros_node   = None
        self.ros_thread = None

        self.player_name = ""
        self.player_id   = -1
        self.selected: list[str] = []
        self.my_mons: list[dict] = []
        self.en_mons: list[dict] = []
        self.my_idx = 0
        self.en_idx = 0

        self._build_ui()
        self._start_ros()
        self._show("name")
        self._poll()

    # ─────────────────────────────── 画面切替 ───────────────────────────────
    def _show(self, key: str):
        for f in self.frames.values():
            f.pack_forget()
        self.frames[key].pack(fill="both", expand=True)

    def _build_ui(self):
        self.frames: dict[str, tk.Frame] = {}
        self._build_name_screen()
        self._build_select_screen()
        self._build_ready_screen()
        self._build_battle_screen()

    # ─────────────────────────────── ヒント枠ウィジェット ───────────────────────────────
    def _tip_box(self, parent, text: str) -> tk.Label:
        """操作説明用の枠付きラベル"""
        return tk.Label(
            parent, text=text, font=FONT_TIP,
            bg=C["tip"], fg=C["sub"],
            justify="left", anchor="w",
            relief="flat", padx=12, pady=8,
        )

    # ════════════════════════════════════════
    # 画面1: 名前入力
    # ════════════════════════════════════════
    def _build_name_screen(self):
        f = tk.Frame(self.root, bg=C["bg"])
        self.frames["name"] = f

        tk.Label(f, text="ROBOSYS FIGHT", font=(_JP_FONT, 28, "bold"),
                 bg=C["bg"], fg=C["accent"]).pack(pady=(30, 2))
        tk.Label(f, text="モンスターで戦え！", font=FONT_MEDIUM,
                 bg=C["bg"], fg=C["sub"]).pack(pady=(0, 16))

        # ROS2 状態バッジ
        ros_txt   = "ROS2: 接続済み" if ROS2_AVAILABLE else "ROS2: 未接続 (デモモードで動作)"
        ros_color = C["green"] if ROS2_AVAILABLE else C["yellow"]
        tk.Label(f, text=ros_txt, font=FONT_SMALL,
                 bg=C["panel"], fg=ros_color, padx=10, pady=4).pack(pady=(0, 18))

        tk.Label(f, text="プレイヤー名を入力してください", font=FONT_MEDIUM,
                 bg=C["bg"], fg=C["text"]).pack()

        self.name_var = tk.StringVar()
        entry = tk.Entry(f, textvariable=self.name_var, font=FONT_LARGE,
                         bg=C["panel"], fg=C["text"], insertbackground=C["text"],
                         relief="flat", width=20, justify="center")
        entry.pack(pady=8, ipady=8)
        entry.focus()
        entry.bind("<Return>", lambda e: self._on_join())

        self.name_status = tk.Label(f, text="", font=FONT_SMALL,
                                    bg=C["bg"], fg=C["sub"])
        self.name_status.pack(pady=4)

        self._btn(f, "参加する  (Enter)", self._on_join).pack(pady=8, ipadx=20, ipady=6)

        # ── 操作説明 ──
        tip = (
            "【ゲームの流れ】\n"
            "  Step 1  プレイヤー名を入力 → 「参加する」を押してサーバに登録\n"
            "  Step 2  モンスターを3体選ぶ\n"
            "  Step 3  「準備完了！」を押して相手の準備を待つ\n"
            "  Step 4  バトル開始！ — 相手の3体を全て倒せば勝ち\n\n"
            "※ ROS2サーバ未起動の場合はデモモードで操作を確認できます\n"
            "※ キーボードの Enter キーでも参加できます"
        )
        self._tip_box(f, tip).pack(fill="x", padx=24, pady=(12, 0))

    def _on_join(self):
        name = self.name_var.get().strip()
        if not name:
            self.name_status.config(text="名前を入力してください", fg=C["red"])
            return
        self.player_name = name
        self.name_status.config(text="サーバに登録中...", fg=C["sub"])
        if self.ros_node:
            self.ros_node.register_name(name)
        else:
            self.event_queue.put(("name_ok", 0, f"[デモ] {name} として P1 に登録しました"))

    # ════════════════════════════════════════
    # 画面2: モンスター選択
    # ════════════════════════════════════════
    def _build_select_screen(self):
        f = tk.Frame(self.root, bg=C["bg"])
        self.frames["select"] = f

        tk.Label(f, text="モンスターを選べ！", font=FONT_TITLE,
                 bg=C["bg"], fg=C["accent"]).pack(pady=(16, 2))
        tk.Label(f, text="3体選択してください（選んだ順番に出場します）",
                 font=FONT_SMALL, bg=C["bg"], fg=C["sub"]).pack(pady=(0, 8))

        # ── モンスターカード一覧 ──
        card_frame = tk.Frame(f, bg=C["bg"])
        card_frame.pack()
        self.monster_btns: dict[str, tk.Button] = {}
        for i, (mname, mdata) in enumerate(MONSTERS.items()):
            card = self._monster_card(card_frame, mname, mdata)
            card.grid(row=i // 3, column=i % 3, padx=6, pady=4)

        # ── 選択スロット ──
        slot_frame = tk.Frame(f, bg=C["bg"])
        slot_frame.pack(pady=8)
        tk.Label(slot_frame, text="出場順:", font=FONT_MEDIUM,
                 bg=C["bg"], fg=C["text"]).pack(side="left", padx=(0, 8))
        self.slots: list[tk.Label] = []
        for i in range(3):
            lbl = tk.Label(slot_frame, text=f"  {i+1}番  ", font=FONT_MEDIUM,
                           bg=C["panel"], fg=C["sub"], width=9, pady=3)
            lbl.pack(side="left", padx=3)
            self.slots.append(lbl)

        self.confirm_btn = self._btn(f, "決定してサーバに送信！",
                                     self._on_confirm_select, state="disabled")
        self.confirm_btn.pack(pady=6, ipadx=16, ipady=5)

        # ── 操作説明 ──
        tip = (
            "【モンスターの選び方】\n"
            "  ・各カードの「選択」ボタンを押すと出場メンバーに追加されます\n"
            "  ・もう一度押すと選択を取り消せます\n"
            "  ・1番目に選んだモンスターが最初に戦います\n\n"
            "【ステータスの見方】\n"
            "  HP  : 体力。0になったモンスターは倒れます\n"
            "  SPD : 素早さ。相手より高いと先攻になります\n"
            "  ATK : 攻撃力。ダメージ = 自分のATK - 相手のDEF\n"
            "  DEF : 防御力。相手のATKから引かれ、ダメージを軽減します"
        )
        self._tip_box(f, tip).pack(fill="x", padx=16, pady=(6, 8))

    def _monster_card(self, parent, mname: str, mdata: dict) -> tk.Frame:
        card = tk.Frame(parent, bg=C["panel"], width=168, height=128)
        card.pack_propagate(False)

        tk.Frame(card, bg=mdata["color"], height=4).pack(fill="x")
        tk.Label(card, text=mname, font=FONT_LARGE,
                 bg=C["panel"], fg=mdata["color"]).pack(pady=(6, 1))

        stats = (f"HP:{mdata['hp']}  SPD:{mdata['speed']}\n"
                 f"ATK:{mdata['atk']}  DEF:{mdata['def']}")
        tk.Label(card, text=stats, font=FONT_SMALL,
                 bg=C["panel"], fg=C["sub"], justify="center").pack()

        btn = tk.Button(card, text="選択", font=FONT_SMALL,
                        bg=C["accent"], fg=C["bg"], relief="flat",
                        command=lambda n=mname: self._toggle_monster(n),
                        cursor="hand2")
        btn.pack(pady=5, ipadx=10)
        self.monster_btns[mname] = btn
        return card

    def _toggle_monster(self, name: str):
        if name in self.selected:
            self.selected.remove(name)
            self.monster_btns[name].config(text="選択", bg=C["accent"])
        elif len(self.selected) < 3:
            self.selected.append(name)
            self.monster_btns[name].config(text="選択済 ✓", bg=C["green"])

        for i, slot in enumerate(self.slots):
            if i < len(self.selected):
                slot.config(text=self.selected[i], fg=C["text"])
            else:
                slot.config(text=f"  {i+1}番  ", fg=C["sub"])

        self.confirm_btn.config(
            state="normal" if len(self.selected) == 3 else "disabled"
        )

    def _on_confirm_select(self):
        if self.ros_node:
            self.ros_node.send_monster_request(self.player_id)
            for mname in self.selected:
                self.ros_node.send_monster_choice(list(MONSTERS.keys()).index(mname))
        self._show("ready")
        self._log_ready(f"モンスター選択完了: {' / '.join(self.selected)}\n")
        self._log_ready("「準備完了！」ボタンを押してサーバに合図を送ってください。\n")

    # ════════════════════════════════════════
    # 画面3: 準備・待機
    # ════════════════════════════════════════
    def _build_ready_screen(self):
        f = tk.Frame(self.root, bg=C["bg"])
        self.frames["ready"] = f

        tk.Label(f, text="準備完了", font=FONT_TITLE,
                 bg=C["bg"], fg=C["accent"]).pack(pady=(24, 6))

        self.ready_log = scrolledtext.ScrolledText(
            f, width=56, height=7, font=FONT_MONO,
            bg=C["panel"], fg=C["text"], relief="flat", state="disabled"
        )
        self.ready_log.pack(pady=6, padx=20)

        self.ready_status = tk.Label(f, text="相手プレイヤーの準備を待っています...",
                                     font=FONT_MEDIUM, bg=C["bg"], fg=C["sub"])
        self.ready_status.pack(pady=6)

        btn_row = tk.Frame(f, bg=C["bg"])
        btn_row.pack(pady=6)
        self._btn(btn_row, "準備完了！", self._on_ready,
                  bg=C["green"]).pack(side="left", padx=10, ipadx=16, ipady=6)
        self._btn(btn_row, "バトル開始 (デモ)", self._start_battle,
                  bg=C["yellow"]).pack(side="left", padx=10, ipadx=16, ipady=6)

        # ── 操作説明 ──
        tip = (
            "【この画面でできること】\n"
            "  準備完了！  … サーバに「準備できた」という合図を送ります\n"
            "              相手プレイヤーも押すと自動的にバトルが始まります\n\n"
            "  バトル開始(デモ)  … サーバなしでローカルバトルを体験できます\n"
            "                      動作確認や練習に使ってください\n\n"
            "※ 上のログエリアにサーバからの返答が表示されます"
        )
        self._tip_box(f, tip).pack(fill="x", padx=20, pady=(8, 0))

    def _on_ready(self):
        self.ready_status.config(text="準備完了を送信しました！相手を待っています...",
                                 fg=C["green"])
        self._log_ready("--- 準備完了の合図をサーバに送信しました ---\n")
        self._log_ready("相手プレイヤーも準備完了するとバトルが始まります。\n")

    def _log_ready(self, text: str):
        self.ready_log.config(state="normal")
        self.ready_log.insert("end", text)
        self.ready_log.see("end")
        self.ready_log.config(state="disabled")

    # ════════════════════════════════════════
    # 画面4: バトル
    # ════════════════════════════════════════
    def _build_battle_screen(self):
        f = tk.Frame(self.root, bg=C["bg"])
        self.frames["battle"] = f

        tk.Label(f, text="BATTLE", font=(_JP_FONT, 20, "bold"),
                 bg=C["bg"], fg=C["red"]).pack(pady=(12, 6))

        # ── ステータスエリア ──
        status_row = tk.Frame(f, bg=C["bg"])
        status_row.pack(fill="x", padx=16)

        # 自分側
        mf = tk.Frame(status_row, bg=C["panel"], width=230, height=110)
        mf.pack(side="left", padx=2)
        mf.pack_propagate(False)
        self.my_name_lbl  = tk.Label(mf, text="自分", font=FONT_LARGE,
                                     bg=C["panel"], fg=C["accent"])
        self.my_name_lbl.pack(pady=(8, 1))
        self.my_hp_lbl    = tk.Label(mf, text="HP: -",
                                     font=FONT_MEDIUM, bg=C["panel"], fg=C["text"])
        self.my_hp_lbl.pack()
        self.my_hp_canvas = tk.Canvas(mf, width=190, height=14,
                                      bg=C["border"], highlightthickness=0)
        self.my_hp_canvas.pack(pady=4)
        self.my_mons_lbl  = tk.Label(mf, text="", font=FONT_SMALL,
                                     bg=C["panel"], fg=C["sub"])
        self.my_mons_lbl.pack()

        # VS
        tk.Label(status_row, text="VS", font=(_JP_FONT, 16, "bold"),
                 bg=C["bg"], fg=C["sub"], width=7).pack(side="left")

        # 相手側
        ef = tk.Frame(status_row, bg=C["panel"], width=230, height=110)
        ef.pack(side="left", padx=2)
        ef.pack_propagate(False)
        self.en_name_lbl  = tk.Label(ef, text="相手", font=FONT_LARGE,
                                     bg=C["panel"], fg=C["red"])
        self.en_name_lbl.pack(pady=(8, 1))
        self.en_hp_lbl    = tk.Label(ef, text="HP: -",
                                     font=FONT_MEDIUM, bg=C["panel"], fg=C["text"])
        self.en_hp_lbl.pack()
        self.en_hp_canvas = tk.Canvas(ef, width=190, height=14,
                                      bg=C["border"], highlightthickness=0)
        self.en_hp_canvas.pack(pady=4)
        self.en_mons_lbl  = tk.Label(ef, text="", font=FONT_SMALL,
                                     bg=C["panel"], fg=C["sub"])
        self.en_mons_lbl.pack()

        # ── バトルログ ──
        self.battle_log = scrolledtext.ScrolledText(
            f, width=64, height=8, font=FONT_MONO,
            bg=C["panel"], fg=C["text"], relief="flat", state="disabled"
        )
        self.battle_log.pack(pady=6, padx=10)

        # ── 操作ボタン ──
        btn_row = tk.Frame(f, bg=C["bg"])
        btn_row.pack(pady=4)
        self._btn(btn_row, "攻撃！", self._on_attack,
                  bg=C["red"]).pack(side="left", padx=6, ipadx=14, ipady=5)
        self._btn(btn_row, "次のモンスターに交代", self._on_next_round,
                  bg=C["purple"]).pack(side="left", padx=6, ipadx=14, ipady=5)
        self._btn(btn_row, "タイトルへ戻る", lambda: self._show("name"),
                  bg=C["border"]).pack(side="left", padx=6, ipadx=14, ipady=5)

        # ── 操作説明 ──
        tip = (
            "【バトルの操作方法】\n"
            "  攻撃！              … 1ラウンド実行。素早さ(SPD)が高い方が先攻で攻撃します\n"
            "  次のモンスターに交代 … 現在のモンスターが倒れたとき、次の1体に交代します\n"
            "  タイトルへ戻る      … タイトル画面に戻ります（バトルデータはリセットされます）\n\n"
            "【勝利条件】相手の3体全てのHPを0にすれば勝ちです！\n"
            "【ダメージ計算】ダメージ = 攻撃側のATK - 防御側のDEF  (最低0)"
        )
        self._tip_box(f, tip).pack(fill="x", padx=10, pady=(4, 8))

    # ─────────────────────────────── バトルロジック ───────────────────────────────
    def _draw_hp_bar(self, canvas, current, max_hp):
        canvas.delete("all")
        ratio = max(0, current / max_hp)
        width = int(190 * ratio)
        color = C["green"] if ratio > 0.3 else C["red"]
        if width > 0:
            canvas.create_rectangle(0, 0, width, 14, fill=color, outline="")

    def _update_battle_ui(self):
        if not self.my_mons or not self.en_mons:
            return
        my = self.my_mons[self.my_idx]
        en = self.en_mons[self.en_idx]
        max_my = MONSTERS[my["name"]]["hp"]
        max_en = MONSTERS[en["name"]]["hp"]

        self.my_name_lbl.config(text=self.player_name)
        self.my_hp_lbl.config(text=f"HP: {max(0, my['hp'])} / {max_my}  [{my['name']}]")
        self._draw_hp_bar(self.my_hp_canvas, my["hp"], max_my)
        alive_my = sum(1 for m in self.my_mons if m["hp"] > 0)
        self.my_mons_lbl.config(text=f"残り {alive_my} / 3 体")

        self.en_hp_lbl.config(text=f"HP: {max(0, en['hp'])} / {max_en}  [{en['name']}]")
        self._draw_hp_bar(self.en_hp_canvas, en["hp"], max_en)
        alive_en = sum(1 for m in self.en_mons if m["hp"] > 0)
        self.en_mons_lbl.config(text=f"残り {alive_en} / 3 体")

    def _log_battle(self, text: str):
        self.battle_log.config(state="normal")
        self.battle_log.insert("end", text + "\n")
        self.battle_log.see("end")
        self.battle_log.config(state="disabled")

    def _on_attack(self):
        if not self.my_mons or not self.en_mons:
            return
        my = self.my_mons[self.my_idx]
        en = self.en_mons[self.en_idx]

        if my["hp"] <= 0:
            self._log_battle("! あなたのモンスターが倒れています。「次のモンスターに交代」を押してください。")
            return
        if en["hp"] <= 0:
            self._log_battle("! 相手のモンスターが倒れています。「次のモンスターに交代」を押してください。")
            return

        self._log_battle(f"--- [{my['name']}] vs [{en['name']}] ---")

        if my["speed"] >= en["speed"]:
            dmg1 = max(0, my["atk"] - en["def"])
            en["hp"] -= dmg1
            self._log_battle(
                f"  あなたが先攻！ (SPD {my['speed']} >= {en['speed']})\n"
                f"  ATK {my['atk']} - DEF {en['def']} = {dmg1} ダメージ → 相手残HP: {max(0, en['hp'])}"
            )
            if en["hp"] <= 0:
                self._log_battle(f"  >> 相手の [{en['name']}] を倒した！")
                self._update_battle_ui()
                self._check_ko()
                return
            dmg2 = max(0, en["atk"] - my["def"])
            my["hp"] -= dmg2
            self._log_battle(
                f"  相手が反撃！\n"
                f"  ATK {en['atk']} - DEF {my['def']} = {dmg2} ダメージ → 自分残HP: {max(0, my['hp'])}"
            )
        else:
            dmg1 = max(0, en["atk"] - my["def"])
            my["hp"] -= dmg1
            self._log_battle(
                f"  相手が先攻！ (SPD {en['speed']} > {my['speed']})\n"
                f"  ATK {en['atk']} - DEF {my['def']} = {dmg1} ダメージ → 自分残HP: {max(0, my['hp'])}"
            )
            if my["hp"] <= 0:
                self._log_battle(f"  >> あなたの [{my['name']}] が倒れた...")
                self._update_battle_ui()
                self._check_ko()
                return
            dmg2 = max(0, my["atk"] - en["def"])
            en["hp"] -= dmg2
            self._log_battle(
                f"  あなたが反撃！\n"
                f"  ATK {my['atk']} - DEF {en['def']} = {dmg2} ダメージ → 相手残HP: {max(0, en['hp'])}"
            )

        self._update_battle_ui()
        self._check_ko()

    def _on_next_round(self):
        changed = False
        if self.my_mons[self.my_idx]["hp"] <= 0:
            for i, m in enumerate(self.my_mons):
                if m["hp"] > 0:
                    self.my_idx = i
                    self._log_battle(f"  >> あなたは [{m['name']}] を繰り出した！")
                    changed = True
                    break
            if not changed:
                self._log_battle("  あなたには交代できるモンスターがいません。")

        if self.en_mons[self.en_idx]["hp"] <= 0:
            for i, m in enumerate(self.en_mons):
                if m["hp"] > 0:
                    self.en_idx = i
                    self._log_battle(f"  >> 相手は [{m['name']}] を繰り出した！")
                    changed = True
                    break

        if changed:
            self._update_battle_ui()
        elif self.my_mons[self.my_idx]["hp"] > 0 and self.en_mons[self.en_idx]["hp"] > 0:
            self._log_battle("  現在のモンスターはまだ戦えます。「攻撃！」を押してください。")

    def _check_ko(self):
        if all(m["hp"] <= 0 for m in self.my_mons):
            self._log_battle("=" * 48)
            self._log_battle("  敗北...  あなたの全モンスターが倒れました。")
            self._log_battle("  「タイトルへ戻る」でもう一度挑戦できます。")
            self._log_battle("=" * 48)
        elif all(m["hp"] <= 0 for m in self.en_mons):
            self._log_battle("=" * 48)
            self._log_battle("  勝利！！  相手の全モンスターを倒しました！")
            self._log_battle("  「タイトルへ戻る」でもう一度遊べます。")
            self._log_battle("=" * 48)
        else:
            if self.my_mons[self.my_idx]["hp"] <= 0 or self.en_mons[self.en_idx]["hp"] <= 0:
                self._log_battle("  >> モンスターが倒れました。「次のモンスターに交代」を押してください。")

    def _start_battle(self):
        if not self.selected:
            self.selected = list(MONSTERS.keys())[:3]

        self.my_mons = [{**MONSTERS[n], "name": n} for n in self.selected]
        enemy_names  = random.sample(list(MONSTERS.keys()), 3)
        self.en_mons = [{**MONSTERS[n], "name": n} for n in enemy_names]
        self.my_idx  = 0
        self.en_idx  = 0

        self._show("battle")
        self._update_battle_ui()

        self.battle_log.config(state="normal")
        self.battle_log.delete("1.0", "end")
        self.battle_log.config(state="disabled")

        self._log_battle("=" * 48)
        self._log_battle("  バトル開始！")
        self._log_battle(f"  あなた : {' / '.join(self.selected)}")
        self._log_battle(f"  相手   : {' / '.join(enemy_names)}")
        self._log_battle("  「攻撃！」ボタンを押してバトルを進めてください。")
        self._log_battle("=" * 48)

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
                target=rclpy.spin, args=(self.ros_node,), daemon=True)
            self.ros_thread.start()
        except Exception as e:
            print(f"[ROS2] 起動失敗: {e}", file=sys.stderr)

    def _poll(self):
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
            self.root.after(900, lambda: self._show("select"))
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
    root.geometry("680x700")
    app = FightGameApp(root)
    root.protocol("WM_DELETE_WINDOW", app.on_close)
    root.mainloop()


if __name__ == "__main__":
    main()
