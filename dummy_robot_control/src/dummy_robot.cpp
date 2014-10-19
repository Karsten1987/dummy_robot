#include <ros/ros.h>
#include <controller_manager/controller_manager.h>

#include "dummy_hardware.h"

int main( int argc, char** argv )
{
  ros::init( argc, argv, "dummy_robot" );

  DummyHardware robot;
  controller_manager::ControllerManager cm( &robot );

  ros::AsyncSpinner spinner( 1 );
  spinner.start();

  size_t freq = 10; // in Hz
  ros::Rate r( freq );

  while( ros::ok() )
  {
    ros::Time t = ros::Time::now();

    robot.readJoints();

    cm.update( t, ros::Duration( 1.0f/freq ) );

    robot.writeJoints();

    r.sleep();
  }

  spinner.stop();

  return 1;
}
