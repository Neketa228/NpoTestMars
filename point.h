#ifndef POINT_H
#define POINT_H


struct Point
{
    double x=0;
    double y=0;
    double k=0;
    double v=0;
    Point(double x, double y, double k, double v);
    Point();
    Point(double x, double y);
};
#endif // POINT_H
