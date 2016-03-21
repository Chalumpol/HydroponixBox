#ifndef CLICKLABEL_H
#define CLICKLABEL_H

#include <QObject>
#include <QLabel>
#include <QWidget>

class clicklabel : public QLabel
{
    Q_OBJECT   
public:
    explicit clicklabel(QWidget* parent=0);
    ~clicklabel();
signals:
    void clicked();
    void released();
public slots:
protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
};

#endif // CLICKLABEL_H
