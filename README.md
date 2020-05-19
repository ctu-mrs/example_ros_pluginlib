# Example ROS Pluginlib

A working example showcasing the [pluginlib](http://wiki.ros.org/pluginlib) feature of ROS.

## example_manager package

* defines the [interface]() for plugins
* defines a *common handlers*, which are passed to the plugins
* dynamically loads the plugins defined in [plugins.yaml]() and [example_manager.yaml]()
* activates the plugin defined in [example_manager.yaml]()
* regularly updates the active plugin and queries a result

## example_plugins package

* defines a plugin complying with the interface [interface]()
* the plugin loads its params and prepares itself for activation
* it calculates results in its `update()` method and returns them to the manager
