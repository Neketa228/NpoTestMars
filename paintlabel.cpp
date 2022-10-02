#include "paintlabel.h"


PaintLabel::PaintLabel(Calculation * calculation, QWidget *parent) : QLabel(parent), cal(calculation)
{

    setMinimumHeight(maxsize);
    setMinimumWidth(maxsize);
}

void PaintLabel::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
        painter->setRenderHint(QPainter::Antialiasing);

        QPen BlackPen (Qt::black);
        BlackPen.setWidth(3);

        QPen BluePen (Qt::blue);
        BluePen.setWidth(5);

        QPen RedPen (Qt::red);
        RedPen.setWidth(5);

        QPen BlackPenThin (Qt::black);
        BlackPenThin.setWidth(1);

        QPoint left,right,up,down,mid;


        left.setX(0);
        left.setY(maxsize/2);
        right.setX(maxsize);
        right.setY(maxsize/2);
        up.setX(maxsize/2);
        up.setY(0);
        down.setX(maxsize/2);
        down.setY(maxsize);
        //x1 = x1 + maxsize/2;

//for(double i = 0; i < maxsize; i+=30){
//    painter -> setPen(RedPen);
//    painter -> drawPoint(QPoint(cal->p1.x));
//}
        painter->setPen(BlackPenThin);
        painter->drawLine(QPoint(cal->p1.x + maxsize/2,abs(cal->p1.y - maxsize/2)), QPoint(cal->crossPoint.x + maxsize/2,abs(cal->crossPoint.y - maxsize/2)));
        painter->drawLine(QPoint(cal->p2.x + maxsize/2,abs(cal->p2.y - maxsize/2)), QPoint(cal->crossPoint.x + maxsize/2,abs(cal->crossPoint.y - maxsize/2)));

        painter->setPen(BlackPen);
        painter->drawLine(left, right);
        painter->drawLine(up, down);

        painter->setPen(BluePen);
        painter->drawPoint(QPoint(cal->crossPoint.x + maxsize/2,abs(cal->crossPoint.y - maxsize/2)));

        painter->setPen(RedPen);
        painter->drawPoint(QPoint(cal->p1.x + maxsize/2,abs(cal->p1.y - maxsize/2)));
        painter->drawPoint(QPoint(cal->p2.x + maxsize/2,abs(cal->p2.y - maxsize/2)));






        painter->end();

}

//void PaintLabel::myrepaint()
//{
//    this->repaint();
//}
