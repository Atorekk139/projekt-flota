#include "Pojazd.h"
#include <iostream>

using namespace std;

Pojazd::Pojazd(string m, string mod, string rej, double prz) {
    marka = m;
    model = mod;
    rejestracja = rej;
    przebieg = prz;
}

string Pojazd::getRejestracja() const {
    return rejestracja;
}

void Pojazd::wyswietl() const {
    cout << marka << " " << model << " | Rejestracja: " << rejestracja << " | Przebieg: " << przebieg << " km";
}

PojazdOsobowy::PojazdOsobowy(string m, string mod, string rej, double prz, int miejsca) 
    : Pojazd(m, mod, rej, prz) {
    liczbaMiejsc = miejsca;
}

void PojazdOsobowy::wyswietl() const {
    Pojazd::wyswietl();
    cout << " | Miejsca: " << liczbaMiejsc << " | Koszt: " << obliczKosztEksploatacji() << " PLN" << endl;
}

double PojazdOsobowy::obliczKosztEksploatacji() const {
    return przebieg * 0.60;
}

PojazdCiezarowy::PojazdCiezarowy(string m, string mod, string rej, double prz, double lad) 
    : Pojazd(m, mod, rej, prz) {
    ladownosc = lad;
}

void PojazdCiezarowy::wyswietl() const {
    Pojazd::wyswietl();
    cout << " | Ladownosc: " << ladownosc << " t | Koszt: " << obliczKosztEksploatacji() << " PLN" << endl;
}

double PojazdCiezarowy::obliczKosztEksploatacji() const {
    return przebieg * 2.20;
}