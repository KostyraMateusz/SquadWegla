#include "zamowienie.h"

Zamowienie::Zamowienie()
{

}

void Zamowienie::setIlosc(int _ilosc)
{
    this->ilosc = _ilosc;
}

void Zamowienie::setWegiel(Wegiel _wegiel)
{
    this->wegiel = _wegiel;
}

int Zamowienie::getIlosc()
{
    return this->ilosc;
}

Wegiel Zamowienie::getWegiel()
{
    return this->wegiel;
}
