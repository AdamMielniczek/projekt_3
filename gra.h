#ifndef GRA_H_INCLUDED
#define GRA_H_INCLUDED
#include "plansza.h"
#include "minimax.h"


enum Stan {GRA, WYJSCIE};

class Gra{
public:
    void start();

private:
    void rozpocznij();
    void kolejGracza();
    void kolejKomputera();
    void zmienGracza();
    void zakonczGre(int Kto);

    Plansza* plansza;
    int aktualnyGracz;
    int komputer;
    Stan status;
    MINIMAX minimax;
    bool multiplayer;
};
#endif // GRA_H_INCLUDED

