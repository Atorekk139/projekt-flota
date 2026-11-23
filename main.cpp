#include <iostream>
#include <stdexcept>
#include "Flota.h"

using namespace std;

int main() {
    Flota mojaFlota;

    try {
        mojaFlota.dodajPojazd(new PojazdCiezarowy("Volvo", "FH16", "WA98765", 120000, 24.5));
        mojaFlota.dodajPojazd(new PojazdOsobowy("Toyota", "Corolla", "DW12345", 15000, 5));

        cout << "Poprawnie dodane pojazdy przed sortowaniem:" << endl;
        mojaFlota.wyswietlWszystkie();

        mojaFlota.sortujPoKoszcie();

        cout << "\nPojazdy posortowane po koszcie eksploatacji:" << endl;
        mojaFlota.wyswietlWszystkie();

        // Celowa proba utworzenia pojazdu z ujemnym przebiegiem w celu testu wyjatku
        cout << "\nProba dodania pojazdu z blednymi danymi..." << endl;
        mojaFlota.dodajPojazd(new PojazdOsobowy("Skoda", "Fabia", "DW00011", -500, 5));
    }
    catch (const exception& e) {
        // Przechwycenie wyjatku rzuconego przez konstruktor
        cout << "Blad: " << e.what() << endl;
    }

    return 0;
}