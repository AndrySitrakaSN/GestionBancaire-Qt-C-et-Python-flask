#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button_Ajouter_clicked();
    void on_Button_modifier_clicked();
    void on_Button_Supprimer_clicked();
    void loadClients();
    void afficherTotalSolde();
    void resetForm();  // Déclaration de la fonction resetForm
    void on_tableWidget_itemClicked(QTableWidgetItem *item);
    void on_Button_Virements_clicked();
    void on_Button_retraiss_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase DB_Connection;
};

#endif // MAINWINDOW_H
