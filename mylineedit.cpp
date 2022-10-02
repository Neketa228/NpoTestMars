#include "mylineedit.h"

MyLineEdit::MyLineEdit(QString name, QWidget *parent) : QWidget(parent)
{
    namelabel = new QLabel(this);
    lineedit = new QLineEdit(this);
    namelabel->setText(name);
    QHBoxLayout *hboxlayout = new QHBoxLayout(this);
    hboxlayout->addWidget(namelabel);
    hboxlayout->addWidget(lineedit);
}
