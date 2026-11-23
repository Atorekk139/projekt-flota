#ifndef FLOTA_H
#define FLOTA_H

#include <vector>
#include "Pojazd.h"

using namespace std;

// Klasa zarzadzajaca kolekcja wskaznikow na obiekty typu Pojazd
class Flota {
private:
    vector<Pojazd*> pojazdy;

public:
    ~Flota(); // Zwalnia pamiec po obiektach utworzonych przez new
    void dodajPojazd(Pojazd* p);
    void sortujPoKoszcie(); // Sortuje pojazdy rosnaco po koszcie eksploatacji (uzywa operatora <)
    void wyswietlWszystkie() const;
};

#endif