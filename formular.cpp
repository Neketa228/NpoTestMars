#include "formular.h"

Formular::Formular(Point point, QWidget *parent) : QWidget(parent){
    info = new QLabel(this);
}

void Formular::updatePosition(Point point)
{
    this->point = point;

}

void Formular::setText(QString text)
{
    info->setText(text);
}

void Formular::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing);


    QPen BlackPen (Qt::black);
    BlackPen.setWidth(2);

    painter->setPen(BlackPen);
    painter->drawRect(point.x, point.y, this->width(), this->height());



    painter->end();
}
