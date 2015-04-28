//You need to modify this file.

#ifndef SENSORTIMER_SENSOR_LASER_VARS_H
#define SENSORTIMER_SENSOR_LASER_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Sensor_Laser_Vars SensorTimer_Sensor_Laser_Vars
	\ingroup SensorTimer_Sensor_Laser
	\brief SensorTimer_Sensor_Laser_Vars defines the Vars in SensorTimer_Sensor_Laser.
*/

/*! \addtogroup SensorTimer_Sensor_Laser_Vars
	@{
*/

/*! \file SensorTimer_Sensor_Laser_Vars.h
	 Defines the Vars of SensorTimer_Sensor_Laser
*/

//*******************Please add other headers below*******************


#include "SensorTimer_Sensor_Laser_ParamsData.h"

//The Vars is defined as below
/*! \class SensorTimer_Sensor_Laser_Vars 
	\brief The Vars of SensorTimer_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Sensor_Laser_Vars 
{
public:
	/*! \fn SensorTimer_Sensor_Laser_Vars()
		\brief The constructor of SensorTimer_Sensor_Laser_Vars. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Sensor_Laser_Vars() 
	{
        skip_scan=0;
        llaser_on = rlaser_on = 1;
        connection_type=URG_SERIAL;
        l_device_or_address= "/dev/ttyACM0";
        r_device_or_address = "/dev/ttyACM1";
        baudreate_or_port=115200;
        measurement_type=URG_DISTANCE;
	}
	/*! \fn ~SensorTimer_Sensor_Laser_Vars()
		\brief The destructor of SensorTimer_Sensor_Laser_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Sensor_Laser_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    bool llaser_on, rlaser_on;
    int skip_scan;
    urg_connection_type_t connection_type;
    QString l_device_or_address;
    QString r_device_or_address;
    int baudreate_or_port;
    urg_measurement_type_t measurement_type;
    urg_t lurg;
    urg_t rurg;

};

/*! @}*/ 

#endif
