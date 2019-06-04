#ifndef MINIMAX_H_INCLUDED
#define MINIMAX_H_INCLUDED
#include "plansza.h"
#include <unordered_map>
#include <vector>

struct RuchMINIMAX{
    RuchMINIMAX() = default;
    unsigned char x;
    unsigned char y;
};

class MINIMAX{
public:
    void rozpocznij(unsigned char graczMINIMAX);
    void wykonajRuch(Plansza *plansza);
    int minimax(Plansza *plansza, bool isMax);
    RuchMINIMAX znajdzNajlepszyRuch(Plansza *plansza);
private:
    char komputer;
    char czlowiek;

    std::unordered_map<std::string, int> cache;
};


#endif // MINIMAX_H_INCLUDED
