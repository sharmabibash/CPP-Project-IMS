#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
#include "../loginwindow/loginwindow.h"
#include "AddProductDialog.h"   // Include AddProductDialog header
#include <QMessageBox>
#include <QDebug>

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

    // Connect logout button
    connect(ui->loginButton, &QPushButton::clicked, this, &DashboardWindow::handleLogin);

    // Create AddProductDialog instance
    addProductDialog = new AddProductDialog(this);

    // Connect Add Product button click to open dialog
    connect(ui->addProductButton, &QPushButton::clicked, this, &DashboardWindow::openAddProductDialog);

    // Connect productAdded signal to your slot to handle new product data
    connect(addProductDialog, &AddProductDialog::productAdded, this, &DashboardWindow::onProductAdded);
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
    // addProductDialog will be deleted automatically because of parent-child ownership
}

void DashboardWindow::handleLogin()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Logout", "Are you sure you want to logout?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    this->hide();

    LoginWindow *login = new LoginWindow();
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}

void DashboardWindow::openAddProductDialog()
{
    addProductDialog->exec();
}

void DashboardWindow::onProductAdded(const QString &name, const QString &category, int quantity, double price, const QString &description)
{
    // Here you can add your logic to handle the new product (e.g., insert into DB, update UI)
    qDebug() << "Product added:" << name << category << quantity << price << description;

    // For example: refresh product list, show confirmation, etc.
}
