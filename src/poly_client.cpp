#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "client_cpp");
  if (argc != 2)
  {
    ROS_INFO("usage: add_two_ints_client x");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<study_pkg::Poly>("poly");
  study_pkg::Poly srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}