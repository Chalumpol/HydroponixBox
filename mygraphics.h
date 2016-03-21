#ifndef MYGRAPHICS_H
#define MYGRAPHICS_H

#include <QtGui>
#include <QtWidgets>

class MyGraphics : public QWidget
{
    Q_OBJECT
public:
    MyGraphics(QWidget* obj=0);

    virtual void paintEvent(QPaintEvent *);
};

#endif // MYGRAPHICS_H
