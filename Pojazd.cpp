#include "Pojazd.h"
#include <iostream>

using namespace std;

Pojazd::Pojazd(string m, string mod, string rej, double prz) {
    marka = m;
    model = mod;
    rejestracja = rej;
    przebieg = prz;
}

string Pojazd::getMarka() const {
    return marka;
}

string Pojazd::getModel() const {
    return model;
}

string Pojazd::getRejestracja() const {
    return rejestracja;
}

double Pojazd::getPrzebieg() const {
    return przebieg;
}

void Pojazd::setPrzebieg(double prz) {
    przebieg = prz;
}

void Pojazd::wyswietl() const {
    cout << marka << " " << model << " | Rejestracja: " << rejestracja << " | Przebieg: " << przebieg << " km" << endl;
}