#ifndef PASSVALUE_H
#define PASSVALUE_H
#include <QObject>

class passvalue : public QObject
{
    Q_OBJECT

public:
    passvalue() { m_value = 0; }

    int value() const { return m_value; }

public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);

private:
    int m_value;
};

#endif // PASSVALUE_H
