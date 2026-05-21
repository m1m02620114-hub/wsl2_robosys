import rclpy
from rclpy.node import Node
import class001

from rsysmsg.srv import NameSrv
from rsysmsg.msg import Num
from rsysmsg.srv import Fight

class FighterClient(Node):

    def __init__(self):
        super().__init__('fighter_client')

    def monsterSelect(self):
        


def main(args=None):
    try:
        rclpy.init(args=args)
        FighterClient = FighterClient()
        rclpy.spin(FighterClient)
    except KeyboardInterrupt:
        FighterClient.destroy_node()