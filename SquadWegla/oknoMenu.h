#ifndef OKNOMENU_H
#define OKNOMENU_H

#include <QDialog>
#include <QStatusBar>
#include <oknowegiel.h>
#include <oknoklient.h>

#include <oknozamowienie.h>
#include <oknopracownicy.h>

namespace Ui {
class oknoMenu;
}

class OknoWegiel;
class OknoKlient;
class OknoZamowienie;
class OknoPracownicy;
class oknoMenu : public QDialog
{
    Q_OBJECT

public:
    explicit oknoMenu(QWidget *parent = nullptr);
    oknoMenu();
    oknoMenu(QWidget *parent = nullptr, QString imie="");
    ~oknoMenu();

private slots:
    void on_wegielButton_clicked();
    void on_klientButton_clicked();
    void on_zamowieniaButton_clicked();
    void on_pracownicyButton_clicked();


private:
    Ui::oknoMenu *ui;
    QString imie;
    OknoWegiel *oknoWegiel;
    OknoKlient *oknoKlient;
    OknoZamowienie *oknoZamowienie;
    OknoPracownicy *oknoPracownicy;

};

#endif // OKNOMENU_H
