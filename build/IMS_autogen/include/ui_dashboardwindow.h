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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
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
    QPushButton *productsButton;
    QPushButton *transactionsButton;
    QPushButton *reportsButtonSidebar;
    QPushButton *suppliersButton;
    QPushButton *usersButton;
    QSpacerItem *sidebarSpacer;
    QPushButton *addProductButton;
    QPushButton *loginButton;
    QWidget *contentArea;
    QVBoxLayout *contentLayout;
    QWidget *header;
    QHBoxLayout *headerLayout;
    QLabel *headerTitle;
    QSpacerItem *headerSpacer;
    QStackedWidget *stackedPages;
    QWidget *overviewPage;
    QVBoxLayout *overviewLayout;
    QLabel *overviewLabel;
    QWidget *overviewCards;
    QGridLayout *overviewGrid;
    QWidget *card1;
    QVBoxLayout *vboxLayout;
    QLabel *card1Title;
    QLabel *card1Value;
    QWidget *productsPage;
    QVBoxLayout *vboxLayout1;
    QWidget *productsToolbar;
    QHBoxLayout *hboxLayout;
    QLineEdit *productsSearch;
    QPushButton *productsSearchButton;
    QSpacerItem *productsSpacer;
    QPushButton *productsAddButton;
    QPushButton *productsEditButton;
    QPushButton *productsDeleteButton;
    QTableWidget *productsTable;
    QWidget *transactionsPage;
    QVBoxLayout *vboxLayout2;
    QWidget *widget;
    QHBoxLayout *hboxLayout1;
    QPushButton *sellProductButton;
    QLineEdit *searchProduct;
    QPushButton *searchProductButton;
    QTableWidget *transactionsTable;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *customerNameInput;
    QLabel *label1;
    QLineEdit *mobileNoInput;
    QLabel *label2;
    QLineEdit *checkoutProductNameInput;
    QLabel *label3;
    QLineEdit *checkoutQuantityInput;
    QLabel *label4;
    QLineEdit *checkoutTotalPriceInput;
    QPushButton *checkoutConfirmButton;
    QWidget *usersPage;
    QVBoxLayout *vboxLayout3;
    QWidget *usersToolbar;
    QHBoxLayout *hboxLayout2;
    QPushButton *usersAddButton;
    QPushButton *usersEditButton;
    QPushButton *usersDeleteButton;
    QSpacerItem *usersSpacer;
    QTableWidget *usersTable;
    QWidget *reportsPage;
    QVBoxLayout *vboxLayout4;
    QWidget *reportsToolbar;
    QHBoxLayout *hboxLayout3;
    QPushButton *exportStockCsv;
    QPushButton *exportTransactionsCsv;
    QSpacerItem *reportsSpacer;
    QWidget *reportsContent;
    QVBoxLayout *vboxLayout5;
    QLabel *reportsPlaceholder;
    QWidget *suppliersPage;
    QVBoxLayout *vboxLayout6;
    QWidget *suppliersToolbar;
    QHBoxLayout *hboxLayout4;
    QPushButton *suppliersAddButton;
    QPushButton *customersAddButton;
    QSpacerItem *suppliersSpacer;
    QTableWidget *suppliersTable;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DashboardWindow)
    {
        if (DashboardWindow->objectName().isEmpty())
            DashboardWindow->setObjectName("DashboardWindow");
        DashboardWindow->resize(1000, 700);
        DashboardWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background-color: #2c3e50;\n"
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
"            margin: 5px 10px;\n"
"            border-radius: 5px;\n"
"            font-size: 16px;\n"
"            text-align: left;\n"
"        }\n"
"        QPushButton:hover {\n"
"            background-color: #2980b9;\n"
"        }\n"
"       "));
        sidebarLayout = new QVBoxLayout(sidebar);
        sidebarLayout->setObjectName("sidebarLayout");
        sidebarTitle = new QLabel(sidebar);
        sidebarTitle->setObjectName("sidebarTitle");
        sidebarTitle->setAlignment(Qt::AlignCenter);
        sidebarTitle->setStyleSheet(QString::fromUtf8("\n"
"           color: white;\n"
"           font-size: 22px;\n"
"           font-weight: bold;\n"
"           padding: 20px;\n"
"           border-bottom: 1px solid #34495e;\n"
"          "));

        sidebarLayout->addWidget(sidebarTitle);

        productsButton = new QPushButton(sidebar);
        productsButton->setObjectName("productsButton");

        sidebarLayout->addWidget(productsButton);

        transactionsButton = new QPushButton(sidebar);
        transactionsButton->setObjectName("transactionsButton");

        sidebarLayout->addWidget(transactionsButton);

        reportsButtonSidebar = new QPushButton(sidebar);
        reportsButtonSidebar->setObjectName("reportsButtonSidebar");

        sidebarLayout->addWidget(reportsButtonSidebar);

        suppliersButton = new QPushButton(sidebar);
        suppliersButton->setObjectName("suppliersButton");

        sidebarLayout->addWidget(suppliersButton);

        usersButton = new QPushButton(sidebar);
        usersButton->setObjectName("usersButton");

        sidebarLayout->addWidget(usersButton);

        sidebarSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        sidebarLayout->addItem(sidebarSpacer);

        addProductButton = new QPushButton(sidebar);
        addProductButton->setObjectName("addProductButton");

        sidebarLayout->addWidget(addProductButton);

        loginButton = new QPushButton(sidebar);
        loginButton->setObjectName("loginButton");
        loginButton->setStyleSheet(QString::fromUtf8("\n"
"           QPushButton {\n"
"               background-color: #1abc9c;\n"
"               color: white;\n"
"               font-size: 16px;\n"
"               padding: 10px;\n"
"               border-radius: 5px;\n"
"               margin: 10px;\n"
"           }\n"
"           QPushButton:hover {\n"
"               background-color: #16a085;\n"
"           }\n"
"          "));

        sidebarLayout->addWidget(loginButton);


        mainLayout->addWidget(sidebar);

        contentArea = new QWidget(centralWidget);
        contentArea->setObjectName("contentArea");
        contentLayout = new QVBoxLayout(contentArea);
        contentLayout->setObjectName("contentLayout");
        header = new QWidget(contentArea);
        header->setObjectName("header");
        header->setStyleSheet(QString::fromUtf8("\n"
"           background-color: #34495e;\n"
"           border-radius:30%;\n"
"           padding: 15px;\n"
"          "));
        headerLayout = new QHBoxLayout(header);
        headerLayout->setObjectName("headerLayout");
        headerTitle = new QLabel(header);
        headerTitle->setObjectName("headerTitle");
        headerTitle->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: #fdfdfdff;"));

        headerLayout->addWidget(headerTitle);

        headerSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        headerLayout->addItem(headerSpacer);


        contentLayout->addWidget(header);

        stackedPages = new QStackedWidget(contentArea);
        stackedPages->setObjectName("stackedPages");
        overviewPage = new QWidget();
        overviewPage->setObjectName("overviewPage");
        overviewPage->setStyleSheet(QString::fromUtf8("background-color: #071625ff; border-radius: 10px; margin: 10px; padding: 20px;"));
        overviewLayout = new QVBoxLayout(overviewPage);
        overviewLayout->setObjectName("overviewLayout");
        overviewLabel = new QLabel(overviewPage);
        overviewLabel->setObjectName("overviewLabel");

        overviewLayout->addWidget(overviewLabel);

        overviewCards = new QWidget(overviewPage);
        overviewCards->setObjectName("overviewCards");
        overviewGrid = new QGridLayout(overviewCards);
        overviewGrid->setObjectName("overviewGrid");
        overviewGrid->setContentsMargins(0, 0, 0, 0);
        card1 = new QWidget(overviewCards);
        card1->setObjectName("card1");
        card1->setStyleSheet(QString::fromUtf8("background-color: #3498db; border-radius: 8px; padding: 15px; color: white; font-size:20px;"));
        vboxLayout = new QVBoxLayout(card1);
        vboxLayout->setObjectName("vboxLayout");
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        card1Title = new QLabel(card1);
        card1Title->setObjectName("card1Title");

        vboxLayout->addWidget(card1Title);

        card1Value = new QLabel(card1);
        card1Value->setObjectName("card1Value");

        vboxLayout->addWidget(card1Value);


        overviewGrid->addWidget(card1, 0, 0, 1, 1);


        overviewLayout->addWidget(overviewCards);

        stackedPages->addWidget(overviewPage);
        productsPage = new QWidget();
        productsPage->setObjectName("productsPage");
        productsPage->setStyleSheet(QString::fromUtf8("background-color: #071625ff; border-radius: 10px; margin: 10px; padding: 10px;"));
        vboxLayout1 = new QVBoxLayout(productsPage);
        vboxLayout1->setObjectName("vboxLayout1");
        productsToolbar = new QWidget(productsPage);
        productsToolbar->setObjectName("productsToolbar");
        hboxLayout = new QHBoxLayout(productsToolbar);
        hboxLayout->setObjectName("hboxLayout");
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        productsSearch = new QLineEdit(productsToolbar);
        productsSearch->setObjectName("productsSearch");

        hboxLayout->addWidget(productsSearch);

        productsSearchButton = new QPushButton(productsToolbar);
        productsSearchButton->setObjectName("productsSearchButton");

        hboxLayout->addWidget(productsSearchButton);

        productsSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout->addItem(productsSpacer);

        productsAddButton = new QPushButton(productsToolbar);
        productsAddButton->setObjectName("productsAddButton");

        hboxLayout->addWidget(productsAddButton);

        productsEditButton = new QPushButton(productsToolbar);
        productsEditButton->setObjectName("productsEditButton");

        hboxLayout->addWidget(productsEditButton);

        productsDeleteButton = new QPushButton(productsToolbar);
        productsDeleteButton->setObjectName("productsDeleteButton");

        hboxLayout->addWidget(productsDeleteButton);


        vboxLayout1->addWidget(productsToolbar);

        productsTable = new QTableWidget(productsPage);
        if (productsTable->columnCount() < 5)
            productsTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        productsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        productsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        productsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        productsTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        productsTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        productsTable->setObjectName("productsTable");
        productsTable->setColumnCount(5);

        vboxLayout1->addWidget(productsTable);

        stackedPages->addWidget(productsPage);
        transactionsPage = new QWidget();
        transactionsPage->setObjectName("transactionsPage");
        vboxLayout2 = new QVBoxLayout(transactionsPage);
        vboxLayout2->setObjectName("vboxLayout2");
        widget = new QWidget(transactionsPage);
        widget->setObjectName("widget");
        hboxLayout1 = new QHBoxLayout(widget);
        hboxLayout1->setObjectName("hboxLayout1");
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        sellProductButton = new QPushButton(widget);
        sellProductButton->setObjectName("sellProductButton");

        hboxLayout1->addWidget(sellProductButton);

        searchProduct = new QLineEdit(widget);
        searchProduct->setObjectName("searchProduct");

        hboxLayout1->addWidget(searchProduct);

        searchProductButton = new QPushButton(widget);
        searchProductButton->setObjectName("searchProductButton");

        hboxLayout1->addWidget(searchProductButton);


        vboxLayout2->addWidget(widget);

        transactionsTable = new QTableWidget(transactionsPage);
        if (transactionsTable->columnCount() < 8)
            transactionsTable->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        transactionsTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        transactionsTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        transactionsTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        transactionsTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        transactionsTable->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        transactionsTable->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        transactionsTable->setHorizontalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        transactionsTable->setHorizontalHeaderItem(7, __qtablewidgetitem12);
        transactionsTable->setObjectName("transactionsTable");
        transactionsTable->setColumnCount(8);

        vboxLayout2->addWidget(transactionsTable);

        groupBox = new QGroupBox(transactionsPage);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        customerNameInput = new QLineEdit(groupBox);
        customerNameInput->setObjectName("customerNameInput");

        gridLayout->addWidget(customerNameInput, 0, 1, 1, 1);

        label1 = new QLabel(groupBox);
        label1->setObjectName("label1");

        gridLayout->addWidget(label1, 1, 0, 1, 1);

        mobileNoInput = new QLineEdit(groupBox);
        mobileNoInput->setObjectName("mobileNoInput");

        gridLayout->addWidget(mobileNoInput, 1, 1, 1, 1);

        label2 = new QLabel(groupBox);
        label2->setObjectName("label2");

        gridLayout->addWidget(label2, 2, 0, 1, 1);

        checkoutProductNameInput = new QLineEdit(groupBox);
        checkoutProductNameInput->setObjectName("checkoutProductNameInput");

        gridLayout->addWidget(checkoutProductNameInput, 2, 1, 1, 1);

        label3 = new QLabel(groupBox);
        label3->setObjectName("label3");

        gridLayout->addWidget(label3, 3, 0, 1, 1);

        checkoutQuantityInput = new QLineEdit(groupBox);
        checkoutQuantityInput->setObjectName("checkoutQuantityInput");

        gridLayout->addWidget(checkoutQuantityInput, 3, 1, 1, 1);

        label4 = new QLabel(groupBox);
        label4->setObjectName("label4");

        gridLayout->addWidget(label4, 4, 0, 1, 1);

        checkoutTotalPriceInput = new QLineEdit(groupBox);
        checkoutTotalPriceInput->setObjectName("checkoutTotalPriceInput");
        checkoutTotalPriceInput->setReadOnly(true);

        gridLayout->addWidget(checkoutTotalPriceInput, 4, 1, 1, 1);

        checkoutConfirmButton = new QPushButton(groupBox);
        checkoutConfirmButton->setObjectName("checkoutConfirmButton");
        checkoutConfirmButton->setMaximumWidth(150);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkoutConfirmButton->sizePolicy().hasHeightForWidth());
        checkoutConfirmButton->setSizePolicy(sizePolicy);
        checkoutConfirmButton->setStyleSheet(QString::fromUtf8("\n"
"                  QPushButton {\n"
"                    padding: 5px;\n"
"                    font-size: 12px;\n"
"                  }\n"
"                "));

        gridLayout->addWidget(checkoutConfirmButton, 5, 0, 1, 2);


        vboxLayout2->addWidget(groupBox);

        stackedPages->addWidget(transactionsPage);
        usersPage = new QWidget();
        usersPage->setObjectName("usersPage");
        usersPage->setStyleSheet(QString::fromUtf8("background-color: #071625ff; border-radius: 10px; margin: 10px; padding: 10px;"));
        vboxLayout3 = new QVBoxLayout(usersPage);
        vboxLayout3->setObjectName("vboxLayout3");
        usersToolbar = new QWidget(usersPage);
        usersToolbar->setObjectName("usersToolbar");
        hboxLayout2 = new QHBoxLayout(usersToolbar);
        hboxLayout2->setObjectName("hboxLayout2");
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        usersAddButton = new QPushButton(usersToolbar);
        usersAddButton->setObjectName("usersAddButton");

        hboxLayout2->addWidget(usersAddButton);

        usersEditButton = new QPushButton(usersToolbar);
        usersEditButton->setObjectName("usersEditButton");

        hboxLayout2->addWidget(usersEditButton);

        usersDeleteButton = new QPushButton(usersToolbar);
        usersDeleteButton->setObjectName("usersDeleteButton");

        hboxLayout2->addWidget(usersDeleteButton);

        usersSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout2->addItem(usersSpacer);


        vboxLayout3->addWidget(usersToolbar);

        usersTable = new QTableWidget(usersPage);
        if (usersTable->columnCount() < 4)
            usersTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        usersTable->setObjectName("usersTable");
        usersTable->setColumnCount(4);

        vboxLayout3->addWidget(usersTable);

        stackedPages->addWidget(usersPage);
        reportsPage = new QWidget();
        reportsPage->setObjectName("reportsPage");
        reportsPage->setStyleSheet(QString::fromUtf8("background-color: #071625ff; border-radius: 10px; margin: 10px; padding: 10px;"));
        vboxLayout4 = new QVBoxLayout(reportsPage);
        vboxLayout4->setObjectName("vboxLayout4");
        reportsToolbar = new QWidget(reportsPage);
        reportsToolbar->setObjectName("reportsToolbar");
        hboxLayout3 = new QHBoxLayout(reportsToolbar);
        hboxLayout3->setObjectName("hboxLayout3");
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        exportStockCsv = new QPushButton(reportsToolbar);
        exportStockCsv->setObjectName("exportStockCsv");

        hboxLayout3->addWidget(exportStockCsv);

        exportTransactionsCsv = new QPushButton(reportsToolbar);
        exportTransactionsCsv->setObjectName("exportTransactionsCsv");

        hboxLayout3->addWidget(exportTransactionsCsv);

        reportsSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout3->addItem(reportsSpacer);


        vboxLayout4->addWidget(reportsToolbar);

        reportsContent = new QWidget(reportsPage);
        reportsContent->setObjectName("reportsContent");
        vboxLayout5 = new QVBoxLayout(reportsContent);
        vboxLayout5->setObjectName("vboxLayout5");
        vboxLayout5->setContentsMargins(0, 0, 0, 0);
        reportsPlaceholder = new QLabel(reportsContent);
        reportsPlaceholder->setObjectName("reportsPlaceholder");

        vboxLayout5->addWidget(reportsPlaceholder);


        vboxLayout4->addWidget(reportsContent);

        stackedPages->addWidget(reportsPage);
        suppliersPage = new QWidget();
        suppliersPage->setObjectName("suppliersPage");
        suppliersPage->setStyleSheet(QString::fromUtf8("background-color: #071625ff; border-radius: 10px; margin: 10px; padding: 10px;"));
        vboxLayout6 = new QVBoxLayout(suppliersPage);
        vboxLayout6->setObjectName("vboxLayout6");
        suppliersToolbar = new QWidget(suppliersPage);
        suppliersToolbar->setObjectName("suppliersToolbar");
        hboxLayout4 = new QHBoxLayout(suppliersToolbar);
        hboxLayout4->setObjectName("hboxLayout4");
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        suppliersAddButton = new QPushButton(suppliersToolbar);
        suppliersAddButton->setObjectName("suppliersAddButton");

        hboxLayout4->addWidget(suppliersAddButton);

        customersAddButton = new QPushButton(suppliersToolbar);
        customersAddButton->setObjectName("customersAddButton");

        hboxLayout4->addWidget(customersAddButton);

        suppliersSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout4->addItem(suppliersSpacer);


        vboxLayout6->addWidget(suppliersToolbar);

        suppliersTable = new QTableWidget(suppliersPage);
        if (suppliersTable->columnCount() < 5)
            suppliersTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        suppliersTable->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        suppliersTable->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        suppliersTable->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        suppliersTable->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        suppliersTable->setHorizontalHeaderItem(4, __qtablewidgetitem21);
        suppliersTable->setObjectName("suppliersTable");
        suppliersTable->setColumnCount(5);

        vboxLayout6->addWidget(suppliersTable);

        stackedPages->addWidget(suppliersPage);

        contentLayout->addWidget(stackedPages);


        mainLayout->addWidget(contentArea);

        DashboardWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DashboardWindow);
        menuBar->setObjectName("menuBar");
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
        productsButton->setText(QCoreApplication::translate("DashboardWindow", "\360\237\223\246 Products", nullptr));
        transactionsButton->setText(QCoreApplication::translate("DashboardWindow", "\360\237\224\201 Transactions", nullptr));
        reportsButtonSidebar->setText(QCoreApplication::translate("DashboardWindow", "\360\237\223\212 Reports", nullptr));
        suppliersButton->setText(QCoreApplication::translate("DashboardWindow", "\360\237\217\267 Suppliers And Customers", nullptr));
        usersButton->setText(QCoreApplication::translate("DashboardWindow", "\360\237\221\245 Users", nullptr));
        addProductButton->setText(QCoreApplication::translate("DashboardWindow", "\342\236\225 Add Product", nullptr));
        loginButton->setText(QCoreApplication::translate("DashboardWindow", "\360\237\224\220 Logout", nullptr));
        headerTitle->setText(QCoreApplication::translate("DashboardWindow", "Welcome to IMS Dashboard", nullptr));
        overviewLabel->setText(QCoreApplication::translate("DashboardWindow", "Overview", nullptr));
        card1Title->setText(QCoreApplication::translate("DashboardWindow", "Total Items", nullptr));
        card1Value->setText(QCoreApplication::translate("DashboardWindow", "1,234", nullptr));
        productsSearch->setPlaceholderText(QCoreApplication::translate("DashboardWindow", "Search products...", nullptr));
        productsSearchButton->setText(QCoreApplication::translate("DashboardWindow", "Search", nullptr));
        productsAddButton->setText(QCoreApplication::translate("DashboardWindow", "\342\236\225 Add", nullptr));
        productsEditButton->setText(QCoreApplication::translate("DashboardWindow", "\342\234\217\357\270\217 Edit", nullptr));
        productsDeleteButton->setText(QCoreApplication::translate("DashboardWindow", "\360\237\227\221 Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem = productsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DashboardWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = productsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DashboardWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = productsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DashboardWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = productsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DashboardWindow", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = productsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DashboardWindow", "Quantity", nullptr));
        sellProductButton->setText(QCoreApplication::translate("DashboardWindow", "\360\237\233\222 Sell Product", nullptr));
        searchProduct->setPlaceholderText(QCoreApplication::translate("DashboardWindow", "Search by Product Name or ID...", nullptr));
        searchProductButton->setText(QCoreApplication::translate("DashboardWindow", "Search", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = transactionsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DashboardWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = transactionsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DashboardWindow", "Customer Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = transactionsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("DashboardWindow", "Customer Mobile No", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = transactionsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("DashboardWindow", "Product ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = transactionsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("DashboardWindow", "Product Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = transactionsTable->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("DashboardWindow", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = transactionsTable->horizontalHeaderItem(6);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("DashboardWindow", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = transactionsTable->horizontalHeaderItem(7);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("DashboardWindow", "Total Price", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DashboardWindow", "Checkout", nullptr));
        label->setText(QCoreApplication::translate("DashboardWindow", "Customer Name:", nullptr));
        label1->setText(QCoreApplication::translate("DashboardWindow", "Mobile No:", nullptr));
        label2->setText(QCoreApplication::translate("DashboardWindow", "Product Name:", nullptr));
        label3->setText(QCoreApplication::translate("DashboardWindow", "Quantity:", nullptr));
        label4->setText(QCoreApplication::translate("DashboardWindow", "Total Price:", nullptr));
        checkoutConfirmButton->setText(QCoreApplication::translate("DashboardWindow", "\342\234\205 Confirm Checkout", nullptr));
        usersAddButton->setText(QCoreApplication::translate("DashboardWindow", "Add User", nullptr));
        usersEditButton->setText(QCoreApplication::translate("DashboardWindow", "Edit User", nullptr));
        usersDeleteButton->setText(QCoreApplication::translate("DashboardWindow", "Delete User", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = usersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("DashboardWindow", "Username", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = usersTable->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("DashboardWindow", "Role", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = usersTable->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("DashboardWindow", "Last Login", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = usersTable->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("DashboardWindow", "Actions", nullptr));
        exportStockCsv->setText(QCoreApplication::translate("DashboardWindow", "Export Stock CSV", nullptr));
        exportTransactionsCsv->setText(QCoreApplication::translate("DashboardWindow", "Export Transactions CSV", nullptr));
        reportsPlaceholder->setText(QCoreApplication::translate("DashboardWindow", "Choose report options to view or export.", nullptr));
        suppliersAddButton->setText(QCoreApplication::translate("DashboardWindow", "Add Supplier", nullptr));
        customersAddButton->setText(QCoreApplication::translate("DashboardWindow", "Add Customer", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = suppliersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("DashboardWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = suppliersTable->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("DashboardWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = suppliersTable->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("DashboardWindow", "Contact", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = suppliersTable->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("DashboardWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = suppliersTable->horizontalHeaderItem(4);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("DashboardWindow", "Notes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashboardWindow: public Ui_DashboardWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARDWINDOW_H
