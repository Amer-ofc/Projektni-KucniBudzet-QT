#include "dashboard.h"
#include "ui_dashboard.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QDateTime>
#include <QVBoxLayout>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

Dashboard::Dashboard(int userId, QWidget *parent) : QMainWindow(parent),ui(new Ui::DashboardWindow),
    trenutniKorisnikID(userId) // pohrana poslanog korisnika
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->pageDashboard);

    connectToDatabase();
    setupTable();
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_btnDashboard_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageDashboard);
}
void Dashboard::on_btnGrafikon_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageChart);
}


void Dashboard::connectToDatabase()
{
    // Provjera da li je baza već otvorena u projektu
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
    }
    db.setDatabaseName("C:/Users/User/Desktop/skola/Programiranje-Objektno-Amer/Projektni/novabaza.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Greška s bazom", 
                              "Baza se nije uspjela otvoriti!\nProvjeri je li fajl u pravom folderu.\n" 
                              + db.lastError().text());
    }
}

void Dashboard::setupTable()
{
    if (!db.isOpen()) return;

    model = new QSqlTableModel(this, db);
    model->setTable("Transakcije");
        model->setFilter("korisnik_id = " + QString::number(trenutniKorisnikID));
    
    model->select();
    
    model->setHeaderData(2, Qt::Horizontal, "Datum");
    model->setHeaderData(3, Qt::Horizontal, "Tip");
    model->setHeaderData(4, Qt::Horizontal, "Kategorija");
    model->setHeaderData(5, Qt::Horizontal, "Opis");
    model->setHeaderData(6, Qt::Horizontal, "Iznos (KM)");

    ui->tableViewTransakcije->setModel(model);
    
    ui->tableViewTransakcije->setStyleSheet("QTableView { color: black; background-color: white; alternate-background-color: #f0f0f0; }");

    ui->tableViewTransakcije->hideColumn(0);
    ui->tableViewTransakcije->hideColumn(1);

    ui->tableViewTransakcije->horizontalHeader()->setStretchLastSection(true);
    ui->tableViewTransakcije->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    updateStatistics();

    loadChart();
    
    ui->cbMjesec->addItems({"Svi", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"});
    
    int trenutnaGodina = QDate::currentDate().year();
    ui->cbGodina->addItems({"Sve", QString::number(trenutnaGodina-1), QString::number(trenutnaGodina), QString::number(trenutnaGodina+1)});
    ui->cbGodina->setCurrentText(QString::number(trenutnaGodina));
}

void Dashboard::updateStatistics()
{
    QSqlQuery qryIn;
    qryIn.prepare("SELECT SUM(iznos) FROM Transakcije WHERE tip = 'Prihod' AND korisnik_id = :kid");
    qryIn.bindValue(":kid", trenutniKorisnikID);
    double ukupniPrihodi = 0.0;
    if(qryIn.exec() && qryIn.next()) {
        ukupniPrihodi = qryIn.value(0).toDouble();
    }
    
    QSqlQuery qryOut;
    qryOut.prepare("SELECT SUM(iznos) FROM Transakcije WHERE tip = 'Rashod' AND korisnik_id = :kid");
    qryOut.bindValue(":kid", trenutniKorisnikID);
    double ukupniRashodi = 0.0;
    if(qryOut.exec() && qryOut.next()) {
        ukupniRashodi = qryOut.value(0).toDouble();
    }
    
    double stanje = ukupniPrihodi - ukupniRashodi;
    
    ui->Prihodi2Label->setText(QString::number(ukupniPrihodi, 'f', 2) + " KM");
    ui->RashodiLabel->setText(QString::number(ukupniRashodi, 'f', 2) + " KM");
    ui->StanjeRacunaLabel->setText(QString::number(stanje, 'f', 2) + " KM");
}

void Dashboard::dodajTransakciju(QString tip)
{
    QDialog dialog(this);
    dialog.setWindowTitle("Dodaj " + tip);
    
    QFormLayout form(&dialog);
    
    QComboBox cbKategorija;
    
    QSqlQuery qCat;
    qCat.prepare("SELECT naziv FROM Kategorije WHERE tip = :tip");
    qCat.bindValue(":tip", tip);
    if(qCat.exec()) {
        while(qCat.next()) {
            cbKategorija.addItem(qCat.value(0).toString());
        }
    }
    
    form.addRow("Kategorija:", &cbKategorija);
    
    QLineEdit leOpis;
    form.addRow("Opis:", &leOpis);
    
    QLineEdit leIznos;
    form.addRow("Iznos (KM):", &leIznos);
    
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    
    if (dialog.exec() == QDialog::Accepted) {
        double iznos = leIznos.text().toDouble();
        if (iznos <= 0) {
            QMessageBox::warning(this, "Greska", "Unesite ispravan iznos!");
            return;
        }
        
        QSqlQuery qry;
        qry.prepare("INSERT INTO Transakcije (korisnik_id, datum, tip, kategorija, opis, iznos) VALUES (:kid, :datum, :tip, :kat, :opis, :iznos)");
        qry.bindValue(":kid", trenutniKorisnikID);
        qry.bindValue(":datum", QDateTime::currentDateTime().toString("yyyy-MM-dd"));
        qry.bindValue(":tip", tip);
        qry.bindValue(":kat", cbKategorija.currentText());
        qry.bindValue(":opis", leOpis.text());
        qry.bindValue(":iznos", iznos);
        
        if(qry.exec()) {
            model->select();
            updateStatistics();
            loadChart();
        }
    }
}

void Dashboard::on_btnDodajPrihod_clicked() { dodajTransakciju("Prihod"); }
void Dashboard::on_btnDodajRashod_clicked() { dodajTransakciju("Rashod"); }

void Dashboard::on_btnObrisi_clicked()
{
    int row = ui->tableViewTransakcije->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "Brisanje", "Odaberite transakciju koju zelite obrisati.");
        return;
    }
    
    if (QMessageBox::question(this, "Potvrda", "Jeste li sigurni da zelite obrisati odabranu transakciju?") == QMessageBox::Yes) {
        model->removeRow(row);
        model->submitAll();
        model->select();
        updateStatistics();
        loadChart();
    }
}

void Dashboard::loadChart()
{
    QLayout *layout = ui->chartContainer->layout();
    if (!layout) {
        layout = new QVBoxLayout(ui->chartContainer);
    } else {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    }

    QBarSet *setPrihodi = new QBarSet("Prihodi");
    QBarSet *setRashodi = new QBarSet("Rashodi");

    QStringList mjeseci = {"Jan", "Feb", "Mar", "Apr", "Maj", "Jun", "Jul", "Avg", "Sep", "Okt", "Nov", "Dec"};
    
    QString odabranaGodina = ui->cbGodina->currentText();
    QString filterGodine = "";
    if (odabranaGodina != "Sve" && !odabranaGodina.isEmpty()) {
        filterGodine = " AND strftime('%Y', datum) = '" + odabranaGodina + "'";
    }
    
    for(int i=1; i<=12; ++i) {
        QString month = QString("%1").arg(i, 2, 10, QChar('0'));
        QSqlQuery qIn;
        qIn.prepare("SELECT SUM(iznos) FROM Transakcije WHERE tip='Prihod' AND strftime('%m', datum) = :m AND korisnik_id = :kid" + filterGodine);
        qIn.bindValue(":m", month);
        qIn.bindValue(":kid", trenutniKorisnikID);
        *setPrihodi << ((qIn.exec() && qIn.next()) ? qIn.value(0).toDouble() : 0.0);

        QSqlQuery qOut;
        qOut.prepare("SELECT SUM(iznos) FROM Transakcije WHERE tip='Rashod' AND strftime('%m', datum) = :m AND korisnik_id = :kid" + filterGodine);
        qOut.bindValue(":m", month);
        qOut.bindValue(":kid", trenutniKorisnikID);
        *setRashodi << ((qOut.exec() && qOut.next()) ? qOut.value(0).toDouble() : 0.0);
    }

    QBarSeries *series = new QBarSeries();
    series->append(setPrihodi);
    series->append(setRashodi);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(mjeseci);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(chartView);
}


void Dashboard::on_cbMjesec_currentTextChanged(const QString &arg1)
{
    primijeniFilter();
}

void Dashboard::on_cbGodina_currentTextChanged(const QString &arg1)
{
    primijeniFilter();
    loadChart();
}

void Dashboard::primijeniFilter()
{
    QString userIdStr = QString::number(trenutniKorisnikID);
    QString mjesec = ui->cbMjesec->currentText();
    QString godina = ui->cbGodina->currentText();
    
    QString filter = "korisnik_id = " + userIdStr;

    if (mjesec != "Svi") {
        filter += " AND strftime('%m', datum) = '" + mjesec + "'";
    }
    
    if (godina != "Sve" && !godina.isEmpty()) {
        filter += " AND strftime('%Y', datum) = '" + godina + "'";
    }

    model->setFilter(filter);
    model->select();
}

