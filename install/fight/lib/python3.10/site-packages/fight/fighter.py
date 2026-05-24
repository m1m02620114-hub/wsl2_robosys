import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from rsysmsg.srv import Name

class nameCl(Node):

    def __init__(self):
        super().__init__('name_pub')
        self.pubname = self.create_publisher(String, 'name', 10)
        timer_period = 0.1
        self.timer = self.create_timer(timer_period, self.name_cb)

    def name_cb(self):
        msg = String()
        print("xxxxx")
        msg.data = input()
        self.pubname.publish(msg)

# class 



def main(args=None):
    try:
        rclpy.init(args=args)
        node = nameCl()
        rclpy.spin_once(node)
    except KeyboardInterrupt:
        node.destroy_node()

if __name__ == '__main__':
    main()