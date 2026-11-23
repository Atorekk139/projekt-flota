#include "Flota.h"
#include <iostream>
#include <algorithm>

using namespace std;

Flota::~Flota() {
    for (size_t i = 0; i < pojazdy.size(); i++) {
        delete pojazdy[i];
    }
}

void Flota::dodajPojazd(Pojazd* p) {
    pojazdy.push_back(p);
}

void Flota::sortujPoKoszcie() {
    // Komparator dereferencjonuje wskazniki i uzywa przeciazonego operatora <
    sort(pojazdy.begin(), pojazdy.end(), [](const Pojazd* a, const Pojazd* b) {
        return *a < *b;
    });
}

void Flota::wyswietlWszystkie() const {
    for (size_t i = 0; i < pojazdy.size(); i++) {
        // Wykorzystanie przeciazonego operatora << do wypisania obiektu
        cout << *pojazdy[i] << endl;
    }
}