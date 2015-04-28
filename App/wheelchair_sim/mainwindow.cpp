#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MONITOR = 1;
QString library = "wheelchair";
QString config = "config.xml";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->starttime->setText("0");
    ui->simurate->setText("1");

    ///create node
    //STM32 MCU
    Simulator* stm32comm = new Simulator(library, "Sensor_stm32comm", "stm32comm", config, QTime(),1);
    stm32comm->setOutputNodesName(QList<QString>()<<"stm32comm_viewer;stm32comm_storage;doordetection;simplecollect;planner");


    VisualizationMono* stm32comm_viewer = new VisualizationMono(library, "Sensor_stm32comm", "stm32comm_viewer", config);
    stm32comm_viewer->setInputNodesName(QList<QString>()<<"stm32comm");
    stm32comm_viewer->connectExternalTrigger(0, DRAINSLOT);

    //LCamera
    Simulator* l_camera = new Simulator(library, "Sensor_Camera", "l_camera", config, QTime(),1);
    l_camera->setOutputNodesName(QList<QString>()<<"l_camera_viewer;l_camera_storage;cameralasercalib");

    VisualizationMono* l_camera_viewer = new VisualizationMono(library, "Sensor_Camera", "l_camera_viewer", config);
    l_camera_viewer->setInputNodesName(QList<QString>()<<"l_camera");
    l_camera_viewer->connectExternalTrigger(0, DRAINSLOT);


    //RCamera
    Simulator* r_camera = new Simulator(library, "Sensor_Camera", "r_camera",config, QTime(),1);
    r_camera->setOutputNodesName(QList<QString>()<<"r_camera_viewer");

    VisualizationMono*r_camera_viewer = new VisualizationMono(library, "Sensor_Camera", "r_camera_viewer", config);
    r_camera_viewer->setInputNodesName(QList<QString>()<<"r_camera");
    r_camera_viewer->connectExternalTrigger(0, DRAINSLOT);


    //Laser
    Simulator* laser = new Simulator(library, "Sensor_Laser", "laser", config, QTime(),1);
    laser->setOutputNodesName(QList<QString>()<<"laser_viewer;doordetection;simplecollect;calib;cameralasercalib");

    VisualizationMono* laser_viewer = new VisualizationMono(library, "Sensor_Laser", "laser_viewer", config);
    laser_viewer->setInputNodesName(QList<QString>()<<"laser");
    laser_viewer->connectExternalTrigger(0, DRAINSLOT);

    //camera laser calib
    ProcessorMulti* cameralasercalib = new ProcessorMulti(library, "Processor_CameraLaser", "cameralasercalib", config);
    cameralasercalib->setInputNodesName(QList<QString>()<<"l_camera"<<"laser");
    cameralasercalib->setOutputNodesName(QList<QString>()<<"cameralasercalib_viewer");
    cameralasercalib->connectExternalTrigger(1,PROCESSORSLOT);

    VisualizationMono *cameralasercalib_viewer = new VisualizationMono(library, "Processor_CameraLaser", "cameralasercalib_viewer", config);
    cameralasercalib_viewer->setInputNodesName(QList<QString>()<<"cameralasercalib");
    cameralasercalib_viewer->connectExternalTrigger(0, DRAINSLOT);

    //calibration
    VisualizationMono *laserCalib = new VisualizationMono(library, "Calibration_Laser", "calib", config);
    laserCalib->setInputNodesName(QList<QString>()<<"laser");
    laserCalib->connectExternalTrigger(0, DRAINSLOT);

    //Path
    ProcessorMono* pathPlanner = new ProcessorMono(library, "Processor_PathGenerator", "planner", config);
    pathPlanner->setInputNodesName(QList<QString>() << "stm32comm");
    pathPlanner->setOutputNodesName(QList<QString>() << "plannerViewer");
    pathPlanner->connectExternalTrigger(0, PROCESSORSLOT);

    VisualizationMono* pathPlannerViewer = new VisualizationMono(library, "Processor_PathGenerator", "plannerViewer", config);
    pathPlannerViewer->setInputNodesName(QList<QString>() << "planner");
    pathPlannerViewer->connectExternalTrigger(0, DRAINSLOT);


    //doordetection
    ProcessorMulti* doordetection = new ProcessorMulti(library,"Processor_doordetection", "doordetection",config);
    doordetection->setInputNodesName(QList<QString>()<<"laser"<<"stm32comm");
    doordetection->setOutputNodesName(QList<QString>()<<"doordetection_viewer;simplecollect");
    doordetection->connectExternalTrigger(1, PROCESSORSLOT);

    VisualizationMono* doordetection_viewer = new VisualizationMono(library,"Processor_doordetection", "doordetection_viewer", config);
    doordetection_viewer->setInputNodesName(QList<QString>()<<"doordetection");
    doordetection_viewer->connectExternalTrigger(0,DRAINSLOT);

    //simple collect
    ProcessorMulti* simplecollect = new ProcessorMulti(library,"Processor_SimpleCollect", "simplecollect", config);
    simplecollect->setInputNodesName(QList<QString>()<<"joystick"<<"laser"<<"stm32comm"<<"doordetection");
    simplecollect->setOutputNodesName(QList<QString>()<<"simplecollect_viewer");
    simplecollect->connectExternalTrigger(2, PROCESSORSLOT);

    VisualizationMono* simplecollect_viewer = new VisualizationMono(library,"Processor_SimpleCollect", "simplecollect_viewer",config);
    simplecollect_viewer->setInputNodesName(QList<QString>()<<"simplecollect");
    simplecollect_viewer->connectExternalTrigger(0,DRAINSLOT);

    ///add node
    edge.addNode(stm32comm, 1, MONITOR);
    edge.addNode(stm32comm_viewer, 0, 0);


    edge.addNode(l_camera, 1, MONITOR);
    edge.addNode(l_camera_viewer, 0, 0);

    edge.addNode(r_camera, 1, MONITOR);
    edge.addNode(r_camera_viewer, 0, 0);


    edge.addNode(laser, 1, MONITOR);
    edge.addNode(laser_viewer, 0, 0);

    edge.addNode(pathPlanner, 1, MONITOR);
    edge.addNode(pathPlannerViewer, 0, 0);


    edge.addNode(doordetection, 1, MONITOR);
    edge.addNode(doordetection_viewer, 0, 0);

    edge.addNode(cameralasercalib, 1, MONITOR);
    edge.addNode(cameralasercalib_viewer, 0, 0);

//    edge.addNode(simplecollect, 1, MONITOR);
//    edge.addNode(simplecollect_viewer, 0, 0);

    edge.addNode(laserCalib, 0, 0);

    edge.connectAll();

    connect(ui->open, SIGNAL(clicked()), &edge, SLOT(openAllNodesSlot()));
    connect(ui->close, SIGNAL(clicked()), &edge, SLOT(closeAllNodesSlot()));

    connect(ui->setvale, SIGNAL(clicked()), this, SLOT(on_setvalue()));
    connect(this, SIGNAL(sig_setstarttime(QTime)), stm32comm, SLOT(setStartTimeSlot(QTime)));
    connect(this,SIGNAL(sig_setsimurate(double)), stm32comm, SLOT(setSimulateRateSlot(double)));
    connect(this, SIGNAL(sig_setstarttime(QTime)), l_camera, SLOT(setStartTimeSlot(QTime)));
    connect(this,SIGNAL(sig_setsimurate(double)), l_camera, SLOT(setSimulateRateSlot(double)));
    connect(this, SIGNAL(sig_setstarttime(QTime)), r_camera, SLOT(setStartTimeSlot(QTime)));
    connect(this,SIGNAL(sig_setsimurate(double)), r_camera, SLOT(setSimulateRateSlot(double)));
    connect(this, SIGNAL(sig_setstarttime(QTime)), laser, SLOT(setStartTimeSlot(QTime)));
    connect(this,SIGNAL(sig_setsimurate(double)), laser, SLOT(setSimulateRateSlot(double)));

    connect(ui->sync, SIGNAL(clicked()), this, SLOT(on_sync()));
    connect(this, SIGNAL(sig_sync()), stm32comm, SLOT(syncTimeTrackSlot()));
    connect(this, SIGNAL(sig_sync()), l_camera, SLOT(syncTimeTrackSlot()));
    connect(this, SIGNAL(sig_sync()), r_camera, SLOT(syncTimeTrackSlot()));
    connect(this, SIGNAL(sig_sync()), laser, SLOT(syncTimeTrackSlot()));

    connect(ui->start, SIGNAL(clicked()), this, SLOT(on_start()));
    connect(this, SIGNAL(sig_start()), stm32comm, SLOT(startSimulatorSlot()));
    connect(this, SIGNAL(sig_start()), l_camera, SLOT(startSimulatorSlot()));
    connect(this, SIGNAL(sig_start()), r_camera, SLOT(startSimulatorSlot()));
    connect(this, SIGNAL(sig_start()), laser, SLOT(startSimulatorSlot()));

    connect(ui->stop, SIGNAL(clicked()), this, SLOT(on_stop()));
    connect(this, SIGNAL(sig_stop()), stm32comm, SLOT(stopSimulatorSlot()));
    connect(this, SIGNAL(sig_stop()), l_camera, SLOT(stopSimulatorSlot()));
    connect(this, SIGNAL(sig_stop()), r_camera, SLOT(stopSimulatorSlot()));
    connect(this, SIGNAL(sig_stop()), laser, SLOT(stopSimulatorSlot()));

    connect(ui->reset, SIGNAL(clicked()), this, SLOT(on_reset()));
    connect(this, SIGNAL(sig_sync()), stm32comm, SLOT(resetTimeTrackSlot()));
    connect(this, SIGNAL(sig_sync()), l_camera, SLOT(resetTimeTrackSlot()));
    connect(this, SIGNAL(sig_sync()), r_camera, SLOT(resetTimeTrackSlot()));
    connect(this, SIGNAL(sig_sync()), laser, SLOT(resetTimeTrackSlot()));

    ///visualazition
    QList<QWidget *> widgets;

    widgets = stm32comm_viewer->getVisualizationWidgets();
    ui->scrollArea->setWidget(widgets.front());

    widgets = laser_viewer->getVisualizationWidgets();
    ui->scrollArea_2->setWidget(widgets.front());

 //   widgets = laserCalib->getVisualizationWidgets();
 //   ui->scrollArea_3->setWidget(widgets.front());
    widgets =cameralasercalib_viewer->getVisualizationWidgets();
    ui->scrollArea_3->setWidget(widgets.front());

    widgets = l_camera_viewer->getVisualizationWidgets();
    ui->scrollArea_4->setWidget(widgets.front());

    widgets = r_camera_viewer->getVisualizationWidgets();
    ui->scrollArea_5->setWidget(widgets.front());

    widgets = doordetection_viewer->getVisualizationWidgets();
    ui->scrollArea_6->setWidget(widgets.front());

    widgets = pathPlannerViewer->getVisualizationWidgets();
    ui->scrollArea_7->setWidget(widgets.front());

//    widgets = simplecollect_viewer->getVisualizationWidgets();
//    ui->scrollArea_8->setWidget(widgets.front());

    if(MONITOR)
        ui->tabWidget->addTab(&edge, "Monitor");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start()
{
    emit sig_start();
}

void MainWindow::on_stop()
{
    emit sig_stop();
}

void MainWindow::on_sync()
{
    emit sig_sync();
}

void MainWindow::on_reset()
{
    emit sig_reset();
}

void MainWindow::on_setvalue()
{
    emit sig_setstarttime(QTime::fromMSecsSinceStartOfDay(ui->starttime->text().toInt()));
    emit sig_setsimurate(ui->simurate->text().toDouble());
}
