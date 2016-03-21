#include "passvalue.h"
#include <QObject>

void passvalue::setValue(int value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged(value);
    }
}
