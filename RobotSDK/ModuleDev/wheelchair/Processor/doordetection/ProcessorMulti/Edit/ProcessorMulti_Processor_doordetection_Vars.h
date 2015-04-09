//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_DOORDETECTION_VARS_H
#define PROCESSORMULTI_PROCESSOR_DOORDETECTION_VARS_H

#include<RobotSDK_Global.h>
#include<QMediaPlayer>
/*! \defgroup ProcessorMulti_Processor_doordetection_Vars ProcessorMulti_Processor_doordetection_Vars
	\ingroup ProcessorMulti_Processor_doordetection
	\brief ProcessorMulti_Processor_doordetection_Vars defines the Vars in ProcessorMulti_Processor_doordetection.
*/

/*! \addtogroup ProcessorMulti_Processor_doordetection_Vars
	@{
*/

/*! \file ProcessorMulti_Processor_doordetection_Vars.h
	 Defines the Vars of ProcessorMulti_Processor_doordetection
*/

//*******************Please add other headers below*******************
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "ProcessorMulti_Processor_doordetection_ParamsData.h"

//The Vars is defined as below
/*! \class ProcessorMulti_Processor_doordetection_Vars 
	\brief The Vars of ProcessorMulti_Processor_doordetection.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_doordetection_Vars 
{
public:
	/*! \fn ProcessorMulti_Processor_doordetection_Vars()
		\brief The constructor of ProcessorMulti_Processor_doordetection_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_doordetection_Vars() 
	{
        PI = 3.14159265358979;
        unit = 100;
        tag = 0;
        current = 0;
        IMUx_0 = 0;
        IMUy_0 = 0;
        //img = cv::Mat::zeros(params->map_size,SIZE_OF_GRID1,CV_8UC1);
	}
	/*! \fn ~ProcessorMulti_Processor_doordetection_Vars()
		\brief The destructor of ProcessorMulti_Processor_doordetection_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_doordetection_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int datatemp[100][600][2];
    cv::Mat img;
    double IMUx_0,IMUy_0;
    int unit;
    double PI;
    int tag;
    int current;

    QMediaPlayer mediaplayer;
    QTime startplaytime;
    bool isPlay;
};

/*! @}*/ 

#endif
