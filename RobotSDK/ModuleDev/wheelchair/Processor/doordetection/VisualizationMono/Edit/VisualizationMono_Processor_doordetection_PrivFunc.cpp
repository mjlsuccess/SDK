//You need to program this file.

#include "../NoEdit/VisualizationMono_Processor_doordetection_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Processor_doordetection_Params * params=(VisualizationMono_Processor_doordetection_Params *)paramsPtr;
	VisualizationMono_Processor_doordetection_Vars * vars=(VisualizationMono_Processor_doordetection_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    vars->limage->setText("Viewer Opened");
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Processor_doordetection_Params * params=(VisualizationMono_Processor_doordetection_Params *)paramsPtr;
	VisualizationMono_Processor_doordetection_Vars * vars=(VisualizationMono_Processor_doordetection_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->limage->setText("Viewer Closed");
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Processor_doordetection_Params * params=(VisualizationMono_Processor_doordetection_Params *)paramsPtr;
	VisualizationMono_Processor_doordetection_Vars * vars=(VisualizationMono_Processor_doordetection_Vars *)varsPtr;
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

void DECOFUNC(getMonoDrainDataSize)(void * paramsPtr, void * varsPtr, int & drainDataSize)
{
	VisualizationMono_Processor_doordetection_Params * params=(VisualizationMono_Processor_doordetection_Params *)paramsPtr;
	VisualizationMono_Processor_doordetection_Vars * vars=(VisualizationMono_Processor_doordetection_Vars *)varsPtr;
	drainDataSize=0;
	/*======Please Program above======*/
	/*
	Function: get drain data size to be grabbed from buffer.
	Rules:
	drainDataSize=0: grab and remove all data from buffer.
	drainDataSize>0: grab drainDataSize latest data from buffer.
	drainDataSize<0: grab and remove drainDataSize ancient data from buffer.
	*/
}

//Input Port #0: Buffer_Size = 1, Params_Type = ProcessorMulti_Processor_doordetection_Params, Data_Type = ProcessorMulti_Processor_doordetection_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Processor_doordetection_Params * params=(VisualizationMono_Processor_doordetection_Params *)paramsPtr;
	VisualizationMono_Processor_doordetection_Vars * vars=(VisualizationMono_Processor_doordetection_Vars *)varsPtr;
	QVector<ProcessorMulti_Processor_doordetection_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMulti_Processor_doordetection_Data *> draindata; copyQVector(draindata,drainData);
    if(draindata.size()==0){
        vars->limage->setText("No Data");
        return 0;
    }
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    cv::Mat tmpimg;

    cv::cvtColor(draindata.front()->img2,tmpimg,CV_GRAY2BGR);


    QImage colorimg=QImage((const uchar*)(tmpimg.data),tmpimg.cols,tmpimg.rows, tmpimg.cols*tmpimg.channels(),QImage::Format_RGB888);
    vars->limage->setPixmap(QPixmap::fromImage(colorimg));
	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Processor_doordetection_Params * params=(VisualizationMono_Processor_doordetection_Params *)paramsPtr;
	VisualizationMono_Processor_doordetection_Vars * vars=(VisualizationMono_Processor_doordetection_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<(vars->limage);;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

