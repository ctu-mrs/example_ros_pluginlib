cmake_minimum_required(VERSION 2.8.3)
project(example_plugins)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  cmake_modules
  mrs_lib
  example_manager
  )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fno-diagnostics-color -Wall -Wextra")

# include Eigen3
find_package(Eigen3 REQUIRED)
set(Eigen_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIRS})
set(Eigen_LIBRARIES ${Eigen_LIBRARIES})

###################################
## catkin specific configuration ##
###################################

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

# NSF controller

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
