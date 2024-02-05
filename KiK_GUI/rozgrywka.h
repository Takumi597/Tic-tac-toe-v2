#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H
#include "plansza.h"



class Rozgrywka
{
private:
    int x, y, tura;
    char gracz;
    Plansza a;
    bool czyKomputer;
    int wRemis;
    long long wKolko;
    long long wKrzyzyk;
    char ruch;
    bool wygrana;
    void nastepnyRuch(Plansza moja, char tGracz,int tX,int tY, int tTura,int poziom);

public:

    Rozgrywka();
    Rozgrywka(bool lCzyKomputer);

    int getX();
    int getY();
    int getTura();
    char getGracz();
    bool getWygrana();
    void czyscPlansze();
    Plansza Start(char wybor,bool klik);

};
#endif
