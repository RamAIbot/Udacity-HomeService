#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char **argv)
{
    
    ros::init(argc,argv,"pick_objects");

    MoveBaseClient ac("move_base",true);

    while(!ac.waitForServer(ros::Duration(5.0)))
    {
        ROS_INFO("Waiting for move_base action server to come up");

    }

    move_base_msgs::MoveBaseGoal goal,start;
    
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();
    

    //goal.target_pose.pose.position.x=1.0;
    //goal.target_pose.pose.position.y=1.0;
    ////goal.target_pose.pose.orientation.w=0.0;
    //goal.target_pose.pose.orientation.w=1.0;

    goal.target_pose.pose.position.x=5.5;
    goal.target_pose.pose.position.y=6.16;
    //goal.target_pose.pose.orientation.w=0.0;
    goal.target_pose.pose.orientation.w=1.0;


    ROS_INFO("Sending goals");
    ac.sendGoal(goal);

    ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
        ROS_INFO("Great!, The base moved 1m forward, Goal has been reached");
       
        ros::Duration(5.0).sleep();
        ROS_INFO("Moving to start");
        start.target_pose.header.frame_id = "map";
    start.target_pose.header.stamp = ros::Time::now();
    
    //start.target_pose.pose.position.x=5.34;
    //start.target_pose.pose.position.y=6.76;
    ////start.target_pose.pose.orientation.w=0.00;
    //start.target_pose.pose.orientation.w=1.0;
    //**********Original Start point*************//
    //start.target_pose.pose.position.x=-2.591308;
    //start.target_pose.pose.position.y=-8.443678;
    //start.target_pose.pose.orientation.w=0.00;
    //start.target_pose.pose.orientation.w=1.0;
    //**********Original Start point*************//
    start.target_pose.pose.position.x=-8.29;
    start.target_pose.pose.position.y=2.01;
    //start.target_pose.pose.orientation.w=0.00;
    start.target_pose.pose.orientation.w=1.0;
    
    //-x 8.443678 -y -2.591308 -Y -3.114166 Start position
    //goal.target_pose.pose.position.x=8.443678;
    //goal.target_pose.pose.position.y=-2.591308;
    //goal.target_pose.pose.orientation.w=-3.114166;

    ROS_INFO("Sending start");
    ac.sendGoal(start);

    ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
        ROS_INFO("Great!, Start has been reached");
        
        ros::Duration(5.0).sleep();
    }
    else{
        ROS_INFO("the base failed to reach start");
        ros::Duration(5.0).sleep();
    }
    
    }
    else
        ROS_INFO("the base failed to reach goal");


    
    
    
    return 0;

}