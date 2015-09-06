#include "dummy_hardware.h"

static const size_t fake_computation = 100000;

DummyHardware::DummyHardware()
{
  std::vector< std::string > joint_names;
  joint_names.push_back( "left_wheel_joint" );
  joint_names.push_back( "right_wheel_joint" );

  // init to make a diff
  pos[0] = 1.5f;
  pos[1] = 2.5f;

  /* not available in indigo anymore */
  //hardware_interface::JointModeHandle mode_handle("joint_mode", &joint_mode);
  //jnt_mode_interface.registerHandle(mode_handle);

  for (size_t i = 0; i < joint_names.size(); ++i)
  {
    // connect and register the joint state interface
    hardware_interface::JointStateHandle state_handle(joint_names[i], &pos[i], &vel[i], &eff[i]);
    jnt_state_interface.registerHandle(state_handle);

    // connect and register the joint position interface
    hardware_interface::JointHandle pos_handle(jnt_state_interface.getHandle(joint_names[i]), &cmd[i]);
    jnt_pos_interface.registerHandle(pos_handle);

    // connect and register the joint velocity interface
    hardware_interface::JointHandle vel_handle(jnt_state_interface.getHandle(joint_names[i]), &cmd[i]);
    jnt_vel_interface.registerHandle(vel_handle);
  }

  registerInterface(&jnt_state_interface);
  registerInterface(&jnt_pos_interface);
  registerInterface(&jnt_vel_interface);
}

void DummyHardware::readJoints()
{
  for (size_t i = 0; i < fake_computation; ++i)
  {
    1+1;
  }

  ROS_INFO_STREAM("*****read*******");
  ROS_INFO_STREAM("pos0 :" << pos[0] );
  ROS_INFO_STREAM("vel0 :" << vel[0] );
  ROS_DEBUG("I just computed read joints");
}

void DummyHardware::writeJoints()
{
  for (size_t i = 0; i< fake_computation; ++i)
  {
    2+2;
  }
  ROS_INFO_STREAM("*****write*******");
  ROS_INFO_STREAM("cmd0: " << cmd[0] );
  ROS_DEBUG("I just computed write joints");
}
