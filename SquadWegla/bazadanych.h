#include <QSqlDatabase>
#include <QSqlQuery>
#ifndef BAZADANYCH_H
#define BAZADANYCH_H


class BazaDanych
{
public:

    QSqlDatabase db;

    BazaDanych();

    QSqlQuery zapytanie(QString zapytanie);
};

#endif // BAZADANYCH_H
