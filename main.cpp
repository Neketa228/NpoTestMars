#include "mainwindow.h"
#include <QString>
#include <QApplication>
#include "form.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form *form = new Form();
    form->show();
//    MainWindow w;
//    w.show();
    return a.exec();
}
