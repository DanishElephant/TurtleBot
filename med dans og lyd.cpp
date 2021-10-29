#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
#include <time.h>
#include "kobuki_msgs/Sound.h"


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "turtlemover");
  ros::NodeHandle n;
  
  sound_play::SoundClient sc;
  
  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1000);
  ros::Publisher singer_pub = n.advertise<kobuki_msgs::Sound>("/mobile_base/commands/sound", 1000);

  ros::Rate loop_rate(10);

  geometry_msgs::Twist msg;
  kobuki_msgs::Sound smsg;
  
  //Drej 8 grader
  msg.angular.z = -1.9;
  msg.linear.x = 0;
  for (size_t i = 0; i < 5; i++)
  {
    chatter_pub.publish(msg);
      loop_rate.sleep();
  }
  
  //Kør 153cm
  msg.angular.z = 0;
  msg.linear.x = 0.7;
  for (size_t i = 0; i < 30; i++)
  {
    chatter_pub.publish(msg);
      loop_rate.sleep();
  }
  
  //Drej 14 grader til venstre
  msg.angular.z = 1.9;
  msg.linear.x = 0;
  for (size_t i = 0; i < 1; i++)
  {
    chatter_pub.publish(msg);
      loop_rate.sleep();
  }
  
  //Kør 261cm
  msg.angular.z = 0;
  msg.linear.x = 0.7;
  for (size_t i = 0; i < 34; i++)
  {
    chatter_pub.publish(msg);
      loop_rate.sleep();
  }
  
//Drej 19 grader til højre
  msg.angular.z = -1.9;
  msg.linear.x = 0;
  for (size_t i = 0; i < 8; i++)
  {
    chatter_pub.publish(msg);
      loop_rate.sleep();
  }
  
//Kør i mål - slutspurten
  msg.angular.z = 0.2;
  msg.linear.x = 0.7;
  for (size_t i = 0; i < 66; i++)
  {
    chatter_pub.publish(msg);
      loop_rate.sleep();
  }

  //Sejrsdans
  smsg.value = 6;
  msg.angular.z = 2;
  msg.linear.x = 0;
  singer_pub.publish(smsg);
  //smsg.sc.playWaveFromPkg("sound_play", "sounds/MARIO.ogg");
  for (size_t i = 0; i < 30; i++)
  {
    if (i%2==0) {
      msg.angular.z = 2;
    }
    if (i%2==1) {
      msg.angular.z = -2;
    }
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
