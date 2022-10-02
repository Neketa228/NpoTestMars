#ifndef CALCULATION_H
#define CALCULATION_H
#include <QObject>
#include "point.h"
#include <QDebug>

#define PI 3.14159265
#define Eps 0.001


class Calculation: public QObject
{
    Q_OBJECT
public:
    Calculation();

    Point p1;
    Point p2;
    double D1=0,D2=0,T1=0,T2=0;
    Point crossPoint;
    bool wasCrossed;
    double prevD1 = 9999, prevD2 = 9999;
public slots:
    void updatePosition();
    void findCrossPoint();

    void timeCross();
};

#endif // CALCULATION_H
