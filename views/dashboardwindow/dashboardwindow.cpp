#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
#include "../loginwindow/loginwindow.h"
#include "AddProductDialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDir>
#include <QCoreApplication>
#include <QAbstractItemView>
#include "../functions/login/handle_login.cpp"
#include "../functions/actions/product_search.cpp"
#include "../functions/actions/onproduct_added.cpp"
#include "../functions/actions/onproduct_edit.cpp"
#include "../functions/actions/loadproduct.cpp"
#include "../functions/actions/onproduct_update.cpp"
#include "../functions/actions/onproduct_delete.cpp"
#include "../functions/read_write/readproduct.cpp"
#include "../functions/read_write/writeproduct.cpp"

DashboardWindow::DashboardWindow(const QString &email,
                                 const QString &companyName,
                                 const QString &mobile,
                                 const QString &regNo,
                                 QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DashboardWindow),
    userEmail(email),
    companyName(companyName),
    mobile(mobile),
    regNo(regNo)
{
    ui->setupUi(this);

    // Setup window title
    QString title = "Inventory Dashboard";
    if (!companyName.isEmpty()) {
        title = companyName + " - " + title;
    }
    setWindowTitle(title);

    // Setup welcome message
    QString welcomeMsg = "Welcome to IMS Dashboard";
    if (!companyName.isEmpty()) {
        welcomeMsg = QString("Welcome to %1's IMS Dashboard").arg(companyName);
    }
    ui->headerTitle->setText(welcomeMsg);

    // Enable editing on products table except ID column
    ui->productsTable->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    ui->productsTable->setItemDelegateForColumn(0, nullptr); // No editing for ID column

    // Create AddProductDialog instance
    addProductDialog = new AddProductDialog(this);

    // Connect signals
    connect(ui->loginButton, &QPushButton::clicked, this, &DashboardWindow::handleLogin);
    connect(ui->addProductButton, &QPushButton::clicked, this, &DashboardWindow::openAddProductDialog);
    connect(ui->productsAddButton, &QPushButton::clicked, this, &DashboardWindow::onProductsAdd);
    connect(ui->productsEditButton, &QPushButton::clicked, this, &DashboardWindow::onProductsEdit);
    connect(ui->productsDeleteButton, &QPushButton::clicked, this, &DashboardWindow::onProductsDelete);
    connect(ui->productsSearchButton, &QPushButton::clicked, this, &DashboardWindow::onProductsSearch);
    connect(ui->productsSearch, &QLineEdit::returnPressed, this, &DashboardWindow::onProductsSearch);

    // Connect AddProductDialog signal to slot
    connect(addProductDialog, &AddProductDialog::productAdded, this, &DashboardWindow::onProductAdded);
// Set header height
// Set header height
ui->productsTable->horizontalHeader()->setFixedHeight(70);

// Disable stretching to keep column widths fixed
ui->productsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

// Set column widths (indices 0-4)
ui->productsTable->setColumnWidth(0, 50);   // ID
ui->productsTable->setColumnWidth(1, 150);  // Name
ui->productsTable->setColumnWidth(2, 300);  // Description
ui->productsTable->setColumnWidth(3, 200);  // Price
ui->productsTable->setColumnWidth(4, 150);  // Quantity

// Center-align header text
ui->productsTable->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

// Center-align all cell content
for (int row = 0; row < ui->productsTable->rowCount(); ++row) {
    for (int col = 0; col < ui->productsTable->columnCount(); ++col) {
        QTableWidgetItem* item = ui->productsTable->item(row, col);
        if (!item) {
            item = new QTableWidgetItem();
            ui->productsTable->setItem(row, col, item);
        }
        item->setTextAlignment(Qt::AlignCenter);
    }
}

// Optional: Disable word wrapping if text should stay in one line
ui->productsTable->setWordWrap(false);


    // Connect navigation buttons
    connect(ui->productsButton, &QPushButton::clicked, this, &DashboardWindow::showProductsPage);
    connect(ui->transactionsButton, &QPushButton::clicked, this, &DashboardWindow::showTransactionsPage);
    connect(ui->usersButton, &QPushButton::clicked, this, &DashboardWindow::showUsersPage);
    connect(ui->reportsButtonSidebar, &QPushButton::clicked, this, &DashboardWindow::showReportsPage);
    connect(ui->suppliersButton, &QPushButton::clicked, this, &DashboardWindow::showSuppliersPage);

    // Transactions buttons
    connect(ui->stockInButton, &QPushButton::clicked, this, &DashboardWindow::onStockIn);
    connect(ui->stockOutButton, &QPushButton::clicked, this, &DashboardWindow::onStockOut);

    // Report exports
    connect(ui->exportStockCsv, &QPushButton::clicked, this, &DashboardWindow::onExportStockCsv);
    connect(ui->exportTransactionsCsv, &QPushButton::clicked, this, &DashboardWindow::onExportTransactionsCsv);

    // Connect cellChanged signal for updating product on edit
    connect(ui->productsTable, &QTableWidget::cellChanged, this, &DashboardWindow::onProductsUpdate);

    // Start on overview page
    ui->stackedPages->setCurrentWidget(ui->overviewPage);

    // Load data
    loadProductsToTable();
    loadTransactionsToTable();
    loadUsersToTable();
    loadSuppliersToTable();
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}
void DashboardWindow::showOverviewPage() { ui->stackedPages->setCurrentWidget(ui->overviewPage); }
void DashboardWindow::showProductsPage() {
    ui->stackedPages->setCurrentWidget(ui->productsPage);
    loadProductsToTable();
}
void DashboardWindow::showTransactionsPage() { ui->stackedPages->setCurrentWidget(ui->transactionsPage); }
void DashboardWindow::showUsersPage() { ui->stackedPages->setCurrentWidget(ui->usersPage); }
void DashboardWindow::showReportsPage() { ui->stackedPages->setCurrentWidget(ui->reportsPage); }
void DashboardWindow::showSuppliersPage() { ui->stackedPages->setCurrentWidget(ui->suppliersPage); }


void DashboardWindow::onProductsAdd()
{
    openAddProductDialog();
}


void DashboardWindow::onStockIn()
{
    qDebug() << "Stock In requested";
    // TODO: Implement StockIn dialog and update product quantity
}

void DashboardWindow::onStockOut()
{
    qDebug() << "Stock Out requested";
    // TODO: Implement StockOut dialog and update product quantity
}

void DashboardWindow::onExportStockCsv()
{
    qDebug() << "Export stock CSV";
    // TODO: Implement CSV export from products.json
}

void DashboardWindow::onExportTransactionsCsv()
{
    qDebug() << "Export transactions CSV";
    // TODO: Implement CSV export from transactions.json
}


void DashboardWindow::loadTransactionsToTable()
{
    ui->transactionsTable->setRowCount(0);
}

void DashboardWindow::loadUsersToTable()
{
    ui->usersTable->setRowCount(0);
}

void DashboardWindow::loadSuppliersToTable()
{
    ui->suppliersTable->setRowCount(0);
}
