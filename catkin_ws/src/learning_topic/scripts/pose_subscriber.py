import rospy
from turtlesim.msg import Pose

def poseCallback(msg):
    rospy.loginfo("Turtle pose: x:%0.6f, y:%0.6f",msg.x, msg.y)

def pose_subscriber():
	#初始化ros节点
    rospy.init_node('pose_subscriber',anonymous=True)

	#创建一个subscriber，订阅名为/turtle1/pose的topic，注册回调函数posecallback
    rospy.Subscriber("/turtle1/pose",Pose,poseCallback)

	#循环等待回调函数
    rospy.spin()

if __name__ == '__main__':
    pose_subscriber()
