#ifndef MINIMAX_H_INCLUDED
#define MINIMAX_H_INCLUDED
#include "plansza.h"

struct RuchMINIMAX{
    RuchMINIMAX() = default;
    int x;
    int y;
    int wartoscPola;
};

class MINIMAX{
public:
    void rozpocznij(int graczMINIMAX);
    void wykonajRuch(Plansza *plansza);
    int minimax(Plansza *plansza, bool isMax);
    RuchMINIMAX znajdzNajlepszyRuch(Plansza *plansza);
private:
    int komputer;
    int czlowiek;
};


#endif // MINIMAX_H_INCLUDED
