#include "form.h"

Form::Form(){
    //Создаем поля для ввода
    cal = new Calculation();
    pl = new PaintLabel(cal, this);
    QGridLayout *glayout = new QGridLayout(this);
    QHBoxLayout *hboxlayout = new QHBoxLayout(this);
    lineEditX1 = new MyLineEdit("x1" , this);
    lineEditY1 = new MyLineEdit("y1" ,this);
    lineEditK1 = new MyLineEdit("k1" ,this);
    lineEditV1 = new MyLineEdit("v1" ,this);
    lineEditX2 = new MyLineEdit("x2" ,this);
    lineEditY2 = new MyLineEdit("y2" ,this);
    lineEditK2 = new MyLineEdit("k2" ,this);
    lineEditV2 = new MyLineEdit("v2" ,this);
    info = new QLabel(this);
    updateLineEdits();
    // Создаем кнопки
    QPushButton *start = new QPushButton("Старт", this);
    QPushButton *pause = new QPushButton("Пауза", this);
    QPushButton *resume = new QPushButton("Продолжить", this);

    // Делаем правильное расположение
    hboxlayout -> addWidget(pl);
    hboxlayout -> addWidget(info);
    glayout->addLayout(hboxlayout, 0, 0);
    glayout->addWidget(lineEditX1);
    glayout->addWidget(lineEditY1);
    glayout->addWidget(lineEditK1);
    glayout->addWidget(lineEditV1);
    glayout->addWidget(lineEditX2);
    glayout->addWidget(lineEditY2);
    glayout->addWidget(lineEditK2);
    glayout->addWidget(lineEditV2);
    glayout->addWidget(start);
    glayout->addWidget(pause);
    glayout->addWidget(resume);
    setLayout(glayout);
    setDefault();
    QObject :: connect(start, &QPushButton::clicked, this, &Form::startProgram);
    QObject :: connect(pause, &QPushButton::clicked, this, &Form::pause);
    QObject :: connect(resume, &QPushButton::clicked, this, &Form::resume);
    timer = new QTimer (this);
    etimer = new QElapsedTimer();
    mtime = QTime(0,0);
    timer->setInterval(1000);
    QObject :: connect(timer, &QTimer::timeout, this, &Form::updateLineEdits);
    QObject :: connect(timer, &QTimer::timeout, pl, qOverload<>(&QWidget::update));
    QObject :: connect(timer, &QTimer::timeout, this, &Form::setInfo);
    QObject :: connect(timer, &QTimer::timeout, this, &Form::updateLineEdits);
    //QObject :: connect(timer, &QTimer::timeout, this, &Form::updateLineEdits);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));

    setInfo();




}
void Form::setDefault()
{
    //Задаем значения по умолчанию
    lineEditX1->lineedit->setText("50");
    lineEditY1->lineedit->setText("0");
    lineEditK1->lineedit->setText("45");
    lineEditV1->lineedit->setText("5");
    lineEditX2->lineedit->setText("100");
    lineEditY2->lineedit->setText("20");
    lineEditK2->lineedit->setText("135");
    lineEditV2->lineedit->setText("7");


}

void Form::updateLineEdits()
{
    //Задаем значения по умолчанию
    setPoints();
    lineEditX1->lineedit->setText(QString::number(cal->p1.x));
    lineEditY1->lineedit->setText(QString::number(cal->p1.y));
    lineEditK1->lineedit->setText(QString::number(cal->p1.k));
    lineEditV1->lineedit->setText(QString::number(cal->p1.v));
    lineEditX2->lineedit->setText(QString::number(cal->p2.x));
    lineEditY2->lineedit->setText(QString::number(cal->p2.y));
    lineEditK2->lineedit->setText(QString::number(cal->p2.k));
    lineEditV2->lineedit->setText(QString::number(cal->p2.v));


}



void Form::setPoints(){
    // Передаем значение из полей в переменные
    cal->p1.x = lineEditX1 -> lineedit->text().toDouble();
    cal->p1.y = lineEditY1 -> lineedit->text().toDouble();
    cal->p1.k = lineEditK1 -> lineedit->text().toDouble();
    cal->p1.v = lineEditV1 -> lineedit->text().toDouble();
    cal->p2.x = lineEditX2 -> lineedit->text().toDouble();
    cal->p2.y = lineEditY2 -> lineedit->text().toDouble();
    cal->p2.k = lineEditK2 -> lineedit->text().toDouble();
    cal->p2.v = lineEditV2 -> lineedit->text().toDouble();

    if(cal->p1.k == cal->p2.k || cal->p1.k -180 == cal->p2.k || cal->p2.k -180 == cal-> p1.k ){
    lineEditX1->lineedit->setText("-");
    lineEditY1->lineedit->setText("-");
    lineEditK1->lineedit->setText("-");
    lineEditV1->lineedit->setText("-");
    lineEditX2->lineedit->setText("-");
    lineEditY2->lineedit->setText("-");
    lineEditK2->lineedit->setText("-");
    lineEditV2->lineedit->setText("-");
    //pause();
    }
    else{
    cal->findCrossPoint();
    cal->timeCross();
    cal->updatePosition();
    }
}

void Form::setInfo()
{
    QString infostr;
    infostr.append("P1: x = " + QString::number(cal->p1.x) + " y = " + QString::number(cal->p1.y) + "\n");
    infostr.append("D1 = " + QString::number(cal->D1) + " T1 = " + QString::number(cal->T1) + "\n");
    infostr.append("P2: x = " + QString::number(cal->p2.x) + " y = " + QString::number(cal->p2.y) + "\n");
    infostr.append("D1 = " + QString::number(cal->D2) + " T1 = " + QString::number(cal->T2) + "\n");
    infostr.append("Координаты точки пересечения : x=" + QString::number(cal->crossPoint.x) + " y=" + QString::number(cal->crossPoint.y) + "\n");
    infostr.append("Текущее время = " + mtime.toString("hh:mm:ss") + "\n");

    info->setText(infostr);
}

void Form::startProgram()
{
    setPoints();
    timer ->start();
    etimer ->start();
}

void Form::pause()
{
    timer->stop();

}

void Form::resume()
{
    timer->start();

}

void Form::updateTime()
{
    mtime = mtime.addMSecs(etimer->restart());
}

