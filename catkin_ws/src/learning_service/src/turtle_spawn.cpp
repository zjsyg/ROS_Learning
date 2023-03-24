#include<ros/ros.h>
#include<turtlesim/Spawn.h>

int main(int argc,char **argv)
{
    ros::init(argc,argv,"turtle_spawn");//初始化ros节点

    ros::NodeHandle node;//创建节点句柄

    //
    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");

    //
    turtlesim::Spawn srv;
    srv.request.x = 2.0;
    srv.request.y = 2.0;
    srv.request.name = "turtle_z";

    //
    ROS_INFO("Call service to spawn turtle[x:%0.6f, y:%0.6f, name:%s]",srv.request.x,srv.request.y,srv.request.name.c_str());

    add_turtle.call(srv);

    //
    ROS_INFO("Spawn turtle successfully [name:%s]",srv.request.name.c_str());

    return 0;
}

