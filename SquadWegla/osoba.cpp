#include "osoba.h"
#include <QString>
using ::QString;


Osoba::Osoba()
{    
    this->imie_ = "";
    this->nazwisko_="";
    this->wiek_=0;
    this->plec_=Plec::kobieta;

}

Osoba::Osoba(QString imie, QString nazwisko, int wiek, Plec plec)
{
    this->imie_ = imie;
    this->nazwisko_=nazwisko;
    this->wiek_=wiek;
    this->plec_=plec;
}

//settery
void Osoba::setImie(QString imie){
    this->imie_=imie;
}

void Osoba::setNazwisko(QString nazwisko){
    this->nazwisko_ = nazwisko;
}

void Osoba::setWiek(int wiek){
    this->wiek_= wiek;
}

void Osoba::setPlec(Plec plec){
    this->plec_=plec;
}

//gettery
QString Osoba::getImie(){return this->imie_;}

QString Osoba::getNazwisko(){return this->nazwisko_;}

int Osoba::getWiek(){return this->wiek_;}

Plec Osoba::getPlec(){return this->plec_;}


QString Osoba::pobierzDane()
{
    return "Imie " + this->imie_ + " Nazwisko " + this->nazwisko_;
}


