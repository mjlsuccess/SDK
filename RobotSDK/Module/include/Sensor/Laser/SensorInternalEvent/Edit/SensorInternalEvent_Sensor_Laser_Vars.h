//You need to modify this file.

#ifndef SENSORINTERNALEVENT_SENSOR_LASER_VARS_H
#define SENSORINTERNALEVENT_SENSOR_LASER_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_Laser_Vars SensorInternalEvent_Sensor_Laser_Vars
	\ingroup SensorInternalEvent_Sensor_Laser
	\brief SensorInternalEvent_Sensor_Laser_Vars defines the Vars in SensorInternalEvent_Sensor_Laser.
*/

/*! \addtogroup SensorInternalEvent_Sensor_Laser_Vars
	@{
*/

/*! \file SensorInternalEvent_Sensor_Laser_Vars.h
	 Defines the Vars of SensorInternalEvent_Sensor_Laser
*/

//*******************Please add other headers below*******************

#include "SensorInternalEvent_Sensor_Laser_ParamsData.h"
#include <rosinterface.h>
#include <sensor_msgs/LaserScan.h>


//The Vars is defined as below
/*! \class SensorInternalEvent_Sensor_Laser_Vars 
	\brief The Vars of SensorInternalEvent_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Laser_Vars 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Laser_Vars()
		\brief The constructor of SensorInternalEvent_Sensor_Laser_Vars. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Laser_Vars() 
	{
        topic = "scan";
        queuesize = 1000;
        quryinterval = 10;
        lasersub = new ROSSub<sensor_msgs::LaserScanConstPtr>(topic, queuesize, quryinterval);
	}
	/*! \fn ~SensorInternalEvent_Sensor_Laser_Vars()
		\brief The destructor of SensorInternalEvent_Sensor_Laser_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Laser_Vars() 
	{
        if(lasersub != NULL)
        {
            delete lasersub;
            lasersub = NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    QString topic;
    u_int32_t queuesize;
    int quryinterval;
    ROSSub<sensor_msgs::LaserScanConstPtr>* lasersub;
};

/*! @}*/ 

#endif
