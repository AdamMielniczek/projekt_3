#include <sstream>
#include "plansza.h"
#include "gra.h"
Plansza::Plansza(unsigned char rozmiar, unsigned char liczba_w_rzedzie) : rozmiar(rozmiar), liczba_w_rzedzie(liczba_w_rzedzie) {
    for (unsigned char i = 0; i < rozmiar; i++) {
        for (unsigned char j = 0; j < rozmiar; j++) {
            pole[i][j] = puste;
        }
    }
}

std::string Plansza::stringify() {
    std::stringstream ss;

    for (unsigned char i = 0; i < rozmiar; i++) {
        for (unsigned char j = 0; j < rozmiar; j++) {
            ss << pole[i][j];
        }
    }

    return ss.str();
}

bool Plansza::czyZostalyRuchy() {
    for (unsigned char i = 0; i < rozmiar; i++) {
        for (unsigned char j = 0; j < rozmiar; j++) {
            if (pole[i][j] == puste) {
                return true;
            }
        }
    }
    return false;
}

void Plansza::wyswietlPlansze() {
    cout << "----------" << endl;
    for (unsigned char i = 0; i < rozmiar; i++) {
        for (unsigned char j = 0; j < rozmiar; j++) {
            if (pole[i][j] == puste) { cout << "#" << " "; }
            else if (pole[i][j] == kolko) { cout << "O" << " "; }
            else if (pole[i][j] == krzyzyk) { cout << "X" << " "; }
        }
        cout << endl;
    }
}

void Plansza::ustaw_wartosc(unsigned char kolumna, unsigned char wiersz, char wartosc) {
    pole[wiersz][kolumna] = wartosc;
}

char Plansza::wez_wartosc(unsigned char kolumna, unsigned char wiersz) {
    return pole[wiersz][kolumna];
}

unsigned char Plansza::wezRozmiar() {
    return rozmiar;
}

char Plansza::czyWygrana() {
    unsigned char o_licznik = 0;
    unsigned char x_licznik = 0;
    if (!czyZostalyRuchy()) {
        return remis;
    }
    //sprawdz kolumny
    for (unsigned char i = 0; i < rozmiar; ++i) {
        o_licznik = 0;
        x_licznik = 0;

        for (unsigned char  j = 0; j < rozmiar; ++j) {
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

    for (unsigned char i = 0; i < rozmiar; ++i) {
        o_licznik = 0;
        x_licznik = 0;

        for (unsigned char  j = 0; j < rozmiar; ++j) {
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
    for (unsigned char i = 0; i < (rozmiar - liczba_w_rzedzie + 1); ++i) {

        o_licznik = 0;
        x_licznik = 0;

        for (unsigned char  j = 0; j < rozmiar - i; ++j) {
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
    for (unsigned char i = 0; i < (rozmiar - liczba_w_rzedzie + 1); ++i) {

        o_licznik = 0;
        x_licznik = 0;

        for (unsigned char  j = 0; j < rozmiar - i; ++j) //+W GORE
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
    for (unsigned char i = 0; i < (rozmiar - liczba_w_rzedzie + 1); ++i) {

        o_licznik = 0;
        x_licznik = 0;

        for (unsigned char j = 0; j < rozmiar; ++j) {
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
    for (unsigned char i = 0; i < (rozmiar - liczba_w_rzedzie + 1); ++i) {

        o_licznik = 0;
        x_licznik = 0;

        for (unsigned char j = 0; j < rozmiar; ++j) {
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
