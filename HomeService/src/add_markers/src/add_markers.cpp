#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
//#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>



 //*******Map Frame points*******
 float objx=5.5;
 float objy=6.16;
 float objw=1.0;

 
 
//8.443678 -y -2.591308
 float stx=8.443678;
 float sty=-2.591308;
 float stw=1.0;
 int pickup=1;

 float posx;
  float posy;
  float posa;

 visualization_msgs::Marker marker;
 uint32_t shape = visualization_msgs::Marker::CUBE;
 
 

//void position_det(const nav_msgs::Odometry::ConstPtr& msg)

void position_det(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
    //ROS_INFO("Position ->  x: [%f], y:[%f], z: [%f]", msg->pose.pose.position.x,msg->pose.pose.position.y,msg->pose.pose.position.z);
    //ROS_INFO("Orientation -> w: [%f] ", msg->pose.pose.orientation.w);
     posx=msg->pose.pose.position.x;
     posy=msg->pose.pose.position.y;
     posa=msg->pose.pose.orientation.w;
     ROS_INFO("x : %f, y: %f",posx,posy);
    
    
}



int main(int argc, char **argv)
{

    ros::init(argc,argv,"add_markers");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_maker",1);
    ros::Subscriber pos=n.subscribe("amcl_pose",10,position_det);
    
    marker.header.frame_id="/map";
    marker.header.stamp=ros::Time::now();

    marker.ns="Destination";
    marker.id=0;
    marker.type=shape;
    marker.action=visualization_msgs::Marker::ADD;

    marker.pose.position.x=5.5;
    marker.pose.position.y=6.16;
    marker.pose.position.z=0.0;
    marker.pose.orientation.x=0.0;
    marker.pose.orientation.y=0.0;
    marker.pose.orientation.z=0.0;
    marker.pose.orientation.w=1.0;

    marker.scale.x=1.0;
    marker.scale.y=1.0;
    marker.scale.z=1.0;

    marker.color.r=0.0f;
    marker.color.g=0.0f;
    marker.color.b=1.0f;
    marker.color.a=1.0;
    marker.lifetime=ros::Duration();

    while(ros::ok()){

        while(marker_pub.getNumSubscribers()<1)
        {
            if(!ros::ok())
            {
                return 0;
            }
            ROS_WARN_ONCE("Please create a subscriber");
            sleep(1);
        }
    //((posx - objx)<0.5) && ((posy - objy)<0.5 )
    if(sqrt(pow((posx - objx),2) + pow((posy-objy),2)) < 0.5)
    {
        marker.color.r=0.0f;
        marker.color.g=0.0f;
        marker.color.b=1.0f;
        marker.color.a=0.0;
        marker_pub.publish(marker);
        pickup=0;


        marker.pose.position.x=-8.29;
        marker.pose.position.y=2.01;
        marker.pose.position.z=0.0;
        marker.pose.orientation.w=1.0;
        marker.color.r=1.0f;
        marker.color.g=0.0f;
        marker.color.b=0.0f;
        marker.color.a=1.0;
        ros::Duration(5.0).sleep();
        ROS_INFO("Adding the marker at start");
        marker_pub.publish(marker);
        //ros::Duration(5.0).sleep();
        //ROS_INFO("Deleting the marker at start");
        //marker.color.a=0.0;
        //.publish(marker);
        //ros::Duration(5.0).sleep();

    }


    else if( (posx - objx) != 0 && (posy - objy)!=0 && pickup==1)
    {
        
        marker.color.r=0.0f;
        marker.color.g=0.0f;
        marker.color.b=1.0f;
        marker.color.a=0.0;
        



        marker.pose.position.x=5.5;
        marker.pose.position.y=6.16;
        marker.pose.position.z=0.0;
        marker.pose.orientation.x=0.0;
        marker.pose.orientation.y=0.0;
        marker.pose.orientation.z=0.0;
        marker.pose.orientation.w=1.0;

        marker.color.r=0.0f;
        marker.color.g=0.0f;
        marker.color.b=1.0f;
        marker.color.a=1.0;
        ros::Duration(5.0).sleep();
        ROS_INFO("Adding the marker at Goal");
        marker_pub.publish(marker);
        //ros::Duration(5.0).sleep();
    }
    
    else if(pickup==0)
    {

        


        marker.pose.position.x=-8.29;
        marker.pose.position.y=2.01;
        marker.pose.position.z=0.0;
        marker.pose.orientation.w=1.0;
        marker.color.r=1.0f;
        marker.color.g=0.0f;
        marker.color.b=0.0f;
        marker.color.a=1.0;
        ros::Duration(5.0).sleep();
        ROS_INFO("Adding the marker at start");
        marker_pub.publish(marker);

    }


    ros::spin();
    
    }
    
}
