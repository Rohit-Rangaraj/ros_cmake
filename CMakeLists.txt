cmake_minimum_required(VERSION 3.0.2)
project(ros_cmake)

set(PACKAGE_CATKIN_DEPENDS
  roscpp
  rospy
  std_msgs
)
# include_directories(include)

find_package(catkin REQUIRED COMPONENTS
  ${PACKAGE_CATKIN_DEPENDS}
)

# find_package(Boost REQUIRED COMPONENTS system)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES ros_cmake
 CATKIN_DEPENDS ${PACKAGE_CATKIN_DEPENDS}
#  DEPENDS system_lib
)

set(PACKAGE_LIBRARIES "")

add_executable(test_node src/test_node.cpp)

list(APPEND PACKAGE_LIBRARIES test_node)

foreach(name IN LISTS PACKAGE_LIBRARIES)
  target_link_libraries(${name} ${catkin_LIBRARIES})
  add_dependencies(${name} ${catkin_EXPORTED_TARGETS})
endforeach()

if (CATKIN_ENABLE_TESTING)
  catkin_add_gtest(utest test/utest.cpp)
  target_link_libraries(utest ${catkin_LIBRARIES})
endif()

install(TARGETS test_node
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(DIRECTORY
launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

# catkin_add_gtest(utest test/utest.cpp)
