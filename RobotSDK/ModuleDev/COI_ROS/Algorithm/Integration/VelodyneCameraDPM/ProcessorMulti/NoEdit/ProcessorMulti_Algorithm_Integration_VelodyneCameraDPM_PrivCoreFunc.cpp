//Generally you need not to program this file.

#include "ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_INPUTPORTSSIZE;
	outputPortsNumber=ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new ProcessorMulti_Algorithm_Integration_VelodyneCameraDPM_Vars());
	/*======No Need to Program======*/
}

