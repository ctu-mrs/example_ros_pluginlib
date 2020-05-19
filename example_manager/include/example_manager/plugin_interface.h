#ifndef PLUGIN_INTERFACE_H
#define PLUGIN_INTERFACE_H

#include <ros/ros.h>

#include <example_manager/common_handlers.h>

namespace example_manager
{

class Plugin {
public:
  virtual ~Plugin() = 0;

  virtual void initialize(const ros::NodeHandle& parent_nh, const std::string& name, const std::string& name_space,
                          std::shared_ptr<example_manager::CommonHandlers_t> common_handlers) = 0;

  virtual bool activate(const int& some_number) = 0;

  virtual void deactivate(void) = 0;

  virtual const std::optional<double> update(const Eigen::Vector3d& input) = 0;
};

// A pure virtual destructor requires a function body.
Plugin::~Plugin(){};

}  // namespace example_manager

#endif
