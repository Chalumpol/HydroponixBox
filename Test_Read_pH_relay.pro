#-------------------------------------------------
#
# Project created by QtCreator 2016-02-26T16:45:26
#
#-------------------------------------------------

QT       += core gui quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Test_Read_pH_relay
TEMPLATE = app
target.path = /home/pi

INSTALLS = target

SOURCES += main.cpp\
        mainwindow.cpp\
    qcustomplot.cpp \
    clicklabel.cpp

HEADERS  += mainwindow.h\
    qcustomplot.h \
    clicklabel.h

FORMS    += mainwindow.ui

RESOURCES += \
    myresources.qrc
LIBS += -lbcm2835
