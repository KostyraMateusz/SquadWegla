#ifndef OKNOPRACOWNICY_H
#define OKNOPRACOWNICY_H

#include <QDialog>
#include <QtSql>
#include "oknoMenu.h"

namespace Ui {
class OknoPracownicy;
}
class oknoMenu;
class OknoPracownicy : public QDialog
{
    Q_OBJECT

public:
    explicit OknoPracownicy(QWidget *parent = nullptr);
    ~OknoPracownicy();

private slots:
    void on_menuButton_pracownicy_clicked();
    void on_wyswietlPracownikoButton_clicked();
    void on_UsunButton_clicked();
    void on_EdytujButton_clicked();
    void on_DodajButton_clicked();

private:
    Ui::OknoPracownicy *ui;
    oknoMenu *menu;
    QSqlDatabase db;
};

#endif // OKNOPRACOWNICY_H
