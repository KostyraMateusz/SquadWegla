#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <oknoMenu.h>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class oknoMenu;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_button_clicked();
    void logowanie(QString login, QString haslo);

private:
    Ui::MainWindow *ui;
    oknoMenu *menu;
    QSqlDatabase db;

};
#endif // MAINWINDOW_H
