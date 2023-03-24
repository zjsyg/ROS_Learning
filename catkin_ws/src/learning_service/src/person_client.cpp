#include<ros/ros.h>
#include<learning_service/Person.h>

int main(int argc,char **argv)
{
    ros::init(argc,argv,"person_client");//初始化ros节点

    ros::NodeHandle node;//创建节点句柄

    //
    ros::service::waitForService("/show_person");
    ros::ServiceClient person_client = node.serviceClient<learning_service::Person>("/show_person");

    //
    learning_service::Person srv;
    srv.request.name = "zjs";
    srv.request.age = 21;
    srv.request.sex = learning_service::Person::Request::male;

    //
    ROS_INFO("Call service to show person[name:%s, age:%d, sex:%d]",srv.request.name.c_str(),srv.request.age,srv.request.sex);

    person_client.call(srv);

    //
    ROS_INFO("show person result : %s",srv.response.result.c_str());

    return 0;
}