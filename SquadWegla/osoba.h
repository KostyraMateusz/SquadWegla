#ifndef OSOBA_H
#define OSOBA_H
#include <QString>

enum Plec{
    mezczyzna,
    kobieta
};

class Osoba
{
private:
    QString imie_;
    QString nazwisko_;
    int wiek_;
    Plec plec_;

public:
    Osoba();
    Osoba(QString imie,QString nazwisko,int wiek,Plec plec);
    void setImie(QString imie);
    void setNazwisko(QString nazwisko);
    void setWiek(int wiek);
    void setPlec(Plec plec);
    QString getImie();
    QString getNazwisko();
    int getWiek();
    Plec getPlec();
    virtual QString pobierzDane();
};

#endif // OSOBA_H
