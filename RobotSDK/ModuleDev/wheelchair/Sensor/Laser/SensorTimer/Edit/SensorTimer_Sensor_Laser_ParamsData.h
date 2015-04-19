//You need to modify this file.

#ifndef SENSORTIMER_SENSOR_LASER_PARAMSDATA_H
#define SENSORTIMER_SENSOR_LASER_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Sensor_Laser_ParamsData SensorTimer_Sensor_Laser_ParamsData
	\ingroup SensorTimer_Sensor_Laser
	\brief SensorTimer_Sensor_Laser_ParamsData defines the ParamsData in SensorTimer_Sensor_Laser.
*/

/*! \addtogroup SensorTimer_Sensor_Laser_ParamsData
	@{
*/

/*! \file SensorTimer_Sensor_Laser_ParamsData.h
	 Defines the ParamsData of SensorTimer_Sensor_Laser
*/

//*******************Please add other headers below*******************
#include<urg_sensor.h>
#include<urg_utils.h>

//There is no input data headers.

/*! \def SensorTimer_Sensor_Laser_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorTimer_Sensor_Laser_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorTimer_Sensor_Laser_Params 
	\brief The Params of SensorTimer_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Sensor_Laser_Params 
{
public:
	/*! \fn SensorTimer_Sensor_Laser_Params()
		\brief The constructor of SensorTimer_Sensor_Laser_Params. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Sensor_Laser_Params() 
	{
        first_step=-360;
        last_step=360;
        skip_step=2;
        nearfilter=0;
        farfilter=5000;
        unit = 100.0;
	}
	/*! \fn ~SensorTimer_Sensor_Laser_Params()
		\brief The destructor of SensorTimer_Sensor_Laser_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Sensor_Laser_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int first_step;
    int last_step;
    int skip_step;
    short nearfilter;
    short farfilter;
    double unit;
};

//The Output Data is defined as below
/*! \class SensorTimer_Sensor_Laser_Data 
	\brief The Data of SensorTimer_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Sensor_Laser_Data 
{
public:
	/*! \fn SensorTimer_Sensor_Laser_Data()
		\brief The constructor of SensorTimer_Sensor_Laser_Data. [required]
		\details ****Please add details below****

	*/
    SensorTimer_Sensor_Laser_Data(int dataSize)
	{
        datasize=dataSize;
        if(datasize>0)
        {
            ldata=new short[dataSize];
            rdata=new short[dataSize];
        }
        else
        {
            ldata=NULL;
            rdata=NULL;
        }
	}
	/*! \fn ~SensorTimer_Sensor_Laser_Data()
		\brief The destructor of SensorTimer_Sensor_Laser_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Sensor_Laser_Data() 
	{
        if(ldata!=NULL)
        {
            delete []ldata;
            ldata=NULL;
        }
        if(rdata!=NULL)
        {
            delete []rdata;
            rdata=NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    QString laserstatus;
    long timestamp;
    QTime qtimestamp;
    int datasize;
    short * ldata;
    short * rdata;
};

/*! \def SensorTimer_Sensor_Laser_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorTimer_Sensor_Laser_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
