#include "plansza.h"


 void Plansza::przygotowaniePlanszy()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (i % 2 == 1)
                {
                    permaMapa[i][j] = '-';
                }
                else if (j % 2 == 1)
                {
                    permaMapa[i][j] = '|';
                }
                else
                {
                    permaMapa[i][j] = ' ';
                }

            }
        }
tura=0;

    }
 void Plansza::wyswietlPlansze(bool czyszczenie)
    {

    }
    void Plansza::wstawPerma(int px, int py, char ruch, int tura)
    {
        permaMapa[py][px] = ruch;
        tura++;
    }
    void Plansza::wstaw(int px, int py, char ruch)
    {
        mapa[py][px] = ruch;
    }
    void Plansza:: kopiuj()
    {
        for (int i = 0; i < 5; i++)
        {

            for (int j = 0; j < 5; j++)
            {
                mapa[i][j] = permaMapa[i][j];
            }

        }
    }
    bool Plansza:: czyPuste(int x,int y)
    {
        if (permaMapa[y][x] == ' ')
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    bool Plansza:: czyWygrana(char gracz)
    {

            for (int i = 0; i < 5; i += 2)
            {
                if (permaMapa[i][0] == gracz && permaMapa[i][2] == gracz && permaMapa[i][4] == gracz ||
                    permaMapa[0][i] == gracz && permaMapa[2][i] == gracz && permaMapa[4][i] == gracz ||
                    permaMapa[0][0] == gracz && permaMapa[2][2] == gracz && permaMapa[4][4] == gracz ||
                    permaMapa[0][4] == gracz && permaMapa[2][2] == gracz && permaMapa[4][0] == gracz)
                {
                    return true;
                }

            }
            return false;

    }

    Plansza::Plansza()
    {
        przygotowaniePlanszy();
    }
    char Plansza::Cialo(int x,int y)
    {

        return mapa[x][y];
    }

