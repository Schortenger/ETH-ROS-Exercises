#include "husky_highlevel_controller/HuskyHighlevelController.hpp"
//#include <ros/ros.h>
#include <cmath>



namespace husky_highlevel_controller {

    HuskyHighlevelController::HuskyHighlevelController(ros::NodeHandle& nodeHandle) :
      nodeHandle_(nodeHandle)
    {
    


    
    ROS_INFO("ROS_INFO_STREAM1 Minimum laser distance(m)");
    sub_laser_scan_ = nodeHandle_.subscribe("/scan", 200,
                                        &HuskyHighlevelController::scanCallback, this);

    ROS_INFO("Node launched.");                                  
    
    
    }



    void HuskyHighlevelController::scanCallback(const sensor_msgs::LaserScan& scan_msg)
    {
         float smallest_distance = 100;
        // the angle corresponding to the minimum distance
      
 
        //number of the elements in ranges array
        int arr_size = floor((scan_msg.angle_max-scan_msg.angle_min)/scan_msg.angle_increment);
        for (int i=0 ; i< arr_size ;i++)
        {
            if (scan_msg.ranges[i] < smallest_distance)
            {
                smallest_distance = scan_msg.ranges[i];
            }
        }
	    ROS_INFO("ROS_INFO Minimum laser distance(m): %lf", smallest_distance);

    }

    HuskyHighlevelController::~HuskyHighlevelController()
    {
    }

} /* namespace */
