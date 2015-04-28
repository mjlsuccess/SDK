//You need to modify this file.

#ifndef PROCESSORMONO_PROCESSOR_PATHGENERATOR_PARAMSDATA_H
#define PROCESSORMONO_PROCESSOR_PATHGENERATOR_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Processor_PathGenerator_ParamsData ProcessorMono_Processor_PathGenerator_ParamsData
	\ingroup ProcessorMono_Processor_PathGenerator
	\brief ProcessorMono_Processor_PathGenerator_ParamsData defines the ParamsData in ProcessorMono_Processor_PathGenerator.
*/

/*! \addtogroup ProcessorMono_Processor_PathGenerator_ParamsData
	@{
*/

/*! \file ProcessorMono_Processor_PathGenerator_ParamsData.h
	 Defines the ParamsData of ProcessorMono_Processor_PathGenerator
*/

//*******************Please add other headers below*******************
#include "kelly_PG.h"

//1 input data header(s) refered

//Defines Params SourceDrainMono_Sensor_stm32comm_Params and Input Data SourceDrainMono_Sensor_stm32comm_Data
#include<wheelchair/Sensor/stm32comm/SourceDrainMono/Edit/SourceDrainMono_Sensor_stm32comm_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMono_Processor_PathGenerator_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
*/
#define ProcessorMono_Processor_PathGenerator_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class ProcessorMono_Processor_PathGenerator_Params 
	\brief The Params of ProcessorMono_Processor_PathGenerator.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Processor_PathGenerator_Params 
{
public:
	/*! \fn ProcessorMono_Processor_PathGenerator_Params()
		\brief The constructor of ProcessorMono_Processor_PathGenerator_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Processor_PathGenerator_Params() 
	{
		
	}
	/*! \fn ~ProcessorMono_Processor_PathGenerator_Params()
		\brief The destructor of ProcessorMono_Processor_PathGenerator_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Processor_PathGenerator_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class ProcessorMono_Processor_PathGenerator_Data 
	\brief The Data of ProcessorMono_Processor_PathGenerator.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Processor_PathGenerator_Data 
{
public:
	/*! \fn ProcessorMono_Processor_PathGenerator_Data()
		\brief The constructor of ProcessorMono_Processor_PathGenerator_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Processor_PathGenerator_Data() 
	{
        for (int i = 0; i < trajSets.size(); i++)
            trajSets[i].clear();
        trajSets.clear();
        startPoint.x = 0;
        startPoint.y = 0;
        startPoint.theta = M_PI / 2;
	}
	/*! \fn ~ProcessorMono_Processor_PathGenerator_Data()
		\brief The destructor of ProcessorMono_Processor_PathGenerator_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Processor_PathGenerator_Data() 
	{
        for (int i = 0; i < trajSets.size(); i++)
            trajSets[i].clear();
        trajSets.clear();
	}
public:
	//*******************Please add variables below*******************
     QVector<QVector<trajec_state> > trajSets;
     trajec_state startPoint;
};

/*! \def ProcessorMono_Processor_PathGenerator_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMono_Processor_PathGenerator_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
