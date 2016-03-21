#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "clicklabel.h"
//#include "passvalue.h"
//#include "timer.h"
#include <iostream>
#include <sstream>
#include <QString>
#include <string>
#include <vector>
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include <QMessageBox>
#include <QDebug>
#include <QThread>
#include <QObject>
#include <QQuickView>
#include "QWidget"
#include <QQmlApplicationEngine>
#include <QPainter>
#include <QPen>
#include <QRect>
#include <QPixmap>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <string.h>
#include <bcm2835.h>

#define BCM2708_PERI_BASE        0x20000000
#define GPIO_BASE                (BCM2708_PERI_BASE + 0x200000) /* GPIO controller */
#define MAXTIMINGS 100
#define pin 22


//#define pinwpump 18
//#define pinphppump 27
//#define pinphdpump 14
//#define pinphppump 15
//#define pinphppump 17

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    this->setStyleSheet();
    //    mouse_clicked1 =0;
    //    mouse_clicked2 =0;
    //    mouse_clicked3 =0;
    //    mouse_clicked4 =0;
    //    mouse_clicked5 =0;
    //    timecounts = 0;
    //    passvalue timec,timeh;
    //    timec.setValue(0);
    sprintf(filename,"/dev/i2c-1");
    file = open(filename,O_RDWR);
    bcm2835_init();
    bcm2835_gpio_fsel(17,BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(27,BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(14,BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(15,BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(18,BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_write(17,HIGH);
    bcm2835_gpio_write(27,HIGH);
    bcm2835_gpio_write(14,HIGH);
    bcm2835_gpio_write(15,HIGH);
    bcm2835_gpio_write(18,HIGH);
    timer = new QTimer(this);
    timer2 = new QTimer(this);
    timer3 = new QTimer(this);
    timer_dht1 = new QTimer(this);
    timer_dht2 = new QTimer(this);
    plottimer = new QTimer(this);
    ph_max = 2;
    ph_min = 0;
    pH_border = 0.2;
    //time label set
    QFont labelfont("Comic Sans MS",12,QFont::Normal);
    ui->timedate->setFont(labelfont);
    ui->timedate->setAlignment(Qt::AlignCenter);
    ui->timedate->setStyleSheet("color:black;");
    // set for graph
    ui->customplot->setLocale(QLocale(QLocale::Thai));
    ui->customplot->addGraph();
    ui->customplot->graph(0)->setPen(QPen(Qt::black));
    //    ui->customplot->graph(0)->setBrush(QBrush(QColor(240, 255, 200)));
    ui->customplot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->customplot->xAxis->setTickLabelFont(QFont("Ubuntu Light",7,QFont::Normal));
    ui->customplot->xAxis->setDateTimeFormat("dd/MMM\nhh:mm");
    ui->customplot->xAxis->setAutoTickStep(true);
    //    ui->customplot->xAxis->setTickStep(300);
    ui->customplot->yAxis->setTickLabelFont(QFont("Ubuntu Light",8,QFont::Normal));
    ui->customplot->xAxis->setLabelFont(QFont("Ubuntu Light",10,QFont::Bold));
    ui->customplot->yAxis->setLabelFont(QFont("Ubuntu Light",10,QFont::Bold));
    ui->customplot->xAxis->setLabel("time");
    ui->customplot->yAxis->setLabel("pH");
    ui->customplot->setBackground(Qt::white);
    ui->customplot->axisRect()->setBackground(Qt::white);
    ui->customplot->yAxis->setRange(ph_min,ph_max);
    QPixmap Pix2(":/red-light.png");
    ui->gr_wP->setPixmap(Pix2);
    ui->gr_pHpp->setPixmap(Pix2);
    ui->gr_pHpn->setPixmap(Pix2);
    ui->gr_fap->setPixmap(Pix2);
    ui->gr_fbp->setPixmap(Pix2);
    //        ui->customplot->axisRect()->setupFullAxesBox();
    //        connect(ui->customplot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customplot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customplot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customplot->yAxis2, SLOT(setRange(QCPRange)));
    connect(timer,SIGNAL(timeout()),this,SLOT(Write_pH()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(Read_pH()));
    connect(plottimer,SIGNAL(timeout()),this,SLOT(Graph_pH()));
    connect(timer3,SIGNAL(timeout()),this,SLOT(setTime()));
    connect(timer,SIGNAL(timeout()),this,SLOT(SendDHT221()));
    connect(timer_dht1,SIGNAL(timeout()),this,SLOT(SendDHT222()));
    connect(timer_dht2,SIGNAL(timeout()),this,SLOT(ReadDHT22()));
    connect(ui->gr_wP,SIGNAL(clicked()),this,SLOT(Mouse_Pressed1()));
    connect(ui->gr_pHpp,SIGNAL(clicked()),this,SLOT(Mouse_Pressed2()));
    connect(ui->gr_pHpn,SIGNAL(clicked()),this,SLOT(Mouse_Pressed3()));
    connect(ui->gr_fap,SIGNAL(clicked()),this,SLOT(Mouse_Pressed4()));
    connect(ui->gr_fbp,SIGNAL(clicked()),this,SLOT(Mouse_Pressed5()));
    connect(ui->gr_wP,SIGNAL(released()),this,SLOT(Mouse_Released1()));
    connect(ui->gr_pHpp,SIGNAL(released()),this,SLOT(Mouse_Released2()));
    connect(ui->gr_pHpn,SIGNAL(released()),this,SLOT(Mouse_Released3()));
    connect(ui->gr_fap,SIGNAL(released()),this,SLOT(Mouse_Released4()));
    connect(ui->gr_fbp,SIGNAL(released()),this,SLOT(Mouse_Released5()));
    //    connect(timer_dht1,SIGNAL(timeout()),this,SLOT(timecount()));
    //    QObject::connect(&a, &passvalue::valueChanged,
    //                     &b, &passvalue::setValue);
    timer->start(5000);
    timer3->start(1000);
}

void MainWindow::Write_pH()
{
    const char *buffer;
    int addr = 0x63;
    int write_to_ph[1] = {0x52}; //r string is to write to ph Sensor
    if (ioctl(file,I2C_SLAVE,addr) < 0) {
        //        cout << "Failed to acquire bus access and/or talk to slave." << endl;
        /* ERROR HANDLING; you can check errno to see what went wrong */
        //        cout << strerror(errno);
        //        cout << errno <<endl;
        QMessageBox::information(this, tr("Hydroponics Box"),tr("Failed to acquire bus access and/or talk to slave."));
    }
    else
    {
        qDebug() << "Success to acquire bus access to slave.";
    }

    if( write(file,write_to_ph,1) != 1)
    {
        QMessageBox::information(this, tr("Hydroponics Box"),tr("Failed to write to the i2c bus.") );
        //        cout << "Failed to write to the i2c bus." << endl;
        buffer = strerror(errno);
        qDebug() << buffer ;
    }
    else
    {
        qDebug() << "Success to write i2c bus" << endl;
        timer2->start(1050);
    }
}

void MainWindow::Read_pH(void)
{
    char buf[33] = {0};
    char buf_pH[6] = {0};
    if(read(file, buf, 32) <1 ) {
        QMessageBox::information(this, tr("Hydroponics Box"),tr("I2C read failed") );
        qDebug() << "I2C Read failed." << endl;
    }
    else{
        qDebug() << "I2C Read Completed" << endl;
        for(int byte=1; byte<6; byte++)
        {
            buf[byte] &= 0x7F;
            buf_pH[byte-1] = buf[byte];
        }
        buf_pH[4] = '\0';
        pH_Value = atof(buf_pH);
        qDebug() << "the ph is" << buf_pH << endl;
        ui->ph_value->setText(buf_pH);
        plottimer->start(0);
    }
    timer2->stop();
}

void MainWindow::Graph_pH()
{
    double recentdata = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    ui->customplot->graph(0)->addData(recentdata,pH_Value);
    ui->customplot->graph(0)->removeDataBefore(recentdata-3000);
    ui->customplot->xAxis->setRange(recentdata,3000,Qt::AlignRight);

    //isFirstGraph

    if(pH_Value < ph_min || ph_min == 0)
    {
        ph_min = pH_Value-pH_border;
        ui->customplot->yAxis->setRange(ph_min,ph_max);
    }

    if(pH_Value > ph_max){
        ph_max = pH_Value+pH_border;
        ui->customplot->yAxis->setRange(ph_min,ph_max);
    }

    ui->customplot->replot();
    plottimer->stop();
}

void MainWindow::setTime()
{
    QDateTime datetime = datetime.currentDateTime();
    QString datetimestr = datetime.toString("dd:MM:yyyy hh:mm");
    ui->timedate->setText(datetimestr);
}

void MainWindow::SendDHT221()
{

    // Set GPIO pin to output
    bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_write(pin, HIGH);
    timer_dht1->start(500);
    qDebug() << "1";

}

void MainWindow::SendDHT222()
{
    timer_dht1->stop();
    bcm2835_gpio_write(pin, LOW);
    timer_dht2->start(20);
    qDebug() << "2";

}

void MainWindow::ReadDHT22()
{
    qDebug() << "3";
    timer_dht2->stop();
    int counter = 0;
    int laststate = HIGH;
    int j=0;

    bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_INPT);

    data[0] = data[1] = data[2] = data[3] = data[4] = 0;

    // wait for pin to drop?
    while (bcm2835_gpio_lev(pin) == 1) {
        usleep(1);
    }

    // read data!
    for (int i=0; i< MAXTIMINGS; i++) {
        counter = 0;
        while ( bcm2835_gpio_lev(pin) == laststate) {
            counter++;
            //nanosleep(1);		// overclocking might change this?
            if (counter == 1000)
                break;
        }
        laststate = bcm2835_gpio_lev(pin);
        if (counter == 1000) break;
        //  #ifdef DEBUG
        //      bits[bitidx++] = counter;
        //  #endif

        if ((i>3) && (i%2 == 0)) {
            // shove each bit into the storage bytes
            data[j/8] <<= 1;
            if (counter > 200)
                data[j/8] |= 1;
            j++;
        }
    }
    qDebug() << "Data " << +j  << ":"<< +data[0] << +data[1] << +data[2] << +data[3]<< +data[4];

    if ((j >= 39) &&
            (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) ) {
        float f, h;
        h = data[0] * 256 + data[1];
        h /= 10;

        f = (data[2] & 0x7F)* 256 + data[3];
        f /= 10.0;
        if (data[2] & 0x80)  f *= -1;
        qDebug() <<"Temp =" << +f << "Hum = " << +h;
        QString a = QString::number(f) + QString(" C"); QString b =QString::number(h) + QString(" %");
        ui->AirT_value->setText(a);ui->AirH_value->setText(b);
    }
    //    timer->start(3000);
}

void MainWindow::Mouse_Pressed1()
{
    QPixmap Pix1(":/green-img.jpg");
    //    QPixmap Pix2(":/red-light.png");
    //    if (mouse_clicked1 == 0)
    //    {
    ui->gr_wP->setPixmap(Pix1);
    bcm2835_gpio_write(17,LOW);
    //    }
    //    else
    //    {
    //        ui->gr_wP->setPixmap(Pix2);
    //        bcm2835_gpio_write(17,HIGH);
    //    }
    //    mouse_clicked1 = !mouse_clicked1;
}

void MainWindow::Mouse_Pressed2()
{
    QPixmap Pix1(":/green-img.jpg");
    //    QPixmap Pix2(":/red-light.png");
    //    if (mouse_clicked2 == 0)
    //    {
    ui->gr_pHpp->setPixmap(Pix1);
    bcm2835_gpio_write(27,LOW);
    //    }
    //    else
    //    {
    //        ui->gr_pHpp->setPixmap(Pix2);
    //        bcm2835_gpio_write(27,HIGH);
    //    }
    //    mouse_clicked2 = !mouse_clicked2;
}

void MainWindow::Mouse_Pressed3()
{
    QPixmap Pix1(":/green-img.jpg");
    //    QPixmap Pix2(":/red-light.png");
    //    if (mouse_clicked3 == 0)
    //    {
    ui->gr_pHpn->setPixmap(Pix1);
    bcm2835_gpio_write(14,LOW);
    //    }
    //    else
    //    {
    //        ui->gr_pHpn->setPixmap(Pix2);
    //        bcm2835_gpio_write(14,HIGH);
    //    }
    //    mouse_clicked3 = !mouse_clicked3;
}

void MainWindow::Mouse_Pressed4()
{
    QPixmap Pix1(":/green-img.jpg");
    //    QPixmap Pix2(":/red-light.png");
    //    if (mouse_clicked4 == 0)
    //    {
    ui->gr_fap->setPixmap(Pix1);
    bcm2835_gpio_write(15,LOW);
    //    }
    //    else
    //    {
    //        ui->gr_fap->setPixmap(Pix2);
    //        bcm2835_gpio_write(15,HIGH);
    //    }
    //    mouse_clicked4 = !mouse_clicked4;
}

void MainWindow::Mouse_Pressed5()
{
    QPixmap Pix1(":/green-img.jpg");
    //    QPixmap Pix2(":/red-light.png");
    //    if (mouse_clicked5 == 0)
    //    {
    ui->gr_fbp->setPixmap(Pix1);
    bcm2835_gpio_write(18,LOW);
    //    }
    //    else
    //    {
    //        ui->gr_fbp->setPixmap(Pix2);
    //        bcm2835_gpio_write(18,HIGH);
    //    }
    //    mouse_clicked5 = !mouse_clicked5;
}
void MainWindow::Mouse_Released1()
{
    QPixmap Pix2(":/red-light.png");
    ui->gr_wP->setPixmap(Pix2);
    bcm2835_gpio_write(17,HIGH);
}
void MainWindow::Mouse_Released2()
{
    QPixmap Pix2(":/red-light.png");
    ui->gr_pHpp->setPixmap(Pix2);
    bcm2835_gpio_write(27,HIGH);
}
void MainWindow::Mouse_Released3()
{
    QPixmap Pix2(":/red-light.png");
    ui->gr_pHpn->setPixmap(Pix2);
    bcm2835_gpio_write(14,HIGH);
}
void MainWindow::Mouse_Released4()
{
    QPixmap Pix2(":/red-light.png");
    ui->gr_fap->setPixmap(Pix2);
    bcm2835_gpio_write(15,HIGH);
}
void MainWindow::Mouse_Released5()
{
    QPixmap Pix2(":/red-light.png");
    ui->gr_fbp->setPixmap(Pix2);
    bcm2835_gpio_write(18,HIGH);
}

MainWindow::~MainWindow()
{
    delete ui;
}

