cmake_minimum_required(VERSION 3.1.2)
project(example_manager)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  cmake_modules
  mrs_lib
  nodelet
  )

find_package(Eigen3 REQUIRED)
set(Eigen_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIRS})
set(Eigen_LIBRARIES ${Eigen_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ExampleManager
  CATKIN_DEPENDS roscpp mrs_lib
  )

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  )

# ExampleManager

add_library(ExampleManager src/example_manager.cpp)

add_dependencies(ExampleManager
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
  )

target_link_libraries(ExampleManager
  ${catkin_LIBRARIES}
  )
