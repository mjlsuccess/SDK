//Generally you need not to program this file.

#include "StorageMono_Sensor_Joystick_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=StorageMono_Sensor_Joystick_INPUTPORTSSIZE;
	outputPortsNumber=StorageMono_Sensor_Joystick_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new StorageMono_Sensor_Joystick_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new StorageMono_Sensor_Joystick_Vars());
	/*======No Need to Program======*/
}

