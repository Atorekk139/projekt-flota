#include <iostream>
#include <stdexcept>
#include <string>
#include "Flota.h"

using namespace std;

int main() {
    Flota mojaFlota;

    // Przykladowe pojazdy na start, zeby lista nie byla pusta
    mojaFlota.dodajPojazd(new PojazdCiezarowy("Volvo", "FH16", "WA98765", 120000, 24.5));
    mojaFlota.dodajPojazd(new PojazdOsobowy("Toyota", "Corolla", "DW12345", 15000, 5));

    int wybor = -1;

    while (wybor != 0) {
        cout << "\n=== MENU SYSTEMU FLOTY ===" << endl;
        cout << "1. Wyswietl wszystkie pojazdy" << endl;
        cout << "2. Dodaj pojazd osobowy" << endl;
        cout << "3. Dodaj pojazd ciezarowy" << endl;
        cout << "4. Posortuj pojazdy rosnaco po koszcie eksploatacji" << endl;
        cout << "0. Wyjdz z programu" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;

        if (wybor == 1) {
            cout << "\nAktualna flota:" << endl;
            mojaFlota.wyswietlWszystkie();
        }
        else if (wybor == 2) {
            string marka, model, rejestracja;
            double przebieg;
            int miejsca;

            cout << "Marka: ";
            cin >> marka;
            cout << "Model: ";
            cin >> model;
            cout << "Rejestracja: ";
            cin >> rejestracja;
            cout << "Przebieg (km): ";
            cin >> przebieg;
            cout << "Liczba miejsc: ";
            cin >> miejsca;

            try {
                mojaFlota.dodajPojazd(new PojazdOsobowy(marka, model, rejestracja, przebieg, miejsca));
                cout << "Dodano pojazd osobowy!" << endl;
            }
            catch (const exception& e) {
                cout << "Blad: " << e.what() << endl;
            }
        }
        else if (wybor == 3) {
            string marka, model, rejestracja;
            double przebieg, ladownosc;

            cout << "Marka: ";
            cin >> marka;
            cout << "Model: ";
            cin >> model;
            cout << "Rejestracja: ";
            cin >> rejestracja;
            cout << "Przebieg (km): ";
            cin >> przebieg;
            cout << "Ladownosc (t): ";
            cin >> ladownosc;

            try {
                mojaFlota.dodajPojazd(new PojazdCiezarowy(marka, model, rejestracja, przebieg, ladownosc));
                cout << "Dodano pojazd ciezarowy!" << endl;
            }
            catch (const exception& e) {
                cout << "Blad: " << e.what() << endl;
            }
        }
        else if (wybor == 4) {
            mojaFlota.sortujPoKoszcie();
            cout << "Posortowano pojazdy po koszcie eksploatacji!" << endl;
        }
        else if (wybor == 0) {
            cout << "Zamykanie programu..." << endl;
        }
        else {
            cout << "Nieznana opcja, sprobuj ponownie." << endl;
        }
    }

    return 0;
}