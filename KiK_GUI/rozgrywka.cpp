#include "rozgrywka.h"
#include<math.h>
#include<windows.h>
#include <ctime>
#include<cstdlib>

Rozgrywka::Rozgrywka()
    {
        gracz = 'O';
        x = 0;
        y = 0;
        tura = 0;
        wKolko=0;
        wRemis = 0;
        wKrzyzyk = 0;
        ruch=' ';
        wygrana = true;
        wKolko = 0;
        wKrzyzyk = 0;
        czyKomputer = false;

    }
Rozgrywka::Rozgrywka(bool lCzyKomputer)
{
    gracz = 'X';
    x = 0;
    y = 0;
    tura = 0;

    czyKomputer = lCzyKomputer;

}
void Rozgrywka::nastepnyRuch(Plansza moja, char tGracz,int tX,int tY, int tTura,int poziom)
{
    Plansza temp = moja;

    int wspx, wspy;
    long long max = -1000000000000;


    if (temp.czyPuste(tX, tY))
    {
        temp.wstawPerma(tX, tY, tGracz,tTura);
        if (temp.czyWygrana(tGracz))
        {
            if (tGracz == 'O')
            {
                wKolko+=100000 / (pow(3,tTura - 2));
            }
            else
            {
                wKrzyzyk += 100000 / (pow(3, tTura - 2));
            }
            return;
        }
        if (tGracz == 'O')
        {
            tGracz = 'X';
        }
        else
        {
            tGracz = 'O';
        }

    }
    if (tTura == 9)
    {
        temp.kopiuj();
        wRemis++;

       // temp.wyswietlPlansze(false);

        return;
    }
    for (int i=0;i<5;i+=2)
    {
        for (int j = 0; j < 5; j += 2)
        {
            if(temp.czyPuste(j, i))
            {
                nastepnyRuch(temp, tGracz, j, i, tTura+1,poziom+1);
                if (poziom == 1)
                {
                    if (tGracz == 'O')
                    {
                        //cout << j/2 << " " << i/2 << " " << wKolko << " " << " " << wKrzyzyk << " " <<  wKolko- wKrzyzyk << endl;
                        if (wKolko - wKrzyzyk > max)
                        {
                            max = wKolko - wKrzyzyk;
                            wspx = j;
                            wspy = i;
                        }
                    }
                    else
                    {
                        //cout << j/2 << " " << i/2 << " " << wKolko << " " << " " << wKrzyzyk << " " << wKrzyzyk - wKolko << endl;
                        if ( wKrzyzyk-wKolko > max)
                        {
                            max = wKrzyzyk - wKolko;
                            wspx = j;
                            wspy = i;
                        }

                    }

                    wKolko = 0;
                    wKrzyzyk = 0;
                }
            }
        }
    }
    if (poziom == 1)
    {
        x = wspx;
        y = wspy;
       // cout << x/2 << " " << y/2 << " " << max << endl;
        max = -1000000000000;
    }
}
Plansza Rozgrywka::Start(char wybor,bool klik)
    {



        wKolko = 0;
        wKrzyzyk = 0;
        //while (wygrana==true)
        {
            if(klik==true)
            {


                ruch=wybor;
               // a.wyswietlPlansze(true);
                //if (czyKomputer == false||tura%2==0)
                {
                    /*if (tura == 0)
                    {
                        srand(time(NULL));
                        x = rand() % 3 * 2;
                        y = rand() % 3 * 2;
                        ruch = 13;
                    }
                    else
                    {
                        //nastepnyRuch(a, gracz, x, y, tura, 1);
                        //ruch = _getch();
                        ruch = 13;
                    }*/


                }
                if (tura % 2 == 1)
                {
                    nastepnyRuch(a, gracz, x, y, tura,1);

                    ruch = 13;


                }

                switch (ruch)
                {

                case 'W':


                    y -= 2;
                    if (y == -2)
                    {
                        y = 4;
                    }
                    break;
                case 'S':
                    y += 2;
                    if (y == 6)
                    {
                        y = 0;
                    }

                    break;
                case 'A':
                    x -= 2;
                    if (x == -2)
                    {
                        x = 4;
                    }

                    break;
                case 'D':
                    x += 2;
                    if (x == 6)
                    {
                        x = 0;
                    }

                    break;
                case 13:
                    if (a.czyPuste(x, y))
                    {
                        tura++;
                      //  cout << tura << endl;
                        a.wstawPerma(x, y, gracz, tura);
                        a.kopiuj();
                        //a.wyswietlPlansze(true);
                        if (a.czyWygrana(gracz) == true)
                        {
                         //   cout << "Wygral " << gracz << endl;
                            wygrana = false;
                            break;
                            a.przygotowaniePlanszy();
                            tura=1;
                        }
                        if (gracz == 'O')
                        {

                            gracz = 'X';
                        }
                        else
                        {

                            gracz = 'O';
                        }
                    }

                    break;
                    klik=false;
                }

            }
            else
            {
                Sleep(1);
            }
            a.kopiuj();
            a.wstaw(x, y, gracz);


        }

        return a;
    }


int Rozgrywka::getX(){
    return x;
}
int Rozgrywka::getY(){
    return y;
}
int Rozgrywka::getTura(){
    return tura;
}
bool Rozgrywka::getWygrana(){
    return wygrana;
}
char Rozgrywka::getGracz()
{
    return gracz;
}
void Rozgrywka::czyscPlansze()
{
    a.przygotowaniePlanszy();
    wygrana=false;
}
