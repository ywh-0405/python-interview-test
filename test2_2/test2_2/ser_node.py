import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts


class ServerNode(Node):
    def __init__(self):
        super().__init__('server_node')
        self.srv = self.create_service(AddTwoInts, 'calc_service', self.callback)

    def callback(self, request, response):
        a = request.a
        b = request.b

        result = a + b

        self.get_logger().info(f'收到请求: {a} + {b}')
        response.sum = result

        return response


def main(args=None):
    rclpy.init(args=args)
    node = ServerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()