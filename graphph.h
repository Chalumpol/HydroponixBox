#ifndef GRAPHPH_H
#define GRAPHPH_H
#include "qcustomplot.h"
#include <QObject>

class graphph : public QObject
{
    Q_OBJECT

public:
    graphph();
    const double pH_Graph;
public slots:
    void receive_value(double);
    void Graph_ph();
private slots:
signals:
    void receive_done(double);
private:
    double m_pH;
};


#endif // GRAPHPH_H
