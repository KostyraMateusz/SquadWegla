#ifndef OKNOWEGIEL_H
#define OKNOWEGIEL_H
#include <QtSql>
#include <QDialog>
#include <QDebug>
#include "wegiel.h"
#include "rodzajwegla.h"
#include <oknoMenu.h>
#include <oknoklient.h>


namespace Ui {
class OknoWegiel;
}
class oknoMenu;
class OknoKlient;
class OknoWegiel : public QDialog
{
    Q_OBJECT

public:
    explicit OknoWegiel(QWidget *parent = nullptr);
    ~OknoWegiel();
    QString getKopalniaWęgla();
    QString getRodzajWęgla();
    double getCeneWegla();
    int getKalorycznosc();
    void rodzajeWegla();
    void kopalnie();

private slots:
    void on_dodajButton_clicked();
    void on_wyswietlButton_clicked();
    void on_usunButton_clicked();
    void on_znajdzRekord_clicked();
    void on_buttonMenu_clicked();
    void on_EdytujButton_clicked();

private:
    Ui::OknoWegiel *ui;
    QSqlDatabase db;
    Wegiel *wegiel;
    OknoKlient *oknoKlient;
    oknoMenu *menu;
};

#endif // OKNOWEGIEL_H
