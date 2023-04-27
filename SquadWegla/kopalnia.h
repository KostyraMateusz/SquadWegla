#ifndef KOPALNIA_H
#define KOPALNIA_H
#include <iostream>
#include <qstring.h>

using std::string;

class Kopalnia
{
private:
    QString nazwaAdresNazwaSpolki;

public:
    // Konstruktory
    Kopalnia();
    Kopalnia(QString nazwaAdresNazwaSpolki);

    // Akcesory
    void setNazwaAdresNazwaSpolki(QString _nazwaAdresNazwaSpolki);
    QString getNazwaAdresNazwaSpolki();
};

#endif // KOPALNIA_H
