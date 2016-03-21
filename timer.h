#ifndef TIMER_H
#define TIMER_H
#include <QObject>

class timer : public QObject
{
    Q_OBJECT

public:
    timer() { m_value = 0; }

    int value() const { return m_value; }

public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);

private:
    int m_value;
};

#endif // TIMER_H
