/********************************************************************************
** Form generated from reading UI file 'dashboardwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARDWINDOW_H
#define UI_DASHBOARDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashboardWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *mainLayout;
    QWidget *sidebar;
    QVBoxLayout *sidebarLayout;
    QLabel *sidebarTitle;
    QPushButton *inventoryButton;
    QPushButton *reportsButton;
    QPushButton *settingsButton;
    QSpacerItem *sidebarSpacer;
    QWidget *contentArea;
    QVBoxLayout *contentLayout;
    QWidget *header;
    QHBoxLayout *headerLayout;
    QLabel *headerTitle;
    QSpacerItem *headerSpacer;
    QWidget *mainContent;
    QGridLayout *contentGrid;
    QLabel *overviewLabel;
    QWidget *card1;
    QVBoxLayout *vboxLayout;
    QLabel *card1Title;
    QLabel *card1Value;
    QWidget *card2;
    QVBoxLayout *vboxLayout1;
    QLabel *card2Title;
    QLabel *card2Value;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DashboardWindow)
    {
        if (DashboardWindow->objectName().isEmpty())
            DashboardWindow->setObjectName("DashboardWindow");
        DashboardWindow->resize(1000, 700);
        DashboardWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background-color: #f5f6fa;\n"
"    }\n"
"   "));
        centralWidget = new QWidget(DashboardWindow);
        centralWidget->setObjectName("centralWidget");
        mainLayout = new QHBoxLayout(centralWidget);
        mainLayout->setObjectName("mainLayout");
        sidebar = new QWidget(centralWidget);
        sidebar->setObjectName("sidebar");
        sidebar->setStyleSheet(QString::fromUtf8("\n"
"        QWidget#sidebar {\n"
"            background-color: #2c3e50;\n"
"            border-right: 1px solid #34495e;\n"
"        }\n"
"        QPushButton {\n"
"            color: white;\n"
"            background-color: #3498db;\n"
"            border: none;\n"
"            padding: 10px;\n"
"            margin: 5px;\n"
"            border-radius: 5px;\n"
"            font-size: 16px;\n"
"        }\n"
"        QPushButton:hover {\n"
"            background-color: #2980b9;\n"
"        }\n"
"       "));
        sidebarLayout = new QVBoxLayout(sidebar);
        sidebarLayout->setObjectName("sidebarLayout");
        sidebarTitle = new QLabel(sidebar);
        sidebarTitle->setObjectName("sidebarTitle");
        sidebarTitle->setStyleSheet(QString::fromUtf8("\n"
"           color: white;\n"
"           font-size: 20px;\n"
"           font-weight: bold;\n"
"           padding: 20px;\n"
"          "));

        sidebarLayout->addWidget(sidebarTitle);

        inventoryButton = new QPushButton(sidebar);
        inventoryButton->setObjectName("inventoryButton");

        sidebarLayout->addWidget(inventoryButton);

        reportsButton = new QPushButton(sidebar);
        reportsButton->setObjectName("reportsButton");

        sidebarLayout->addWidget(reportsButton);

        settingsButton = new QPushButton(sidebar);
        settingsButton->setObjectName("settingsButton");

        sidebarLayout->addWidget(settingsButton);

        sidebarSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        sidebarLayout->addItem(sidebarSpacer);


        mainLayout->addWidget(sidebar);

        contentArea = new QWidget(centralWidget);
        contentArea->setObjectName("contentArea");
        contentLayout = new QVBoxLayout(contentArea);
        contentLayout->setObjectName("contentLayout");
        header = new QWidget(contentArea);
        header->setObjectName("header");
        header->setStyleSheet(QString::fromUtf8("\n"
"           background-color: white;\n"
"           border-bottom: 1px solid #e0e0e0;\n"
"           padding: 15px;\n"
"          "));
        headerLayout = new QHBoxLayout(header);
        headerLayout->setObjectName("headerLayout");
        headerTitle = new QLabel(header);
        headerTitle->setObjectName("headerTitle");
        headerTitle->setStyleSheet(QString::fromUtf8("\n"
"              font-size: 24px;\n"
"              font-weight: bold;\n"
"              color: #2c3e50;\n"
"             "));

        headerLayout->addWidget(headerTitle);

        headerSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        headerLayout->addItem(headerSpacer);


        contentLayout->addWidget(header);

        mainContent = new QWidget(contentArea);
        mainContent->setObjectName("mainContent");
        mainContent->setStyleSheet(QString::fromUtf8("\n"
"           background-color: white;\n"
"           border-radius: 10px;\n"
"           margin: 10px;\n"
"           padding: 20px;\n"
"          "));
        contentGrid = new QGridLayout(mainContent);
        contentGrid->setObjectName("contentGrid");
        overviewLabel = new QLabel(mainContent);
        overviewLabel->setObjectName("overviewLabel");
        overviewLabel->setStyleSheet(QString::fromUtf8("\n"
"              font-size: 18px;\n"
"              font-weight: bold;\n"
"              color: #2c3e50;\n"
"             "));

        contentGrid->addWidget(overviewLabel, 0, 0, 1, 1);

        card1 = new QWidget(mainContent);
        card1->setObjectName("card1");
        card1->setStyleSheet(QString::fromUtf8("\n"
"              background-color: #3498db;\n"
"              border-radius: 8px;\n"
"              padding: 15px;\n"
"              color: white;\n"
"             "));
        vboxLayout = new QVBoxLayout(card1);
        vboxLayout->setObjectName("vboxLayout");
        card1Title = new QLabel(card1);
        card1Title->setObjectName("card1Title");
        card1Title->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold;"));

        vboxLayout->addWidget(card1Title);

        card1Value = new QLabel(card1);
        card1Value->setObjectName("card1Value");
        card1Value->setStyleSheet(QString::fromUtf8("font-size: 24px;"));

        vboxLayout->addWidget(card1Value);


        contentGrid->addWidget(card1, 1, 0, 1, 1);

        card2 = new QWidget(mainContent);
        card2->setObjectName("card2");
        card2->setStyleSheet(QString::fromUtf8("\n"
"              background-color: #e74c3c;\n"
"              border-radius: 8px;\n"
"              padding: 15px;\n"
"              color: white;\n"
"             "));
        vboxLayout1 = new QVBoxLayout(card2);
        vboxLayout1->setObjectName("vboxLayout1");
        card2Title = new QLabel(card2);
        card2Title->setObjectName("card2Title");
        card2Title->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold;"));

        vboxLayout1->addWidget(card2Title);

        card2Value = new QLabel(card2);
        card2Value->setObjectName("card2Value");
        card2Value->setStyleSheet(QString::fromUtf8("font-size: 24px;"));

        vboxLayout1->addWidget(card2Value);


        contentGrid->addWidget(card2, 1, 1, 1, 1);


        contentLayout->addWidget(mainContent);


        mainLayout->addWidget(contentArea);

        DashboardWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DashboardWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        DashboardWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(DashboardWindow);
        statusBar->setObjectName("statusBar");
        DashboardWindow->setStatusBar(statusBar);

        retranslateUi(DashboardWindow);

        QMetaObject::connectSlotsByName(DashboardWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DashboardWindow)
    {
        DashboardWindow->setWindowTitle(QCoreApplication::translate("DashboardWindow", "Inventory Dashboard", nullptr));
        sidebarTitle->setText(QCoreApplication::translate("DashboardWindow", "IMS Dashboard", nullptr));
        inventoryButton->setText(QCoreApplication::translate("DashboardWindow", "Inventory", nullptr));
        reportsButton->setText(QCoreApplication::translate("DashboardWindow", "Reports", nullptr));
        settingsButton->setText(QCoreApplication::translate("DashboardWindow", "Settings", nullptr));
        headerTitle->setText(QCoreApplication::translate("DashboardWindow", "Welcome to IMS Dashboard", nullptr));
        overviewLabel->setText(QCoreApplication::translate("DashboardWindow", "Overview", nullptr));
        card1Title->setText(QCoreApplication::translate("DashboardWindow", "Total Items", nullptr));
        card1Value->setText(QCoreApplication::translate("DashboardWindow", "1,234", nullptr));
        card2Title->setText(QCoreApplication::translate("DashboardWindow", "Low Stock", nullptr));
        card2Value->setText(QCoreApplication::translate("DashboardWindow", "45", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashboardWindow: public Ui_DashboardWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARDWINDOW_H
