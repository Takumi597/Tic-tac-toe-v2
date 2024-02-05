#ifndef PLANSZA_H
#define PLANSZA_H


class Plansza
{
private:
    char mapa[5][5];//[wiersz][kolumna]
    char permaMapa[5][5];
    int  tura = 0;
public:
    Plansza();
    void przygotowaniePlanszy();

    void wyswietlPlansze(bool czyszczenie);

    void wstawPerma(int px, int py, char ruch, int tura);

    void wstaw(int px, int py, char ruch);

    void kopiuj();

    bool czyPuste(int x,int y);
    bool czyWygrana(char gracz);
    char Cialo(int x, int y);

};

#endif // PLANSZA_H
