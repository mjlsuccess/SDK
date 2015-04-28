//You need to modify this file.

#ifndef VISUALIZATIONMONO_PROCESSOR_PATHGENERATOR_VARS_H
#define VISUALIZATIONMONO_PROCESSOR_PATHGENERATOR_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_PathGenerator_Vars VisualizationMono_Processor_PathGenerator_Vars
	\ingroup VisualizationMono_Processor_PathGenerator
	\brief VisualizationMono_Processor_PathGenerator_Vars defines the Vars in VisualizationMono_Processor_PathGenerator.
*/

/*! \addtogroup VisualizationMono_Processor_PathGenerator_Vars
	@{
*/

/*! \file VisualizationMono_Processor_PathGenerator_Vars.h
	 Defines the Vars of VisualizationMono_Processor_PathGenerator
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Processor_PathGenerator_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Processor_PathGenerator_Vars 
	\brief The Vars of VisualizationMono_Processor_PathGenerator.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Processor_PathGenerator_Vars 
{
public:
	/*! \fn VisualizationMono_Processor_PathGenerator_Vars()
		\brief The constructor of VisualizationMono_Processor_PathGenerator_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Processor_PathGenerator_Vars() 
	{
        glview = new GLViewer();
        shownum = 5;
        glview->makeCurrent();

       movingTraj.clear();
    }
	/*! \fn ~VisualizationMono_Processor_PathGenerator_Vars()
		\brief The destructor of VisualizationMono_Processor_PathGenerator_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Processor_PathGenerator_Vars() 
	{
        glview->clearDisplayList();
        if(glview->parent() ==NULL)
            delete glview;
        movingTraj.clear();
	}
public:
	//*******************Please add variables below*******************
    GLViewer *glview;
    GLuint shownum;
    GLuint displaylistbase;
    QVector<trajec_state> movingTraj;
};

/*! @}*/ 

#endif
