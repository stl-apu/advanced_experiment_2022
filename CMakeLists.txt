cmake_minimum_required(VERSION 2.8.3)

project(advanced_experiment)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	rospy
	std_msgs
	genmsg
	sensor_msgs
	geometry_msgs
	mouse_teleop
)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})

add_executable(talker_with_parameter src/talker_with_parameter.cpp)
target_link_libraries(talker_with_parameter ${catkin_LIBRARIES})
