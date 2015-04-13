#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <RobotSDK_Global.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:

    void on_setvalue();
    void on_sync();
    void on_start();
    void on_stop();
    void on_reset();
signals:
    void sig_sync();
    void sig_start();
    void sig_stop();
    void sig_reset();
    void sig_setvalue();
    void sig_setstarttime(QTime starttime);
    void sig_setsimurate(double rate);
private:
    Ui::MainWindow *ui;
    Edge edge;
};

#endif // MAINWINDOW_H
