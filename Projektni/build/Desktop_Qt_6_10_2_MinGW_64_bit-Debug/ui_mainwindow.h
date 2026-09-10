/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *loginFrame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(904, 818);
        MainWindow->setStyleSheet(QString::fromUtf8("/* Main background */\n"
"QMainWindow {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #667eea, stop:1 #764ba2);\n"
"    font-family: \"Segoe UI\";\n"
"}\n"
"\n"
"/* Login card */\n"
"QFrame#loginFrame {\n"
"    background-color: rgba(255,255,255,0.07);\n"
"    border: 1px solid rgba(255,255,255,0.12);\n"
"    border-radius: 16px;\n"
"    padding: 18px;\n"
"}\n"
"\n"
"/* Title */\n"
"QLabel#label {\n"
"    color: white;\n"
"    font-weight: 700;\n"
"    font-size: 22px; /* Designer \304\207e kontrolirati realnu visinu */\n"
"}\n"
"\n"
"/* Rows: icon QLabel + QLineEdit siting inside horizontal layout */\n"
"\n"
"/* QLineEdit: ima lijevi padding iznad (ostavi mjesto za ikonicu) */\n"
"QLineEdit {\n"
"    background-color: rgba(255,255,255,0.06);\n"
"    border: 1px solid rgba(255,255,255,0.10);\n"
"    border-radius: 10px;\n"
"    padding: 10px 12px 10px 12px; /* padding unutar polja */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* Focus effect */\n"
""
                        "QLineEdit:focus {\n"
"    border: 1px solid #06b6d4;\n"
"    background-color: rgba(255,255,255,0.09);\n"
"}\n"
"\n"
"/* Push button */\n"
"QPushButton#pushButton {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #6366f1, stop:1 #06b6d4);\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"    font-weight: 700;\n"
"}\n"
"\n"
"\n"
"QLabel[scaledContents=\"true\"] {\n"
"}\n"
"\n"
"QMainWindow {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #667eea, stop:1 #764ba2);\n"
"    border-image: url(:/slike/img.jpg) 0 0 0 0 stretch stretch; \n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        loginFrame = new QFrame(centralwidget);
        loginFrame->setObjectName("loginFrame");
        loginFrame->setGeometry(QRect(100, 60, 681, 631));
        loginFrame->setFrameShape(QFrame::Shape::StyledPanel);
        loginFrame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget = new QWidget(loginFrame);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(120, 20, 451, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 40));
        label->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(24, 24));
        label_2->setMaximumSize(QSize(35, 35));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/slike/user.png")));
        label_2->setScaledContents(true);

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(24, 24));
        label_3->setMaximumSize(QSize(35, 35));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/slike/padlock.png")));
        label_3->setScaledContents(true);

        horizontalLayout_3->addWidget(label_3);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 904, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "LOGIN", nullptr));
        label_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        label_3->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Spremi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
