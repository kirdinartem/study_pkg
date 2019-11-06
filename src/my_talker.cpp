#include <ros/ros.h>
#include <study_pkg/Control.h>

#include <sstream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "my_talker_cpp");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<study_pkg::Control>("cpp_chatter", 1000);
	ros::Rate loop_rate(1);

	int count = 0;
	while (ros::ok())
	{
		study_pkg::Control msg;
		msg.steer = 10;
		msg.speed = 20;

		ROS_INFO("steer = %d, speed = %d \n", msg.steer, msg.speed);

		pub.publish(msg);

		ros::spinOnce();
		
		loop_rate.sleep();
	}
	return 0;
}