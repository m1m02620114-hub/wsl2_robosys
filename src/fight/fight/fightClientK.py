import sys
import threading
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer

# from std_msgs.msg import String
from rsysmsg.srv import Name
# from rsysmsg.srv import Ready
# from rsysmsg.srv import Fight
from rsysmsg.msg import Num
from rsysmsg.action import Monster

tilde = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

class FighterClient(Node):

    def __init__(self):
        super().__init__('fighter_client')
        self.ID = 2
        self.Pname = ""
        self.Pmonsters = []

        self.monsters = ["A", "B", "C", "D", "E"]
        self.Mreqs = [-1, 1, 2, 3, 4, 5]
        self.Breqs = [1, 2, 3, 4]
        self.Areqs = [1, 2, 3]
        self.req = 0
        
        self.startFlg = 0
        # self.request = 0

        self.nameCli = self.create_client(Name, 'name_srv')
        self.readyCli = self.create_client(Name, 'ready_srv')
        self.fightCli = self.create_client(Name, 'ready_srv')

        self.monsterPublish = self.create_publisher(Num, 'monster_select', 10)
        self.monsterSelectComplete = self.create_subscription(Num, 'monsterSelectComplete', self.monsterSelectCompleteCb, 10)

        self.monsterActionSv0 = ActionServer(self, Monster, 'monster_action_0', self.monsterServerCallback)
        self.monsterActionSv1 = ActionServer(self, Monster, 'monster_action_1', self.monsterServerCallback)



        # self.nameClient()
        print('ゲームクライアントが起動しました. ファイトゲームへようこそ. ')
        self.chooseReq()

    def chooseReq(self):
        if self.startFlg != 1:#対戦が始まっているかを判定
            print('----------------------------------------------------------------------------------')
            self.get_logger().info('現在，ゲーム開始前の準備フェーズです. ')
            self.get_logger().info('サーバへのリクエスト内容を選んでください. ')
            print('プレイヤーネーム： %s ' % self.Pname)
            print('----------------------------------------------------------------------------------')
            print('コマンド一覧  1:名前登録, 2:モンスター選択, 3:準備完了, 4:ゲームスタート')
            print('----------------------------------------------------------------------------------')
            self.req = int(input())
            if not self.req in self.Breqs: #準備フェーズ範囲外入力エラー判定
                self.get_logger().info('入力エラー, そのリクエストはリストに含まれていません. ') 
                self.chooseReq()          
            elif self.req == 1:
                if self.ID != 2:
                    self.get_logger().info('名前の登録は完了しています. ')
                    readID = self.ID + 1
                    self.get_logger().info('あなたはプレイヤー %d です. '% readID)
                    self.chooseReq()
                self.nameClient()#名前登録関数呼び出し
            elif self.req == 2:
                if self.ID == 0 or self.ID == 1:
                    self.monsterServerTopic()

        else:
            print('----------------------------------------------------------------------------------')
            self.get_logger().info('現在，ゲーム開始後の戦闘フェーズです. ')
            self.get_logger().info('サーバへのリクエスト内容を選んでください. ')
            print('----------------------------------------------------------------------------------')
            print('コマンド一覧  1:攻撃, 2:防御, 3:溜める')
            print('----------------------------------------------------------------------------------')
            self.req = int(input())
            if not self.req in self.Areqs:#戦闘フェーズ範囲外入力エラー判定
                self.get_logger().info('入力エラー, そのリクエストはリストに含まれていません. ') 
                self.chooseReq()          
            

#名前登録サービスクライアント
    def nameClient(self):
        self.get_logger().info('登録したい名前を入力してください. ')
        name = input()

        while not self.nameCli.wait_for_service(timeout_sec=5.0):
            self.get_logger().info('name_srv サーバの応答を待っています...')

        request = Name.Request()
        request.name = name
        self.Pname = name
        request.id = self.ID

        self.future = self.nameCli.call_async(request)
        self.future.add_done_callback(self.nameRes_callback)

    def nameRes_callback(self, future):
        print(tilde)
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
            self.get_logger().info('あなたのプレイヤーネームは %s です. '% self.Pname)
            print(tilde)
        elif res.res == "2":
            self.ID = 1
            self.get_logger().info('あなたはプレイヤー2として登録されました. ')
            self.get_logger().info('あなたのプレイヤーネームは %s です. '% self.Pname)
            print(tilde)
        self.chooseReq()
#名前登録サービスクライアント


#モンスター登録パブリッシャー＆アクションサーバ
    def monsterServerTopic(self):
        self.get_logger().info('モンスター登録のリクエストを承認しました. ')
        msg = Num()
        msg.num = self.ID
        self.monsterPublish.publish(msg)

    def monsterServerCallback(self, goal_handle):
        self.get_logger().info('サーバからモンスター選択のリクエストを受け取りました. ')
        feedback_msg = Monster.Feedback()
        # feedback_msg.midf = 0

        while True:
            self.get_logger().info('モンスターを番号で選択してください. ')
            orderM = input()
            try:
                orderM = int(orderM)
            except ValueError:
                orderM = -2
            lenM = len(self.Pmonsters) - 1
            
            if orderM == 0 and lenM == 2:
                break
            elif orderM != -1 and lenM == 2:
                self.get_logger().info('あなたはすでに3体のモンスターを選択しています. ')
                self.get_logger().info('取り消すか終了の操作をしてください. ')
                print(self.Pmonsters)
                continue
            elif orderM == 0:
                self.get_logger().info('モンスターを合計3体登録してください. ')
                lenLog = len(self.Pmonsters)
                self.get_logger().info('あなたは現在 %d 体のモンスターを選択済みです. ' % lenLog)
                print(self.Pmonsters)
                continue
            if not orderM in self.Mreqs:
                self.get_logger().info('範囲外の数字が入力されました. ')
                print(self.Pmonsters)
                continue
            elif orderM == -1 and lenM != -1:
                feedback_msg.feedback = -1
                goal_handle.publish_feedback(feedback_msg)
                print(self.Pmonsters)
                self.Pmonsters.pop()
            elif orderM == -1 and lenM == -1:
                self.get_logger().info('あなたはまだモンスターを選択していないため取り消し操作ができません. ')
                print(self.Pmonsters)
                continue
            else:
                feedback_msg.feedback = orderM - 1
                goal_handle.publish_feedback(feedback_msg)
                self.Pmonsters.append(orderM)

                print(self.Pmonsters)

        goal_handle.succeed()
        self.get_logger().info('モンスターの選択を完了しました. ')

        result = Monster.Result()
        result.result = 0
        # self.chooseReq()#どうすればいい？トピック通信で解決
        
        return result

    def monsterSelectCompleteCb(self, msg):
        if msg.num == self.ID:
            self.get_logger().info('終了シグナルがサーバで正常に処理されました. ')
            self.chooseReq()
        else:
            pass
        
#モンスター登録パブリッシャー＆アクションサーバ


#準備完了サービスクライアント
    def readyClient(self):
        self.get_logger().info('準備完了のコマンドを受け取りました. ')
        if self.Pname == '' or self.Pmonsters == []:
            if self.Pname == '':
                self.get_logger().info('あなたは名前を登録していません. ')
                self.chooseReq()
            else:
                self.get_logger().info('あなたはモンスターを登録していません. ')
                self.chooseReq()
        request = Name.Request()
        
        request.id = self.ID
        self.future = self.ready.call_async(request)
        self.future.add_done_callback(self.readyRes_callback)
    
    def readyRes_callback(self, future):
        self.get_logger().info('サーバに準備完了リクエストが承認されました. ')
        self.chooseReq()
#準備完了サービスクライアント
        
        


def main(args=None):
    try:
        rclpy.init(args=args)
        FC = FighterClient()
        rclpy.spin(FC)
    except KeyboardInterrupt:
        FC.destroy_node()