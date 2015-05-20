#include <iostream>
#include <gazebo/gazebo.hh>

int main()
{
  gazebo::transport::init();
  gazebo::transport::run();
  gazebo::transport::NodePtr node(new gazebo::transport::Node());
  node->Init();
  gazebo::transport::PublisherPtr pub;
  pub = node->Advertise<gazebo::msgs::Pose>("/gazebo/default/pioneer2dx/vel_cmd");

  gazebo::msgs::Pose msg;
  gazebo::math::Pose pose(0.5, 0, 0, 0, 0, 0.1);
  gazebo::msgs::Set(&msg, pose);

  while (true)
  {
    gazebo::common::Time::MSleep(100);
    pub->Publish(msg);
  }

  return 0;
}
