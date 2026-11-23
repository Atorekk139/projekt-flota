#include "Pojazd.h"
#include <stdexcept>

using namespace std;

Pojazd::Pojazd(string m, string mod, string rej, double prz) {
    // Walidacja danych wejsciowych - rzucamy wyjatek przy blednych wartosciach
    if (rej.empty()) {
        throw invalid_argument("Numer rejestracyjny nie moze byc pusty!");
    }
    if (prz < 0) {
        throw invalid_argument("Przebieg pojazdu nie moze byc ujemny!");
    }

    marka = m;
    model = mod;
    rejestracja = rej;
    przebieg = prz;
}

string Pojazd::getRejestracja() const {
    return rejestracja;
}

void Pojazd::wypiszSzczegoly(ostream& os) const {
    os << marka << " " << model << " | Rejestracja: " << rejestracja << " | Przebieg: " << przebieg << " km";
}

bool Pojazd::operator<(const Pojazd& inny) const {
    return this->obliczKosztEksploatacji() < inny.obliczKosztEksploatacji();
}

ostream& operator<<(ostream& os, const Pojazd& p) {
    p.wypiszSzczegoly(os);
    return os;
}

PojazdOsobowy::PojazdOsobowy(string m, string mod, string rej, double prz, int miejsca)
    : Pojazd(m, mod, rej, prz) {
    if (miejsca <= 0) {
        throw invalid_argument("Liczba miejsc w pojezdzie osobowym musi byc wieksza od zera!");
    }
    liczbaMiejsc = miejsca;
}

void PojazdOsobowy::wypiszSzczegoly(ostream& os) const {
    Pojazd::wypiszSzczegoly(os);
    os << " | Miejsca: " << liczbaMiejsc << " | Koszt: " << obliczKosztEksploatacji() << " PLN";
}

double PojazdOsobowy::obliczKosztEksploatacji() const {
    return przebieg * 0.60;
}

PojazdCiezarowy::PojazdCiezarowy(string m, string mod, string rej, double prz, double lad)
    : Pojazd(m, mod, rej, prz) {
    if (lad <= 0) {
        throw invalid_argument("Ladownosc pojazdu ciezarowego musi byc dodatnia!");
    }
    ladownosc = lad;
}

void PojazdCiezarowy::wypiszSzczegoly(ostream& os) const {
    Pojazd::wypiszSzczegoly(os);
    os << " | Ladownosc: " << ladownosc << " t | Koszt: " << obliczKosztEksploatacji() << " PLN";
}

double PojazdCiezarowy::obliczKosztEksploatacji() const {
    return przebieg * 2.20;
}