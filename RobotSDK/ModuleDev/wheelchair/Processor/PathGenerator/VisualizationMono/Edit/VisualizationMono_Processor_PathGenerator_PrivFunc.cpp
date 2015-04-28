//You need to program this file.

#include "../NoEdit/VisualizationMono_Processor_PathGenerator_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Processor_PathGenerator_Params * params=(VisualizationMono_Processor_PathGenerator_Params *)paramsPtr;
	VisualizationMono_Processor_PathGenerator_Vars * vars=(VisualizationMono_Processor_PathGenerator_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,loadOfflineData);
    qDebug() << params->loadOfflineData;
    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Processor_PathGenerator_Params * params=(VisualizationMono_Processor_PathGenerator_Params *)paramsPtr;
	VisualizationMono_Processor_PathGenerator_Vars * vars=(VisualizationMono_Processor_PathGenerator_Vars *)varsPtr;
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
	VisualizationMono_Processor_PathGenerator_Params * params=(VisualizationMono_Processor_PathGenerator_Params *)paramsPtr;
	VisualizationMono_Processor_PathGenerator_Vars * vars=(VisualizationMono_Processor_PathGenerator_Vars *)varsPtr;
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
	VisualizationMono_Processor_PathGenerator_Params * params=(VisualizationMono_Processor_PathGenerator_Params *)paramsPtr;
	VisualizationMono_Processor_PathGenerator_Vars * vars=(VisualizationMono_Processor_PathGenerator_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMono_Processor_PathGenerator_Params, Data_Type = ProcessorMono_Processor_PathGenerator_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Processor_PathGenerator_Params * params=(VisualizationMono_Processor_PathGenerator_Params *)paramsPtr;
	VisualizationMono_Processor_PathGenerator_Vars * vars=(VisualizationMono_Processor_PathGenerator_Vars *)varsPtr;
	QVector<ProcessorMono_Processor_PathGenerator_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMono_Processor_PathGenerator_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    vars->glview->clearDisplayList();
    vars->displaylistbase = glGenLists(vars->shownum);
    for(unsigned int i=0; i<vars->shownum; i++)
    {
        vars->glview->addDisplayList(vars->displaylistbase+i);
    }

    vars->movingTraj.push_back(draindata.front()->startPoint);

    FILE * traj = fopen("traj", "w");
    for (QVector<trajec_state>::iterator pt = vars->movingTraj.begin();
         pt != vars->movingTraj.end(); pt++)
    {
        fprintf(traj, "%lf %lf\n", pt->x, pt->y);
    }
    fclose(traj);



    qDebug() << draindata.front()->startPoint.x << ' ' << draindata.front()->startPoint.y;
    glNewList(vars->displaylistbase,GL_COMPILE_AND_EXECUTE);
    glPushMatrix();
    glLineWidth(1);

    if (params->loadOfflineData)
    {
        FILE *offlinedata = fopen("trajdata", "r");
        if (offlinedata)
        {
            double tx, ty;
            glColor3f(0, 1, 1);
            glBegin(GL_LINE_STRIP);
            while (fscanf(offlinedata, "%lf %lf", &tx, &ty) == 2)
            {
                glVertex3f(tx, ty, 0);
            }
            glEnd();
        }
    }

    glColor3f(1, 0, 0);
    glBegin(GL_LINE_STRIP);
    for (QVector<trajec_state>::iterator pt = vars->movingTraj.begin();
         pt != vars->movingTraj.end(); pt++)
    {
        glVertex3f(pt->x, pt->y, 0);
    }
    glEnd();


    glColor3f(0, 1, 0);

    for (QVector<QVector<trajec_state> >::iterator tlist = draindata.front()->trajSets.begin();
         tlist != draindata.front()->trajSets.end();
         tlist++)
    {
        glBegin(GL_LINE_STRIP);
        for (QVector<trajec_state>::iterator pt = tlist->begin();
             pt != tlist->end(); pt++)
        {
            glVertex3f(pt->x, pt->y, 0);
        }
        glEnd();
    }

    glPopMatrix();
    glEndList();
    vars->glview->update();
    return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Processor_PathGenerator_Params * params=(VisualizationMono_Processor_PathGenerator_Params *)paramsPtr;
	VisualizationMono_Processor_PathGenerator_Vars * vars=(VisualizationMono_Processor_PathGenerator_Vars *)varsPtr;
    widgets=QList<QWidget *>() << vars->glview;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

