#include "gra.h"
#include <string>
#include "plansza.h"

void Gra::start() {
    menu();

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



        zmienGracza();

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
}

void Gra::menu() {
    unsigned char M, A;
    cout << "\n GRA KOLKO I KRZYZYK \n\n";
    cout << "Wprowadz rozmiar planszy M (ilosc wierszy i ilosc kolumn),\n";
    cout << "a nastepnie podaj ile symboli musi sie znajdowac pod rzad,\n";
    cout << "zeby gra sie zakonczyla (A)\n";
    cout << "Minimalne wartosci to 3, a maksymalne to 10\n\n";
    cout << "M = ";
    cin >> M;
    cout << "A = ";
    cin >> A;

    if(M >= 48){
        M -= 48;
    }
    if(A >= 48){
        A -= 48;
    }

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
    unsigned char x, y;

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
        if(x >= 48){
            x -= 48;
        }
        if(y >= 48){
            y -= 48;
        }

        if (x < 1 || y < 1 || x > plansza->wezRozmiar() || y > plansza->wezRozmiar()) {
            cout << "Zbyt duze lub zbyt male wartosci!\n";
        } else if (plansza->wez_wartosc(x - 1, y - 1) != puste) {
            cout << "Pole juz jest zajete!\n";
        } else {
            bylDobry = true;
        }
    } while (!bylDobry);

    plansza->ustaw_wartosc(x - 1, y - 1, aktualnyGracz);
}

void Gra::kolejKomputera() {
    minimax.wykonajRuch(plansza);
}

void Gra::zmienGracza() {
    zakonczGre(plansza->czyWygrana());
    if (aktualnyGracz == krzyzyk) {
        aktualnyGracz = kolko;
    } else {
        aktualnyGracz = krzyzyk;
    }
}


void Gra::zakonczGre(int Kto) {

    plansza->wyswietlPlansze();
    if (Kto==nikt){
        return ;
    }
    if (Kto==remis) {
        cout << "\n\n REMIS!\n";
        cout << "\n\n wcisnij dowolna litere i enter,\n";
        cout << " zeby kontynuowac \n ";
        cout << " lub W zeby zakonczyc: ";
    } else {
        if (Kto == krzyzyk) {
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
        menu();
    }
}

