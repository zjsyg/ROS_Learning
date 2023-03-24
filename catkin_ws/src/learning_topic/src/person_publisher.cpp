#include<ros/ros.h>
#include<learning_topic/Person.h>

int main(int argc,char **argv)
{
    ros::init(argc,argv,"person_publisher");//初始化ros节点

    ros::NodeHandle n;//创建节点句柄

    ros::Publisher person_info_pub = n.advertise<learning_topic::Person>("/person_info",10);
    //创建一个publisher，发布名为/person_info的topic，消息类型为learning_topic::Person，队列长度10

    ros::Rate loop_rate(1);//设置循环的频率

    int count = 0;
    while(ros::ok())
    {
        learning_topic::Person person_msg;//初始化learning_topic::Person类型的消息
        person_msg.name = "zjs";
        person_msg.age = 21;
        person_msg.sex = learning_topic::Person::male;

        person_info_pub.publish(person_msg);//发布消息
        ROS_INFO("Publish Person Info: name: %s, age: %d sex: %d",person_msg.name.c_str(),person_msg.age,person_msg.sex);

        loop_rate.sleep();//按照循环频率延时
    }
    return 0;
}