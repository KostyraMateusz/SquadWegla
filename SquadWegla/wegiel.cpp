#include "wegiel.h"

Wegiel::Wegiel()
{

}

Wegiel::Wegiel(RodzajWegla _rodzaj, Kopalnia _kopalnia, double _cena, int _kalorycznosc)
{
    this->rodzajWegla = _rodzaj;
    this->kopalniaPochodzenia = _kopalnia;
    this->cena = _cena;
    this->kalorycznosc = _kalorycznosc;
}

void Wegiel::setRodzajWegla(RodzajWegla _rodzaj)
{
    this->rodzajWegla = _rodzaj;
}

void Wegiel::setKopalniaPochodzenia(Kopalnia _kopalnia)
{
    this->kopalniaPochodzenia = _kopalnia;
}

void Wegiel::setCena(double _cena)
{
    this->cena = _cena;
}

void Wegiel::setKalorycznosc(int _kalorycznosc)
{
    this->kalorycznosc = _kalorycznosc;
}

RodzajWegla Wegiel::getRodzajWegla()
{
    return this->rodzajWegla;
}

Kopalnia Wegiel::getKopalniaPochodzenia()
{
    return this->kopalniaPochodzenia;
}

double Wegiel::getCena()
{
    return this->cena;
}

int Wegiel::getKalorycznosc()
{
    return this->kalorycznosc;
}
