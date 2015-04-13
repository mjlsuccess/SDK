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

private:
    Ui::MainWindow *ui;

public:
    Edge edge;
    QTimer commSourceTimer;
    QTimer laserTmer;
signals:
    void sig_timerstart();
    void sig_timerstop();
public slots:
//    void on_open_clicked();
//    void on_close_clicked();
    void on_start_clicked();
    void on_stop_clicked();
//    void on_reset_clicked();
};

#endif // MAINWINDOW_H
