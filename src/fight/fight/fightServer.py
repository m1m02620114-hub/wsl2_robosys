import rclpy
from rclpy.node import Node

from std_msgs.msg import String

name1 = ''

class NameSv(Node):

    def __init__(self):
        super().__init__('name_sub')
        self.subscription = self.create_subscription(
            String,
            'name',
            self.name_cb,
            10
        )
        self.subscription

    def name_cb(self, msg):
        global name1
        print('xxxxxxx')
        self.get_logger().info('I heard: "%s"' % msg.data)
        name1 = msg.data


def main(args=None):
    try:
        rclpy.init(args=args)
        names = []
        node = NameSv()
        rclpy.spin_once(node)
        names.append(name1)
        print('OK')
        name2 = rclpy.spin_once(node)
        names.append(name2)
        print(names)
    except KeyboardInterrupt:
        node.destroy_node()

if __name__ == '__main__':
    main()