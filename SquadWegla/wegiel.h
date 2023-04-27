#ifndef WEGIEL_H
#define WEGIEL_H
#include "rodzajwegla.h"
#include "kopalnia.h"

class Wegiel
{
private:
    RodzajWegla rodzajWegla;
    Kopalnia kopalniaPochodzenia;
    double cena;
    int kalorycznosc;

public:
    // Konstruktory
    Wegiel();
    Wegiel(RodzajWegla _rodzaj, Kopalnia _kopalnia, double _cena, int _kalorycznosc);

    //Akcesory
    void setRodzajWegla(RodzajWegla _rodzaj);
    void setKopalniaPochodzenia(Kopalnia _kopalnia);
    void setCena(double _cena);
    void setKalorycznosc(int _kalorycznosc);
    RodzajWegla getRodzajWegla();
    Kopalnia getKopalniaPochodzenia();
    double getCena();
    int getKalorycznosc();

};

#endif // WEGIEL_H
