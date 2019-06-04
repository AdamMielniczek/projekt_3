#ifndef PLANSZA_H_INCLUDED
#define PLANSZA_H_INCLUDED
#include <iostream>
#include <vector>

#define ROZMIAR 6

using namespace std;

const char remis = -1;
const char puste = 0;
const char krzyzyk = 1;
const char kolko = 2;
const char nikt = 3;


class Plansza{
    unsigned char rozmiar;
    unsigned char liczba_w_rzedzie;
    char pole[ROZMIAR][ROZMIAR];

public:
    Plansza(unsigned char rozmiar, unsigned char liczba_w_rzedzie);
    void wyswietlPlansze();
    char wez_wartosc(unsigned char kolumna, unsigned char wiersz);
    void ustaw_wartosc(unsigned char kolumna, unsigned char wiersz, char wartosc);
    unsigned char wezRozmiar();
    char czyWygrana();
    bool czyZostalyRuchy();
//    std::vector<char> serialize();
    std::string stringify();
};


#endif // PLANSZA_H_INCLUDED

