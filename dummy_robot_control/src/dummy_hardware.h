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

  hardware_interface::JointStateInterface jnt_state_interface;
  hardware_interface::PositionJointInterface jnt_pos_interface;

  double cmd[2];
  double pos[2];
  double vel[2];
  double eff[2];

  static const size_t fake_computation_ = 100000;
};
