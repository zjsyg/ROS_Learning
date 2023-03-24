#include<ros/ros.h>
#include<learning_service/Person.h>

bool PensonCallback(learning_service::Person::Request &req,learning_service::Person::Response &res)
{
    ROS_INFO("Person name : %s age : %d sex : %d",req.name.c_str(),req.age,req.sex);

    res.result = "OK";

    return true;
}

int main(int argc,char **argv)
{
    ros::init(argc,argv,"person_server");
    ros::NodeHandle n;

    ros::ServiceServer command_service = n.advertiseService("/show_person",PensonCallback);

    ROS_INFO("Ready to show person infomation");
    ros::spin();

    return 0;
}
