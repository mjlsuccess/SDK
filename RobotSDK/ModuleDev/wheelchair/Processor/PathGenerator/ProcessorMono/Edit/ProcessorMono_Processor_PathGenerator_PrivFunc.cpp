//You need to program this file.

#include "../NoEdit/ProcessorMono_Processor_PathGenerator_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMono_Processor_PathGenerator_Params * params=(ProcessorMono_Processor_PathGenerator_Params *)paramsPtr;
	ProcessorMono_Processor_PathGenerator_Vars * vars=(ProcessorMono_Processor_PathGenerator_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
	
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMono_Processor_PathGenerator_Params * params=(ProcessorMono_Processor_PathGenerator_Params *)paramsPtr;
	ProcessorMono_Processor_PathGenerator_Vars * vars=(ProcessorMono_Processor_PathGenerator_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
	
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	ProcessorMono_Processor_PathGenerator_Params * params=(ProcessorMono_Processor_PathGenerator_Params *)paramsPtr;
	ProcessorMono_Processor_PathGenerator_Vars * vars=(ProcessorMono_Processor_PathGenerator_Vars *)varsPtr;
	internalTrigger=NULL;
	internalTriggerSignal=QString();
	/*======Occasionally Program above======*/
	/*
	Function: get internal trigger [defined in vars] for node.
	You need to program here when you need internal trigger (internalTrigger + internalTriggerSignal) for node.
	E.g.
	internalTrigger=&(vars->trigger);
	internalTriggerSignal=QString(SIGNAL(triggerSignal()));
	*/
}

void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
{
	ProcessorMono_Processor_PathGenerator_Params * params=(ProcessorMono_Processor_PathGenerator_Params *)paramsPtr;
	ProcessorMono_Processor_PathGenerator_Vars * vars=(ProcessorMono_Processor_PathGenerator_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMono_Processor_PathGenerator_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMonoInputDataSize)(void * paramsPtr, void * varsPtr, int & inputDataSize)
{
	ProcessorMono_Processor_PathGenerator_Params * params=(ProcessorMono_Processor_PathGenerator_Params *)paramsPtr;
	ProcessorMono_Processor_PathGenerator_Vars * vars=(ProcessorMono_Processor_PathGenerator_Vars *)varsPtr;
	inputDataSize=0;
	/*======Please Program above======*/
	/*
	Function: get input data size to be grabbed from buffer.
	Rules:
	inputDataSize=0: grab and remove all data from buffer.
	inputDataSize>0: grab inputDataSize latest data from buffer.
	inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
	*/
}

//Input Port #0: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
bool DECOFUNC(processMonoInputData)(void * paramsPtr, void * varsPtr, QVector<void *> inputParams, QVector<void *> inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMono_Processor_PathGenerator_Params * params=(ProcessorMono_Processor_PathGenerator_Params *)paramsPtr;
	ProcessorMono_Processor_PathGenerator_Vars * vars=(ProcessorMono_Processor_PathGenerator_Vars *)varsPtr;
	QVector<SourceDrainMono_Sensor_stm32comm_Params *> inputparams; copyQVector(inputparams,inputParams);
	QVector<SourceDrainMono_Sensor_stm32comm_Data *> inputdata; copyQVector(inputdata,inputData);
	ProcessorMono_Processor_PathGenerator_Data * outputdata=(ProcessorMono_Processor_PathGenerator_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    PG_kelly pg;
    trajec_state startState = {0.0, 0.0, PI / 2, 0}, endState = {0.7, 2, PI / 2 , 0};


    for (int i = 0; i < outputdata->trajSets.size(); i++)
        outputdata->trajSets[i].clear();
    outputdata->trajSets.clear();

    for (int i = -10; i <= 10; i++)
        {
            QVector<trajec_state> tmp;
            trajec_state traj;
            tmp.clear();

            endState.x = i * 0.1;
            qDebug() << pg.Path_Generating(startState, endState);
            qDebug() << pg.state_data.size();
            int num = pg.state_data.size();
            for (int i = 0; i < num; i++)
            {
                traj.x = pg.state_data[i].x;
                traj.y = pg.state_data[i].y;
                tmp.push_back(traj);
            }
            outputdata->trajSets.push_back(tmp);
        }
	return 1;
}

