#ifndef WLASCICIEL_H
#define WLASCICIEL_H
#include "osoba.h"

class Wlasciciel : public Osoba
{
private:
    double stanKonta_;
    double wydatki_;
    double przychody_;
    double zysk_;
    double kosztyUtrzymania_;
    QString KRS_;
    QString NIP_;

public:
    Wlasciciel();
    Wlasciciel(QString imie,QString nazwisko,int wiek,Plec plec,double stanKonta,double wydatki,double przychody,double zysk,double kosztyUtrzymania,QString KRS,QString NIP);
    double stanKonta() const;
    void setStanKonta(double stanKonta);
    double wydatki() const;
    void setWydatki(double wydatki);
    double przychody() const;
    void setPrzychody(double przychody);
    double zysk() const;
    void setZysk(double zysk);
    double kosztyUtrzymania() const;
    void setKosztyUtrzymania(double kosztyUtrzymania);
    const QString &KRS() const;
    void setKRS(const QString &KRS);
    const QString &NIP() const;
    void setNIP(const QString &NIP);
    QString pobierzDane() override;

};

#endif // WLASCICIEL_H
