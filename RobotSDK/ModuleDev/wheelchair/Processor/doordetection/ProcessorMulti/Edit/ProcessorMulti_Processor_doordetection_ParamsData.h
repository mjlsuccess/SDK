//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_DOORDETECTION_PARAMSDATA_H
#define PROCESSORMULTI_PROCESSOR_DOORDETECTION_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_doordetection_ParamsData ProcessorMulti_Processor_doordetection_ParamsData
	\ingroup ProcessorMulti_Processor_doordetection
	\brief ProcessorMulti_Processor_doordetection_ParamsData defines the ParamsData in ProcessorMulti_Processor_doordetection.
*/

/*! \addtogroup ProcessorMulti_Processor_doordetection_ParamsData
	@{
*/

/*! \file ProcessorMulti_Processor_doordetection_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Processor_doordetection
*/

//*******************Please add other headers below*******************
#define SIZE_OF_GRID1 1000   //  ÁÙÊ±ÓÃ
#include <opencv2/core/core.hpp>  //  ÁÙÊ±ÓÃ
#include <opencv2/highgui/highgui.hpp>  //  ÁÙÊ±ÓÃ

//2 input data header(s) refered

//Defines Params SensorTimer_Sensor_Laser_Params and Input Data SensorTimer_Sensor_Laser_Data
#include<wheelchair/Sensor/Laser/SensorTimer/Edit/SensorTimer_Sensor_Laser_ParamsData.h>
//Defines Params SourceDrainMono_Sensor_stm32comm_Params and Input Data SourceDrainMono_Sensor_stm32comm_Data
#include<wheelchair/Sensor/stm32comm/SourceDrainMono/Edit/SourceDrainMono_Sensor_stm32comm_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Processor_doordetection_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_Laser_Params, Data_Type = SensorTimer_Sensor_Laser_Data
	- Input Port #1: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
*/
#define ProcessorMulti_Processor_doordetection_INPUTPORTSSIZE QList<int>()<<10<<10

//The Params is defined as below
/*! \class ProcessorMulti_Processor_doordetection_Params 
	\brief The Params of ProcessorMulti_Processor_doordetection.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_doordetection_Params 
{
public:
	/*! \fn ProcessorMulti_Processor_doordetection_Params()
		\brief The constructor of ProcessorMulti_Processor_doordetection_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_doordetection_Params() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Processor_doordetection_Params()
		\brief The destructor of ProcessorMulti_Processor_doordetection_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_doordetection_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class ProcessorMulti_Processor_doordetection_Data 
	\brief The Data of ProcessorMulti_Processor_doordetection.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_doordetection_Data 
{
public:
	/*! \fn ProcessorMulti_Processor_doordetection_Data()
		\brief The constructor of ProcessorMulti_Processor_doordetection_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_doordetection_Data() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Processor_doordetection_Data()
		\brief The destructor of ProcessorMulti_Processor_doordetection_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_doordetection_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QByteArray datagram;
    cv::Mat img2;//***********
    bool is_door_detected;
};

/*! \def ProcessorMulti_Processor_doordetection_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Processor_doordetection_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
