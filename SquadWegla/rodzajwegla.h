#ifndef RODZAJWEGLA_H
#define RODZAJWEGLA_H
#include <string>
#include <qstring.h>

using std::string;

class RodzajWegla
{
private:
    QString nazwaOrazKolor;

public:
    // Konstruktory
    RodzajWegla();
    RodzajWegla(QString wszystko);

    //Akcesory
    void setNazwaOrazKolor(QString _nazwa);
    QString getNazwaOrazKolor();
};

#endif // RODZAJWEGLA_H
