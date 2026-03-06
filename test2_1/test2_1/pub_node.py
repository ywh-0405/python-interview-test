import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class PubNode(Node):
    def __init__(self):
        super().__init__('pub_node')
        self.publisher_ = self.create_publisher(String, 'counter_info', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.counter = 0

    def timer_callback(self):
        msg = String()
        now = self.get_clock().now().to_msg()
        time_str = f"{now.sec}.{now.nanosec}"
        msg.data = f"count={self.counter},time={time_str}"

        self.publisher_.publish(msg)
        self.get_logger().info(f'发布: {msg.data}')

        self.counter += 1
        if self.counter > 100:
            self.counter = 0


def main(args=None):
    rclpy.init(args=args)
    node = PubNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()