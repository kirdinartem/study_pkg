#include <ros/ros.h>
#include <std_msgs/String.h>

void topicCallback(const std_msgs::String& msg)
{
  ROS_INFO("I heard: [%s]", msg.data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("cpp_chatter", 1000, topicCallback);

  ros::spin();

  return 0;
}