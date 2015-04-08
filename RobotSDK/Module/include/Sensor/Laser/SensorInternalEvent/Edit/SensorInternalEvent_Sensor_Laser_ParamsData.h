//You need to modify this file.

#ifndef SENSORINTERNALEVENT_SENSOR_LASER_PARAMSDATA_H
#define SENSORINTERNALEVENT_SENSOR_LASER_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_Laser_ParamsData SensorInternalEvent_Sensor_Laser_ParamsData
	\ingroup SensorInternalEvent_Sensor_Laser
	\brief SensorInternalEvent_Sensor_Laser_ParamsData defines the ParamsData in SensorInternalEvent_Sensor_Laser.
*/

/*! \addtogroup SensorInternalEvent_Sensor_Laser_ParamsData
	@{
*/

/*! \file SensorInternalEvent_Sensor_Laser_ParamsData.h
	 Defines the ParamsData of SensorInternalEvent_Sensor_Laser
*/

//*******************Please add other headers below*******************
#include <sensor_msgs/LaserScan.h>

//There is no input data headers.

/*! \def SensorInternalEvent_Sensor_Laser_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorInternalEvent_Sensor_Laser_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorInternalEvent_Sensor_Laser_Params 
	\brief The Params of SensorInternalEvent_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Laser_Params 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Laser_Params()
		\brief The constructor of SensorInternalEvent_Sensor_Laser_Params. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Laser_Params() 
	{
		
	}
	/*! \fn ~SensorInternalEvent_Sensor_Laser_Params()
		\brief The destructor of SensorInternalEvent_Sensor_Laser_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Laser_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class SensorInternalEvent_Sensor_Laser_Data 
	\brief The Data of SensorInternalEvent_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Laser_Data 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Laser_Data()
		\brief The constructor of SensorInternalEvent_Sensor_Laser_Data. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Laser_Data() 
	{
        laserdata = new float [1000];          //有问题，先这样写
	}
	/*! \fn ~SensorInternalEvent_Sensor_Laser_Data()
		\brief The destructor of SensorInternalEvent_Sensor_Laser_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Laser_Data() 
	{
        delete [] laserdata;
	}
public:
	//*******************Please add variables below*******************
    sensor_msgs::LaserScanConstPtr  laserPtr;
    QTime timestamp;
    int datasize;
    double angle_min;
    double angle_max;
    float *laserdata;
};

/*! \def SensorInternalEvent_Sensor_Laser_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorInternalEvent_Sensor_Laser_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
