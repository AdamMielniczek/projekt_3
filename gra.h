#ifndef GRA_H_INCLUDED
#define GRA_H_INCLUDED
#include "plansza.h"
#include "minimax.h"


enum Stan {GRA, WYJSCIE};

class Gra{
public:
    void start();

private:
    void menu();
    void kolejGracza();
    void kolejKomputera();
    void zmienGracza();
    void zakonczGre(int Kto);

    Plansza* plansza;
    unsigned char aktualnyGracz;
    unsigned char komputer;
    Stan status;
    MINIMAX minimax;
    bool multiplayer;
};
#endif // GRA_H_INCLUDED

