#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle nh;
  ros::NodeHandle nhp("~");

  std::string str_param = "hello world? ";
  if(nhp.hasParam("param"))
  {
    nhp.getParam("param", str_param);
    str_param.append(" ");
  }
  else
  {
    ROS_INFO("No parameter");
    return 1;
  }

  ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;

    std::stringstream ss;
    ss << str_param << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
