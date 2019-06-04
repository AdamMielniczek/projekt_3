#include "minimax.h"
#include <vector>

void MINIMAX::rozpocznij(int graczMINIMAX) {
    komputer = graczMINIMAX;
    if (komputer == krzyzyk) {
        czlowiek = kolko;
    } else {
        czlowiek = krzyzyk;
    }
}

void MINIMAX::wykonajRuch(Plansza *plansza) {

    RuchMINIMAX najlepszy = znajdzNajlepszyRuch(plansza);

    plansza->ustaw_wartosc(najlepszy.x, najlepszy.y, komputer);
}

RuchMINIMAX MINIMAX::znajdzNajlepszyRuch(Plansza *plansza)
{
    int najlepszaWartosc = -1000;
    RuchMINIMAX ruch;
    ruch.x = -1;
    ruch.y = -1;



    // Przejście przez wszystkie komórki, ocena funkcji minimaks dla
    // wszystkie puste komórki. I zwróć komórkę z optymalnym wartość.


    // przejdź przez wszystkie komórki
    for (int x = 0; x < plansza->wez_rozmiar(); x++) {
        for (int y = 0; y < plansza->wez_rozmiar(); y++) {
            // Sprawdź, czy komórka jest pusta
            if (plansza->wez_wartosc(x, y) == puste) {
                // Wykonaj ruch
                plansza->ustaw_wartosc(x, y, komputer);


                int nowaWartosc = minimax(plansza, false);

                // Cofnij ruch
                plansza->ustaw_wartosc(x, y, puste);

                // Jeśli nowaWartosc jest więcej niż najlepsza wartość,
                //  a następnie zaktualizuj najlepszaWartosc
                if (nowaWartosc > najlepszaWartosc)
                {
                    ruch.x = x;
                    ruch.y = y;
                    najlepszaWartosc = nowaWartosc;
                }
            }
        }
    }

    return ruch;
}

int MINIMAX::minimax(Plansza *plansza, bool isMax) {
    if (!plansza->czyZostalyRuchy()) {

        return 0;
    }

    int ow = plansza->czyWygrana();
    if (ow == komputer) {
        return 10;
    }
    if (ow == czlowiek) {
        return -10;
    }


    if (isMax) {
        int najlepszyWybor = -1000000;


        for (int x = 0; x < plansza->wez_rozmiar(); x++) {
            for (int y = 0; y < plansza->wez_rozmiar(); y++) {

                if (plansza->wez_wartosc(x, y) == puste) {

                    plansza->ustaw_wartosc(x, y, komputer);

                    // Wywołaj minimaks rekurencyjnie i wybierz maksymalna wartość
                    najlepszyWybor = max(najlepszyWybor, minimax(plansza, !isMax));


                    plansza->ustaw_wartosc(x, y, puste);
                }
            }
        }
        return najlepszyWybor;
    }


    else {
        int najlepszyWybor = 1000000;



        for (int x = 0; x < plansza->wez_rozmiar(); x++) {
            for (int y = 0; y < plansza->wez_rozmiar(); y++) {

                if (plansza->wez_wartosc(x, y) == puste) {

                    plansza->ustaw_wartosc(x, y, czlowiek);

                    // Wywołaj minimaks rekurencyjnie i wybierz minimalna wartość
                    najlepszyWybor = min(najlepszyWybor, minimax(plansza, !isMax));


                    plansza->ustaw_wartosc(x, y, puste);
                }
            }
        }
        return najlepszyWybor;
    }
}
