#include "calculation.h"


Calculation::Calculation()
{

}
void Calculation::updatePosition(){
    //Метод изменения координат каждой точки

    p1.x += p1.v * std::cos(p1.k * PI / 180);
    p1.y += p1.v * std::sin(p1.k * PI / 180);
    p2.x +=  p2.v * std::cos(p2.k * PI / 180);
    p2.y +=  p2.v * std::sin(p2.k * PI / 180);
    qDebug() <<"p1=" << p1.x << "," << p1.y << "p2 = "<< p2.x << "," << p2.y;
}

void Calculation::findCrossPoint(){
    // Метод длля поиска точки пересечения
    double x1, y1, x2, y2, A1, B1, C1, A2, B2, C2, N, resX = 0, resY = 0, pr;
    x1 = p1.x + p1.v * std::cos(p1.k * PI / 180);//Вторая точка по траектории движения
    y1 = p1.y + p1.v * std::sin(p1.k * PI / 180);//Вторая точка по траектории движения
    x2 = p2.x + p2.v * std::cos(p2.k * PI / 180);//Вторая точка по траектории движения
    y2 = p2.y + p2.v * std::sin(p2.k * PI / 180);//Вторая точка по траектории движения
    A1 = y1 - p1.y;
    A2 = y2 - p2.y;
    B1 = p1.x - x1;
    B2 = p2.x - x2;
    N = A1*B2 - A2*B1;
    pr = (qAbs(N) > Eps);
    if (pr == true){
        C1 = x1*p1.y -p1.x*y1;
        C2 = x2*p2.y - p2.x*y2;
        resX = -(C1*B2 - C2*B1)/N;
        resY = -(A1*C2 - A2*C1)/N;
        qDebug() << "Точка пересечения =" << resX << resY;
    }
    else{
        qDebug()<< "Пересечения не найдено";
    }

    crossPoint = Point(resX, resY);
}

void Calculation::timeCross(){
    //Метод для поиска дистанции и времени пересечения
    D1 = sqrt(pow(crossPoint.x - p1.x,2) + pow(crossPoint.y - p1.y,2));
    D2 = sqrt(pow(crossPoint.x - p2.x,2) + pow(crossPoint.y - p2.y,2));
    T1=D1/p1.v;
    T2=D2/p2.v;

    if (D1>=prevD1){

    qDebug() << "Дистанция после пересечения объектом 1" << D1 <<"Время после пересечения для объекта 1 =" << T1;
    }
    else{

     qDebug() << "Дистанция до пересечения объектом 1" << D1 <<"Время до пересечения для объекта 1 =" << T1;
    }
    if (D2>=prevD2){

    qDebug() << "Дистанция после пересечения объектом 2" << D2 <<"Время после пересечения для объекта 2 =" << T2;
    }
    else{

     qDebug() << "Дистанция до пересечения объектом 2" << D2 <<"Время до пересечения для объекта 2 =" << T2;
    }

    prevD1 = D1;
    prevD2 = D2;


}
