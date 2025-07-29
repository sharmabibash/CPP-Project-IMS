#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include "../loginwindow/loginwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    setWindowTitle("User Registration");
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::on_registerButton_clicked()
{
    QString email = ui->emailInput->text().trimmed();
    QString password = ui->passwordInput->text();
    QString confirmPassword = ui->confirmPasswordInput->text();
    QString CompanyName = ui->companyNameInput->text().trimmed();
    QString registrationNo = ui->regNoInput->text().trimmed();
    QString MobileNo = ui->mobileInput->text().trimmed();

    if (email.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Input Error", "Passwords do not match.");
        return;
    }

    QString folderPath = "../database";
    QString filePath = folderPath + "/users.txt";

    qDebug() << "Current working directory:" << QDir::currentPath();

    QDir dir;
    if (!dir.exists(folderPath)) {
        if (!dir.mkdir(folderPath)) {
            QMessageBox::critical(this, "Folder Error", "Failed to create 'database' folder.");
            return;
        }
    }

    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Unable to open users.txt file.");
        return;
    }

    QTextStream out(&file);
    out << email << "," << password << "," << CompanyName << "," <<registrationNo << "," << MobileNo<< "\n";
    file.close();

    QMessageBox::information(this, "Registration Successful", "User registered successfully!");

   
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->setAttribute(Qt::WA_DeleteOnClose);
    loginWindow->show();

    this->close(); 
}
