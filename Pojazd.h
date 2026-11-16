#ifndef POJAZD_H
#define POJAZD_H

#include <string>

using namespace std;

class Pojazd {
private:
    string marka;
    string model;
    string rejestracja;
    double przebieg;

public:
    Pojazd(string m, string mod, string rej, double prz);

    string getMarka() const;
    string getModel() const;
    string getRejestracja() const;
    double getPrzebieg() const;

    void setPrzebieg(double prz);
    void wyswietl() const;
};

#endif