#ifndef FORM_H
#define FORM_H
#include "QWidget"
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QObject>
#include <QMainWindow>
#include <QGridLayout>
#include <QDebug>
#include <QTimer>
#include <cmath>
#include "point.h"
#include "paintlabel.h"
#include "calculation.h"




class Form : public QWidget{
    Q_OBJECT
public:
    Form();



private:

    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QLineEdit *lineEdit4;
    QLineEdit *lineEdit5;
    QLineEdit *lineEdit6;
    QLineEdit *lineEdit7;
    QLineEdit *lineEdit8;
    Calculation *cal;
    QTimer *timer;
    void setDefault();


private slots:
   void setPoints();

//   void updatePosition();
//   void findCrossPoint();
//   void timeCross();
   void pause();
   void resume();


};

#endif // FORM_H
