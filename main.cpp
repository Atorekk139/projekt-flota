#include <iostream>
#include "Flota.h"

using namespace std;

int main() {
    Flota mojaFlota;

    mojaFlota.dodajPojazd(Pojazd("Toyota", "Corolla", "DW12345", 15000));
    mojaFlota.dodajPojazd(Pojazd("Skoda", "Octavia", "DW67890", 35000));

    cout << "Aktualna flota pojazdow:" << endl;
    mojaFlota.wyswietlWszystkie();

    return 0;
}