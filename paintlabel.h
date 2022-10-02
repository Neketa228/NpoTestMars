#ifndef PAINTLABEL_H
#define PAINTLABEL_H
#include <QPainter>
#include <QLabel>
#include <QPointF>
#include "calculation.h"
//#include "form.h"

class PaintLabel : public QLabel
{
   // Q_OBJECT
public:
    PaintLabel(Calculation *calculation , QWidget *parent = 0);
    //PaintLabel(QWidget *parent = 0, );

protected:
    QPainter * painter;
    void paintEvent(QPaintEvent *event);
private:
    const double maxsize = 300;
    Calculation *cal;
    Calculation *x1, *y1;

//public slots:
//    void myrepaint();
};

#endif // PAINTLABEL_H
