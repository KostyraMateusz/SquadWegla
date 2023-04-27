#include "oknoMenu.h"
#include "ui_oknoMenu.h"

oknoMenu::oknoMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::oknoMenu)
{
    ui->setupUi(this);
}

oknoMenu::oknoMenu(QWidget *parent, QString p_imie) :
    QDialog(parent),
    ui(new Ui::oknoMenu)
{
    ui->setupUi(this);
    this->imie=p_imie;
    //ui->zalogowany->setText(imie);
    ui->label->setText("Nazwa Firmy: Squad Wędla\n"
                       "Nip: 7319542684\n"
                       "KRS: 3481685429\n"
                       "Regon: 714 383 053851\n"
                       "Właściciel: Mrągowski Ryszard\n"
                       "Ulica: Kryształowa 12\n"
                       "Miasto: Żywiec\n"
                       "Powiat: Żywiecki\n"
                       "Województwo: Śląskie\n"
                       "Tel. komórkowy: 412-831-975\n"
                       "Adres e-mail: squadwegla@gmail.com");
}

oknoMenu::~oknoMenu()
{
    delete ui;
}

void oknoMenu::on_wegielButton_clicked()
{
    this->close();
    oknoWegiel = new OknoWegiel(this);
    oknoWegiel->show();
}


void oknoMenu::on_klientButton_clicked()
{
    this->close();
    oknoKlient = new OknoKlient(this);
    oknoKlient->show();
}

void oknoMenu::on_zamowieniaButton_clicked()
{
    hide();
    this->oknoZamowienie = new OknoZamowienie(this);
    this->oknoZamowienie->show();
}

void oknoMenu::on_pracownicyButton_clicked()
{
    this->close();
    oknoPracownicy = new OknoPracownicy(this);
    oknoPracownicy->show();
}

