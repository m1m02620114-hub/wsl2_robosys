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
        self.pre_monster = [0, 0, 0]
        self.action_client_monster_0 = ActionClient(self, Monster, 'monster_action_0')
        self.action_client_monster_1 = ActionClient(self, Monster, 'monster_action_1')

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
            self.pre_monster[num-1] = 0
        else:
            self.pre_monster[num] = monster

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

    def fightingSrvCb(self, request, response):
        self.get_logger().info("プレイヤー %s から指示を受け取りました. ", request.ID)
        if self.startflg != 1:
            response.reID = request.ID
            response.res = "ゲームが開始していないため, 指示を受付できません. "
            return response
        if request.ID == 1:
            
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

