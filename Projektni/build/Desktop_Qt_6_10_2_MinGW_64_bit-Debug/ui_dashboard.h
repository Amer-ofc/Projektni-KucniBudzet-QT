/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashboardWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *sidebar;
    QVBoxLayout *verticalLayout;
    QLabel *label3;
    QPushButton *btnDashboard;
    QPushButton *btnGrafikon;
    QPushButton *btnPostavke;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *pageDashboard;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_cards;
    QFrame *FrameKartica;
    QVBoxLayout *verticalLayout_3;
    QLabel *Stanjeracuna2Label;
    QLabel *StanjeRacunaLabel;
    QFrame *PrihodiKartica;
    QVBoxLayout *verticalLayout_4;
    QLabel *PrihodiLabel;
    QLabel *Prihodi2Label;
    QFrame *RashodiKartica;
    QVBoxLayout *verticalLayout_5;
    QLabel *Rashodi2Label;
    QLabel *RashodiLabel;
    QHBoxLayout *horizontalLayout_filter;
    QLabel *label_4;
    QComboBox *cbMjesec;
    QLabel *labelGodina;
    QComboBox *cbGodina;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnDodajPrihod;
    QPushButton *btnDodajRashod;
    QPushButton *btnObrisi;
    QTableView *tableViewTransakcije;
    QWidget *pageChart;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_chart_title;
    QWidget *chartContainer;

    void setupUi(QMainWindow *DashboardWindow)
    {
        if (DashboardWindow->objectName().isEmpty())
            DashboardWindow->setObjectName("DashboardWindow");
        DashboardWindow->resize(1200, 800);
        DashboardWindow->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #667eea, stop:1 #764ba2);\n"
"    font-family: \"Segoe UI\";\n"
"}\n"
"\n"
"QWidget#sidebar {\n"
"    background: rgba(0,0,0,0.12);\n"
"    border-right: 1px solid rgba(255,255,255,0.06);\n"
"}\n"
"QLabel#appTitle {\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: 700;\n"
"    padding: 12px 16px;\n"
"}\n"
"QPushButton.sideBtn {\n"
"    color: rgba(255,255,255,0.9);\n"
"    background: transparent;\n"
"    border: none;\n"
"    text-align: left;\n"
"    padding: 10px 16px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton.sideBtn:hover {\n"
"    background: rgba(255,255,255,0.04);\n"
"}\n"
"\n"
"QFrame.card {\n"
"    background: rgba(255,255,255,0.06);\n"
"    border: 1px solid rgba(255,255,255,0.10);\n"
"    border-radius: 10px;\n"
"    padding: 14px;\n"
"}\n"
"QLabel.cardTitle { color: rgba(255,255,255,0.8); font-size:12px; }\n"
"QLabel.cardValue { color: white; font-size:20px; font-weight:700; }\n"
""
                        "\n"
"QTableView {\n"
"    background: rgba(255,255,255,0.03);\n"
"    gridline-color: rgba(255,255,255,0.06);\n"
"    color: white;\n"
"    selection-background-color: rgba(99,102,241,0.3);\n"
"    alternate-background-color: rgb(0, 0, 0);\n"
"    border: 1px solid rgba(255,255,255,0.06);\n"
"    border-radius: 6px;\n"
"}\n"
"QHeaderView::section {\n"
"    background: rgba(255,255,255,0.04);\n"
"    color: rgb(119, 73, 255);\n"
"    padding: 6px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton#btnDodajPrihod, QPushButton#btnDodajRashod {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #6366f1, stop:1 #06b6d4);\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    font-weight: 700;\n"
"}\n"
"   "));
        centralwidget = new QWidget(DashboardWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sidebar = new QWidget(centralwidget);
        sidebar->setObjectName("sidebar");
        sidebar->setMinimumSize(QSize(220, 0));
        sidebar->setMaximumSize(QSize(220, 16777215));
        verticalLayout = new QVBoxLayout(sidebar);
        verticalLayout->setObjectName("verticalLayout");
        label3 = new QLabel(sidebar);
        label3->setObjectName("label3");

        verticalLayout->addWidget(label3);

        btnDashboard = new QPushButton(sidebar);
        btnDashboard->setObjectName("btnDashboard");

        verticalLayout->addWidget(btnDashboard);

        btnGrafikon = new QPushButton(sidebar);
        btnGrafikon->setObjectName("btnGrafikon");

        verticalLayout->addWidget(btnGrafikon);

        btnPostavke = new QPushButton(sidebar);
        btnPostavke->setObjectName("btnPostavke");

        verticalLayout->addWidget(btnPostavke);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(sidebar);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        pageDashboard = new QWidget();
        pageDashboard->setObjectName("pageDashboard");
        verticalLayout_2 = new QVBoxLayout(pageDashboard);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        horizontalLayout_cards = new QHBoxLayout();
        horizontalLayout_cards->setObjectName("horizontalLayout_cards");
        FrameKartica = new QFrame(pageDashboard);
        FrameKartica->setObjectName("FrameKartica");
        verticalLayout_3 = new QVBoxLayout(FrameKartica);
        verticalLayout_3->setObjectName("verticalLayout_3");
        Stanjeracuna2Label = new QLabel(FrameKartica);
        Stanjeracuna2Label->setObjectName("Stanjeracuna2Label");

        verticalLayout_3->addWidget(Stanjeracuna2Label);

        StanjeRacunaLabel = new QLabel(FrameKartica);
        StanjeRacunaLabel->setObjectName("StanjeRacunaLabel");

        verticalLayout_3->addWidget(StanjeRacunaLabel);


        horizontalLayout_cards->addWidget(FrameKartica);

        PrihodiKartica = new QFrame(pageDashboard);
        PrihodiKartica->setObjectName("PrihodiKartica");
        verticalLayout_4 = new QVBoxLayout(PrihodiKartica);
        verticalLayout_4->setObjectName("verticalLayout_4");
        PrihodiLabel = new QLabel(PrihodiKartica);
        PrihodiLabel->setObjectName("PrihodiLabel");

        verticalLayout_4->addWidget(PrihodiLabel);

        Prihodi2Label = new QLabel(PrihodiKartica);
        Prihodi2Label->setObjectName("Prihodi2Label");

        verticalLayout_4->addWidget(Prihodi2Label);


        horizontalLayout_cards->addWidget(PrihodiKartica);

        RashodiKartica = new QFrame(pageDashboard);
        RashodiKartica->setObjectName("RashodiKartica");
        verticalLayout_5 = new QVBoxLayout(RashodiKartica);
        verticalLayout_5->setObjectName("verticalLayout_5");
        Rashodi2Label = new QLabel(RashodiKartica);
        Rashodi2Label->setObjectName("Rashodi2Label");

        verticalLayout_5->addWidget(Rashodi2Label);

        RashodiLabel = new QLabel(RashodiKartica);
        RashodiLabel->setObjectName("RashodiLabel");

        verticalLayout_5->addWidget(RashodiLabel);


        horizontalLayout_cards->addWidget(RashodiKartica);


        verticalLayout_2->addLayout(horizontalLayout_cards);

        horizontalLayout_filter = new QHBoxLayout();
        horizontalLayout_filter->setObjectName("horizontalLayout_filter");
        label_4 = new QLabel(pageDashboard);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_filter->addWidget(label_4);

        cbMjesec = new QComboBox(pageDashboard);
        cbMjesec->setObjectName("cbMjesec");

        horizontalLayout_filter->addWidget(cbMjesec);

        labelGodina = new QLabel(pageDashboard);
        labelGodina->setObjectName("labelGodina");
        labelGodina->setStyleSheet(QString::fromUtf8("color: white; margin-left: 10px;"));

        horizontalLayout_filter->addWidget(labelGodina);

        cbGodina = new QComboBox(pageDashboard);
        cbGodina->setObjectName("cbGodina");

        horizontalLayout_filter->addWidget(cbGodina);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_filter->addItem(horizontalSpacer);

        btnDodajPrihod = new QPushButton(pageDashboard);
        btnDodajPrihod->setObjectName("btnDodajPrihod");

        horizontalLayout_filter->addWidget(btnDodajPrihod);

        btnDodajRashod = new QPushButton(pageDashboard);
        btnDodajRashod->setObjectName("btnDodajRashod");

        horizontalLayout_filter->addWidget(btnDodajRashod);

        btnObrisi = new QPushButton(pageDashboard);
        btnObrisi->setObjectName("btnObrisi");
        btnObrisi->setStyleSheet(QString::fromUtf8("background: #ef4444; color: white; border-radius: 8px; padding: 8px 12px; font-weight: 700;"));

        horizontalLayout_filter->addWidget(btnObrisi);


        verticalLayout_2->addLayout(horizontalLayout_filter);

        tableViewTransakcije = new QTableView(pageDashboard);
        tableViewTransakcije->setObjectName("tableViewTransakcije");
        tableViewTransakcije->setAutoScroll(false);
        tableViewTransakcije->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        tableViewTransakcije->setShowGrid(false);
        tableViewTransakcije->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(tableViewTransakcije);

        stackedWidget->addWidget(pageDashboard);
        pageChart = new QWidget();
        pageChart->setObjectName("pageChart");
        verticalLayout_6 = new QVBoxLayout(pageChart);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_chart_title = new QLabel(pageChart);
        label_chart_title->setObjectName("label_chart_title");
        label_chart_title->setMaximumSize(QSize(16777215, 200));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(16);
        font.setBold(true);
        label_chart_title->setFont(font);
        label_chart_title->setStyleSheet(QString::fromUtf8("color: white;"));
        label_chart_title->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(label_chart_title);

        chartContainer = new QWidget(pageChart);
        chartContainer->setObjectName("chartContainer");
        chartContainer->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0.05); border-radius: 10px;"));

        verticalLayout_6->addWidget(chartContainer);

        stackedWidget->addWidget(pageChart);

        horizontalLayout->addWidget(stackedWidget);

        DashboardWindow->setCentralWidget(centralwidget);

        retranslateUi(DashboardWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DashboardWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DashboardWindow)
    {
        DashboardWindow->setWindowTitle(QCoreApplication::translate("DashboardWindow", "Ku\304\207ni Bud\305\276et - Dashboard", nullptr));
        label3->setText(QCoreApplication::translate("DashboardWindow", "Ku\304\207ni Bud\305\276et", nullptr));
        btnDashboard->setText(QCoreApplication::translate("DashboardWindow", "\360\237\223\212 Dashboard", nullptr));
        btnDashboard->setProperty("class", QVariant(QCoreApplication::translate("DashboardWindow", "sideBtn", nullptr)));
        btnGrafikon->setText(QCoreApplication::translate("DashboardWindow", "\360\237\223\210 Prikaz Grafikona", nullptr));
        btnGrafikon->setProperty("class", QVariant(QCoreApplication::translate("DashboardWindow", "sideBtn", nullptr)));
        btnPostavke->setText(QCoreApplication::translate("DashboardWindow", "\342\232\231\357\270\217 Postavke", nullptr));
        btnPostavke->setProperty("class", QVariant(QCoreApplication::translate("DashboardWindow", "sideBtn", nullptr)));
        FrameKartica->setProperty("class", QVariant(QCoreApplication::translate("DashboardWindow", "card", nullptr)));
        Stanjeracuna2Label->setText(QCoreApplication::translate("DashboardWindow", "Trenutno Stanje", nullptr));
        Stanjeracuna2Label->setProperty("class", QVariant(QCoreApplication::translate("DashboardWindow", "cardTitle", nullptr)));
        StanjeRacunaLabel->setText(QCoreApplication::translate("DashboardWindow", "0.00 KM", nullptr));
        StanjeRacunaLabel->setProperty("class", QVariant(QCoreApplication::translate("DashboardWindow", "cardValue", nullptr)));
        PrihodiKartica->setProperty("class", QVariant(QCoreApplication::translate("DashboardWindow", "card", nullptr)));
        PrihodiLabel->setText(QCoreApplication::translate("DashboardWindow", "Prihodi (Ova godina)", nullptr));
        PrihodiLabel->setProperty("class", QVariant(QCoreApplication::translate("DashboardWindow", "cardTitle", nullptr)));
        Prihodi2Label->setText(QCoreApplication::translate("DashboardWindow", "0.00 KM", nullptr));
        Prihodi2Label->setProperty("class", QVariant(QCoreApplication::translate("DashboardWindow", "cardValue", nullptr)));
        RashodiKartica->setProperty("class", QVariant(QCoreApplication::translate("DashboardWindow", "card", nullptr)));
        Rashodi2Label->setText(QCoreApplication::translate("DashboardWindow", "Rashodi (Ova godina)", nullptr));
        Rashodi2Label->setProperty("class", QVariant(QCoreApplication::translate("DashboardWindow", "cardTitle", nullptr)));
        RashodiLabel->setText(QCoreApplication::translate("DashboardWindow", "0.00 KM", nullptr));
        RashodiLabel->setProperty("class", QVariant(QCoreApplication::translate("DashboardWindow", "cardValue", nullptr)));
        label_4->setText(QCoreApplication::translate("DashboardWindow", "Prikaz za mjesec:", nullptr));
        labelGodina->setText(QCoreApplication::translate("DashboardWindow", "Godina:", nullptr));
        btnDodajPrihod->setText(QCoreApplication::translate("DashboardWindow", "+ Dodaj Prihod", nullptr));
        btnDodajRashod->setText(QCoreApplication::translate("DashboardWindow", "- Dodaj Rashod", nullptr));
        btnObrisi->setText(QCoreApplication::translate("DashboardWindow", "\360\237\227\221\357\270\217 Obri\305\241i", nullptr));
        label_chart_title->setText(QCoreApplication::translate("DashboardWindow", "Prihodi i rashodi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashboardWindow: public Ui_DashboardWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
