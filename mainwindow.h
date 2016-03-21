#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
//#include "graphph.h"
#include <QtGui>
#include <QtCore>
#include <bcm2835.h>
#include "clicklabel.h"
//#include "passvalue.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    int file;
    char filename[11];
    double pH_Value;
//    passvalue a, b;

    //    QPixmap Green_light;
//    QPixmap Red_light;
//    void paintEvent(QPaintEvent *);
    ~MainWindow();   
public slots:
//    void timecount();
    void ReadDHT22();

protected:

private slots:
    void Write_pH();
    void Graph_pH();
    void setTime();
    void Read_pH(void);
    void SendDHT221();
    void SendDHT222();
    void Mouse_Pressed1();
    void Mouse_Pressed2();
    void Mouse_Pressed3();
    void Mouse_Pressed4();
    void Mouse_Pressed5();
    void Mouse_Released1();
    void Mouse_Released2();
    void Mouse_Released3();
    void Mouse_Released4();
    void Mouse_Released5();
signals:

private:
    Ui::MainWindow *ui;
    QTimer *timer2;
    QTimer *plottimer;
    QTimer *timer;
    QTimer *timer3;
    QTimer *timer_dht1;
    QTimer *timer_dht2;
    QDateTime time;
    bool mouse_clicked1;
    bool mouse_clicked2;
    bool mouse_clicked3;
    bool mouse_clicked4;
    bool mouse_clicked5;
    int bits[250], data[100];
    int bitidx ;
    int i;
    int counter;
    int laststate;
    int j;
    float ph_max,ph_min;
    float pH_border;
//    bool isFirstGraph;
};

#endif // MAINWINDOW_H
