#include "point.h"


Point::Point(double x, double y, double k, double v) {
    this->x = x;
    this->y = y;
    this->k = k;
    this->v = v;
}

Point::Point(){}

Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}
