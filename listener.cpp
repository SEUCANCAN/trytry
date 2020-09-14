#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

ros::Publisher information_pub;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s}", msg->data.c_str());
    information_pub.publish(msg);
}
int main(int argc, char **argv)
{
    ros::init(argc,argv,"listener");
    ros::NodeHandle n;
     information_pub = n.advertise<std_msgs::String>("information", 1000 );
    ros::Subscriber sub = n.subscribe("chatter",1000,chatterCallback);
    //ros::Publisher information_pub = n.advertise<std_msgs::String>("information", 1000 );
    //ros::Rate loop_rate(10);
    ros::spin();
    return 0;
}