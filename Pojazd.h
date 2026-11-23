#ifndef POJAZD_H
#define POJAZD_H

#include <iostream>
#include <string>

using namespace std;

// Klasa bazowa reprezentujaca dowolny pojazd we flocie
class Pojazd {
protected:
    string marka;
    string model;
    string rejestracja;
    double przebieg;

public:
    Pojazd(string m, string mod, string rej, double prz);
    virtual ~Pojazd() {} // Wirtualny destruktor przy dziedziczeniu przez wskaznik bazowy

    string getRejestracja() const;
    virtual void wypiszSzczegoly(ostream& os) const; // Metoda pomocnicza do operatora <<
    virtual double obliczKosztEksploatacji() const = 0; // Metoda czysto wirtualna nadpisywana w klasach pochodnych

    // Przeciazony operator < porownuje pojazdy po koszcie eksploatacji
    bool operator<(const Pojazd& inny) const;
};

// Przeciazony operator << pozwala wypisac obiekt Pojazd przez cout
ostream& operator<<(ostream& os, const Pojazd& p);

// Klasa pochodna dla samochodow osobowych
class PojazdOsobowy : public Pojazd {
private:
    int liczbaMiejsc;

public:
    PojazdOsobowy(string m, string mod, string rej, double prz, int miejsca);
    void wypiszSzczegoly(ostream& os) const override;
    double obliczKosztEksploatacji() const override;
};

// Klasa pochodna dla samochodow ciezarowych
class PojazdCiezarowy : public Pojazd {
private:
    double ladownosc;

public:
    PojazdCiezarowy(string m, string mod, string rej, double prz, double lad);
    void wypiszSzczegoly(ostream& os) const override;
    double obliczKosztEksploatacji() const override;
};

#endif