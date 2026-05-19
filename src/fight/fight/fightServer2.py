import rclpy
from rclpy.node import Node
import class001

from rsysmsg.srv import NameSrv
from rsysmsg.msg import Num
from rsysmsg.srv import Fight


class FighterServer(Node):

    def __init__(self):
        super().__init__('name_srv_server')
        self.P1 = class001.Player("", 0, ["", "", ""], 0, 0, 0, 0)
        self.P2 = class001.Player("", 1, ["", "", ""], 0, 0, 0, 0)
        self.field = class001.Field([0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [0, 0])
        self.nameSrv = self.create_service(NameSrv, 'name_srv', self.nameSrvCb)
        self.readySrv = self.create_service(NameSrv, 'ready_srv', self.readySrvCb)
        self.startflg = 0
        self.ready = [0, 0]
        self.order = [0, 0]

    #モンスターを入れ替えるやつとか

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
        if request.ID == 0:
            response.reID = 0
            response.res = "このクライアントはプレイヤーとして登録されていません. "
            return response

        if request.ID == 1 and self.P1.monsters == ["", "", ""]:
            response.reID = request.ID
            response.res = "あなたはモンスターを選択していないため準備完了できません. "
            return response

        if request.ID == 2 and self.P2.monsters == ["", "", ""]:
            response.reID = request.ID
            response.res = "あなたはモンスターを選択していないため準備完了できません. "
            return response

        if request.ID == 1 or request.ID == 2:
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
            response.reID = 0
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
                response.reID = 2
                response.res = "あなたは2番目のプレイヤーとして登録されました. "
                return response

        else:
            self.P1.Pname = reqName
            response.reID = 1
            response.res = "あなたは1番目のプレイヤーとして登録されました. "
            return response


def main(args=None):
    try:
        rclpy.init(args=args)
        FighterServer = FighterServer()
        rclpy.spin(FighterServer)
    except KeyboardInterrupt:
        FighterServer.destroy_node()

