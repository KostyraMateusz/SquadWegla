#include "oknopracownicy.h"
#include "ui_oknopracownicy.h"

OknoPracownicy::OknoPracownicy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OknoPracownicy)
{
    ui->setupUi(this);
    this->menu = new oknoMenu(this, "cokolwiek");

    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("../database.db");
}

OknoPracownicy::~OknoPracownicy()
{
    delete ui;
}

void OknoPracownicy::on_menuButton_pracownicy_clicked()
{
    this->close();
    this->menu->show();
}


void OknoPracownicy::on_wyswietlPracownikoButton_clicked()
{
    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
       QSqlQueryModel *modal = new QSqlQueryModel();
       modal->clear();
       QSqlQuery zapytanie;
       zapytanie.prepare("SELECT Id, Imie, Nazwisko, Wiek, login FROM Pracownicy");
       zapytanie.exec();
       modal->setQuery(zapytanie);
       ui->WyswietlPracownikow->setModel(modal);
       db.close();
    }
}


void OknoPracownicy::on_UsunButton_clicked()
{
    QString id = ui->UsunID->toPlainText();
    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        zapytanie.prepare("DELETE FROM Pracownicy WHERE Id=:id");
        zapytanie.bindValue(":id", id);
        zapytanie.exec();
        db.close();
        qDebug()<< "Usunąłeś objekt o id: " + id;
    }
      on_wyswietlPracownikoButton_clicked();
}


void OknoPracownicy::on_EdytujButton_clicked()
{
   int id = ui->EdytujId->toPlainText().toInt();
   QString imie = ui->EdytujImie->toPlainText();
   QString nazwisko = ui->EdytujNazwisko->toPlainText();
   int wiek = ui->EdytujWiek->toPlainText().toInt();

   if(!db.open())
   {
       qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
   }
   else
   {
       QSqlQuery zapytanie;
       zapytanie.prepare("UPDATE Pracownicy SET Imie=:Imie, Nazwisko=:Nazwisko, Wiek=:Wiek WHERE Id=:Id;");
       zapytanie.bindValue(":Id", id);
       zapytanie.bindValue(":Imie", imie);
       zapytanie.bindValue(":Nazwisko", nazwisko);
       zapytanie.bindValue(":Wiek", wiek);
       if(zapytanie.exec())
       {
           qDebug() << "Zaktualizowano rekord w bazie danych";
       }
       else
       {
           qDebug() << "Coś poszło nie tak!";
       }
       db.close();
   }
   on_wyswietlPracownikoButton_clicked();
}


void OknoPracownicy::on_DodajButton_clicked()
{
    QString imie = ui->DodajImie->toPlainText();
    QString nazwisko = ui->DodajNazwisko->toPlainText();
    int wiek = ui->DodajWiek->toPlainText().toInt();
    QString login = imie[0] + nazwisko;
    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        zapytanie.prepare("INSERT INTO Pracownicy (login, haslo, Nazwisko, Imie, Wiek)"
                          "VALUES (:login, :haslo, :Nazwisko, :Imie, :Wiek)");
        zapytanie.bindValue(":login", login);
        zapytanie.bindValue(":haslo", nazwisko.toLower());
        zapytanie.bindValue(":Nazwisko", nazwisko);
        zapytanie.bindValue(":Imie", imie);
        zapytanie.bindValue(":Wiek", wiek);
        if(zapytanie.exec())
        {
            qDebug() << "Dodano rekord do bazy danych";
        }
        else
        {
            qDebug() << "Coś poszło nie tak!";
        }
        db.close();
    }
    on_wyswietlPracownikoButton_clicked();

}

