#ifndef FORMULAR_H
#define FORMULAR_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QPainter>

#include "point.h"


class Formular : public QWidget
{
    Q_OBJECT
public:

    Formular(Point point, QWidget *parent);
    void updatePosition(Point point);
    void setText(QString text);
protected:
    QPainter * painter;
    void paintEvent(QPaintEvent *event);
private:
    Point point;
    QLabel *info;
};

#endif // FORMULAR_H
