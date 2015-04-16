//You need to program this file.

#include "../NoEdit/ProcessorMulti_Processor_doordetection_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Processor_doordetection_Params * params=(ProcessorMulti_Processor_doordetection_Params *)paramsPtr;
	ProcessorMulti_Processor_doordetection_Vars * vars=(ProcessorMulti_Processor_doordetection_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, map_size);
    GetParamValue(xmlloader, params, pixel_per_meter);

    GetParamValue(xmlloader, params, mediapath);
    GetParamValue(xmlloader, params, startmusicfilename);
    GetParamValue(xmlloader, params, endmusicfilename);

    vars->img = cv::Mat(params->map_size,params->map_size,CV_8UC3);
    vars->img.setTo(cv::Scalar(0,0,0));

    vars->isPlay = 0;

    QString filename = params->mediapath+"/"+params->startmusicfilename;
    vars->mediaplayer.setMedia(QUrl::fromLocalFile(QFileInfo(filename).absoluteFilePath()));

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMulti_Processor_doordetection_Params * params=(ProcessorMulti_Processor_doordetection_Params *)paramsPtr;
	ProcessorMulti_Processor_doordetection_Vars * vars=(ProcessorMulti_Processor_doordetection_Vars *)varsPtr;
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
	ProcessorMulti_Processor_doordetection_Params * params=(ProcessorMulti_Processor_doordetection_Params *)paramsPtr;
	ProcessorMulti_Processor_doordetection_Vars * vars=(ProcessorMulti_Processor_doordetection_Vars *)varsPtr;
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
	ProcessorMulti_Processor_doordetection_Params * params=(ProcessorMulti_Processor_doordetection_Params *)paramsPtr;
	ProcessorMulti_Processor_doordetection_Vars * vars=(ProcessorMulti_Processor_doordetection_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Processor_doordetection_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Processor_doordetection_Params * params=(ProcessorMulti_Processor_doordetection_Params *)paramsPtr;
	ProcessorMulti_Processor_doordetection_Vars * vars=(ProcessorMulti_Processor_doordetection_Vars *)varsPtr;
	inputDataSize=QList<int>();
	/*======Please Program above======*/
	/*
	Function: get input data size to be grabbed from buffer.
	Rules:
	inputDataSize=0: grab and remove all data from buffer.
	inputDataSize>0: grab inputDataSize latest data from buffer.
	inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
	E.g.
	inputDataSize=QList<int>()<<0<<1<<-1...;
	*/
}

int cmp1(const void*a,const void*b)
{
return *(double*)a-*(double*)b;
}
int cmp2(const void*a,const void*b)
{
return *(int*)a-*(int*)b;
}

//Input Port #0: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_Laser_Params, Data_Type = SensorTimer_Sensor_Laser_Data
//Input Port #1: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Processor_doordetection_Params * params=(ProcessorMulti_Processor_doordetection_Params *)paramsPtr;
	ProcessorMulti_Processor_doordetection_Vars * vars=(ProcessorMulti_Processor_doordetection_Vars *)varsPtr;
	QVector<SensorTimer_Sensor_Laser_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<SourceDrainMono_Sensor_stm32comm_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
	QVector<SensorTimer_Sensor_Laser_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<SourceDrainMono_Sensor_stm32comm_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
	ProcessorMulti_Processor_doordetection_Data * outputdata=(ProcessorMulti_Processor_doordetection_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
	if(inputdata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    short steer = 0;
    short speed = 0;
    int URGDataSize = inputdata_0.front()->datasize;
    short URGData[600];
    for (int i = 0; i < URGDataSize; i++)
        URGData[i] = inputdata_0.front()->data[i];

    double IMUx = inputdata_1.front()->x;
    double IMUy = inputdata_1.front()->y;
    double IMUorientation = inputdata_1.front()->theta;

    int door_index_in_URGData = -1;
    int min_dis_to_door = 0x7FFFFFFF;//a large number

    QTime timestamp = QTime::currentTime();
    //ŒÆËãÕÏ°­Îïµã×ø±ê
    outputdata->is_door_detected = 0;
    int knum = vars->current;
    double temp_angle;
    for (int i = 0; i < URGDataSize; i++)
    {
        temp_angle = IMUorientation + (double)i / 360 * vars->PI - vars->PI / 2;
        vars->datatemp[knum][i][0] = (int)((IMUx-vars->IMUx_0 + cos(temp_angle)*URGData[i] / vars->unit) * params->pixel_per_meter);//Ò»Ã×DEFINE_3žñ£¬³õÊŒÎ»ÖÃ£šDEFINE_4,DEFINE_4)
        vars->datatemp[knum][i][1] = (int)((IMUy-vars->IMUy_0 + sin(temp_angle)*URGData[i] / vars->unit) * params->pixel_per_meter);
    }
    vars->current++;
    if (vars->current == 1)//ÀÛŒÓ?ŽÎÊýŸÝ *************************************************   ÐÞžÄÕâÀï
    {
        vars->tag = 1;
        vars->IMUx_0 = IMUx;
        vars->IMUy_0 = IMUy;
    }
    if (vars->tag == 0)
    {

    }
    else
    {
        //
        static double dist_to_wall[10][180];//********************************* ¿ÉÄÜÐèÒªÐÞžÄÊý×éŽóÐ¡ ÔÝÀÛŒÓ ¡¶10×éÊýŸÝ
        static double dist_mid;
        static double dist_error[400];
        static int tx;
        static int ty;


        //žùŸÝ×îÐÂµÄ10×éÊýŸÝ
        //vars->img = cv::Mat::zeros(params->map_size,params->map_size,CV_8UC1);        
        vars->img.setTo(cv::Scalar(0,0,0));
        for (int i = vars->current - 1; i >= 0; i--)
        {
            for (int j = 0; j < 361; j++)//
            {
                tx = vars->datatemp[i][j][0];
                ty = vars->datatemp[i][j][1];
                if(tx < 490 && ty < 490 && tx > -490 && ty > -490)
                    cv::circle(vars->img, cv::Point(tx+params->map_size/2, ty+params->map_size/2),1,cv::Scalar(0,255,0), 1);
                    //vars->img.at<cv::Vec3i>(tx+params->map_size/2,ty+params->map_size/2) = cv::Vec3i(0,255,0);
                    //vars->img.at<unsigned char, 3>(tx+(int)params->map_size/2,ty+(int)params->map_size/2) = cv::Scalar(0,255,0);//ÇœÁÁ¶È********************ÐÞžÄÕâÀï
            }

            for(int j = 1; j < 131; j++)//Ö»ÔÚÒ»¶šœÇ¶ÈÄÚŒì²âÇœÃæ ÔÝ¶š1¶È - 65¶È*********************************  ÐÞžÄÕâÀï
            {
                dist_to_wall[i][j] = (double)URGData[j] * cos((double)j/360*vars->PI);
            }
            qsort((void*)&dist_to_wall[i][1],130,sizeof(double),cmp1);//******************************ÐÞžÄÕâÀï
            dist_mid = dist_to_wall[i][65];//******************************ÐÞžÄÕâÀï
            for(int j = 1; j < 131; j++)//Ö»ÔÚÒ»¶šœÇ¶ÈÄÚŒì²âÒ»±ßµÄÃÅ *********************************  ÐÞžÄÕâÀï
            {
                if((dist_to_wall[i][j] - dist_mid)/vars->unit > 0.2 )//Æ«ÀëŽóÓÚ0.2Ã×
                {
                    tx = vars->datatemp[i][j][0];
                    ty = vars->datatemp[i][j][1];
                    if(tx < 490 && ty < 490 && tx > -490 && ty > -490)
                    {
                        //ÏìÒ»Éù
                        //vars->img.at<unsigned char>(tx+(int)params->map_size/2,ty+(int)params->map_size/2) = cv::Scalar(0,0,255);	//ÃÅÐÎÎïÌåÁÁ¶È********************ÐÞžÄÕâÀï
                        cv::circle(vars->img, cv::Point(tx+params->map_size/2, ty+params->map_size/2),1,cv::Scalar(255,255,255), 1);
                        //vars->img.at<cv::Vec3i>(tx+params->map_size/2,ty+params->map_size/2) = cv::Vec3i(255,0,0);
                        outputdata->is_door_detected = 1;
                        if(door_index_in_URGData == -1)
                        {
                            door_index_in_URGData = j-1;
                        }

                    }

                }
            }
            if(outputdata->is_door_detected == 1)
            {
                temp_angle = IMUorientation - (double)door_index_in_URGData / 360 * vars->PI + vars->PI / 2;
                outputdata->door_x = IMUx + cos(temp_angle)*URGData[ door_index_in_URGData] / vars->unit;
                outputdata->door_y = IMUy + sin(temp_angle)*URGData[ door_index_in_URGData] / vars->unit;
                tx = vars->datatemp[i][door_index_in_URGData][0];
                ty = vars->datatemp[i][door_index_in_URGData][1];
                cv::circle(vars->img, cv::Point(tx+params->map_size/2, ty+params->map_size/2),4,cv::Scalar(255,0,0),4);

            }
            else
            {
                outputdata->door_x= 0;
                outputdata->door_y = 0;
            }
        }
        //»­³ögrid1
//		cv::namedWindow("Test");      //ŽŽœšÒ»žöÃûÎªTestŽ°¿Ú
//		cv::imshow("sw",vars->img);   //Ž°¿ÚÖÐÏÔÊŸÍŒÏñ
        if(outputdata->is_door_detected == 1)
        {
            cv::putText(vars->img, "DOOR",cv::Point(40,40), 1, 1, cv::Scalar(255,0,0),2);
        }
        vars->img.copyTo(outputdata->img2);
        vars->current = 0;
    }

    if(outputdata->is_door_detected == 1)
    {
        vars->mediaplayer.play();
        if(vars->mediaplayer.error()!= QMediaPlayer::NoError)
                return 0;
        vars->isPlay = 1;
        vars->startplaytime = timestamp;
    }
    if(vars->isPlay == 1)
    {
        int timeduration = vars->startplaytime.msecsTo(timestamp);//QTime::currentTime().msecsTo(vars->startplaytime);
        if(timeduration > 2000)
        {
            vars->isPlay = 0;
            vars->mediaplayer.stop();
        }
    }



    //Ð¡³µ¿ØÖÆÃüÁî·¢ËÍ
    char dataput[10];
    dataput[0] = 0xF8;
    dataput[1] = 4;
    *(short*)&dataput[2] = steer;
    *(short*)&dataput[4] = speed;
    dataput[6] = 0x8F;

    outputdata->datagram.append(dataput, 7);
	return 1;
}

