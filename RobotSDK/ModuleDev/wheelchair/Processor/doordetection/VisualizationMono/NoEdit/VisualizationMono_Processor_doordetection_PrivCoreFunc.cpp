//Generally you need not to program this file.

#include "VisualizationMono_Processor_doordetection_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=VisualizationMono_Processor_doordetection_INPUTPORTSSIZE;
	outputPortsNumber=VisualizationMono_Processor_doordetection_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new VisualizationMono_Processor_doordetection_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new VisualizationMono_Processor_doordetection_Vars());
	/*======No Need to Program======*/
}

