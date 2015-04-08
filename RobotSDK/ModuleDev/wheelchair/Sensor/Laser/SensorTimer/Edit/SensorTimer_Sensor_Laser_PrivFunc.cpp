//You need to program this file.

#include "../NoEdit/SensorTimer_Sensor_Laser_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorTimer_Sensor_Laser_Params * params=(SensorTimer_Sensor_Laser_Params *)paramsPtr;
	SensorTimer_Sensor_Laser_Vars * vars=(SensorTimer_Sensor_Laser_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetEnumParamValue(xmlloader,vars,connection_type);
    GetParamValue(xmlloader,vars,device_or_address);
    GetParamValue(xmlloader,vars,baudreate_or_port);
    GetEnumParamValue(xmlloader,vars,measurement_type);
    GetParamValue(xmlloader,vars,skip_scan);
    GetParamValue(xmlloader,params,first_step);
    GetParamValue(xmlloader,params,last_step);
    GetParamValue(xmlloader,params,skip_step);
    GetParamValue(xmlloader,params,nearfilter);
    GetParamValue(xmlloader,params,farfilter);
    GetParamValue(xmlloader,params,unit);


    int n=urg_open(&(vars->urg),vars->connection_type,vars->device_or_address.toUtf8().data(),vars->baudreate_or_port);
    if(n<0)
    {
        return 0;
    }
    n=urg_set_scanning_parameter(&(vars->urg),params->first_step,params->last_step,params->skip_step);
    if(n<0)
    {
        return 0;
    }

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorTimer_Sensor_Laser_Params * params=(SensorTimer_Sensor_Laser_Params *)paramsPtr;
	SensorTimer_Sensor_Laser_Vars * vars=(SensorTimer_Sensor_Laser_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    urg_close(&(vars->urg));
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SensorTimer_Sensor_Laser_Params * params=(SensorTimer_Sensor_Laser_Params *)paramsPtr;
	SensorTimer_Sensor_Laser_Vars * vars=(SensorTimer_Sensor_Laser_Vars *)varsPtr;
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
	SensorTimer_Sensor_Laser_Params * params=(SensorTimer_Sensor_Laser_Params *)paramsPtr;
	SensorTimer_Sensor_Laser_Vars * vars=(SensorTimer_Sensor_Laser_Vars *)varsPtr;
    int beamnumber=(params->last_step-params->first_step)/params->skip_step+1;
    outputDataPtr=boost::shared_ptr<void>(new SensorTimer_Sensor_Laser_Data(beamnumber));
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorTimer_Sensor_Laser_Params * params=(SensorTimer_Sensor_Laser_Params *)paramsPtr;
	SensorTimer_Sensor_Laser_Vars * vars=(SensorTimer_Sensor_Laser_Vars *)varsPtr;
	SensorTimer_Sensor_Laser_Data * outputdata=(SensorTimer_Sensor_Laser_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    long * urgdata=new long[outputdata->datasize];
    urg_start_measurement(&(vars->urg),vars->measurement_type,1,vars->skip_scan);
    int n=urg_get_distance(&(vars->urg),urgdata,&(outputdata->timestamp));
    outputdata->qtimestamp=QTime::currentTime();
    if(n<=0||n!=outputdata->datasize)
    {
        return 0;
    }
    int i;
    for(i=0;i<n;i++)
    {
        short distance=short(urgdata[i]/10.0+0.5);
        if(distance<params->nearfilter||distance>params->farfilter)
        {
            outputdata->data[i]=0;
        }
        else
        {
            outputdata->data[i]=distance;
        }
    }
    return 1;
	return 1;
}

