#include "gra.h"
#include <string>

void Gra::start() {
    rozpocznij();

    while (status != WYJSCIE) {
        plansza->wyswietlPlansze();

        if (aktualnyGracz == krzyzyk) {
            cout << "\n\nGra KRZYZYK!\n\n";
        } else {
            cout << "\n\nGra KOLKO!\n\n";
        }

        if (!multiplayer && aktualnyGracz == komputer) {
            kolejKomputera();
        } else {
            kolejGracza();
        }

        if (!plansza->czyZostalyRuchy()) {
            int ow = plansza->czyWygrana();
            zakoncz_gre(ow == remis);
        }

        zmien_gracza();

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
}

void Gra::rozpocznij() {
    int M, A;
    cout << "\n GRA KOLKO I KRZYZYK \n\n";
    cout << "Wprowadz rozmiar planszy M (ilosc wierszy i ilosc kolumn),\n";
    cout << "a nastepnie podaj ile symboli musi sie znajdowac pod rzad,\n";
    cout << "zeby gra sie zakonczyla (A)\n";
    cout << "Minimalne wartosci to 3, a maksymalne to 10\n\n";
    cout << "M = ";
    cin >> M;
    cout << "A = ";
    cin >> A;

    status = GRA;
    plansza = new Plansza(M, A);
    aktualnyGracz = krzyzyk;


    cout << "\n\nCzy chcesz zagrac z druga osoba(MULTIPLAYER)?\n t/n: ";
    bool czyPrawidlowy;
    char multi;

    do {
        czyPrawidlowy = true;
        if (!(cin >> multi)) {
            cout << "Blad!";
            cin.clear();
            cin.ignore(1000, '\n');
            czyPrawidlowy = false;
        } else if (multi == 't' || multi == 'T') {
            multiplayer = true;
        } else {
            multiplayer = false;
        }
    } while (!czyPrawidlowy);

    if (!multiplayer) {
        cout << "\nChcesz byc O czy X? : \n";

        do {
            czyPrawidlowy = true;

            if (!(cin >> multi)) {
                cout << "Blad!";
                cin.clear();
                cin.ignore(1000, '\n');
                czyPrawidlowy = false;
            } else if (multi == 'x' || multi == 'X') {
                komputer = kolko;
            } else if (multi == 'o' || multi == 'O') {
                komputer = krzyzyk;
            } else {
                cout << "Blad! Wpisz X lub O!";
                czyPrawidlowy = false;
            }
        } while (!czyPrawidlowy);

        minimax.rozpocznij(komputer);
    }
    cout << "\n\n";
}

void Gra::kolejGracza() {
    bool bylDobry = false;
    int x, y;

    do {
        cout << "Numer kolumny: ";
        while (!(cin >> x)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Blad!";
        }
        cout << "Numer wiersza: ";
        while (!(cin >> y)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Blad!";
        }

        if (x < 1 || y < 1 || x > plansza->wez_rozmiar() || y > plansza->wez_rozmiar()) {
            cout << "Zbyt duze lub zbyt male wartosci!\n";
        } else if (plansza->wez_wartosc(x - 1, y - 1) != puste) {
            cout << "Plansza juz jest zajete!\n";
        } else {
            bylDobry = true;
        }
    } while (!bylDobry);

    plansza->ustaw_wartosc(x - 1, y - 1, aktualnyGracz);
}

void Gra::kolejKomputera() {
    minimax.wykonajRuch(plansza);
}

void Gra::zmien_gracza() {
    if (aktualnyGracz == krzyzyk) {
        aktualnyGracz = kolko;
    } else {
        aktualnyGracz = krzyzyk;
    }
}


void Gra::zakoncz_gre(bool bylRemis) {

    plansza->wyswietlPlansze();

    if (bylRemis) {
        cout << "\n\n REMIS!\n";
        cout << "\n\n wcisnij dowolna litere i enter,\n";
        cout << " zeby kontynuowac \n ";
        cout << " lub W zeby zakonczyc: ";
    } else {
        if (aktualnyGracz == krzyzyk) {
            cout << "\n\n KRZYZYK WYGRAL!\n";
            cout << "\n\n wcisnij dowolna litere i enter,\n";
            cout << " zeby kontynuowac \n ";
            cout << " lub W zeby zakonczyc: ";

        } else {
            cout << "\n\n WYGRALO KOLKO!\n";
            cout << "\n\n wcisnij dowolna litere i enter,\n";
            cout << " zeby kontynuowac \n ";
            cout << " lub W zeby zakonczyc: ";
        }

    }

    char wej;
    cin >> wej;
    if (wej == 'W' || wej == 'w') {
        status = WYJSCIE;
    } else {
        rozpocznij();
    }
}

