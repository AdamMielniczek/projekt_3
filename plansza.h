#ifndef PLANSZA_H_INCLUDED
#define PLANSZA_H_INCLUDED
#include <iostream>

#define ROZMIAR 10

using namespace std;

const int remis = -1;
const int puste = 0;
const int krzyzyk = 1;
const int kolko = 2;


class Plansza{
    int rozmiar;
    int liczba_w_rzedzie;
    int pole[ROZMIAR][ROZMIAR] ;

public:
    Plansza(int rozmiar, int liczba_wygrana);
    void wyswietlPlansze();
    int wez_wartosc(int kolumna, int wiersz);
    void ustaw_wartosc(int kolumna, int wiersz, int wartosc);
    int wez_rozmiar();
    int czyWygrana();
    bool czyZostalyRuchy();
};


#endif // PLANSZA_H_INCLUDED

