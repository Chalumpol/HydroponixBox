#include "timer.h"
#include <QTimer>

timer::timer()
{
}
timer::~timer()
{
}
void timer::setValue(int value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged(value);
    }
}
