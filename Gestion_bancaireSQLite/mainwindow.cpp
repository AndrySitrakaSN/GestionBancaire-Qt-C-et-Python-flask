#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Rendre le champ "ID" en lecture seule
    ui->lineEdit_id->setReadOnly(true);
    ui->lineEdit_Total->setReadOnly(true);
    ui->lineEdit_Montant->setReadOnly(true);
    // Initialisation des boutons
    ui->Button_modifier->setEnabled(false);
    ui->Button_Supprimer->setEnabled(false);
    ui->Button_Virements->setEnabled(false);
    ui->Button_retraiss->setEnabled(false);


    // Connexion à la base de données SQLite
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("../db/database.db");

    if (DB_Connection.open()) {
        qDebug() << "Connecté à la base de données SQLite.";

        // Calculer et afficher la somme des soldes au démarrage
        afficherTotalSolde();

        // Charger les clients dans le tableau
        loadClients();
    } else {
        qDebug() << "Échec de la connexion à la base de données.";
        qDebug() << "Erreur :" << DB_Connection.lastError().text();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* ____________________ Fonction Ajouter ________________________ */

void MainWindow::on_Button_Ajouter_clicked()
{
    if (DB_Connection.open()) {
        QSqlDatabase::database().transaction();

        QSqlQuery QueryInsertData(DB_Connection);
        QueryInsertData.prepare("INSERT INTO client(nom, prenom, email, telephone, adresse, mots_de_pass, solde) "
                                "VALUES(:nom, :prenom, :email, :telephone, :adresse, :mots_de_pass, :solde)");

        QueryInsertData.bindValue(":nom", ui->lineEdit_nom->text());
        QueryInsertData.bindValue(":prenom", ui->lineEdit_prenom->text());
        QueryInsertData.bindValue(":email", ui->lineEdit_email->text());
        QueryInsertData.bindValue(":telephone", ui->lineEdit_telephone->text());
        QueryInsertData.bindValue(":adresse", ui->lineEdit_adresse->text());
        QueryInsertData.bindValue(":mots_de_pass", ui->lineEdit_mdp->text());
        QueryInsertData.bindValue(":solde", ui->lineEdit_sld->text());

        if (QueryInsertData.exec()) {
            QSqlDatabase::database().commit();
            QMessageBox::information(this, "Succès", "Client ajouté avec succès.");
            afficherTotalSolde();  // Mettre à jour la somme des soldes après ajout
            loadClients(); // Recharger les clients après ajout
            resetForm(); // Réinitialiser le formulaire
        } else {
            QSqlDatabase::database().rollback();
            QMessageBox::warning(this, "Erreur", "Échec de l'insertion : " + QueryInsertData.lastError().text());
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Base de données non connectée.");
    }
}

/* ________________ Fonction Modifier (Update) ____________________ */

void MainWindow::on_Button_modifier_clicked()
{
    if (DB_Connection.open()) {
        QSqlDatabase::database().transaction();

        QSqlQuery QueryUpdateData(DB_Connection);
        QueryUpdateData.prepare("UPDATE client SET nom=:nom, prenom=:prenom, email=:email, "
                                "telephone=:telephone, adresse=:adresse, mots_de_pass=:mots_de_pass, solde=:solde "
                                "WHERE id=:id");

        QueryUpdateData.bindValue(":id", ui->lineEdit_id->text());
        QueryUpdateData.bindValue(":nom", ui->lineEdit_nom->text());
        QueryUpdateData.bindValue(":prenom", ui->lineEdit_prenom->text());
        QueryUpdateData.bindValue(":email", ui->lineEdit_email->text());
        QueryUpdateData.bindValue(":telephone", ui->lineEdit_telephone->text());
        QueryUpdateData.bindValue(":adresse", ui->lineEdit_adresse->text());
        QueryUpdateData.bindValue(":mots_de_pass", ui->lineEdit_mdp->text());
        QueryUpdateData.bindValue(":solde", ui->lineEdit_sld->text());

        if (QueryUpdateData.exec()) {
            QSqlDatabase::database().commit();
            QMessageBox::information(this, "Succès", "Client modifié avec succès.");
            afficherTotalSolde();  // Mettre à jour la somme des soldes après modification
            loadClients(); // Recharger les clients après modification
            resetForm(); // Réinitialiser le formulaire
            ui->Button_Ajouter->setEnabled(true);
            ui->Button_modifier->setEnabled(false);
            ui->Button_Supprimer->setEnabled(false);
            ui->Button_Virements->setEnabled(false);
            ui->Button_retraiss->setEnabled(false);
             ui->lineEdit_Montant->setReadOnly(true);
        } else {
            QSqlDatabase::database().rollback();
            QMessageBox::warning(this, "Erreur", "Échec de la modification : " + QueryUpdateData.lastError().text());
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Base de données non connectée.");
    }
}

/* ________________ Fonction Supprimer (Delete) ____________________ */

void MainWindow::on_Button_Supprimer_clicked()
{
    if (DB_Connection.open()) {
        QSqlDatabase::database().transaction();

        QSqlQuery QueryDeleteData(DB_Connection);
        QueryDeleteData.prepare("DELETE FROM client WHERE id=:id");
        QueryDeleteData.bindValue(":id", ui->lineEdit_id->text());

        if (QueryDeleteData.exec()) {
            QSqlDatabase::database().commit();
            QMessageBox::information(this, "Succès", "Client supprimé avec succès.");
            afficherTotalSolde();  // Mettre à jour la somme des soldes après suppression
            loadClients(); // Recharger les clients après suppression
            resetForm(); // Réinitialiser le formulaire
            ui->Button_Ajouter->setEnabled(true);
            ui->Button_modifier->setEnabled(false);
            ui->Button_Supprimer->setEnabled(false);
            ui->Button_Virements->setEnabled(false);
            ui->Button_retraiss->setEnabled(false);
            ui->lineEdit_Montant->setReadOnly(true);
        } else {
            QSqlDatabase::database().rollback();
            QMessageBox::warning(this, "Erreur", "Échec de la suppression : " + QueryDeleteData.lastError().text());
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Base de données non connectée.");
    }
}

/* ________________ Fonction afficherTotalSolde ____________________ */

void MainWindow::afficherTotalSolde()
{
    if (DB_Connection.open()) {
        QSqlQuery query(DB_Connection);

        // Exécuter la requête pour obtenir la somme des soldes
        query.prepare("SELECT SUM(solde) FROM client");

        if (query.exec()) {
            if (query.next()) {
                // Récupérer la somme des soldes
                double sommeSolde = query.value(0).toDouble();

                // Afficher la somme dans lineEdit_Total
                ui->lineEdit_Total->setText(QString::number(sommeSolde, 'f', 2) + " Ar");  // Afficher avec 2 décimales
            }
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        }
    } else {
        qDebug() << "La base de données n'est pas ouverte.";
    }
}

/* ________________ Fonction loadClients ____________________ */

void MainWindow::loadClients()
{
    // Vider le QTableWidget avant de le remplir
    ui->tableWidget->setRowCount(0);  // Remplacez 'tableWidget' par le nom de votre widget

    if (DB_Connection.open()) {
        QSqlQuery query(DB_Connection);
        query.prepare("SELECT id, nom, prenom, email, telephone, adresse, mots_de_pass, solde FROM client");

        if (query.exec()) {
            while (query.next()) {
                int rowCount = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(rowCount);

                // Récupérer les données et les insérer dans le tableau
                ui->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(query.value(0).toString())); // ID
                ui->tableWidget->setItem(rowCount, 1, new QTableWidgetItem(query.value(1).toString())); // Nom
                ui->tableWidget->setItem(rowCount, 2, new QTableWidgetItem(query.value(2).toString())); // Prénom
                ui->tableWidget->setItem(rowCount, 3, new QTableWidgetItem(query.value(3).toString())); // Email
                ui->tableWidget->setItem(rowCount, 4, new QTableWidgetItem(query.value(4).toString())); // Téléphone
                ui->tableWidget->setItem(rowCount, 5, new QTableWidgetItem(query.value(5).toString())); // Adresse
                ui->tableWidget->setItem(rowCount, 6, new QTableWidgetItem(query.value(6).toString())); // Mot de passe
                ui->tableWidget->setItem(rowCount, 7, new QTableWidgetItem(query.value(7).toString())); // Solde
            }
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête pour charger les clients :" << query.lastError().text();
        }
    } else {
        qDebug() << "La base de données n'est pas ouverte.";
    }
}

/* ________________ Fonction resetForm ____________________ */

void MainWindow::resetForm() {
    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_telephone->clear();
    ui->lineEdit_adresse->clear();
    ui->lineEdit_mdp->clear();
    ui->lineEdit_sld->clear();
     ui->lineEdit_Montant->clear();
}

/* ________________ Fonction itemClicked ____________________ */

void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    int row = item->row();

    // Remplir les champs avec les données de la ligne sélectionnée
    ui->lineEdit_id->setText(ui->tableWidget->item(row, 0)->text());
    ui->lineEdit_nom->setText(ui->tableWidget->item(row, 1)->text());
    ui->lineEdit_prenom->setText(ui->tableWidget->item(row, 2)->text());
    ui->lineEdit_email->setText(ui->tableWidget->item(row, 3)->text());
    ui->lineEdit_telephone->setText(ui->tableWidget->item(row, 4)->text());
    ui->lineEdit_adresse->setText(ui->tableWidget->item(row, 5)->text());
    ui->lineEdit_mdp->setText(ui->tableWidget->item(row, 6)->text());
    ui->lineEdit_sld->setText(ui->tableWidget->item(row, 7)->text());

    // Activer les boutons de modification et de suppression
    ui->Button_modifier->setEnabled(true);
    ui->Button_Supprimer->setEnabled(true);
    ui->Button_Virements->setEnabled(true);
    ui->Button_retraiss->setEnabled(true);
    ui->Button_Ajouter->setEnabled(false);
     ui->lineEdit_Montant->setReadOnly(false);


}




/* ________________ Fonction Virement ____________________ */



void MainWindow::on_Button_Virements_clicked()
{

    if (DB_Connection.open()) {
           QSqlDatabase::database().transaction();

           // Récupérer le montant à ajouter et l'ID du client destinataire
           double montantVirement = ui->lineEdit_Montant->text().toDouble();
           int idClientDestinataire = ui->lineEdit_id->text().toInt();
           qDebug() << montantVirement;
           qDebug()<< idClientDestinataire;

           // Obtenir le solde actuel du client destinataire
           QSqlQuery queryDestinataire(DB_Connection);
           queryDestinataire.prepare("SELECT solde FROM client WHERE id = :id");
           queryDestinataire.bindValue(":id", idClientDestinataire);

           if (queryDestinataire.exec() && queryDestinataire.next()) {
               double soldeActuelDestinataire = queryDestinataire.value(0).toDouble();

               // Calculer le nouveau solde en ajoutant le montant du virement
               double nouveauSoldeDestinataire = soldeActuelDestinataire + montantVirement;

               // Mettre à jour le solde du client destinataire
               QSqlQuery queryUpdateDestinataire(DB_Connection);
               queryUpdateDestinataire.prepare("UPDATE client SET solde = :solde WHERE id = :id");
               queryUpdateDestinataire.bindValue(":solde", nouveauSoldeDestinataire);
               queryUpdateDestinataire.bindValue(":id", idClientDestinataire);

               if (queryUpdateDestinataire.exec()) {
                   QSqlDatabase::database().commit();
                   QMessageBox::information(this, "Succès", "Virement effectué avec succès.");
                   afficherTotalSolde();  // Mettre à jour la somme des soldes
                   loadClients(); // Recharger les clients après virement
                   resetForm(); // Réinitialiser le formulaire
                   ui->Button_Ajouter->setEnabled(true);
                   ui->Button_modifier->setEnabled(false);
                   ui->Button_Supprimer->setEnabled(false);
                   ui->Button_Virements->setEnabled(false);
                   ui->Button_retraiss->setEnabled(false);
                   ui->lineEdit_Montant->setReadOnly(true);
               } else {
                   QSqlDatabase::database().rollback();
                   QMessageBox::warning(this, "Erreur", "Échec de la mise à jour du solde : " + queryUpdateDestinataire.lastError().text());
                   ui->Button_Ajouter->setEnabled(true);
                   ui->Button_modifier->setEnabled(false);
                   ui->Button_Supprimer->setEnabled(false);
                   ui->Button_Virements->setEnabled(false);
                   ui->Button_retraiss->setEnabled(false);
                   ui->lineEdit_Montant->setReadOnly(true);
               }
           } else {
               QMessageBox::warning(this, "Erreur", "Client destinataire introuvable.");
               ui->Button_Ajouter->setEnabled(true);
               ui->Button_modifier->setEnabled(false);
               ui->Button_Supprimer->setEnabled(false);
               ui->Button_Virements->setEnabled(false);
               ui->Button_retraiss->setEnabled(false);
               ui->lineEdit_Montant->setReadOnly(true);
           }
       } else {
           QMessageBox::warning(this, "Erreur", "Base de données non connectée.");
           ui->Button_Ajouter->setEnabled(true);
           ui->Button_modifier->setEnabled(false);
           ui->Button_Supprimer->setEnabled(false);
           ui->Button_Virements->setEnabled(false);
           ui->Button_retraiss->setEnabled(false);
           ui->lineEdit_Montant->setReadOnly(true);
       }

}

/* ________________ Fonction Retrait ____________________ */

void MainWindow::on_Button_retraiss_clicked()
{
    if (DB_Connection.open()) {
        QSqlDatabase::database().transaction();

        // Récupérer le montant à retirer et l'ID du client
        double montantRetrait = ui->lineEdit_Montant->text().toDouble();
        int idClient = ui->lineEdit_id->text().toInt();

        // Obtenir le solde actuel du client
        QSqlQuery queryClient(DB_Connection);
        queryClient.prepare("SELECT solde FROM client WHERE id = :id");
        queryClient.bindValue(":id", idClient);

        if (queryClient.exec() && queryClient.next()) {
            double soldeActuelClient = queryClient.value(0).toDouble();

            // Vérifier si le montant de retrait est valide
            if (montantRetrait > 0 && montantRetrait <= soldeActuelClient) {
                // Calculer le nouveau solde en soustrayant le montant du retrait
                double nouveauSoldeClient = soldeActuelClient - montantRetrait;

                // Mettre à jour le solde du client
                QSqlQuery queryUpdateClient(DB_Connection);
                queryUpdateClient.prepare("UPDATE client SET solde = :solde WHERE id = :id");
                queryUpdateClient.bindValue(":solde", nouveauSoldeClient);
                queryUpdateClient.bindValue(":id", idClient);

                if (queryUpdateClient.exec()) {
                    QSqlDatabase::database().commit();
                    QMessageBox::information(this, "Succès", "Retrait effectué avec succès.");
                    afficherTotalSolde();  // Mettre à jour la somme des soldes
                    loadClients(); // Recharger les clients après retrait
                    resetForm(); // Réinitialiser le formulaire
                } else {
                    QSqlDatabase::database().rollback();
                    QMessageBox::warning(this, "Erreur", "Échec de la mise à jour du solde : " + queryUpdateClient.lastError().text());
                    ui->Button_Ajouter->setEnabled(true);
                    ui->Button_modifier->setEnabled(false);
                    ui->Button_Supprimer->setEnabled(false);
                    ui->Button_Virements->setEnabled(false);
                    ui->Button_retraiss->setEnabled(false);
                    ui->lineEdit_Montant->setReadOnly(true);
                    afficherTotalSolde();  // Mettre à jour la somme des soldes
                    loadClients(); // Recharger les clients après retrait
                    resetForm(); // Réinitialiser le formulaire
                }
            } else {
                QMessageBox::warning(this, "Erreur", "Montant de retrait invalide.");
                ui->Button_Ajouter->setEnabled(true);
                ui->Button_modifier->setEnabled(false);
                ui->Button_Supprimer->setEnabled(false);
                ui->Button_Virements->setEnabled(false);
                ui->Button_retraiss->setEnabled(false);
                ui->lineEdit_Montant->setReadOnly(true);
                afficherTotalSolde();  // Mettre à jour la somme des soldes
                loadClients(); // Recharger les clients après retrait
                resetForm(); // Réinitialiser le formulaire
            }
        } else {
            QMessageBox::warning(this, "Erreur", "Client introuvable.");
            ui->Button_Ajouter->setEnabled(true);
            ui->Button_modifier->setEnabled(false);
            ui->Button_Supprimer->setEnabled(false);
            ui->Button_Virements->setEnabled(false);
            ui->Button_retraiss->setEnabled(false);
            ui->lineEdit_Montant->setReadOnly(true);
            afficherTotalSolde();  // Mettre à jour la somme des soldes
            loadClients(); // Recharger les clients après retrait
            resetForm(); // Réinitialiser le formulaire
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Base de données non connectée.");
        ui->Button_Ajouter->setEnabled(true);
        ui->Button_modifier->setEnabled(false);
        ui->Button_Supprimer->setEnabled(false);
        ui->Button_Virements->setEnabled(false);
        ui->Button_retraiss->setEnabled(false);
        ui->lineEdit_Montant->setReadOnly(true);
        afficherTotalSolde();  // Mettre à jour la somme des soldes
        loadClients(); // Recharger les clients après retrait
        resetForm(); // Réinitialiser le formulaire
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->Button_Ajouter->setEnabled(true);
    ui->Button_modifier->setEnabled(false);
    ui->Button_Supprimer->setEnabled(false);
    ui->Button_Virements->setEnabled(false);
    ui->Button_retraiss->setEnabled(false);
    ui->lineEdit_Montant->setReadOnly(true);
    afficherTotalSolde();  // Mettre à jour la somme des soldes
    loadClients(); // Recharger les clients après retrait
    resetForm(); // Réinitialiser le formulaire
}
