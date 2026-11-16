#include "Flota.h"
#include <iostream>

using namespace std;

void Flota::dodajPojazd(const Pojazd& p) {
    pojazdy.push_back(p);
}

void Flota::usunPojazd(string rej) {
    for (size_t i = 0; i < pojazdy.size(); i++) {
        if (pojazdy[i].getRejestracja() == rej) {
            pojazdy.erase(pojazdy.begin() + i);
            break;
        }
    }
}

void Flota::wyswietlWszystkie() const {
    for (size_t i = 0; i < pojazdy.size(); i++) {
        pojazdy[i].wyswietl();
    }
}

Pojazd* Flota::znajdzPojazd(string rej) {
    for (size_t i = 0; i < pojazdy.size(); i++) {
        if (pojazdy[i].getRejestracja() == rej) {
            return &pojazdy[i];
        }
    }
    return nullptr;
}