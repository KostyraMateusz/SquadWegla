#include "bazadanych.h"

BazaDanych::BazaDanych()
{
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("../database.db");
}

QSqlQuery BazaDanych::zapytanie(QString zapytanie)
{
    QSqlQuery komenda(zapytanie);

    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        if(komenda.exec())
        {

        }
        db.close();
    }

    return komenda;
}


