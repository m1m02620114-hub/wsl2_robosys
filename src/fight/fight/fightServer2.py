import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
import class001

from rsysmsg.srv import NameSrv
from rsysmsg.msg import Num
from rsysmsg.srv import Fight
from rsysmsg.action import Monster


class FighterServer(Node):

    def __init__(self):
        super().__init__('fighter_server')
        self.P1 = class001.Player("", 0, ["", "", ""], 0, 0, 0, 0)
        self.P2 = class001.Player("", 1, ["", "", ""], 0, 0, 0, 0)
        self.field = class001.Field([0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [0, 0])
        self.nameSrv = self.create_service(NameSrv, 'name_srv', self.nameSrvCb)
        self.readySrv = self.create_service(NameSrv, 'ready_srv', self.readySrvCb)
        self.startflg = 0
        self.ready = [0, 0]
        self.order = [0, 0]
        self.subscription_monster = self.create_subscription(Num, 'monster_select', self.monsterCb, 10)
        self.monster_select_ID = 2
        self.pre_monsters = [[0, 0, 0], [0, 0, 0]]
        self.action_client_monster_0 = ActionClient(self, Monster, 'monster_action_0')
        self.action_client_monster_1 = ActionClient(self, Monster, 'monster_action_1')

############################################################################################################
# モンスター選択用トピック＆アクション通信関数
# トピック通信でモンスターを選択したいプレイヤーのメッセージを受け取り, 受け取り次第そのプレイヤーにアクション通信で
# モンスターを選択するように指示を出す. プレイヤーが選択したときにフィードバックで逐次選択状況を受け取りリストを更新する. 
# 選択はモンスター登録と取り消しができる. クライアントから選択完了のメッセージを受け取ったら出来上がったリストを元に
# プレイヤーのモンスターを登録する. 
    def monsterAction(self):
        goal_msg = Monster.Goal()
            goal_msg.order = '受け取った. '
        if self.monster_select_ID == 0:
            self.action_client_monster_0.wait_for_server()
            self.send_goal_monster_future = self.action_client_monster_0.send_goal_async(goal_msg)
            self.send_goal_monster_future.add_done_callback(self.goal_response_callback)
        else:
            self.action_client_monster_1.wait_for_server()
            self.send_goal_monster_future = self.action_client_monster_1.send_goal_async(goal_msg)
            self.send_goal_monster_future.add_done_callback(self.goal_response_callback)
            
    def goal_response_callback(self, future):
        goal_handle = future.result()
        if goal_handle == 2:
            self.get_logger().info('クライアントが拒否しました. ')
            return
        self.get_logger().info('クライアントが承認しました. ')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('終了メッセージ受信')

    def feedback_callback(self, feedback_msg):
        monster = feedback_msg.monster
        num = feedback_msg.fbnum
        if monster == 'back':
            self.pre_monsters[monster_select_ID][num-1] = 0
        else:
            self.pre_monster[monster_select_ID][num] = monster

        self.get_logger().info('フィードバック受信')



    def monsterCb(self, msg):
        self.get_logger().info('プレイヤー %s からモンスター選択のリクエストを受け取りました. ', msg.ID)
        if msg.ID == 2:
            self.get_logger().info('このクライアントはプレイヤーとして登録されていないためスキップします. ')
            return 0
        else:
            self.monster_select_ID = msg.ID
            self.monsterAction()

    def monsterSelect(self, order):
        goal_msg = Monster.Goal()

# モンスター選択用アクション通信関数
######################################################################################################


# 指示受け取りサービス通信関数
# プレイヤーからの指令を受け取ったときにプレイヤー1かプレイヤー2どちらの指令なのかを判定し, 
# そのプレイヤーの指示通りにfieldの攻撃力や防御力を更新する. もしゲームが開始していなければ
# 受付できないことをメッセージで返す. 
    def fightingSrvCb(self, request, response):
        self.get_logger().info("プレイヤー %s から指示を受け取りました. ", request.ID)
        if self.startflg != 1:
            response.reID = request.ID
            response.res = "ゲームが開始していないため, 指示を受付できません. "
            return response
        if request.ID == 1:
            

# 準備完了状況に応じてゲームを開始するか否かを判定するためのサービス通信関数
# 両方準備完了していればfieldにプレイヤーの初期HPとスピードを反映しfightingSrvCbを受付できるようにする
# 準備完了していなければその旨のメッセージを返す.
    def startSrvCb(self, request, response):
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
        self.get_logger().info("クライアントからプレイヤーネームのリクエストを受け取りました. ")

        if self.P1.Pname != "" and self.P2.Pname != "":
            response.reID = request.ID
            response.res = "すでに2人のプレイヤーが登録されています. "
            return response

        reqName = request.name
        if self.P1.Pname != "":
            if reqName == self.P2.Pname:
                response.reID = request.ID
                response.res = "そのプレイヤーネームはすでに使用されています. もう一度お試しください. "
                return response

            else:
                self.P2.Pname = reqName
                response.reID = 1
                response.res = "あなたは2番目のプレイヤーとして登録されました. "
                return response

        else:
            self.P1.Pname = reqName
            response.reID = 0
            response.res = "あなたは1番目のプレイヤーとして登録されました. "
            return response


def main(args=None):
    try:
        rclpy.init(args=args)
        FighterServer = FighterServer()
        rclpy.spin(FighterServer)
    except KeyboardInterrupt:
        FighterServer.destroy_node()

