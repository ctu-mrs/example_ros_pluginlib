cmake_minimum_required(VERSION 3.1.2)
project(example_plugins)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  cmake_modules
  mrs_lib
  example_manager
  )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 REQUIRED)
set(Eigen_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIRS})
set(Eigen_LIBRARIES ${Eigen_LIBRARIES})

catkin_package(
  # INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp example_manager mrs_lib
  DEPENDS Eigen
  )

include_directories(
  # include
  ${catkin_INCLUDE_DIRS}
  ${dynamic_reconfigure_PACKAGE_PATH}/cmake/cfgbuild.cmake
  )

# ExamplePlugin

add_library(ExamplePlugin
  src/example_plugin/example_plugin.cpp
  )

add_dependencies(ExamplePlugin
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
  )

target_link_libraries(ExamplePlugin
  ${catkin_LIBRARIES}
  )
