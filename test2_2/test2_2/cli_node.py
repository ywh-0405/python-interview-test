import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts


class ClientNode(Node):
    def __init__(self):
        super().__init__('client_node')
        self.cli = self.create_client(AddTwoInts, 'calc_service')

        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('等待服务...')

        self.req = AddTwoInts.Request()

    def send_request(self, a, b):
        self.req.a = a
        self.req.b = b
        return self.cli.call_async(self.req)


def main(args=None):
    rclpy.init(args=args)

    node = ClientNode()

    future = node.send_request(2, 3)

    rclpy.spin_until_future_complete(node, future)

    if future.result() is not None:
        node.get_logger().info(
            f'结果: {future.result().sum}'
        )

    node.destroy_node()
    rclpy.shutdown()