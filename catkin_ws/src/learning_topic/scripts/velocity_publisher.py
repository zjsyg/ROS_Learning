#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist

def velocity_publisher():

	rospy.init_node('velocity_publisher',anonymous = True)#初始化ros节点

	turtle_vel_pub = rospy.Publisher('/turtle1/cmd_vel',Twist,queue_size=10)#创建一个publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist，队列长度10

	rate = rospy.Rate(10)#设置循环的频率

	while not rospy.is_shutdown():
	    	vel_msg = Twist()#初始化geometry_msgs::Twist类型的消息
	    	vel_msg.linear.x = 0.5
	    	vel_msg.angular.z = 0.2

	    	turtle_vel_pub.publish(vel_msg)#发布消息
	    	rospy.loginfo("Publish turtle velocity command[%0.2f m/s, %0.2f rad/s]",vel_msg.linear.x,vel_msg.angular.z)
	    	
	    	rate.sleep()#按照循环频率延时

if __name__ == '__main__':
	try:
		velocity_publisher()
	except:
		pass
