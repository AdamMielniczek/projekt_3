#include "plansza.h"

Plansza::Plansza(int rozmiar, int liczba_w_rzedzie) : rozmiar(rozmiar), liczba_w_rzedzie(liczba_w_rzedzie) {
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            pole[i][j] = puste;
        }
    }
}

bool Plansza::czyZostalyRuchy() {
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            if (pole[i][j] == puste) {
                return true;
            }
        }
    }
    return false;
}

void Plansza::wyswietlPlansze() {
    cout << "----------" << endl;
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            if (pole[i][j] == puste) { cout << "#" << " "; }
            else if (pole[i][j] == kolko) { cout << "O" << " "; }
            else if (pole[i][j] == krzyzyk) { cout << "X" << " "; }
        }
        cout << endl;
    }
}

void Plansza::ustaw_wartosc(int kolumna, int wiersz, int wartosc) {
    pole[wiersz][kolumna] = wartosc;
}

int Plansza::wez_wartosc(int kolumna, int wiersz) {
    return pole[wiersz][kolumna];
}

int Plansza::wez_rozmiar() {
    return rozmiar;
}

int Plansza::czyWygrana() {
    int o_licznik = 0;
    int x_licznik = 0;

    //sprawdz kolumny
    for (int i = 0; i < rozmiar; ++i) {
        o_licznik = 0;
        x_licznik = 0;

        for (int j = 0; j < rozmiar; ++j) {
            if (pole[j][i] == kolko) {
                x_licznik = 0;
                o_licznik += 1;
            }
            if (pole[j][i] == krzyzyk) {
                o_licznik = 0;
                x_licznik += 1;
            }
            if (pole[j][i] == puste) {
                o_licznik = 0;
                x_licznik = 0;
            }
        }

        if (o_licznik == liczba_w_rzedzie) return kolko;
        if (x_licznik == liczba_w_rzedzie) return krzyzyk;
    }

    //sprawdz wiersze
    // TODO: skleic w mniej petli
    for (int i = 0; i < rozmiar; ++i) {
        o_licznik = 0;
        x_licznik = 0;

        for (int j = 0; j < rozmiar; ++j) {
            if (pole[i][j] == kolko) {
                x_licznik = 0;
                o_licznik += 1;
            }
            if (pole[i][j] == krzyzyk) {
                o_licznik = 0;
                x_licznik += 1;
            }
            if (pole[i][j] == puste) {
                o_licznik = 0;
                x_licznik = 0;
            }
        }

        if (o_licznik == liczba_w_rzedzie) return kolko;
        if (x_licznik == liczba_w_rzedzie) return krzyzyk;
    }

    //sprawdz przekatne lewa-prawa liczac w dol
    for (int i = 0; i < (rozmiar - liczba_w_rzedzie + 1); ++i) {

        o_licznik = 0;
        x_licznik = 0;

        for (int j = 0; j < rozmiar - i; ++j) {
            if (pole[j + i][j] == kolko) {
                x_licznik = 0;
                o_licznik += 1;
            }
            if (pole[j + i][j] == krzyzyk) {
                o_licznik = 0;
                x_licznik += 1;
            }
            if (pole[j + i][j] == puste) {
                o_licznik = 0;
                x_licznik = 0;
            }
        }

        if (o_licznik == liczba_w_rzedzie) return kolko;
        if (x_licznik == liczba_w_rzedzie) return krzyzyk;
    }

    //sprawdz przekatne lewa-prawa liczac w dol
    for (int i = 0; i < (rozmiar - liczba_w_rzedzie + 1); ++i) {

        o_licznik = 0;
        x_licznik = 0;

        for (int j = 0; j < rozmiar - i; ++j) //+W GORE
        {
            if (pole[j][j + i] == kolko) {
                x_licznik = 0;
                o_licznik += 1;
            }
            if (pole[j][j + i] == krzyzyk) {
                o_licznik = 0;
                x_licznik += 1;
            }
            if (pole[j][j + i] == puste) {
                o_licznik = 0;
                x_licznik = 0;
            }
        }

        if (o_licznik == liczba_w_rzedzie) return kolko;
        if (x_licznik == liczba_w_rzedzie) return krzyzyk;
    }

    //sprawdz przekatne prawa-lewa liczac w dol
    for (int i = 0; i < (rozmiar - liczba_w_rzedzie + 1); ++i) {

        o_licznik = 0;
        x_licznik = 0;

        for (int j = 0; j < rozmiar; ++j) {
            if (pole[j + i][rozmiar - 1 - j] == kolko) {
                x_licznik = 0;
                o_licznik += 1;
            }
            if (pole[j + i][rozmiar - 1 - j] == krzyzyk) {
                o_licznik = 0;
                x_licznik += 1;
            }
            if (pole[j + i][rozmiar - 1 - j] == puste) {
                o_licznik = 0;
                x_licznik = 0;
            }
        }

        if (o_licznik == liczba_w_rzedzie) return kolko;
        if (x_licznik == liczba_w_rzedzie) return krzyzyk;
    }

    //sprawdz przekatne prawa-lewa liczac w gore
    for (int i = 0; i < (rozmiar - liczba_w_rzedzie + 1); ++i) {

        o_licznik = 0;
        x_licznik = 0;

        for (int j = 0; j < rozmiar; ++j) {
            if (pole[j][rozmiar - 1 - j - i] == kolko) {
                x_licznik = 0;
                o_licznik += 1;
            }
            if (pole[j][rozmiar - 1 - j - i] == krzyzyk) {
                o_licznik = 0;
                x_licznik += 1;
            }
            if (pole[j][rozmiar - 1 - j - i] == puste) {
                o_licznik = 0;
                x_licznik = 0;
            }
        }

        if (o_licznik == liczba_w_rzedzie) return kolko;
        if (x_licznik == liczba_w_rzedzie) return krzyzyk;
    }

    //jesli nic innego nie jest poprawne to wtedy jest remis
    return nikt;
}


