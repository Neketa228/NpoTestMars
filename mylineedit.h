#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QWidget>
#include <Qlabel>
#include <QHBoxLayout>
class MyLineEdit : public QWidget
{
public:
    MyLineEdit(QString name , QWidget *parent = 0);
    QLabel *namelabel;
    QLineEdit *lineedit;
};

#endif // MYLINEEDIT_H
