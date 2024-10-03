/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_telephone;
    QLineEdit *lineEdit_adresse;
    QLineEdit *lineEdit_mdp;
    QPushButton *Button_Ajouter;
    QPushButton *Button_Supprimer;
    QPushButton *Button_modifier;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_sld;
    QLabel *label_9;
    QLineEdit *lineEdit_id;
    QPushButton *Button_Virements;
    QLineEdit *lineEdit_Montant;
    QLineEdit *lineEdit_Total;
    QLabel *label_10;
    QLabel *label_11;
    QTableWidget *tableWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *Button_retraiss;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1038, 473);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit_nom = new QLineEdit(centralWidget);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(90, 110, 121, 20));
        lineEdit_prenom = new QLineEdit(centralWidget);
        lineEdit_prenom->setObjectName(QStringLiteral("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(90, 140, 121, 20));
        lineEdit_email = new QLineEdit(centralWidget);
        lineEdit_email->setObjectName(QStringLiteral("lineEdit_email"));
        lineEdit_email->setGeometry(QRect(90, 180, 121, 20));
        lineEdit_telephone = new QLineEdit(centralWidget);
        lineEdit_telephone->setObjectName(QStringLiteral("lineEdit_telephone"));
        lineEdit_telephone->setGeometry(QRect(90, 220, 121, 20));
        lineEdit_adresse = new QLineEdit(centralWidget);
        lineEdit_adresse->setObjectName(QStringLiteral("lineEdit_adresse"));
        lineEdit_adresse->setGeometry(QRect(90, 260, 121, 20));
        lineEdit_mdp = new QLineEdit(centralWidget);
        lineEdit_mdp->setObjectName(QStringLiteral("lineEdit_mdp"));
        lineEdit_mdp->setGeometry(QRect(90, 300, 121, 20));
        Button_Ajouter = new QPushButton(centralWidget);
        Button_Ajouter->setObjectName(QStringLiteral("Button_Ajouter"));
        Button_Ajouter->setGeometry(QRect(0, 370, 91, 41));
        Button_Supprimer = new QPushButton(centralWidget);
        Button_Supprimer->setObjectName(QStringLiteral("Button_Supprimer"));
        Button_Supprimer->setGeometry(QRect(190, 370, 81, 41));
        Button_modifier = new QPushButton(centralWidget);
        Button_modifier->setObjectName(QStringLiteral("Button_modifier"));
        Button_modifier->setGeometry(QRect(100, 370, 81, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 110, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 150, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 190, 47, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 270, 47, 13));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 230, 47, 13));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 300, 71, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 340, 47, 13));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(90, 10, 601, 41));
        QFont font;
        font.setFamily(QStringLiteral("Maiandra GD"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        label_8->setFont(font);
        lineEdit_sld = new QLineEdit(centralWidget);
        lineEdit_sld->setObjectName(QStringLiteral("lineEdit_sld"));
        lineEdit_sld->setGeometry(QRect(90, 340, 121, 20));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 70, 47, 13));
        lineEdit_id = new QLineEdit(centralWidget);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(90, 69, 121, 21));
        Button_Virements = new QPushButton(centralWidget);
        Button_Virements->setObjectName(QStringLiteral("Button_Virements"));
        Button_Virements->setGeometry(QRect(490, 370, 75, 41));
        lineEdit_Montant = new QLineEdit(centralWidget);
        lineEdit_Montant->setObjectName(QStringLiteral("lineEdit_Montant"));
        lineEdit_Montant->setGeometry(QRect(330, 370, 151, 41));
        lineEdit_Total = new QLineEdit(centralWidget);
        lineEdit_Total->setObjectName(QStringLiteral("lineEdit_Total"));
        lineEdit_Total->setGeometry(QRect(722, 350, 271, 61));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(280, 380, 47, 13));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(670, 370, 41, 20));
        QFont font1;
        font1.setPointSize(12);
        label_11->setFont(font1);
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(220, 70, 801, 271));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(620, 240, 160, 80));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        Button_retraiss = new QPushButton(centralWidget);
        Button_retraiss->setObjectName(QStringLiteral("Button_retraiss"));
        Button_retraiss->setGeometry(QRect(570, 372, 75, 41));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(770, 20, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1038, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Button_Ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        Button_Supprimer->setText(QApplication::translate("MainWindow", "Supprimer ", Q_NULLPTR));
        Button_modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Prenom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "email", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "adresse", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "telephone", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "mots de passe", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Solde", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Gestion Bancaire [ Banque Madagascar ]", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        Button_Virements->setText(QApplication::translate("MainWindow", "Virements", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Montant", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Total:", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Id", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Prenom", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Email", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "telephone", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Adresse", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "mots de pass", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Solde", Q_NULLPTR));
        Button_retraiss->setText(QApplication::translate("MainWindow", "Retrais", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "fresh", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
