import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class SubNode(Node):
    def __init__(self):
        super().__init__('sub_node')
        self.subscription = self.create_subscription(
            String,
            'counter_info',
            self.listener_callback,
            10
        )
        self.reset_count = 0

    def listener_callback(self, msg):
        data = msg.data

        try:
            parts = data.split(',')
            count = int(parts[0].split('=')[1])
            time_str = parts[1].split('=')[1]

            self.get_logger().info(f'接收: 时间={time_str}, 计数器={count}')

            if count == 0:
                self.reset_count += 1
                self.get_logger().info(f'嘿！我已经被清零 {self.reset_count} 次了！')

        except Exception as e:
            self.get_logger().error(f'解析消息失败: {e}')


def main(args=None):
    rclpy.init(args=args)
    node = SubNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()