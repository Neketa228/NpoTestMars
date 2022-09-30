#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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

#define PI 3.14159265
#define Eps 0.0001

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

};







#endif // MAINWINDOW_H
