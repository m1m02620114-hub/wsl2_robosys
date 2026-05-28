import sys
import threading
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer

# from std_msgs.msg import String
from rsysmsg.srv import Name
# from rsysmsg.srv import Ready
from rsysmsg.srv import Fight
from rsysmsg.msg import Num
from rsysmsg.msg import Fighting
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
        self.NoM = ["First", "Second", "Third"]
        self.OoP = ["ATK", "DEF", "CHG"]
        
        self.readyFlg = 0
        self.startFlg = 0
        # self.request = 0

        self.nameCli = self.create_client(Name, 'name_srv')
        self.readyCli = self.create_client(Name, 'ready_srv')
        self.startCli = self.create_client(Name, 'start_srv')
        self.fightingCli = self.create_client(Fight, 'fighting_srv')

        self.req_status = [0, 0, 0] #atk, def, charge

        self.subscription_fighting = self.create_subscription(Fighting, 'fighting', self.fightingSub_callback, 10)

        self.monsterPublish = self.create_publisher(Num, 'monster_select', 10)
        self.turnPublish = self.create_publisher(Num, 'turn', 10)
        self.monsterSelectComplete = self.create_subscription(Num, 'monsterSelectComplete', self.monsterSelectCompleteCb, 10)

        # self.monsterActionSv0 = ActionServer(self, Monster, 'monster_action_0', self.monsterServerCallback)
        # self.monsterActionSv1 = ActionServer(self, Monster, 'monster_action_1', self.monsterServerCallback)



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
            self.req = input()
            try:
                self.req = int(self.req)
            except ValueError:
                self.req = -2
            if not self.req in self.Breqs: #準備フェーズ範囲外入力エラー判定
                self.get_logger().info('入力エラー, そのリクエストはリストに含まれていません. ') 
                self.chooseReq()          
            elif self.req == 1:
                if self.ID != 2:
                    self.get_logger().info('名前の登録は完了しています. ')
                    readID = self.ID + 1
                    self.get_logger().info('あなたはプレイヤー %d です. '% readID)
                    self.chooseReq()
                    return
                else:
                    self.nameClient()#名前登録関数呼び出し
            elif self.req == 2:
                if self.ID == 0 or self.ID == 1:
                    if self.Pmonsters != []:
                        self.get_logger().info('あなたはすでにモンスターを登録しています. 操作を続行しますか？ y/n')
                        remonster = ''
                        while remonster != 'y' or remonster != 'n':
                            remonster = input()
                            if remonster == 'y':
                                break
                            elif remonster == 'n':
                                self.get_logger().info('中止します. ')
                                self.chooseReq()
                                return
                            else:
                                self.get_logger().info('想定外の入力が行われました. ')
                    self.Pmonsters = []
                    self.monsterServerTopic()
                else:
                    self.get_logger().info('あなたは名前を登録していません. ')
                    self.chooseReq()
                    return
            elif self.req == 3:
                if self.readyFlg == 1:
                    self.get_logger().info('あなたはすでに準備完了しています. ')
                    self.chooseReq()
                    return
                self.readyClient()
            elif self.req == 4:
                if self.startFlg == 1:
                    self.chooseReq()
                    return
                self.startClient()

        else:
            print('----------------------------------------------------------------------------------')
            self.get_logger().info('現在，ゲーム開始後の戦闘フェーズです. ')
            self.get_logger().info('サーバへのリクエスト内容を選んでください. ')
            print('プレイヤーネーム： %s ' % self.Pname)
            print('----------------------------------------------------------------------------------')
            print('コマンド一覧  1:攻撃, 2:防御, 3:溜める')
            print('----------------------------------------------------------------------------------')
            self.req = input()
            try:
                self.req = int(self.req)
            except ValueError:
                self.req = -2
            if not self.req in self.Areqs:#戦闘フェーズ範囲外入力エラー判定
                self.get_logger().info('入力エラー, そのリクエストはリストに含まれていません. ') 
                self.chooseReq()
                return
            else:
                self.fightingClient()
                
    def fightingClient(self):
        self.get_logger().info('戦闘指示クライアントが起動しました. ')
        
        if self.req == 1:
            self.req_status[0] = 1
        elif self.req == 2:
            self.req_status[1] = 1
        elif self.req == 3:
            self.req_status[2] = 1

        print(self.req)
        print(self.req_status)

        while not self.readyCli.wait_for_service(timeout_sec=5.0):
            self.get_logger().info('ready_srv サーバの応答を待っています...')
        request = Fight.Request()
        request.status = self.req_status
        request.id = self.ID

        self.future = self.fightingCli.call_async(request)
        self.future.add_done_callback(self.fightingRes_callback)

    def fightingRes_callback(self, future):
        print(tilde)
        self.get_logger().info('サーバからの結果を表示します. ')
        
        res = future.result()
        if res.res == "C":
            self.get_logger().info('攻撃指示がサーバで処理されました. 相手の行動選択をお待ちください. ')
        elif res.res == "CC":
            self.get_logger().info('両プレイヤーの攻撃指示がサーバで処理されました. ')
            self.get_logger().info('ターン処理の指示をサーバに送信します... ')
            
            msg = Num()
            msg.num = self.ID
            self.turnPublish.publish(msg)
        else:
            self.get_logger().info('想定外のメッセージ')
        self.req_status = [0, 0, 0]



#ターン終了の合図を受け取るためのコールバック関数
    def fightingSub_callback(self, msg):
        self.get_logger().info('ターンが終了しました！ 結果を表示します. ')

        P1_s = msg.pone
        P2_s = msg.ptwo

        print(P1_s)
        print(P2_s)

        if P1_s[0] == 3 or P2_s[0] == 3:
            if P1_s[0] == 3:
                self.get_logger().info('プレイヤー 2 が勝利しました！')
                if self.ID == 1:
                    self.get_logger().info('あなたの勝利です！')
                else:
                    self.get_logger().info('あなたは敗北しました...')
            elif P2_s[0] == 3:
                self.get_logger().info('プレイヤー 1 が勝利しました！')
                if self.ID == 0:
                    self.get_logger().info('あなたの勝利です！')
                else:
                    self.get_logger().info('あなたは敗北しました...')
            self.get_logger().info('ctrl+cで終了してください.')
            return

        # msg.pone = [0(First), 1(Second), 2(Third), pre_hp, now_hp, "0(ATK) or 1(DEF) or 2(CRG)]
        print(f"monster:{self.NoM[P1_s[0]]}, pre_HP:{P1_s[1]}, now_HP:{P1_s[2]}, order:{self.OoP[P1_s[3]]}")
        print(f"monster:{self.NoM[P2_s[0]]}, pre_HP:{P2_s[1]}, now_HP:{P2_s[2]}, order:{self.OoP[P2_s[3]]}")

        self.chooseReq()
        return
#ターン終了の合図を受け取るためのコールバック関数


#準備完了サービスクライアント
    def readyClient(self):
        if self.Pname == "" or self.Pmonsters == []:
            if self.Pname == "":
                self.get_logger().info('名前が登録されていません. ')
                self.chooseReq()
                return
            else:
                self.get_logger().info('モンスターを選んでいません. ')
                self.chooseReq()
                return
        while not self.readyCli.wait_for_service(timeout_sec=5.0):
            self.get_logger().info('ready_srv サーバの応答を待っています...')
        request = Name.Request()
        request.id = self.ID

        self.future = self.readyCli.call_async(request)
        self.future.add_done_callback(self.readyRes_callback)

    def readyRes_callback(self, future):
        print(tilde)
        self.get_logger().info('サーバからの結果を表示します. ')
        res = future.result()
        if res.res == "NP": #Not Player
            self.get_logger().info('このクライアントはプレイヤーとして登録されていません. ')
        elif res.res == "NMS": #Nothing Monster Select
            self.get_logger().info('あなたはモンスターを選択していないため準備完了できません. ')
        elif res.res == "WAP": #wait the Another Player
            self.readyFlg = 1
            self.get_logger().info('もう1人のプレイヤーの準備完了を待っています...')
        elif res.res == "SA": #Start Available
            self.readyFlg = 1
            self.get_logger().info('両方のプレイヤーが準備完了しました. startでゲームを開始できます. ')
        else:
            self.get_logger().info('想定外のメッセージ')

        self.chooseReq()
#準備完了サービスクライアント

#ゲームスタートサービスクライアント
    def startClient(self):
        if self.readyFlg == 0:
            self.get_logger().info('あなたは準備完了していません. ')
            self.chooseReq()
            return
        while not self.readyCli.wait_for_service(timeout_sec=5.0):
            self.get_logger().info('start_srv サーバの応答を待っています...')
        request = Name.Request()
        request.id = self.ID

        self.future = self.startCli.call_async(request)
        self.future.add_done_callback(self.startRes_callback)

    def startRes_callback(self, future):
        print(tilde)
        self.get_logger().info('サーバからの結果を表示します. ')
        res = future.result()
        if res.res == "E":
            self.get_logger().info('相手が準備完了していないため, ゲームを開始できません. 相手の準備が完了するまでお待ちください. ')
        elif res.res == "GS": #Game Start
            self.startFlg = 1
            self.get_logger().info('ゲームが開始されました！ ')
        elif res.res == "AGS":
            self.startFlg = 1
            self.get_logger().info('ゲームは相手によって開始されました！ ')
        else:
            self.get_logger().info(' %s '% res.res)
            self.get_logger().info('想定外のメッセージ')

        self.chooseReq()
#ゲームスタートサービスクライアント
            

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
            self.monsterActionSv0 = ActionServer(self, Monster, 'monster_action_0', self.monsterServerCallback)
            print(tilde)
        elif res.res == "2":
            self.ID = 1
            self.get_logger().info('あなたはプレイヤー2として登録されました. ')
            self.get_logger().info('あなたのプレイヤーネームは %s です. '% self.Pname)
            self.monsterActionSv1 = ActionServer(self, Monster, 'monster_action_1', self.monsterServerCallback)
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

        
        


def main(args=None):
    try:
        rclpy.init(args=args)
        FC = FighterClient()
        rclpy.spin(FC)
    except KeyboardInterrupt:
        FC.destroy_node()