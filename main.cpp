#include <iostream>
#include "Flota.h"

using namespace std;

int main() {
    Flota mojaFlota;

    // Dodajemy pojazdy - ciezarowy ma wyzszy koszt, osobowy nizszy
    mojaFlota.dodajPojazd(new PojazdCiezarowy("Volvo", "FH16", "WA98765", 120000, 24.5));
    mojaFlota.dodajPojazd(new PojazdOsobowy("Toyota", "Corolla", "DW12345", 15000, 5));

    cout << "Flota przed sortowaniem:" << endl;
    mojaFlota.wyswietlWszystkie();

    // Sortowanie wykorzystuje przeciazony operator <
    mojaFlota.sortujPoKoszcie();

    cout << "\nFlota po sortowaniu rosnaco po koszcie eksploatacji:" << endl;
    mojaFlota.wyswietlWszystkie();

    return 0;
}