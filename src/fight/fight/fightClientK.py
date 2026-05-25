import rclpy
from rclpy.node import Node

from rsysmsg.srv import Name
from rsysmsg.msg import Num

class FighterClient(Node):

    def __init__(self):
        super().__init__('fighter_client')
        self.ID = 2
        self.reqs = [1]
        self.req = 0
        self.nameCli = self.create_client(Name, 'name_srv')
        self.chooseReq()

    def chooseReq(self):
        while True:
            self.get_logger().info('サーバへのリクエスト内容を選んでください. ')
            self.get_logger().info('1:名前登録, ')
            self.req = int(input())
            if not self.req in self.reqs:
                self.get_logger().info('入力エラー, そのリクエストはリストに含まれていません. ')
                continue
            if self.req == 1:
                self.nameClient()

    def nameClient(self):
        self.get_logger().info('登録したい名前を入力してください. ')
        name = input()

        while not self.nameCli.wait_for_service(timeout_sec=5.0):
            self.get_logger().info('name_srv サーバの応答を待っています...')

        request = Name.Request()
        request.name = name
        request.id =self.ID

        self.future = self.nameCli.call_async(request)
        self.get_logger().info('debugPoint1')
        
        self.future.add_done_callback(self.nameResCb)
        self.get_logger().info('debugPoint2')

    def nameResCb(self, future):
        self.get_logger().info('サーバからの結果を表示します. ')
        res = future.result()
        if "E" in res.res:
            self.get_logger().info('名前を登録できませんでした. ')
            if "name" in res.res:
                self.get_logger().info('エラー内容:その名前はすでに使用されています. ')
            else:
                self.get_logger().info('エラー内容:サーバにはすでに2人のプレイヤーが登録されています. ')
        elif res.res == "1":
            self.ID = 0
            self.get_logger().info('あなたはプレイヤー1として登録されました. ')
        elif res.res == "2":
            self.ID = 1
            self.get_logger().info('あなたはプレイヤー2として登録されました. ')




def main(args=None):
    try:
        rclpy.init(args=args)
        FC = FighterClient()
        rclpy.spin(FC)
    except KeyboardInterrupt:
        FC.destroy_node()