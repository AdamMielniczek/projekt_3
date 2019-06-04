#include <iostream>
#include "plansza.h"
#include "gra.h"
#include "minimax.h"

using namespace std;
//main zajmuje sie tylko samym odpaleniem gry
int main()
{
    auto kolkokrzyzyk = new Gra();
    kolkokrzyzyk->start();

    return 0;
}
