#include "pracownik.h"

Pracownik::Pracownik():Osoba()
{
    this->pensja_ = 0;
    this->typUmowy_ = "";
}

Pracownik::Pracownik(QString imie, QString nazwisko, int wiek, Plec plec, QString stanowisko, double pensja, QString typUmowy)
    :Osoba(imie,nazwisko,wiek,plec)
{
    this->pensja_ = pensja;
    this->typUmowy_= typUmowy;
}

void Pracownik::setTypUmowy(const QString &typUmowy)
{
    this->typUmowy_ = typUmowy;
}

void Pracownik::setPensja(double pensja)
{
    this->pensja_=pensja;
}


double Pracownik::getPensja()
{
   return this->pensja_;
}

const QString &Pracownik::getTypUmowy() const
{
    return this->typUmowy_;
}

QString Pracownik::pobierzDane()
{
    return Osoba::pobierzDane() + " Pracownik ";
}




