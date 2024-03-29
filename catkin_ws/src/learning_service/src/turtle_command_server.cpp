#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<std_srvs/Trigger.h>

ros::Publisher turtle_vel_pub;
bool pubCommand = false;

bool CommandCallback(std_srvs::Trigger::Request &req,std_srvs::Trigger::Response &res)
{
    pubCommand = !pubCommand;

    ROS_INFO("Publish turtle velocity command [%s]",pubCommand==true?"Yes":"No");

    res.success = true;
    res.message = "Change turtle command state!"; 

    return true;
}

int main(int argc,char **argv)
{
    ros::init(argc,argv,"turtle_command_server");
    ros::NodeHandle n;

    ros::ServiceServer command_service = n.advertiseService("/turtle_command",CommandCallback);
    turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
    ROS_INFO("Ready to receive turtle command");

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        ros::spinOnce();

        if(pubCommand)
        {
            geometry_msgs::Twist vel_msg;
            vel_msg.linear.x = 0.5;
            vel_msg.angular.z = 0.2;
            
            turtle_vel_pub.publish(vel_msg);
        }
        loop_rate.sleep();
    }
    return 0;
}
