#ifndef KLIENT_H
#define KLIENT_H
#include "osoba.h"
#include "zamowienie.h"
#include <QDate>
#include <QList>


class Klient : public Osoba
{
private:
    int numerKonta_;
    QString adres_;

public:
    Klient();
    Klient(QString imie,QString nazwisko,int wiek,Plec plec,int numerKonta,QString adres);
    void setNumerKonta(int numerKonta);
    void dodajZamowienie(Zamowienie zamowienie);
    void setAdres(QString adres);
    int getNumerKonta();
    QString adres();
    QString pobierzDane() override;
};

#endif // KLIENT_H
