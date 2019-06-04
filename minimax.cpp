#include "minimax.h"

void MINIMAX::rozpocznij(unsigned char graczMINIMAX) {
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
    RuchMINIMAX ruch{};
    ruch.x = CHAR_MAX;
    ruch.y = CHAR_MAX;

    // Przejście przez wszystkie komórki, ocena funkcji minimaks dla
    // wszystkie puste komórki. I zwróć komórkę z optymalnym wartość.


    // przejdź przez wszystkie komórki
    for (unsigned char x = 0; x < plansza->wezRozmiar(); x++) {
        for (unsigned char y = 0; y < plansza->wezRozmiar(); y++) {
            // Sprawdź, czy komórka jest pusta
            if (plansza->wez_wartosc(x, y) == puste) {
                // Wykonaj ruch
                plansza->ustaw_wartosc(x, y, komputer);

                // przelicz
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

//    std::vector<char> planszaSkompresowanaOld = plansza->serialize();
    std::string planszaSkompresowana = plansza->stringify();

    auto szukaj = cache.find(planszaSkompresowana);
    if (szukaj != cache.end()) {
        return szukaj->second;
    }

    if (!plansza->czyZostalyRuchy()) {
        cache.insert(std::make_pair(planszaSkompresowana, 0));
        return 0;
    }

    int ow = plansza->czyWygrana();
    if (ow == komputer) {
        cache.insert(std::make_pair(planszaSkompresowana, 10));
        return 10;
    }
    if (ow == czlowiek) {
        cache.insert(std::make_pair(planszaSkompresowana, -10));
        return -10;
    }

    if (isMax) {
        int najlepszyWybor = -1000000;

        for (unsigned char x = 0; x < plansza->wezRozmiar(); x++) {
            for (unsigned char y = 0; y < plansza->wezRozmiar(); y++) {
                if (plansza->wez_wartosc(x, y) == puste) {

                    plansza->ustaw_wartosc(x, y, komputer);

                    // Wywołaj minimaks rekurencyjnie i wybierz maksymalna wartość
                    najlepszyWybor = max(najlepszyWybor, minimax(plansza, !isMax));

                    plansza->ustaw_wartosc(x, y, puste);
                }
            }
        }
        cache.insert(std::make_pair(plansza->stringify(), najlepszyWybor));
        return najlepszyWybor;
    }

    else {
        int najlepszyWybor = 1000000;


        for (unsigned char x = 0; x < plansza->wezRozmiar(); x++) {
            for (unsigned char y = 0; y < plansza->wezRozmiar(); y++) {
                if (plansza->wez_wartosc(x, y) == puste) {
                    plansza->ustaw_wartosc(x, y, czlowiek);

                    // Wywołaj minimaks rekurencyjnie i wybierz minimalna wartość
                    najlepszyWybor = min(najlepszyWybor, minimax(plansza, !isMax));

                    plansza->ustaw_wartosc(x, y, puste);
                }
            }
        }
        cache.insert(std::make_pair(plansza->stringify(), najlepszyWybor));
        return najlepszyWybor;
    }
}
