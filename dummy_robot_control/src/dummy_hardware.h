#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>

class DummyHardware : public hardware_interface::RobotHW
{
public:

  DummyHardware();

  void readJoints();

  void writeJoints();

private:

  /* not available in indigo anymore */
  //hardware_interface::JointModeInterface      jnt_mode_interface;
  hardware_interface::JointStateInterface     jnt_state_interface;
  hardware_interface::PositionJointInterface  jnt_pos_interface;
  hardware_interface::VelocityJointInterface  jnt_vel_interface;

  //int joint_mode;
  double cmd[2];
  double pos[2];
  double vel[2];
  double eff[2];

};
