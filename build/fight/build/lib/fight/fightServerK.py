import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient



from rsysmsg.srv import Name
from rsysmsg.msg import Num
from rsysmsg.action import Monster

monsters = {"A":{"hp": 50, "speed": 5, "attack": 10, "defense": 10},
            "B":{"hp": 50, "speed": 5, "attack": 10, "defense": 10},
            "C":{"hp": 50, "speed": 5, "attack": 10, "defense": 10},
            "D":{"hp": 50, "speed": 5, "attack": 10, "defense": 10},
            "E":{"hp": 50, "speed": 5, "attack": 10, "defense": 10}}

class Player:
    def __init__(self, Pname, Pnum, monsters, Php, Pspeed, Pattack, Pdefense):
        self.Pname = Pname
        self.Pnum = Pnum
        self.monsters = monsters
        self.Php = Php
        self.Pspeed = Pspeed
        self.Pattack = Pattack
        self.Pdefense = Pdefense
        self.flg = 0

    def dead(self):
        return self.Php <= 0

    def defeat(self):
        return self.flg >= 3

    def speed(self, field):
        field.speeds[self.Pnum] = self.Pspeed


    def hp(self, field):
        field.hps[self.Pnum] = self.Php
  

    def attack(self, field):
        field.attacksP[self.Pnum] = field.attacks[self.Pnum]
        field.attacks[self.Pnum] = self.Pattack
  

    def defense(self, field):
        field.defensesP[self.Pnum] = field.defenses[self.Pnum]
        field.defenses[self.Pnum] = self.Pdefense
  
class Field:
    def __init__(self, attacks, attacksP, defenses, defensesP, speeds, hps):
        self.attacks = attacks
        self.attacksP = attacksP
        self.defenses = defenses
        self.defensesP = defensesP
        self.speeds = speeds
        self.hps = hps
        self.hpsF = [0, 0]

    def battle(self):
        if self.speeds[0] >= self.speeds[1]:
            F = 0
            S = 1
        else:
            F = 1
            S = 0

        self.hpsF[S] = self.hps[S] + self.defensesP[S] - self.attacks[F]
        if self.hpsF[S] < self.hps[S]:
            self.hps[S] = self.hpsF[S]
        else:
            print("no damage")
        if self.hps[S] <= 0:
            return 0
        
        self.hpsF[F] = self.hps[F] + self.defensesP[F] - self.attacks[S]
        if self.hpsF[F] < self.hps[F]:
            self.hps[F] = self.hpsF[F]
        else:
            print("no damage")
            
        return 0

class FighterServer(Node):

    def __init__(self):
        super().__init__('fighter_server')
        self.P1 = Player("", 0, ["", "", ""], 0, 0, 0, 0)
        self.P2 = Player("", 1, ["", "", ""], 0, 0, 0, 0)
        self.field = Field([0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [0, 0])
        self.nameSrv = self.create_service(Name, 'name_srv', self.nameSrvCb)
        self.readySrv = self.create_service(Name, 'ready_srv', self.readySrvCb)
        self.startflg = 0
        self.ready = [0, 0]
        self.order = [0, 0]
        self.subscription_monster = self.create_subscription(Num, 'monster_select', self.monsterCb, 10)
        self.monster_select_ID = 2
        self.pre_monsters = [[0, 0, 0], [0, 0, 0]]
        self.action_client_monster_0 = ActionClient(self, Monster, 'monster_action_0')
        self.action_client_monster_1 = ActionClient(self, Monster, 'monster_action_1')
        self.get_logger().info('サーバ準備完了')

############################################################################################################
# モンスター選択用トピック＆アクション通信関数
# トピック通信でモンスターを選択したいプレイヤーのメッセージを受け取り, 受け取り次第そのプレイヤーにアクション通信で
# モンスターを選択するように指示を出す. プレイヤーが選択したときにフィードバックで逐次選択状況を受け取りリストを更新する. 
# 選択はモンスター登録と取り消しができる. クライアントから選択完了のメッセージを受け取ったら出来上がったリストを元に
# プレイヤーのモンスターを登録する. 
    def monsterAction(self):
        self.get_logger().info('monsterAction')
        goal_msg = Monster.Goal()
        goal_msg.order = 'モンスターセレクトのリクエストを受け付けました. '
        if self.monster_select_ID == 0:
            if not self.action_client_monster_0.wait_for_server():
                self.get_logger().info('クライアントが見つかりませんでした. ')
                return
            self.send_goal_monster_future = self.action_client_monster_0.send_goal_async(goal_msg, feedback_callback = self.feedback_callback)
            self.send_goal_monster_future.add_done_callback(self.goal_response_callback)
        else:
            if not self.action_client_monster_1.wait_for_server():
                self.get_logger().info('クライアントが見つかりませんでした. ')
                return
            self.send_goal_monster_future = self.action_client_monster_1.send_goal_async(goal_msg, feedback_callback = self.feedback_callback)
            self.send_goal_monster_future.add_done_callback(self.goal_response_callback)
            
    def goal_response_callback(self, future):
        self.get_logger().info('goal_response_callback')
        goal_handle = future.result()
        if goal_handle == 2:
            self.get_logger().info('プレイヤーがリクエストを取り消しました. ')
            return
        self.get_logger().info('クライアントが承認しました. ')

        self.pre_monsters[self.monster_select_ID] = [0, 0, 0] #プレイヤーの登録用リストを初期化

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        self.get_logger().info('get_result_callback')
        result = future.result().result
        self.get_logger().info('終了メッセージ受信')

    def feedback_callback(self, feedback_msg):
        self.get_logger().info('feedback_callback')
        self.get_logger().info('フィードバック受信')
        monster = feedback_msg.monster
        num = feedback_msg.fbnum
        if monster == 'back':
            self.pre_monsters[monster_select_ID][num-1] = 0
        else:
            self.pre_monster[monster_select_ID][num] = monster

        


#トピック通信用関数
# プレイヤーのIDが登録されていなければスキップする. 登録されていればそのプレイヤーがモンスターを選択できるように
# アクション通信クライアントを起動する. 
    def monsterCb(self, msg):
        self.get_logger().info('monsterCb')
        self.get_logger().info('プレイヤー %s からモンスター選択のリクエストを受け取りました. ', msg.ID)
        if msg.ID == 2:
            self.get_logger().info('このクライアントはプレイヤーとして登録されていないためスキップします. ')
            return 0
        else:
            self.monster_select_ID = msg.ID
            self.monsterAction()

    # def monsterSelect(self, order):
    #     goal_msg = Monster.Goal()

# モンスター選択用アクション通信関数
######################################################################################################


# 指示受け取りサービス通信関数
# プレイヤーからの指令を受け取ったときにプレイヤー1かプレイヤー2どちらの指令なのかを判定し, 
# そのプレイヤーの指示通りにfieldの攻撃力や防御力を更新する. もしゲームが開始していなければ
# 受付できないことをメッセージで返す. 
    def fightingSrvCb(self, request, response):
        self.get_logger().info('fightingSrvCb')
        self.get_logger().info("プレイヤー %s から指示を受け取りました. ", request.ID)
        if self.startflg != 1:
            response.reID = request.ID
            response.res = "ゲームが開始していないため, 指示を受付できません. "
            return response
        if request.ID == 1:
            print("aaaa")
            

# 準備完了状況に応じてゲームを開始するか否かを判定するためのサービス通信関数
# 両方準備完了していればfieldにプレイヤーの初期HPとスピードを反映しfightingSrvCbを受付できるようにする
# 準備完了していなければその旨のメッセージを返す.
    def startSrvCb(self, request, response):
        self.get_logger().info('startSrvCb')
        if self.ready != [1, 1]:
            response.reID = request.ID
            response.res = "相手が準備完了していないため, ゲームを開始できません. "
            return response
        else:
            self.startflg = 1
            self.field.speeds = [self.P1.Pspeed, self.P2.Pspeed]
            self.field.hps = [self.P1.Php, self.P2.Php]
            response.reID = request.ID
            response.res = "ゲームが開始されました. "
            return response


# プレイヤーの準備完了メッセージを受け取り判定するためのサービス通信関数
# プレイヤーの準備完了メッセージを受け取ったときに, そのプレイヤーが名前と使用モンスターを登録しているかどうか
# を確認し, 状況に応じてメッセージを返す. 自分だけが完了していた場合は相手の完了を待つ旨のメッセージを送り, 
# 相手も準備が完了していれば開始できる旨のメッセージを返す. 
    def readySrvCb(self, request, response):
        self.get_logger().info('readySrvCb')
        self.get_logger().info("プレイヤー %s から準備完了のリクエストを受け取りました. ", request.ID)
        if request.ID == 2:
            response.reID = request.ID
            response.res = "このクライアントはプレイヤーとして登録されていません. "
            return response

        if request.ID == 0 and self.P1.monsters == ["", "", ""]:
            response.reID = request.ID
            response.res = "あなたはモンスターを選択していないため準備完了できません. "
            return response

        if request.ID == 1 and self.P2.monsters == ["", "", ""]:
            response.reID = request.ID
            response.res = "あなたはモンスターを選択していないため準備完了できません. "
            return response

        if request.ID == 0 or request.ID == 1:
            self.ready[request.ID] = 1
        
        if self.ready != [1, 1]:
            response.reID = request.ID
            response.res = "もう1人のプレイヤーの準備完了を待っています..."
        else:
            response.reID = request.ID
            response.res = "両方のプレイヤーが準備完了しました. startでゲームを開始できます. "
            return response
    
# プレイヤーネーム登録用サービス通信関数
# プレイヤーがもう登録されているか, 登録しようとするプレイヤーネームがすでに使用されているのかを判定し登録処理を行う.
# クライアント側には登録できたら何番目のプレイヤーとして登録されたかをメッセージとIDで返し, 
# 登録できなかったときはその理由を示したメッセージを返す. 
    def nameSrvCb(self, request, response):
        self.get_logger().info('nameSrvCb')
        self.get_logger().info("クライアントからプレイヤーネームのリクエストを受け取りました. ")

        if self.P1.Pname != "" and self.P2.Pname != "":
            response.reid = request.id
            response.res = "E2"#"すでに2人のプレイヤーが登録されています. "
            return response

        reqName = request.name
        if self.P1.Pname != "":
            if reqName == self.P2.Pname:
                response.reid = request.id
                response.res = "Ename"#"そのプレイヤーネームはすでに使用されています. もう一度お試しください. "
                return response

            else:
                self.P2.Pname = reqName
                response.reid = 1
                response.res = "2"#"あなたは2番目のプレイヤーとして登録されました. "
                return response

        else:
            self.P1.Pname = reqName
            response.reid = 0
            response.res = "2"#"あなたは1番目のプレイヤーとして登録されました. "
            return response


def main(args=None):
    try:
        rclpy.init(args=args)
        FS = FighterServer()
        rclpy.spin(FS)
    except KeyboardInterrupt:
        FS.destroy_node()

