cmake_minimum_required(VERSION 2.8.3)
project(dummy_robot_control)

find_package(catkin REQUIRED COMPONENTS
  controller_manager
  geometry_msgs
  hardware_interface
  roscpp
  sensor_msgs
  std_msgs
  tf
)
catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES dummy_hardware dummy_robot
  CATKIN_DEPENDS controller_manager geometry_msgs hardware_interface roscpp sensor_msgs std_msgs tf
#  DEPENDS system_lib
)
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp library
add_library(dummy_hardware
  src/dummy_hardware.cpp
)
target_link_libraries(dummy_hardware
  ${catkin_LIBRARIES}
)

## Declare a cpp executable
add_executable(dummy_robot src/dummy_robot.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(dummy_robot
  ${catkin_LIBRARIES}
  dummy_hardware
)
