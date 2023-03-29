#include<ros/ros.h>
#include<tf2_ros/static_transform_broadcaster.h>
#include<geometry_msgs/TransformStamped.h>
#include<tf2/LinearMath/Quaternion.h>

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"static_pub");
    ros::NodeHandle n;
    tf2_ros::StaticTransformBroadcaster stb;
    geometry_msgs::TransformStamped ts;
    ts.header.stamp = ros::Time::now();
    ts.header.frame_id = "base_link";
    ts.child_frame_id = "laser";
    ts.transform.translation.x = 0.2;
    ts.transform.translation.y = 0.0;
    ts.transform.translation.z = 0.5;
    tf2::Quaternion q;
    q.setRPY(0,0,0);
    ts.transform.rotation.x = q.getX();
    ts.transform.rotation.y = q.getY();
    ts.transform.rotation.z = q.getZ();
    ts.transform.rotation.w = q.getW();
    stb.sendTransform(ts);
    ros::spin();
    return 0;
}
