cmake_minimum_required(VERSION 2.8.3)
project(example_manager)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  cmake_modules
  mrs_lib
  nodelet
  )

# include Eigen3
find_package(Eigen3 REQUIRED)
set(Eigen_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIRS})
set(Eigen_LIBRARIES ${Eigen_LIBRARIES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fno-diagnostics-color -Wall -Wextra")

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ExampleManager
  CATKIN_DEPENDS roscpp mrs_lib
  )

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  )

# ControlManager

add_library(ExampleManager src/example_manager.cpp)

add_dependencies(ExampleManager
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
  )

target_link_libraries(ExampleManager
  ${catkin_LIBRARIES}
  )
