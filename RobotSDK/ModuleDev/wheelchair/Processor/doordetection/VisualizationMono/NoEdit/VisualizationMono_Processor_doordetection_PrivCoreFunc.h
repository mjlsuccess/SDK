//You need not to modify this file.

/*! \defgroup VisualizationMono_Processor_doordetection VisualizationMono_Processor_doordetection
	\ingroup VisualizationMono_Library Processor_doordetection_NodeClass
	\brief VisualizationMono_Processor_doordetection defines the Processor_doordetection in VisualizationMono.
*/

#ifndef VISUALIZATIONMONO_PROCESSOR_DOORDETECTION_PRIVCOREFUNC_H
#define VISUALIZATIONMONO_PROCESSOR_DOORDETECTION_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_doordetection_PrivCoreFunc VisualizationMono_Processor_doordetection_PrivCoreFunc
	\ingroup VisualizationMono_Processor_doordetection
	\brief VisualizationMono_Processor_doordetection_PrivCoreFunc defines the PrivCoreFunc in VisualizationMono_Processor_doordetection.
*/

/*! \addtogroup VisualizationMono_Processor_doordetection_PrivCoreFunc
	@{
*/

/*! \file VisualizationMono_Processor_doordetection_PrivCoreFunc.h
	 Defines the PrivCoreFunc of VisualizationMono_Processor_doordetection
*/

//*******************Please add other headers below*******************


#include "../Edit/VisualizationMono_Processor_doordetection_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG VisualizationMono_Processor_doordetection

/*! void VisualizationMono_Processor_doordetection_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void VisualizationMono_Processor_doordetection_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void VisualizationMono_Processor_doordetection_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif