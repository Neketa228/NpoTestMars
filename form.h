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
#include <QElapsedTimer>
#include <QTime>
#include <cmath>
#include "calculation.h"
#include "paintlabel.h"
#include "qlabel.h"
#include "mylineedit.h"


class Form : public QWidget{
    Q_OBJECT
public:
    Form();



private:
    PaintLabel *pl;
    QLabel *info;
    MyLineEdit *lineEditX1;
    MyLineEdit *lineEditY1;
    MyLineEdit *lineEditK1;
    MyLineEdit *lineEditV1;
    MyLineEdit *lineEditX2;
    MyLineEdit *lineEditY2;
    MyLineEdit *lineEditK2;
    MyLineEdit *lineEditV2;
    Calculation *cal;
    QTimer *timer;
    QElapsedTimer *etimer;
    QTime mtime;



    void setDefault();
private slots:
   void setPoints();
   void setInfo();
   void updateLineEdits();
   void startProgram();
   void pause();
   void resume();
   void updateTime();


};

#endif // FORM_H
