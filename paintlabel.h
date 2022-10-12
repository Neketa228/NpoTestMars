#ifndef PAINTLABEL_H
#define PAINTLABEL_H
#include <QPainter>
#include <QLabel>
#include <QPointF>
#include "calculation.h"
#include "formular.h"


class PaintLabel : public QLabel
{
   // Q_OBJECT
public:
    PaintLabel(Calculation *calculation , QWidget *parent = 0);
    void updateInfo();
    //PaintLabel(QWidget *parent = 0, );

protected:
    QPainter * painter;
    void paintEvent(QPaintEvent *event);

private:
    const double maxsize = 300;
    Calculation *cal;
    Calculation *x1, *y1;
    Formular *formular1;
    Formular *formular2;
//public slots:
//    void myrepaint();
};

#endif // PAINTLABEL_H
