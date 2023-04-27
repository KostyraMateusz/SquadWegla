#include "wlasciciel.h"

Wlasciciel::Wlasciciel():Osoba()
{
    this->stanKonta_ = 0;
    this->wydatki_ = 0;
    this->przychody_ = 0;
    this->zysk_ = 0;
    this->kosztyUtrzymania_ = 0;
    this->KRS_ = "";
    this->NIP_ = "";
}

Wlasciciel::Wlasciciel(QString imie, QString nazwisko, int wiek, Plec plec, double stanKonta, double wydatki, double przychody, double zysk, double kosztyUtrzymania, QString KRS, QString NIP)
    :Osoba(imie,nazwisko,wiek,plec)
{
        this->stanKonta_ = stanKonta;
        this->wydatki_ = wydatki;
        this->przychody_ = przychody;
        this->zysk_ = zysk;
        this->kosztyUtrzymania_ = kosztyUtrzymania;
        this->KRS_ = KRS;
        this->NIP_ = NIP;
}

double Wlasciciel::wydatki() const
{
    return wydatki_;
}

void Wlasciciel::setWydatki(double wydatki)
{
    wydatki_ = wydatki;
}

double Wlasciciel::przychody() const
{
    return przychody_;
}

void Wlasciciel::setPrzychody(double przychody)
{
    przychody_ = przychody;
}

double Wlasciciel::zysk() const
{
    return zysk_;
}

void Wlasciciel::setZysk(double zysk)
{
    zysk_ = zysk;
}

double Wlasciciel::kosztyUtrzymania() const
{
    return kosztyUtrzymania_;
}

void Wlasciciel::setKosztyUtrzymania(double kosztyUtrzymania)
{
    kosztyUtrzymania_ = kosztyUtrzymania;
}

const QString &Wlasciciel::KRS() const
{
    return KRS_;
}

void Wlasciciel::setKRS(const QString &KRS)
{
    KRS_ = KRS;
}

const QString &Wlasciciel::NIP() const
{
    return NIP_;
}

void Wlasciciel::setNIP(const QString &NIP)
{
    NIP_ = NIP;
}

QString Wlasciciel::pobierzDane()
{
    return Osoba::pobierzDane() + " Wlasciciel ";
}





