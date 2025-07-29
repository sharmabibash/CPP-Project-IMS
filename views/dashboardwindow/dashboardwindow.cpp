#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
#include "../loginwindow/loginwindow.h"
#include <QMessageBox>

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
    
    
    QString title = "Inventory Dashboard";
    if (!companyName.isEmpty()) {
        title = companyName + " - " + title;
    }
    setWindowTitle(title);

  
    QString welcomeMsg = "Welcome to IMS Dashboard";
    if (!companyName.isEmpty()) {
        welcomeMsg = QString("Welcome to %1's IMS Dashboard").arg(companyName);
    }
    ui->headerTitle->setText(welcomeMsg);

   
    connect(ui->loginButton, &QPushButton::clicked, this, &DashboardWindow::handleLogin);
    
   
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
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