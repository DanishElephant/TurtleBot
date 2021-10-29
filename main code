#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
#include <time.h>


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "turtlemover");
  ros::NodeHandle n;

 
  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1000);

  ros::Rate loop_rate(10);

  geometry_msgs::Twist msg;
  
  //Drej 8 grader
  msg.angular.z = 1.9;
  msg.linear.x = 0;
  for (size_t i = 0; i < 2; i++)
  {
    chatter_pub.publish(msg);
      loop_rate.sleep();
  }
  
  //Kør 153cm
  msg.angular.z = 0;
  msg.linear.x = 0.7;
  for (size_t i = 0; i < 24; i++)
  {
    chatter_pub.publish(msg);
      loop_rate.sleep();
  }
  
  //Drej 14 grader til venstre
  msg.angular.z = -1.9;
  msg.linear.x = 0;
  for (size_t i = 0; i < 4; i++)
  {
    chatter_pub.publish(msg);
      loop_rate.sleep();
  }
  
  //Kør 261cm
  msg.angular.z = 0;
  msg.linear.x = 0.7;
  for (size_t i = 0; i < 30; i++)
  {
    chatter_pub.publish(msg);
      loop_rate.sleep();
  }
  
//Drej 19 grader til højre
  msg.angular.z = 1.9;
  msg.linear.x = 0;
  for (size_t i = 0; i < 6; i++)
  {
    chatter_pub.publish(msg);
      loop_rate.sleep();
  }
  
//Kør i mål - slutspurten
  msg.angular.z = 0;
  msg.linear.x = 0.7;
  for (size_t i = 0; i < 30; i++)
  {
    chatter_pub.publish(msg);
      loop_rate.sleep();
  }

  while (ros::ok())
  {
    geometry_msgs::Twist msg;

  
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
 
  }

  return 0;
}
