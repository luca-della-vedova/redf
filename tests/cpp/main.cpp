#include <test_api.hpp>
#include <rclcpp/rclcpp.hpp>

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  auto test_node = rclcpp::Node::make_shared("test_node");

  using test_namespace::test_api::SimpleQoS;
  auto pub = test_node->create_publisher<SimpleQoS::MessageType>(SimpleQoS::topic_name(), SimpleQoS::qos());
  SimpleQoS::MessageType msg;
  msg.data = "hello";
  pub->publish(msg);

  return 0;
}