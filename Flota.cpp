#include "Flota.h"

using namespace std;

Flota::~Flota() {
    for (size_t i = 0; i < pojazdy.size(); i++) {
        delete pojazdy[i];
    }
}

void Flota::dodajPojazd(Pojazd* p) {
    pojazdy.push_back(p);
}

void Flota::wyswietlWszystkie() const {
    for (size_t i = 0; i < pojazdy.size(); i++) {
        pojazdy[i]->wyswietl();
    }
}