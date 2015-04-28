//You need to modify this file.

#ifndef VISUALIZATIONMONO_PROCESSOR_PATHGENERATOR_PARAMSDATA_H
#define VISUALIZATIONMONO_PROCESSOR_PATHGENERATOR_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_PathGenerator_ParamsData VisualizationMono_Processor_PathGenerator_ParamsData
	\ingroup VisualizationMono_Processor_PathGenerator
	\brief VisualizationMono_Processor_PathGenerator_ParamsData defines the ParamsData in VisualizationMono_Processor_PathGenerator.
*/

/*! \addtogroup VisualizationMono_Processor_PathGenerator_ParamsData
	@{
*/

/*! \file VisualizationMono_Processor_PathGenerator_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Processor_PathGenerator
*/

//*******************Please add other headers below*******************
#include "glviewer.h"

//2 input data header(s) refered

//Defines Params ProcessorMono_Processor_PathGenerator_Params and Input Data ProcessorMono_Processor_PathGenerator_Data
#include<wheelchair/Processor/PathGenerator/ProcessorMono/Edit/ProcessorMono_Processor_PathGenerator_ParamsData.h>
//Defines Params SourceDrainMono_Sensor_stm32comm_Params and Input Data SourceDrainMono_Sensor_stm32comm_Data
#include<wheelchair/Sensor/stm32comm/SourceDrainMono/Edit/SourceDrainMono_Sensor_stm32comm_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Processor_PathGenerator_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMono_Processor_PathGenerator_Params, Data_Type = ProcessorMono_Processor_PathGenerator_Data
*/
#define VisualizationMono_Processor_PathGenerator_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class VisualizationMono_Processor_PathGenerator_Params 
	\brief The Params of VisualizationMono_Processor_PathGenerator.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Processor_PathGenerator_Params 
{
public:
	/*! \fn VisualizationMono_Processor_PathGenerator_Params()
		\brief The constructor of VisualizationMono_Processor_PathGenerator_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Processor_PathGenerator_Params() 
	{
        loadOfflineData = 0;
	}
	/*! \fn ~VisualizationMono_Processor_PathGenerator_Params()
		\brief The destructor of VisualizationMono_Processor_PathGenerator_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Processor_PathGenerator_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int loadOfflineData;
};

//There is no Output Data.

/*! \def VisualizationMono_Processor_PathGenerator_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Processor_PathGenerator_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
