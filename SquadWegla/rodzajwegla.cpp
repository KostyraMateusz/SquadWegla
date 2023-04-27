#include "rodzajwegla.h"

RodzajWegla::RodzajWegla()
{
    setNazwaOrazKolor("");
}

RodzajWegla::RodzajWegla(QString wszystko)
{
    this->nazwaOrazKolor = wszystko;
}

void RodzajWegla::setNazwaOrazKolor(QString _nazwa)
{
    this->nazwaOrazKolor = _nazwa;
}

QString RodzajWegla::getNazwaOrazKolor()
{
    return this->nazwaOrazKolor;
}
