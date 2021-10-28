#De kommandoer Kasper indtastede for at starte robotten i onsdags

source /opt/ros/kinetic/setup.bash
roslaunch turtlebot_bringup minimal.launch

#source catkin_ws/devel/setup.bash
source /opt/ros/kinetic/setup.bash
source catkin_ws/devel/setup.bash
rosrun turtlemovement turtlemovement_node
