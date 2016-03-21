/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <clicklabel.h>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *customplot;
    QLabel *ph_font;
    QLabel *ph_value;
    QLabel *ec_label;
    QLabel *ec_value;
    QLabel *AirT_label;
    QLabel *AirT_value;
    QLabel *AirH_value;
    QLabel *AirH_label;
    QLabel *Hydroponics;
    QLabel *WPump;
    QLabel *pHppump;
    QLabel *pHnpump;
    QLabel *ecA;
    QLabel *ecb;
    clicklabel *gr_wP;
    clicklabel *gr_pHpp;
    clicklabel *gr_pHpn;
    clicklabel *gr_fap;
    clicklabel *gr_fbp;
    QLabel *timedate;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 461);
        MainWindow->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        customplot = new QCustomPlot(centralWidget);
        customplot->setObjectName(QStringLiteral("customplot"));
        customplot->setGeometry(QRect(440, 120, 351, 251));
        ph_font = new QLabel(centralWidget);
        ph_font->setObjectName(QStringLiteral("ph_font"));
        ph_font->setGeometry(QRect(10, 140, 51, 41));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        ph_font->setFont(font);
        ph_font->setAutoFillBackground(false);
        ph_font->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        ph_font->setAlignment(Qt::AlignCenter);
        ph_value = new QLabel(centralWidget);
        ph_value->setObjectName(QStringLiteral("ph_value"));
        ph_value->setGeometry(QRect(80, 140, 81, 41));
        ph_value->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        ec_label = new QLabel(centralWidget);
        ec_label->setObjectName(QStringLiteral("ec_label"));
        ec_label->setGeometry(QRect(10, 200, 51, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(15);
        ec_label->setFont(font1);
        ec_label->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        ec_label->setAlignment(Qt::AlignCenter);
        ec_value = new QLabel(centralWidget);
        ec_value->setObjectName(QStringLiteral("ec_value"));
        ec_value->setGeometry(QRect(80, 200, 81, 41));
        ec_value->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        AirT_label = new QLabel(centralWidget);
        AirT_label->setObjectName(QStringLiteral("AirT_label"));
        AirT_label->setGeometry(QRect(10, 260, 51, 41));
        AirT_label->setFont(font1);
        AirT_label->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        AirT_label->setAlignment(Qt::AlignCenter);
        AirT_value = new QLabel(centralWidget);
        AirT_value->setObjectName(QStringLiteral("AirT_value"));
        AirT_value->setGeometry(QRect(80, 260, 81, 41));
        AirT_value->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        AirH_value = new QLabel(centralWidget);
        AirH_value->setObjectName(QStringLiteral("AirH_value"));
        AirH_value->setGeometry(QRect(80, 320, 81, 41));
        AirH_value->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        AirH_label = new QLabel(centralWidget);
        AirH_label->setObjectName(QStringLiteral("AirH_label"));
        AirH_label->setGeometry(QRect(10, 320, 51, 41));
        AirH_label->setFont(font1);
        AirH_label->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        AirH_label->setAlignment(Qt::AlignCenter);
        Hydroponics = new QLabel(centralWidget);
        Hydroponics->setObjectName(QStringLiteral("Hydroponics"));
        Hydroponics->setGeometry(QRect(0, 0, 800, 80));
        QFont font2;
        font2.setFamily(QStringLiteral("Comic Sans MS"));
        font2.setPointSize(30);
        font2.setBold(true);
        font2.setWeight(75);
        Hydroponics->setFont(font2);
        Hydroponics->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(34, 58, 255);"));
        Hydroponics->setAlignment(Qt::AlignCenter);
        WPump = new QLabel(centralWidget);
        WPump->setObjectName(QStringLiteral("WPump"));
        WPump->setGeometry(QRect(180, 140, 121, 41));
        QFont font3;
        font3.setPointSize(15);
        WPump->setFont(font3);
        WPump->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        WPump->setAlignment(Qt::AlignCenter);
        pHppump = new QLabel(centralWidget);
        pHppump->setObjectName(QStringLiteral("pHppump"));
        pHppump->setGeometry(QRect(180, 200, 121, 41));
        pHppump->setFont(font3);
        pHppump->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        pHppump->setAlignment(Qt::AlignCenter);
        pHnpump = new QLabel(centralWidget);
        pHnpump->setObjectName(QStringLiteral("pHnpump"));
        pHnpump->setGeometry(QRect(180, 260, 121, 41));
        pHnpump->setFont(font3);
        pHnpump->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        pHnpump->setAlignment(Qt::AlignCenter);
        ecA = new QLabel(centralWidget);
        ecA->setObjectName(QStringLiteral("ecA"));
        ecA->setGeometry(QRect(180, 320, 121, 41));
        ecA->setFont(font3);
        ecA->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        ecA->setAlignment(Qt::AlignCenter);
        ecb = new QLabel(centralWidget);
        ecb->setObjectName(QStringLiteral("ecb"));
        ecb->setGeometry(QRect(180, 380, 121, 41));
        ecb->setFont(font3);
        ecb->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        ecb->setAlignment(Qt::AlignCenter);
        gr_wP = new clicklabel(centralWidget);
        gr_wP->setObjectName(QStringLiteral("gr_wP"));
        gr_wP->setGeometry(QRect(320, 140, 48, 47));
        gr_wP->setMouseTracking(true);
        gr_wP->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        gr_pHpp = new clicklabel(centralWidget);
        gr_pHpp->setObjectName(QStringLiteral("gr_pHpp"));
        gr_pHpp->setGeometry(QRect(320, 200, 48, 47));
        gr_pHpp->setMouseTracking(true);
        gr_pHpp->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        gr_pHpn = new clicklabel(centralWidget);
        gr_pHpn->setObjectName(QStringLiteral("gr_pHpn"));
        gr_pHpn->setGeometry(QRect(320, 260, 48, 47));
        gr_pHpn->setMouseTracking(true);
        gr_pHpn->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        gr_fap = new clicklabel(centralWidget);
        gr_fap->setObjectName(QStringLiteral("gr_fap"));
        gr_fap->setGeometry(QRect(320, 320, 48, 47));
        gr_fap->setMouseTracking(true);
        gr_fap->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        gr_fbp = new clicklabel(centralWidget);
        gr_fbp->setObjectName(QStringLiteral("gr_fbp"));
        gr_fbp->setGeometry(QRect(320, 380, 48, 47));
        gr_fbp->setMouseTracking(true);
        gr_fbp->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        timedate = new QLabel(centralWidget);
        timedate->setObjectName(QStringLiteral("timedate"));
        timedate->setGeometry(QRect(10, 90, 241, 21));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        ph_font->setText(QApplication::translate("MainWindow", "pH", 0));
        ph_value->setText(QString());
        ec_label->setText(QApplication::translate("MainWindow", "EC", 0));
        ec_value->setText(QString());
        AirT_label->setText(QApplication::translate("MainWindow", "AirT", 0));
        AirT_value->setText(QString());
        AirH_value->setText(QString());
        AirH_label->setText(QApplication::translate("MainWindow", "AirH", 0));
        Hydroponics->setText(QApplication::translate("MainWindow", "Hydroponics Box", 0));
        WPump->setText(QApplication::translate("MainWindow", "Water pump", 0));
        pHppump->setText(QApplication::translate("MainWindow", "pH + pump", 0));
        pHnpump->setText(QApplication::translate("MainWindow", "pH - pump", 0));
        ecA->setText(QApplication::translate("MainWindow", "Fer A pump", 0));
        ecb->setText(QApplication::translate("MainWindow", "Fer B pump", 0));
        gr_wP->setText(QString());
        gr_pHpp->setText(QString());
        gr_pHpn->setText(QString());
        gr_fap->setText(QString());
        gr_fbp->setText(QString());
        timedate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
