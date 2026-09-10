#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QSQLDatabase>
#include <QSQLTableModel>

namespace Ui
{
class DashboardWindow;
}

class Dashboard : public QMainWindow{
    Q_OBJECT

public:
    explicit Dashboard(int userId = 1, QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_btnDashboard_clicked();
    void on_btnGrafikon_clicked();
    void on_btnDodajPrihod_clicked();
    void on_btnDodajRashod_clicked();
    void on_btnObrisi_clicked();
    void on_cbMjesec_currentTextChanged(const QString &arg1);
    void on_cbGodina_currentTextChanged(const QString &arg1);

private:
    void primijeniFilter();
    
    Ui::DashboardWindow *ui;
    
    int trenutniKorisnikID; // Pamtimo ko je ulogovan

    QSqlDatabase db;
    QSqlTableModel *model;

    void connectToDatabase();
    void setupTable();
    void updateStatistics();
    void loadChart();
    void dodajTransakciju(QString tip);
};

#endif // DASHBOARD_H
