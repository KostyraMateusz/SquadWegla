#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include "osoba.h"


class Pracownik : public Osoba
{
private:
    double pensja_;
    QString typUmowy_;
    QString stanowisko_;

public:
    Pracownik();
    Pracownik(QString imie,QString nazwisko,int wiek,Plec plec,QString stanowisko,double pensja,QString typUmowy);
    void setPensja(double pensja);
    void setTypUmowy(const QString &newTypUmowy);
    double getPensja();
    const QString &getTypUmowy() const;
    QString pobierzDane() override;


};

#endif // PRACOWNIK_H
