#ifndef OKNOKLIENT_H
#define OKNOKLIENT_H
#include <QtSql>
#include <QDialog>
#include <QListWidget>
#include "klient.h"
#include "oknoMenu.h"

namespace Ui {
class OknoKlient;
}
class oknoMenu;
class OknoKlient : public QDialog
{
    Q_OBJECT

public:
    explicit OknoKlient(QWidget *parent = nullptr);
    ~OknoKlient();
    void zaladujTabele();


private slots:
    void on_dodajButton_clicked();
    void on_tableKlienci_itemClicked(QListWidgetItem *item);
    void on_menuButton_clicked();

private:
    Ui::OknoKlient *ui;
    QSqlDatabase db;
    oknoMenu *menu;
};

#endif // OKNOKLIENT_H
