#include "kopalnia.h"

Kopalnia::Kopalnia()
{
    setNazwaAdresNazwaSpolki("");
}

Kopalnia::Kopalnia(QString nazwaAdresNazwaSpolki)
{
    setNazwaAdresNazwaSpolki(nazwaAdresNazwaSpolki);
}

void Kopalnia::setNazwaAdresNazwaSpolki(QString _nazwaAdresNazwaSpolki)
{
    this->nazwaAdresNazwaSpolki = _nazwaAdresNazwaSpolki;
}

QString Kopalnia::getNazwaAdresNazwaSpolki()
{
    return this->nazwaAdresNazwaSpolki;
}

