#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rozgrywka.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    char wybor;
    bool klik;
    Rozgrywka r;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent (QKeyEvent *event);

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
