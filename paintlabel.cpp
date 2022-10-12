#include "paintlabel.h"


PaintLabel::PaintLabel(Calculation * calculation, QWidget *parent) : QLabel(parent), cal(calculation)
{
    Point newpoint1 = Point(cal->p1.x + maxsize/2,qAbs(cal->p1.y - maxsize/2) );
    Point newpoint2 = Point(cal->p2.x + maxsize/2,qAbs(cal->p2.y - maxsize/2) );
    formular1 = new Formular(newpoint1, this);
    formular2 = new Formular(newpoint2, this);
    formular1->setText("x1 = " + QString::number(cal->p1.x));
    formular1->update();
    formular2->setText("sg");
    setMinimumHeight(maxsize);
    setMinimumWidth(maxsize);
}

void PaintLabel::updateInfo()
{
//    Point newpoint1 = Point(cal->p1.x + maxsize/2,qAbs(cal->p1.y - maxsize/2) );
//    Point newpoint2 = Point(cal->p2.x + maxsize/2,qAbs(cal->p2.y - maxsize/2) );
//    formular1 = new Formular(newpoint1, this);
//    formular2 = new Formular(newpoint2, this);
//    formular1->setText("x1 = " + QString::number(cal->p1.x));
//    formular1->update();
//    formular2->setText("sg");
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

        QPoint left,right,up,down;


        left.setX(0);
        left.setY(maxsize/2);
        right.setX(maxsize);
        right.setY(maxsize/2);
        up.setX(maxsize/2);
        up.setY(0);
        down.setX(maxsize/2);
        down.setY(maxsize);

        painter->setPen(BlackPenThin);
        painter->drawLine(QPoint(cal->p1.x + maxsize/2,abs(cal->p1.y - maxsize/2)), QPoint(cal->crossPoint.x + maxsize/2,qAbs(cal->crossPoint.y - maxsize/2)));
        painter->drawLine(QPoint(cal->p2.x + maxsize/2,abs(cal->p2.y - maxsize/2)), QPoint(cal->crossPoint.x + maxsize/2,qAbs(cal->crossPoint.y - maxsize/2)));

        painter->setPen(BlackPen);
        painter->drawLine(left, right);
        painter->drawLine(up, down);

        painter->setPen(BluePen);
        painter->drawPoint(QPoint(cal->crossPoint.x + maxsize/2,qAbs(cal->crossPoint.y - maxsize/2)));

        painter->setPen(RedPen);
        painter->drawPoint(QPoint(cal->p1.x + maxsize/2,qAbs(cal->p1.y - maxsize/2)));
        painter->drawPoint(QPoint(cal->p2.x + maxsize/2,qAbs(cal->p2.y - maxsize/2)));

        Point newpoint1 = Point(cal->p1.x + maxsize/2,qAbs(cal->p1.y - maxsize/2) );
        Point newpoint2 = Point(cal->p2.x + maxsize/2,qAbs(cal->p2.y - maxsize/2) );
        formular1->updatePosition(newpoint1);
        formular2->updatePosition(newpoint2);
        formular1->move(newpoint1.x, newpoint1.y);
        formular2->move(newpoint2.x, newpoint2.y);
        painter->end();

}

