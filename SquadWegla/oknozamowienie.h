#ifndef OKNOZAMOWIENIE_H
#define OKNOZAMOWIENIE_H

#include <QtSql>
#include <QDialog>
#include <oknoMenu.h>

namespace Ui {
class OknoZamowienie;
}
class oknoMenu;
class OknoZamowienie : public QDialog
{
    Q_OBJECT

public:
    explicit OknoZamowienie(QWidget *parent = nullptr);
    ~OknoZamowienie();
    QString getRodzajWegla();
    int getIloscWegla();
    void rodzajeWegla();
    void pracownicy();
    void klienci();

private slots:
    void on_pushButtonPowrot_clicked();
    void on_DodajZamowienieButton_clicked();
    void on_usunZamowienieButton_clicked();
    void on_wyswietlZamowieniaButton_clicked();
    void on_EdytujZamowienieButton_clicked();

private:
    Ui::OknoZamowienie *ui;
    oknoMenu *menu;
    Zamowienie *zamowienie;
    QSqlDatabase db;
};

#endif // OKNOZAMOWIENIE_H
