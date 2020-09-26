#!/bin/sh

export ROBOT_INITIAL_POSE="-x 8.443678 -y -2.591308 -Y -3.114166"

xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 5


xterm -e "roslaunch turtlebot_gazebo amcl_demo.launch" &
sleep 5

xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5


xterm -e "rosrun add_markersold add_markersold"
sleep 5

