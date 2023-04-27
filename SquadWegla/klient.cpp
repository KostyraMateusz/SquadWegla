#include "klient.h"

Klient::Klient():Osoba()
{
    Zamowienie puste;
    this->numerKonta_ = 0;
    this->adres_ = "";
}

Klient::Klient(QString imie, QString nazwisko, int wiek, Plec plec, int numerKonta, QString adres):Osoba(imie,nazwisko,wiek,plec)
{
    this->numerKonta_ = numerKonta;
    this->adres_ = adres;
}

void Klient::setNumerKonta(int numerKonta){
    this->numerKonta_ = numerKonta;
}

void Klient::dodajZamowienie(Zamowienie zamowienie){

}

void Klient::setAdres(QString adres){
    this->adres_=adres;
}

int Klient::getNumerKonta(){
    return this->numerKonta_;
}

QString Klient::adres(){
    return this->adres_;
}

QString Klient::pobierzDane()
{
    return Osoba::pobierzDane() + " Klient ";
}

