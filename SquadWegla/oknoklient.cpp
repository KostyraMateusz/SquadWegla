#include "oknoklient.h"
#include "ui_oknoklient.h"

OknoKlient::OknoKlient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OknoKlient)
{
    ui->setupUi(this);
    this->resize(1170,750);
    this->menu = new oknoMenu(this, "cokolwiek");
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("../database.db");
    zaladujTabele();
}

OknoKlient::~OknoKlient()
{
    delete ui;
}

void OknoKlient::zaladujTabele()
{
    ui->tableKlienci->clear();
    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        if(zapytanie.exec("SELECT * FROM Klienci"))
        {
            while(zapytanie.next())
            {

                QString temp =
                zapytanie.value(1).toString() +" "+ zapytanie.value(2).toString() +" "+ zapytanie.value(3).toString() +" "+
                zapytanie.value(4).toString() +" "+ zapytanie.value(5).toString();
                ui->tableKlienci->insertItem(1,temp);
            }
        db.close();
        }
    }
}

void OknoKlient::on_dodajButton_clicked()
{
    zaladujTabele();
}


void OknoKlient::on_tableKlienci_itemClicked(QListWidgetItem *item)
{
    ui->tableZamowieniaKlientow->clear();
    ui->tableZamowieniaKlientow->insertItem(1,item->text());
}


void OknoKlient::on_menuButton_clicked()
{
    this->close();
    this->menu->show();
}

