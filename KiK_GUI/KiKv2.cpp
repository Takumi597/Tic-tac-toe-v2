#include<time.h>
#include<cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;

class Plansza
{
private:
    char mapa[5][5];//[wiersz][kolumna]
    char permaMapa[5][5];
    int  tura = 0;
public:
    void przygotowaniePlanszy()
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

    }
    void wyswietlPlansze(bool czyszczenie)
    {
        if (czyszczenie == true)
        {
            system("CLS");
        }
        cout << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << " ";
            for (int j = 0; j < 5; j++)
            {
                cout << mapa[i][j];
            }
            cout << endl;
        }
    }
    void wstawPerma(int px, int py, char ruch, int tura)
    {
        permaMapa[py][px] = ruch;
        tura++;
    }
    void wstaw(int px, int py, char ruch)
    {
        mapa[py][px] = ruch;
    }
    void kopiuj()
    {
        for (int i = 0; i < 5; i++)
        {
           
            for (int j = 0; j < 5; j++)
            {
                mapa[i][j] = permaMapa[i][j];
            }
            
        }
    }
    bool czyPuste(int x,int y)
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
    bool czyWygrana(char gracz)
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
    Plansza()
    {
        przygotowaniePlanszy();
    }
};


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

    void nastepnyRuch(Plansza moja, char tGracz,int tX,int tY, int tTura,int poziom)
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
                            cout << j/2 << " " << i/2 << " " << wKolko << " " << " " << wKrzyzyk << " " <<  wKolko- wKrzyzyk << endl;
                            if (wKolko - wKrzyzyk > max)
                            {
                                max = wKolko - wKrzyzyk;
                                wspx = j;
                                wspy = i;
                            }
                        }
                        else
                        {
                            cout << j/2 << " " << i/2 << " " << wKolko << " " << " " << wKrzyzyk << " " << wKrzyzyk - wKolko << endl;
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
            cout << x/2 << " " << y/2 << " " << max << endl;
            max = -1000000000000;
        }
    }
public:
    void Start()
    {
        char ruch=' ';
        bool wygrana = true;
        wKolko = 0;
        wKrzyzyk = 0;
        while (wygrana==true)
        {
            a.kopiuj();
            a.wstaw(x, y, gracz);
            a.wyswietlPlansze(true);
            if (czyKomputer == false||tura%2==0)
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
                    nastepnyRuch(a, gracz, x, y, tura, 1);
                    ruch = _getch();
                    ruch = 13;
                }*/
                ruch = _getch();
                
            }
            else if (tura % 2 == 1)
            {
                nastepnyRuch(a, gracz, x, y, tura,1);
                ruch = _getch();
                ruch = 13;
                
                
            }
            
            switch (ruch)
            {
                
            case 'w':
                y -= 2;
                if (y == -2)
                {
                    y = 4;
                }
                break;
            case 's':
                y += 2;
                if (y == 6)
                {
                    y = 0;
                }
                
                break;
            case 'a':
                x -= 2;
                if (x == -2)
                {
                    x = 4;
                }

                break;
            case 'd':
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
                    cout << tura << endl;
                    a.wstawPerma(x, y, gracz, tura);
                    a.kopiuj();
                    a.wyswietlPlansze(true);
                    if (a.czyWygrana(gracz) == true)
                    {
                        cout << "Wygral " << gracz << endl;
                        wygrana = false;
                        break;
                    }
                    if (gracz == 'O')
                    {

                        gracz = 'X';
                    }
                    else
                    {

                        gracz = 'O';
                    }
                    if (tura == 9)
                    {
                        cout << "Remis" << endl;
                        wygrana = false;
                    }

                }
                break;
            }
                
            
        }
       
    }
    Rozgrywka()
    {
        gracz = 'O';
        x = 0;
        y = 0;
        tura = 0;
        wKolko=0;
        wRemis = 0;
        wKrzyzyk = 0;
        
        czyKomputer = false;

    }
    Rozgrywka(bool lCzyKomputer)
    {
        gracz = 'X';
        x = 0;
        y = 0;
        tura = 0;
        
        czyKomputer = lCzyKomputer;

    }
};

int main()
{
    Rozgrywka r(true);
    r.Start();
    
}


