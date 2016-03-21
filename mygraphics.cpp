#include "mygraphics.h"
#include <QtGui>
#include <QWidget>

MyGraphics::MyGraphics(QWidget *obj)
    :QWidget(obj)
{

}

void MyGraphics::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(QPen(Qt::white,3));
    p.drawRect(0,0,800,480);
}
