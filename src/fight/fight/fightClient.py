import sys
import threading
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer

from rsysmsg.srv import Name
from rsysmsg.msg import Num
from rsysmsg.action import Monster

#NameSrv

class GameClient(Node):

    def __init__(self):
        super().__init__('game_client')
        self.player_id = 2

        # 1. サーバーの player_name 登録用クライアント
        self.client = self.create_client(Name, 'name_srv')
        # while not self.client.wait_for_service(timeout_sec=1.0):
        #     self.get_logger().info('name_srv サーバーの起動を待っています...')

        # 2. モンスター選択を始める合図を出すパブリッシャ
        # self.select_start_pub = self.create_publisher(Num, 'monster_select')

        # 3. サーバーからのアクション（指示）を待ち受ける窓口
        self.monster_action_server_0 = ActionServer(
            self, Monster, 'monster_action_0', self.execute_monster_action_callback)
        self.monster_action_server_1 = ActionServer(
            self, Monster, 'monster_action_1', self.execute_monster_action_callback)

        # 起動と同時に名前入力を開始
        self.ask_and_send_name()

    def ask_and_send_name(self):
        print("\n========================================")
        user_name = input("プレイヤー名を入力してください: ")
        print("========================================")


        while not self.client.wait_for_service(timeout_sec=5.0):
            self.get_logger().info('name_srv サーバーの起動を待っています...')
        request = Name.Request()
        request.name = user_name
        request.id =self.player_id
        self.future = self.client.call_async(request)
        self.future.add_done_callback(self.response_callback)

    def response_callback(self, future):
        print("aaaaaaa")
        try:
            response = future.result()
            
            if "すでに2人の" in response.res:
                print(response.res)
                print("プログラムを終了します。")
                sys.exit()
                
            elif "すでに使用されています" in response.res:
                print(response.res) 
                self.ask_and_send_name()
                
            elif "1番目のプレイヤー" in response.res:
                print(response.res)
                print("対戦相手が参加するのを待っています...")
                
                self.player_id = response.reid  # サーバーから割り振られたIDを記憶
                msg = Num()
                msg.id = 0  
                self.select_start_pub.publish(msg)
                print("⇒ サーバへモンスター選択開始トピックを送信しました。")
                
            elif "2番目のプレイヤー" in response.res:
                print(response.res)
                print("プレイヤーが揃いました。")
                
                self.player_id = response.reid  # サーバーから割り振られたIDを記憶
                msg = Num()
                msg.ID = 1  
                self.select_start_pub.publish(msg)
                print("⇒ サーバへモンスター選択開始トピックを送信しました。")
                
            else:
                print(f"想定外のメッセージを受信しました: {response.res}")

        except Exception as e:
            print(f"エラーが発生しました: {e}")

    def execute_monster_action_callback(self, goal_handle):
        print(f"\n[サーバからの指示]: {goal_handle.request.order}")
        
        # input()によるROS 2のフリーズを防ぐため、入力処理を別スレッドで立ち上げる
        threading.Thread(target=self.monster_selection_thread, args=(goal_handle,)).start()
        
        # アクション自体はすぐに承認して処理をスレッドに引き継ぐ
        #goal_handle.succeed()
        return Monster.Result()

    def monster_selection_thread(self, goal_handle):
        my_monsters = ["", "", ""]
        current_slot = 0

        print("\n========================================")
        print("         モンスター選択モード開始          ")
        print("  ※『back』と入力すると、1つ前に戻れます  ")
        print("========================================")

        while current_slot < 3:
            print(f"\n現在のパーティ: {my_monsters}")
            user_input = input(f"【{current_slot + 1}匹目】のモンスター名を入力してください: ").strip()

            if user_input.lower() == 'back':
                if current_slot == 0:
                    print(" まだ1匹も登録していないため、これ以上戻れません！")
                    continue
                
                current_slot -= 1
                cancelled_monster = my_monsters[current_slot]
                my_monsters[current_slot] = ""
                print(f"↩ 【{current_slot + 1}匹目】の {cancelled_monster} を取り消しました。")

                # サーバーの feedback_callback の仕様 [num-1] に合わせて送信
                feedback_msg = Monster.Feedback()
                feedback_msg.monster = 'back'
                feedback_msg.fbnum = current_slot + 1 
                goal_handle.publish_feedback(feedback_msg)
                continue

            if not user_input:
                print(" モンスター名を入力してください。")
                continue

            # モンスターをセット
            my_monsters[current_slot] = user_input
            print(f"▲ {user_input} を【{current_slot + 1}匹目】にセットしました。")

            # サーバーの feedback_callback の仕様 [num] にそのまま文字列を代入
            feedback_msg = Monster.Feedback()
            feedback_msg.monster = user_input
            feedback_msg.fbnum = current_slot
            goal_handle.publish_feedback(feedback_msg)

            current_slot += 1

        print(f"\n パーティが完成しました！: {my_monsters}")

        goal_handle.succeed()
        
        # 選び終わったら、自動で「準備完了」リクエストへ進む
        if self.player_id is not None:
            self.send_ready_request(self.player_id)

    def send_ready_request(self, player_id):
        self.ready_client = self.create_client(Name, 'ready_srv')
        
        while not self.ready_client.wait_for_service(timeout_sec=1.0):
            print("ready_srv の起動を待っています...")

        request = Name.Request()
        # サーバー側の readySrvCb(request.ID) に合わせて自分のIDを入れる
        request.ID = player_id 

        print("⇒ サーバへ準備完了のリクエストを送信中...")
        self.ready_future = self.ready_client.call_async(request)
        self.ready_future.add_done_callback(self.ready_response_callback)

    def ready_response_callback(self, future):
        response = future.result()
        print(f"\n[サーバからの回答]: {response.res}")
        
        if "両方のプレイヤーが準備完了" in response.res:
            print("両者の準備が整いました！いつでもゲームを開始できます。")


def main(args=None):
    rclpy.init(args=args)
    node = GameClient()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()