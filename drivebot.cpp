#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include <sstream>

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "turtlemover");
  ros::NodeHandle n;

 
  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1000);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
   
    geometry_msgs::Twist msg;

    msg.angular.z = 0.3;
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
 
  }


  return 0;
}
