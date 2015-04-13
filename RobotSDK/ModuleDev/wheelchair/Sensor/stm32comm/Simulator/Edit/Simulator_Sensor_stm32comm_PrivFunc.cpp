//You need to program this file.

#include "../NoEdit/Simulator_Sensor_stm32comm_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	Simulator_Sensor_stm32comm_Params * params=(Simulator_Sensor_stm32comm_Params *)paramsPtr;
	Simulator_Sensor_stm32comm_Vars * vars=(Simulator_Sensor_stm32comm_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, path);
    GetParamValue(xmlloader, params, filename);

    QString filename = QString("%1/%2").arg(params->path).arg(params->filename);

    QFile odomsimu;
    QTextStream textstream;
    odomsimu.setFileName(filename);
    if (!odomsimu.open(QFile::ReadOnly | QFile::Text))
    {
        return 0;
    }
    textstream.setDevice(&(odomsimu));

    vars->ComDataIndex = 0;
    vars->AllComData.clear();

    SourceDrainMono_Sensor_stm32comm_Data OneComData;
    textstream.readLine();
    while (!textstream.atEnd())
    {
        int ltimestamp;
        textstream >> ltimestamp
                >> OneComData.x
                >> OneComData.y
                >> OneComData.theta
                >> OneComData.yaw
                >> OneComData.leftodom
                >> OneComData.rightodom;

        //ÊäÈë Ÿø¶Ô×ø±ê£¬ºœÏòœÇ£¬ËÙ¶È£¬×ÜÀï³Ì
        OneComData.timestamp = QTime::fromMSecsSinceStartOfDay(ltimestamp);
        //AllComDataÖÐµÄËùÓÐ³ÉÔ±ÊÇÃ¿Ò»Ê±¿ÌµÄÊýŸÝ
        vars->AllComData.push_back(OneComData);
    }
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	Simulator_Sensor_stm32comm_Params * params=(Simulator_Sensor_stm32comm_Params *)paramsPtr;
	Simulator_Sensor_stm32comm_Vars * vars=(Simulator_Sensor_stm32comm_Vars *)varsPtr;
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
	Simulator_Sensor_stm32comm_Params * params=(Simulator_Sensor_stm32comm_Params *)paramsPtr;
	Simulator_Sensor_stm32comm_Vars * vars=(Simulator_Sensor_stm32comm_Vars *)varsPtr;
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
	Simulator_Sensor_stm32comm_Params * params=(Simulator_Sensor_stm32comm_Params *)paramsPtr;
	Simulator_Sensor_stm32comm_Vars * vars=(Simulator_Sensor_stm32comm_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SourceDrainMono_Sensor_stm32comm_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	Simulator_Sensor_stm32comm_Params * params=(Simulator_Sensor_stm32comm_Params *)paramsPtr;
	Simulator_Sensor_stm32comm_Vars * vars=(Simulator_Sensor_stm32comm_Vars *)varsPtr;
	SourceDrainMono_Sensor_stm32comm_Data * outputdata=(SourceDrainMono_Sensor_stm32comm_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    if (vars->ComDataIndex >= vars->AllComData.size())
    {
        timeStamp = QTime();
        return 0;
    }

    *outputdata = vars->AllComData[vars->ComDataIndex];
    timeStamp = outputdata->timestamp;
    vars->ComDataIndex ++;
	return 1;
}

