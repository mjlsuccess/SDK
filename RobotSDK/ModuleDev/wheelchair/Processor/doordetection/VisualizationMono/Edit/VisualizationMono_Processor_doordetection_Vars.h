//You need to modify this file.

#ifndef VISUALIZATIONMONO_PROCESSOR_DOORDETECTION_VARS_H
#define VISUALIZATIONMONO_PROCESSOR_DOORDETECTION_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_doordetection_Vars VisualizationMono_Processor_doordetection_Vars
	\ingroup VisualizationMono_Processor_doordetection
	\brief VisualizationMono_Processor_doordetection_Vars defines the Vars in VisualizationMono_Processor_doordetection.
*/

/*! \addtogroup VisualizationMono_Processor_doordetection_Vars
	@{
*/

/*! \file VisualizationMono_Processor_doordetection_Vars.h
	 Defines the Vars of VisualizationMono_Processor_doordetection
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Processor_doordetection_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Processor_doordetection_Vars 
	\brief The Vars of VisualizationMono_Processor_doordetection.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Processor_doordetection_Vars 
{
public:
	/*! \fn VisualizationMono_Processor_doordetection_Vars()
		\brief The constructor of VisualizationMono_Processor_doordetection_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Processor_doordetection_Vars() 
	{
        limage = new QLabel();
        int i,n=256;
        limage->setAlignment(Qt::AlignCenter);
        i,n=256;
        lcolortable.resize(n);
        for(i=0;i<n;i++)
        {
            lcolortable[i]=qRgb(i,i,i);
        }
	}
	/*! \fn ~VisualizationMono_Processor_doordetection_Vars()
		\brief The destructor of VisualizationMono_Processor_doordetection_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Processor_doordetection_Vars() 
	{
        if(limage->parent() == NULL)
        {
            delete limage;
        }
	}
public:
	//*******************Please add variables below*******************
    QLabel * limage;
    QVector<QRgb> lcolortable;
};

/*! @}*/ 

#endif
