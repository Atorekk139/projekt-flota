#ifndef POJAZD_H
#define POJAZD_H

#include <string>

using namespace std;

class Pojazd {
protected:
    string marka;
    string model;
    string rejestracja;
    double przebieg;

public:
    Pojazd(string m, string mod, string rej, double prz);
    virtual ~Pojazd() {}

    string getRejestracja() const;
    virtual void wyswietl() const;
    virtual double obliczKosztEksploatacji() const = 0;
};

class PojazdOsobowy : public Pojazd {
private:
    int liczbaMiejsc;

public:
    PojazdOsobowy(string m, string mod, string rej, double prz, int miejsca);
    void wyswietl() const override;
    double obliczKosztEksploatacji() const override;
};

class PojazdCiezarowy : public Pojazd {
private:
    double ladownosc;

public:
    PojazdCiezarowy(string m, string mod, string rej, double prz, double lad);
    void wyswietl() const override;
    double obliczKosztEksploatacji() const override;
};

#endif