#include "ros/ros.h"
#include "study_pkg/Poly.h"

bool poly_cb(study_pkg::Poly::Request &req,
			 study_pkg::Poly::Responce &res)
{
	res.y = req.x + req.x * req.x;
	ROS_INFO("request: x=%ld", (long int)req.x);
	ROS_INFO("sending back response: [%ld]", (long int)req.y);
	return true;
}

int main (int argc, char **argv)
{
	ros::init(argc, argv, "server_cpp");
	ros::NodeHandle n;

	ros:ServiceServer service = n.advertiseService("poly", poly_cb);
	ROS_INFO("Ready to get x");
	ros::spin();

	return 0;

}