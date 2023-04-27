#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("../database.db");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_button_clicked()
{
    QString login = ui->input_login->toPlainText();
    QString haslo = ui->input_haslo->text();
    logowanie(login, haslo);
}

void MainWindow::logowanie(QString login, QString haslo){

    if(!db.open())
    {
        qDebug()<<"Error! Podłączenie do bazy danych nie powiodło się.";
    }
    else
    {
        QSqlQuery zapytanie;
        if(zapytanie.exec("Select * from Pracownicy")){
            while(zapytanie.next()){
                if(login==zapytanie.value(4).toString() && haslo==zapytanie.value(5).toString()){
                    hide();
                    menu = new oknoMenu(this, zapytanie.value(3).toString());
                    menu->show();
                }
                else{
                    ui->napis->setStyleSheet("QLabel { color : red; }");
                    ui->napis->setText("Błędny login lub hasło, spróbuj ponownie !");
                    ui->input_login->clear();
                    ui->input_haslo->clear();
                }
            }
        }
        db.close();
    }
}
