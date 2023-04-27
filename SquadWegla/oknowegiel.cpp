#include "oknowegiel.h"
#include "ui_oknowegiel.h"

OknoWegiel::OknoWegiel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OknoWegiel)
{
    ui->setupUi(this);
    wegiel = new Wegiel();
    this->oknoKlient = new OknoKlient(this);
    this->menu = new oknoMenu(this, "cokolwiek");

    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("../database.db");

    this->resize(1300,800);

    rodzajeWegla();
    kopalnie();
}

OknoWegiel::~OknoWegiel()
{
    delete ui;
}

QString OknoWegiel::getKopalniaWęgla()
{
    QString rodzajKopalniaFromComboBox = ui->kopalnie->currentText();
    return rodzajKopalniaFromComboBox;
}

QString OknoWegiel::getRodzajWęgla()
{
    QString rodzajWeglaFromComboBox = ui->rodzaje->currentText();
    return  rodzajWeglaFromComboBox;
}

double OknoWegiel::getCeneWegla()
{
    double cena = ui->cena->toPlainText().toDouble();
    return cena;
}

int OknoWegiel::getKalorycznosc()
{
    int kalorycznosc = ui->kalorycznosc->toPlainText().toInt();
    return kalorycznosc;
}

void OknoWegiel::rodzajeWegla()
{
    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        if(zapytanie.exec("Select * from RodzajeWegla"))
        {
            while(zapytanie.next())
            {
                QString temp = "Rodzaj: " + zapytanie.value(0).toString() +  " Kolor: " +  zapytanie.value(1).toString();
                ui->rodzaje->addItem(temp);
                ui->EdytujRodzajWegla->addItem(temp);
            }

        }
        db.close();
    }
}

void OknoWegiel::kopalnie()
{
    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        if(zapytanie.exec("Select * from Kopalnie"))
        {
            while(zapytanie.next())
            {
                QString temp = zapytanie.value(0).toString() +  " "
                +  zapytanie.value(1).toString() + " " + zapytanie.value(2).toString();
                ui->kopalnie->addItem(temp);
                ui->EdytujKrajPochodzenia->addItem(temp);
            }

        }
        db.close();
    }
}


void OknoWegiel::on_dodajButton_clicked()
{
    RodzajWegla rodzaj(getRodzajWęgla());
    Kopalnia kopalnia(getKopalniaWęgla());
    this->wegiel->setCena(getCeneWegla());
    this->wegiel->setKalorycznosc(getKalorycznosc());
    this->wegiel->setRodzajWegla(rodzaj);
    this->wegiel->setKopalniaPochodzenia(kopalnia);

    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        zapytanie.prepare("INSERT INTO SkladnicaWegla (RodzajWegla,Kopalnia,Cena,Kalorycznosc)"
                          "VALUES (:RodzajWegla, :Kopalnia, :Cena, :Kalorycznosc)");
        zapytanie.bindValue(":RodzajWegla", getRodzajWęgla());
        zapytanie.bindValue(":Kopalnia", getKopalniaWęgla());
        zapytanie.bindValue(":Cena", getCeneWegla());
        zapytanie.bindValue(":Kalorycznosc", getKalorycznosc());
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
    on_wyswietlButton_clicked();
}


void OknoWegiel::on_wyswietlButton_clicked()
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
       zapytanie.prepare("Select Id, RodzajWegla, Kopalnia, Cena, Kalorycznosc from SkladnicaWegla");
       zapytanie.exec();
       modal->setQuery(zapytanie);
       ui->tableSkladnicaWegla->setModel(modal);
       ui->tableSkladnicaWegla->setColumnWidth(2, 300);
       ui->tableSkladnicaWegla->setColumnWidth(1, 300);
       db.close();
    }
}



void OknoWegiel::on_usunButton_clicked()
{
    QString index = ui->usunId->toPlainText();
    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        zapytanie.prepare("DELETE FROM SkladnicaWegla WHERE Id =?");
        zapytanie.addBindValue(index);
        zapytanie.exec();
        db.close();
        qDebug()<< "Usunąłeś objekt o id: " + index;
    }
    on_wyswietlButton_clicked();
}


void OknoWegiel::on_znajdzRekord_clicked()
{
    QString phrase = ui->searchRecord->toPlainText();
    phrase = "%" + phrase + "%";
    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        QSqlQueryModel *modal = new QSqlQueryModel();
        zapytanie.prepare("SELECT * FROM SkladnicaWegla WHERE RodzajWegla LIKE :phrase OR Kopalnia LIKE :phrase OR Cena LIKE :phrase OR Kalorycznosc LIKE :phrase");
        zapytanie.bindValue(":phrase", phrase);
        zapytanie.exec();
        ui->tableSkladnicaWegla->setModel(modal);
        modal->setQuery(zapytanie);
        ui->tableSkladnicaWegla->setModel(modal);
        ui->tableSkladnicaWegla->setColumnWidth(2, 300);
        ui->tableSkladnicaWegla->setColumnWidth(1, 300);
        db.close();
    }
}


void OknoWegiel::on_buttonMenu_clicked()
{
    this->close();
    this->menu->show();
}

void OknoWegiel::on_EdytujButton_clicked()
{

    int id = ui->EdytujID->toPlainText().toInt();
    QString kopalnia = ui->EdytujKrajPochodzenia->currentText();
    QString rodzaj = ui->EdytujRodzajWegla->currentText();
    double cena = ui->EdytujCena->toPlainText().toDouble();
    double kalorycznosc = ui->EdytujKalorycznosc->toPlainText().toDouble();

    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        zapytanie.prepare("UPDATE SkladnicaWegla SET RodzajWegla=:RodzajWegla, Kopalnia=:Kopalnia, Cena=:Cena, Kalorycznosc=:Kalorycznosc WHERE Id=:id;");
        zapytanie.bindValue(":id", id);
        zapytanie.bindValue(":RodzajWegla", rodzaj);
        zapytanie.bindValue(":Kopalnia", kopalnia);
        zapytanie.bindValue(":Cena", cena);
        zapytanie.bindValue(":Kalorycznosc", kalorycznosc);
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
     on_wyswietlButton_clicked();
}

