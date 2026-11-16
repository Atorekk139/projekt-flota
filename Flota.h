#ifndef FLOTA_H
#define FLOTA_H

#include <vector>
#include "Pojazd.h"

using namespace std;

class Flota {
private:
    vector<Pojazd> pojazdy;

public:
    void dodajPojazd(const Pojazd& p);
    void usunPojazd(string rej);
    void wyswietlWszystkie() const;
    Pojazd* znajdzPojazd(string rej);
};

#endif