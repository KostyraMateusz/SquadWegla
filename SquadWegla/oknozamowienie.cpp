#include "oknozamowienie.h"
#include "ui_oknozamowienie.h"

OknoZamowienie::OknoZamowienie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OknoZamowienie)
{
    ui->setupUi(this);
    this->menu = new oknoMenu(this, "");
    this->zamowienie = new Zamowienie();

    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("../database.db");

    rodzajeWegla();
    pracownicy();
    klienci();
}

OknoZamowienie::~OknoZamowienie()
{
    delete ui;
}

QString OknoZamowienie::getRodzajWegla()
{
    QString rodzajWeglaFromComboBox = ui->DodajRodzajComboBox->currentText();
    return  rodzajWeglaFromComboBox;
}

int OknoZamowienie::getIloscWegla()
{
    int ilosc = ui->textEditIlosc->toPlainText().toInt();
    return ilosc;
}

void OknoZamowienie::pracownicy()
{
    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        if(zapytanie.exec("SELECT Imie, Nazwisko FROM Pracownicy"))
        {
            while(zapytanie.next())
            {
                QString temp = "Imie: " + zapytanie.value(0).toString() +  " Nazwisko: " +  zapytanie.value(1).toString();
                ui->DodajPracownikaComboBox->addItem(temp);
                ui->EdytujPracownikaCombobox->addItem(temp);
            }
        }
        db.close();
    }
}

void OknoZamowienie::klienci()
{
    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        if(zapytanie.exec("SELECT imie, nazwisko, adres FROM Klienci"))
        {
            while(zapytanie.next())
            {
                QString temp = "Imie: " + zapytanie.value(0).toString() +  " Nazwisko: " +  zapytanie.value(1).toString() + " adres: " + zapytanie.value(2).toString();
                ui->DodajKlientaComboBox->addItem(temp);
                ui->EdytujKlientaCombobox->addItem(temp);
            }
        }
        db.close();
    }
}

void OknoZamowienie::rodzajeWegla()
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
                ui->DodajRodzajComboBox->addItem(temp);
                ui->EdytujRodzajWegla->addItem(temp);
            }

        }
        db.close();
    }
}

void OknoZamowienie::on_pushButtonPowrot_clicked()
{
    this->close();
    this->menu->show();
}


void OknoZamowienie::on_DodajZamowienieButton_clicked()
{
    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        QString pracownik = ui->DodajPracownikaComboBox->currentText();
        QString klient = ui->DodajKlientaComboBox->currentText();
        zapytanie.prepare("INSERT INTO Zamowienia (RodzajWegla,Ilosc,Pracownik,Klient)"
                          "VALUES (:RodzajWegla, :Ilosc, :Pracownik, :Klient)");
        zapytanie.bindValue(":RodzajWegla", getRodzajWegla());
        zapytanie.bindValue(":Ilosc", getIloscWegla());
        zapytanie.bindValue(":Pracownik", pracownik);
        zapytanie.bindValue(":Klient", klient);
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

    on_wyswietlZamowieniaButton_clicked();

}

void OknoZamowienie::on_usunZamowienieButton_clicked()
{
    QString index = ui->textEditUsun->toPlainText();
    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        zapytanie.prepare("DELETE FROM Zamowienia WHERE Id =?");
        zapytanie.addBindValue(index);
        zapytanie.exec();
        db.close();
        qDebug()<< "Usunąłeś objekt o id: " + index;
    }

    on_wyswietlZamowieniaButton_clicked();
}


void OknoZamowienie::on_wyswietlZamowieniaButton_clicked()
{
    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
       QSqlQueryModel *modal = new QSqlQueryModel();
       QSqlQuery zapytanie;
       zapytanie.prepare("Select * from Zamowienia");
       zapytanie.exec();
       modal->setQuery(zapytanie);
       ui->tablicaZamowien->setModel(modal);
       ui->tablicaZamowien->setColumnWidth(4, 450);
       ui->tablicaZamowien->setColumnWidth(3, 225);
       ui->tablicaZamowien->setColumnWidth(2, 50);
       ui->tablicaZamowien->setColumnWidth(1, 250);
       ui->tablicaZamowien->setColumnWidth(0,25);
       db.close();
    }
}

void OknoZamowienie::on_EdytujZamowienieButton_clicked()
{
    int id = ui->EdytujNumer->toPlainText().toInt();
    QString rodzaj = ui->EdytujRodzajWegla->currentText();
    int ilosc = ui->EdytujIlosc->toPlainText().toInt();
    QString pracownik = ui->EdytujPracownikaCombobox->currentText();
    QString klient = ui->EdytujKlientaCombobox->currentText();

    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        zapytanie.prepare("UPDATE Zamowienia SET RodzajWegla=:RodzajWegla, Ilosc=:Ilosc, Pracownik=:Pracownik, Klient=:Klient WHERE Id=:id;");

        zapytanie.bindValue(":id", id);
        zapytanie.bindValue(":RodzajWegla", rodzaj);
        zapytanie.bindValue(":Ilosc", ilosc);
        zapytanie.bindValue(":Pracownik", pracownik);
        zapytanie.bindValue(":Klient", klient);
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

    on_wyswietlZamowieniaButton_clicked();
}

