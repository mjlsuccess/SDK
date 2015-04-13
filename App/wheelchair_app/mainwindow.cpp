#include "mainwindow.h"
#include "ui_mainwindow.h"
bool MONITOR = 1;
bool storage = 1;
int laserInterval = 100;
int commInterval = 80;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString library = "wheelchair";
    QString config = "config.xml";

    commSourceTimer.setInterval(commInterval);
    laserTmer.setInterval(laserInterval);


    SensorInternalEvent* joystick = new SensorInternalEvent(library, "Sensor_Joystick", "joystick", config);
    joystick->setOutputNodesName(QList<QString>()<<"joystick_viewer;stm32comm;simplecollect");


    VisualizationMono* joystick_viewer = new VisualizationMono(library, "Sensor_Joystick", "joystick_viewer", config);
    joystick_viewer->setInputNodesName(QList<QString>()<<"joystick");
    joystick_viewer->connectExternalTrigger(0, DRAINSLOT);

    //STM32 MCU
    SourceDrainMono* stm32comm = new SourceDrainMono(library, "Sensor_stm32comm", "stm32comm", config);
    stm32comm->setInputNodesName(QList<QString>()<<"joystick");
    stm32comm->setOutputNodesName(QList<QString>()<<"stm32comm_viewer;stm32comm_storage;doordetection;simplecollect");
    stm32comm->connectExternalTrigger(0, DRAINSLOT);
    //stm32comm->connectInternalTrigger(SOURCESLOT);
    stm32comm->connectExternalTrigger(&commSourceTimer, SIGNAL(timeout()), SOURCESLOT);

    VisualizationMono* stm32comm_viewer = new VisualizationMono(library, "Sensor_stm32comm", "stm32comm_viewer", config);
    stm32comm_viewer->setInputNodesName(QList<QString>()<<"stm32comm");
    stm32comm_viewer->connectExternalTrigger(0, DRAINSLOT);

    StorageMono* stm32comm_storage = new StorageMono(library, "Sensor_stm32comm", "stm32comm_storage", config);
    stm32comm_storage->setInputNodesName(QList<QString>()<<"stm32comm");
    stm32comm_storage->connectExternalTrigger(0, DRAINSLOT);

    //LCamera
    SensorInternalEvent* l_camera = new SensorInternalEvent(library, "Sensor_Camera", "l_camera", config);
    l_camera->setOutputNodesName(QList<QString>()<<"l_camera_viewer;l_camera_storage");

    VisualizationMono* l_camera_viewer = new VisualizationMono(library, "Sensor_Camera", "l_camera_viewer", config);
    l_camera_viewer->setInputNodesName(QList<QString>()<<"l_camera");
    l_camera_viewer->connectExternalTrigger(0, DRAINSLOT);

    StorageMono* l_camera_storage = new StorageMono(library, "Sensor_Camera", "l_camera_storage", config);
    l_camera_storage->setInputNodesName(QList<QString>()<<"l_camera");
    l_camera_storage->connectExternalTrigger(0, DRAINSLOT);

    //RCamera
    SensorInternalEvent* r_camera = new SensorInternalEvent(library, "Sensor_Camera", "r_camera",config);
    r_camera->setOutputNodesName(QList<QString>()<<"r_camera_viewer;r_camera_storage");

    VisualizationMono*r_camera_viewer = new VisualizationMono(library, "Sensor_Camera", "r_camera_viewer", config);
    r_camera_viewer->setInputNodesName(QList<QString>()<<"r_camera");
    r_camera_viewer->connectExternalTrigger(0, DRAINSLOT);

    StorageMono* r_camera_storage = new StorageMono(library, "Sensor_Camera", "r_camera_storage", config);
    r_camera_storage->setInputNodesName(QList<QString>()<<"r_camera");
    r_camera_storage->connectExternalTrigger(0, DRAINSLOT);

    //LLaser
    SensorTimer* l_laser = new SensorTimer(library, "Sensor_Laser", "l_laser", config,laserInterval);
    l_laser->setOutputNodesName(QList<QString>()<<"l_laser_viewer;l_laser_storage;doordetection;simplecollect");
    l_laser->connectExternalTrigger(&laserTmer, SIGNAL(timeout()), SOURCESLOT);

    VisualizationMono* l_laser_viewer = new VisualizationMono(library, "Sensor_Laser", "l_laser_viewer", config);
    l_laser_viewer->setInputNodesName(QList<QString>()<<"l_laser");
    l_laser_viewer->connectExternalTrigger(0, DRAINSLOT);

    StorageMono* l_laser_storage = new StorageMono(library, "Sensor_Laser", "l_laser_storage", config);
    l_laser_storage->setInputNodesName(QList<QString>()<<"l_laser");
    l_laser_storage->connectExternalTrigger(0,DRAINSLOT);

    //RLaser

    SensorTimer* r_laser = new SensorTimer(library, "Sensor_Laser", "r_laser", config,laserInterval);
    r_laser->setOutputNodesName(QList<QString>()<<"r_laser_viewer;r_laser_storage");
    r_laser->connectExternalTrigger(&laserTmer, SIGNAL(timeout()), SOURCESLOT);

    VisualizationMono* r_laser_viewer = new VisualizationMono(library, "Sensor_Laser", "r_laser_viewer", config);
    r_laser_viewer->setInputNodesName(QList<QString>()<<"r_laser");
    r_laser_viewer->connectExternalTrigger(0, DRAINSLOT);

    StorageMono* r_laser_storage = new StorageMono(library, "Sensor_Laser", "r_laser_storage", config);
    r_laser_storage->setInputNodesName(QList<QString>()<<"r_laser");
    r_laser_storage->connectExternalTrigger(0,DRAINSLOT);

    //doordetection
    ProcessorMulti* doordetection = new ProcessorMulti(library,"Processor_doordetection", "doordetection",config);
    doordetection->setInputNodesName(QList<QString>()<<"l_laser"<<"stm32comm");
    doordetection->setOutputNodesName(QList<QString>()<<"doordetection_viewer;simplecollect");
    doordetection->connectExternalTrigger(1, PROCESSORSLOT);

    VisualizationMono* doordetection_viewer = new VisualizationMono(library,"Processor_doordetection", "doordetection_viewer", config);
    doordetection_viewer->setInputNodesName(QList<QString>()<<"doordetection");
    doordetection_viewer->connectExternalTrigger(0,DRAINSLOT);

    //simple collect
    ProcessorMulti* simplecollect = new ProcessorMulti(library,"Processor_SimpleCollect", "simplecollect", config);
    simplecollect->setInputNodesName(QList<QString>()<<"joystick"<<"l_laser"<<"stm32comm"<<"doordetection");
    simplecollect->setOutputNodesName(QList<QString>()<<"simplecollect_viewer");
    simplecollect->connectExternalTrigger(2, PROCESSORSLOT);

    VisualizationMono* simplecollect_viewer = new VisualizationMono(library,"Processor_SimpleCollect", "simplecollect_viewer",config);
    simplecollect_viewer->setInputNodesName(QList<QString>()<<"simplecollect");
    simplecollect_viewer->connectExternalTrigger(0,DRAINSLOT);



    edge.addNode(joystick, 1, MONITOR);
    edge.addNode(joystick_viewer, 0, 0);

    edge.addNode(stm32comm, 1, MONITOR);
    edge.addNode(stm32comm_viewer, 0, 0);


    edge.addNode(l_camera, 1, MONITOR);
    edge.addNode(l_camera_viewer, 0, 0);

    edge.addNode(r_camera, 1, MONITOR);
    edge.addNode(r_camera_viewer, 0, 0);


    edge.addNode(l_laser, 1, MONITOR);
    edge.addNode(l_laser_viewer, 0, 0);

    edge.addNode(r_laser, 1, MONITOR);
    edge.addNode(r_laser_viewer, 0, 0);

    edge.addNode(doordetection, 1, MONITOR);
    edge.addNode(doordetection_viewer, 0, 0);

    edge.addNode(simplecollect, 1, MONITOR);
    edge.addNode(simplecollect_viewer, 0, 0);


    if(storage)
    {
        edge.addNode(stm32comm_storage, 1, 0);
        edge.addNode(l_camera_storage, 1, 0);
        edge.addNode(r_camera_storage, 1, 0);
        edge.addNode(l_laser_storage, 1, 0);
        edge.addNode(r_laser_storage, 1, 0);
    }

    edge.connectAll();

    connect(ui->open, SIGNAL(clicked()), &edge, SLOT(openAllNodesSlot()));
    connect(ui->close, SIGNAL(clicked()), &edge, SLOT(closeAllNodesSlot()));
    connect(ui->start, SIGNAL(clicked()), this, SLOT(on_start_clicked()));
    connect(ui->stop, SIGNAL(clicked()), this, SLOT(on_stop_clicked()));

    connect(this, SIGNAL(sig_timerstart()), l_laser, SLOT(startTimerSlot()));
    connect(this, SIGNAL(sig_timerstop()), l_laser, SLOT(stopTimerSlot()));

    connect(this, SIGNAL(sig_timerstart()), r_laser, SLOT(startTimerSlot()));
    connect(this, SIGNAL(sig_timerstop()), r_laser, SLOT(stopTimerSlot()));



    QList<QWidget *> widgets;
    widgets = joystick_viewer->getVisualizationWidgets();
    ui->scrollArea->setWidget(widgets.front());

    widgets = stm32comm_viewer->getVisualizationWidgets();
    ui->scrollArea_2->setWidget(widgets.front());

    widgets = l_camera_viewer->getVisualizationWidgets();
    ui->scrollArea_3->setWidget(widgets.front());

    widgets = r_camera_viewer->getVisualizationWidgets();
    ui->scrollArea_4->setWidget(widgets.front());

    widgets = l_laser_viewer->getVisualizationWidgets();
    ui->scrollArea_5->setWidget(widgets.front());

    widgets = r_laser_viewer->getVisualizationWidgets();
    ui->scrollArea_6->setWidget(widgets.front());

    widgets = doordetection_viewer->getVisualizationWidgets();
    ui->scrollArea_7->setWidget(widgets.front());

    widgets = simplecollect_viewer->getVisualizationWidgets();
    ui->scrollArea_8->setWidget(widgets.front());

    if(MONITOR)
        ui->tabWidget->addTab(&edge, "Monitor");

}

void MainWindow::on_start_clicked()
{
    commSourceTimer.start();
    laserTmer.start();
    emit sig_timerstart();
}

void MainWindow::on_stop_clicked()
{
    commSourceTimer.stop();
    laserTmer.stop();
    emit sig_timerstop();
}

MainWindow::~MainWindow()
{
    delete ui;
}
