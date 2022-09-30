#include "form.h"

Form::Form(){
    //Создаем поля для ввода
    cal = new Calculation();
    PaintLabel *pl = new PaintLabel(cal, this);
    QGridLayout *glayout = new QGridLayout(this);
    lineEdit1 = new QLineEdit(this);
    lineEdit2 = new QLineEdit(this);
    lineEdit3 = new QLineEdit(this);
    lineEdit4 = new QLineEdit(this);
    lineEdit5 = new QLineEdit(this);
    lineEdit6 = new QLineEdit(this);
    lineEdit7 = new QLineEdit(this);
    lineEdit8 = new QLineEdit(this);
    setDefault();
    // Создаем кнопки
    QPushButton *start = new QPushButton("Start", this);
    QPushButton *pause = new QPushButton("Pause", this);
    QPushButton *resume = new QPushButton("Resume", this);

    // Делаем правильное расположение
    glayout->addWidget(pl);
    glayout->addWidget(lineEdit1);
    glayout->addWidget(lineEdit2);
    glayout->addWidget(lineEdit3);
    glayout->addWidget(lineEdit4);
    glayout->addWidget(lineEdit5);
    glayout->addWidget(lineEdit6);
    glayout->addWidget(lineEdit7);
    glayout->addWidget(lineEdit8);
    glayout->addWidget(start);
    glayout->addWidget(pause);
    glayout->addWidget(resume);

    setLayout(glayout);

    QObject :: connect(start, &QPushButton::clicked, this, &Form::setPoints);
   // QObject :: connect(start, &QPushButton::clicked, cal, &PaintLabel::paintEvent);
    QObject :: connect(pause, &QPushButton::clicked, this, &Form::pause);
    QObject :: connect(resume, &QPushButton::clicked, this, &Form::resume);
    timer= new QTimer (this);
    timer->setInterval(1000);
    QObject :: connect(timer, &QTimer::timeout, cal, &Calculation::updatePosition);
    QObject :: connect(timer, &QTimer::timeout, cal, &Calculation::timeCross);


}

void Form::setDefault()
{
    //Задаем значения по умолчанию
    lineEdit1->setText("0");
    lineEdit2->setText("0");
    lineEdit3->setText("45");
    lineEdit4->setText("1");
    lineEdit5->setText("7");
    lineEdit6->setText("0");
    lineEdit7->setText("135");
    lineEdit8->setText("1");

}

void Form::setPoints(){
    // Передаем значение из полей в переменные
    cal->p1.x = lineEdit1 -> text().toDouble();
    cal->p1.y = lineEdit2 -> text().toDouble();
    cal->p1.k = lineEdit3 -> text().toDouble();
    cal->p1.v = lineEdit4 -> text().toDouble();
    cal->p2.x = lineEdit5 -> text().toDouble();
    cal->p2.y = lineEdit6 -> text().toDouble();
    cal->p2.k = lineEdit7 -> text().toDouble();
    cal->p2.v = lineEdit8 -> text().toDouble();
    //Запускаем таймер
    timer->start();
    cal->findCrossPoint();
    cal->timeCross();

}



void Form::pause()
{
    timer->stop();

}

void Form::resume()
{
    timer->start();

}


