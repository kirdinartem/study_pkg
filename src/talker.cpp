#include <ros/ros.h>
#include <std_msgs/String.h>

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cpp_talker");

  ros::NodeHandle n;

  ros::Publisher pub = n.advertise<std_msgs::String>("cpp_chatter", 1000);

  ros::Rate loop_rate(1);

  int count = 0;
  while ( ros::ok() )
  {
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count++;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}