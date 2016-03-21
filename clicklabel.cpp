#include <QObject>
#include <QLabel>
#include <QWidget>
#include "clicklabel.h"

clicklabel::clicklabel(QWidget* parent)
    : QLabel(parent)
{

}
clicklabel::~clicklabel()
{
}
void clicklabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}
void clicklabel::mouseReleaseEvent(QMouseEvent* event)
{
    emit released();
}
