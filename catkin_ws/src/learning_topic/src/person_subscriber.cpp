#include<ros/ros.h>
#include<learning_topic/Person.h>

//接收到订阅的消息后，会进入消息回调函数
void personInfoCallback(const learning_topic::Person::ConstPtr& msg)
{
	//将接收到的消息打印出来
    ROS_INFO("Subscrib Person Info: name:%s, age:%d, sex:%d",msg->name.c_str(),msg->age,msg->sex);
}

int main(int argc,char **argv)
{
	//初始化ros节点
    ros::init(argc,argv,"person_subscriber");

	//创建节点句柄
    ros::NodeHandle n;

	//创建一个subscriber，订阅名为/person_info的topic，注册回调函数posecallback
    ros::Subscriber person_info_sub = n.subscribe("/person_info",10,personInfoCallback);
	
	//循环等待回调函数
    ros::spin();

    return 0;
}