#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

int main(int argc,char **argv)
{
    ros::init(argc,argv,"veloity_publisher");//初始化ros节点

    ros::NodeHandle n;//创建节点句柄

    ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);//创建一个publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist，队列长度10

    ros::Rate loop_rate(10);//设置循环的频率

    int count = 0;

    while(ros::ok())
    {
        geometry_msgs::Twist vel_msg;//初始化geometry_msgs::Twist类型的消息
        vel_msg.linear.x = 4;
        vel_msg.angular.z = 1;

        turtle_vel_pub.publish(vel_msg);//发布消息
        ROS_INFO("publish turtle velocity command[%0.2f m/s, %0.2f rad/s]",vel_msg.linear.x,vel_msg.angular.z);

        loop_rate.sleep();//按照循环频率延时
    }
    return 0;
}
