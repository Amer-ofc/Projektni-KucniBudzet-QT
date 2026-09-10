#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dashboard.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_2->setMaxLength(20); // Username polje
    ui->lineEdit->setMaxLength(20);   // Password polje

    ui->lineEdit->setEchoMode(QLineEdit::Password);

    if (!QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/User/Desktop/skola/Programiranje-Objektno-Amer/Projektni/novabaza.db"); 
        db.open();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_2->text();
    QString password = ui->lineEdit->text();

    QSqlQuery qry;
    qry.prepare("SELECT * FROM Korisnici WHERE username = :username AND password = :password");
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);

    if (qry.exec()) {
        if (qry.next()) {
            int logovaniKorisnikID = qry.value(0).toInt();

            Dashboard *dash = new Dashboard(logovaniKorisnikID);
            dash->show();
            
            this->hide();
        } else {
            QMessageBox::warning(this, "Neuspješan login", "Pogrešno korisničko ime ili lozinka!");
            
            ui->lineEdit_2->clear();
            ui->lineEdit->clear();
            
            ui->lineEdit_2->setFocus();
        }
    } else {
        QMessageBox::critical(this, "Greška s bazom", qry.lastError().text());
    }
}

