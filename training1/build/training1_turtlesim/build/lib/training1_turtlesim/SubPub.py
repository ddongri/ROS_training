import rclpy
from rclpy.node import Node
from turtle_msg.msg import Custom
from geometry_msgs.msg import Twist, Vector3
from std_msgs.msg import Float32


class SubPub(Node):

    def __init__(self):
        super().__init__('sub_pub')

        self.radius = 1.5
        self.velocity = 0.0
        self.direction = 1
        self.linear = None
        self.angular = None
        self.twist = None

        self.sub = self.create_subscription(Custom, 'info', self.subscribe, 10)
        self.pub = self.create_publisher(Twist, '/turtle1/cmd_vel', 10) 

        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.publish)

    def subscribe(self, msg):
        self.radius = msg.radius
        self.velocity = msg.velocity
        self.direction = msg.direction

    def publish(self):
        self.cmd = Twist()
        self.linear = Vector3()
        self.angular = Vector3()

        self.linear.x = self.velocity
        self.linear.y = 0.0
        self.linear.z = 0.0
        self.angular.x = 0.0
        self.angular.y = 0.0
        self.angular.z = self.direction * (self.velocity / self.radius)

        self.cmd.linear = self.linear
        self.cmd.angular = self.angular

        self.pub.publish(self.cmd)

def main(args=None):
    rclpy.init(args=args)

    node = SubPub()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

