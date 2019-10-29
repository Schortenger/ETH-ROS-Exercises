#pragma once

#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <ros/console.h>

namespace husky_highlevel_controller {

/*!
 * Class containing the Husky Highlevel Controller
 */
class HuskyHighlevelController {
public:
	/*!
	 * Constructor.
	 */
	HuskyHighlevelController(ros::NodeHandle& nodeHandle);

	/*!
	 * Destructor.
	 */
	virtual ~HuskyHighlevelController();

private:
	int queue_size;
	bool readParameters();
	void scanCallback(const sensor_msgs::LaserScan& scan_msg);
	
	//! ROS node handle.
  	ros::NodeHandle& nodeHandle_;

	//! ROS topic subscriber.
 	ros::Subscriber sub_laser_scan_;
	//! ROS topic name to subscribe to.
 	std::string scan_sub_topic;
	 
	//! ROS topic name to subscribe to.
 	std::string  scan_sub_queue_size;
};

} /* namespace */
