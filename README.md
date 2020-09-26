# Udacity-HomeService

<p> The project focusses on autonomous navigation of a turtlebot robot to pick up an object in the environment and to drop it at the destination predefined in the environment.
Here the environment consists of multiple rooms. The robot travels to the cafe room (the room at last with many tables) to pick up and object (maybe coffee) and deliver it to the 
conference room. The robot starts near the entrance of the room and moves towards pickup. The project is divided into various modules showcasing various functions.
</p>
<UL>
 <LI> SLAM modules which enables the robot to map the environment using SLAM </LI>
 <LI> AMCL modules which enables the robot to perform localization in a map </LI>
 <LI> Pick Objects modules to move the robot between source and destination </LI>
 <LI> A demo marker modules for displaying markers whihc signify the object </LI>
 <LI> Home Service modules which show the complete system </LI>
</UL>

<h2> Installation instructions </h2>

```
sudo apt-get update && apt-get upgrade
pip install rospkg
//clone the repo
cd HomeService  //Move to the HomeService Directory
catkin_make
source devel/setup.bash

```
<h2> Packages Used </h2>

<h5> Gmapping: </h5>
  The package is used to perform SLAM gmapping to generate the map of an unknown environment.
  
```
Source: https://github.com/ros-perception/slam_gmapping.git
//TO LAUNCH
roslaunch turtlebot_gazebo gmapping_demo.launch
```
<h5> TurtleBot Teleop: </h5>
  This package is used to manually control the robot movement with keyboard.
  
```
Source:  https://github.com/turtlebot/turtlebot.git
//TO LAUNCH 
roslaunch turtlebot_teleop keyboard_teleop.launch
```
<h5> Turtlebot rviz launchers: </h5>
  This package is used to Rviz with preconfigured settings which may include robot model, laser range finder data, amcl particle cloud and a map.
  
```
Source: https://github.com/turtlebot/turtlebot_interactions.git
//TO LAUNCH 
roslaunch turtlebot_rviz_launchers view_navigation.launch
```

<h5> Turtlebot Gazebo: </h5>
  This package is used to import the turtlebot2 robot model into gazebo world. The default world (willow garage) is changed to world which is created using world editior.
  
```
Soruce:  https://github.com/turtlebot/turtlebot_interactions.git
//TO LAUNCH
roslaunch turtlebot_gazebo turtlebot_world.launch
```




