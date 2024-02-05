#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QKeyEvent>
#include<time.h>
#include<cstdlib>
#include <iostream>
#include <conio.h>
#include<Windows.h>
#include<string>
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    klik=false;
    wybor = ' ';

 void keyPressEvent (QKeyEvent *event);
    ui->setupUi(this);


    //Boze cos polske czemu to Qt jest uposledzone
    //ui->O0->setStyleSheet(" color : blue; }");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{


    if(event->key()==Qt::Key_W)
        {
                    wybor='W';
        }
    if(event->key()==Qt::Key_A)
        {
                    wybor='A';
        }
    if(event->key()==Qt::Key_S)
        {
                    wybor='S';
        }
    if(event->key()==Qt::Key_D)
        {
                    wybor='D';
        }
    if(event->key()==Qt::Key_K)
        {
                    wybor=13;
        }
   if(r.getWygrana())
   {

    klik=true;
    Plansza temp;
    temp=r.Start(wybor,klik);
    string linia1="X:"+to_string(r.getX())+"\tY:"+to_string(r.getY())+
            "\nTura:"+to_string(r.getTura());


    ui->wyswietlacz->setText(QString::fromStdString(linia1));

    ui->O0->setText(QString(temp.Cialo(0,0)));
    ui->O2->setText(QString(temp.Cialo(0,2)));
    ui->O4->setText(QString(temp.Cialo(0,4)));

    ui->Z0->setText(QString(temp.Cialo(2,0)));
    ui->Z2->setText(QString(temp.Cialo(2,2)));
    ui->Z4->setText(QString(temp.Cialo(2,4)));

    ui->A0->setText(QString(temp.Cialo(4,0)));
    ui->A2->setText(QString(temp.Cialo(4,2)));
    ui->A4->setText(QString(temp.Cialo(4,4)));
   }
   else if (r.getWygrana()==false)
   {
       klik = false;
       string linia2="Wygrana:"+to_string(r.getGracz());
       ui->wyswietlacz->setText(QString::fromStdString(linia2));
       //r.czyscPlansze();


   }
   if(r.getTura()==9)
   {
       klik = false;
        ui->wyswietlacz->setText("Remis");
         Sleep(100);
   }

   if(r.getWygrana())
   {

    klik=true;
    Plansza temp;
    temp=r.Start('H',klik);
    string linia1="X:"+to_string(r.getX())+"\tY:"+to_string(r.getY())+
            "\nTura:"+to_string(r.getTura());


    ui->wyswietlacz->setText(QString::fromStdString(linia1));

    ui->O0->setText(QString(temp.Cialo(0,0)));
    ui->O2->setText(QString(temp.Cialo(0,2)));
    ui->O4->setText(QString(temp.Cialo(0,4)));

    ui->Z0->setText(QString(temp.Cialo(2,0)));
    ui->Z2->setText(QString(temp.Cialo(2,2)));
    ui->Z4->setText(QString(temp.Cialo(2,4)));

    ui->A0->setText(QString(temp.Cialo(4,0)));
    ui->A2->setText(QString(temp.Cialo(4,2)));
    ui->A4->setText(QString(temp.Cialo(4,4)));
   }

   else if (r.getWygrana()==false)
   {
       klik=false;
       string linia2="Wygrana:"+to_string(r.getGracz());
       ui->wyswietlacz->setText(QString::fromStdString(linia2));
       //r.czyscPlansze();


   }
   if(r.getTura()==9)
   {
       klik=false;
       ui->wyswietlacz->setText("Remis");
       Sleep(100);
   }
}



