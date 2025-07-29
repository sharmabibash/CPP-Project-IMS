#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "../dashboardwindow/dashboardwindow.h"
#include "../registrationwindow/registrationwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    setWindowTitle("IMS Login");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    QString email = ui->emailInput->text().trimmed();
    QString password = ui->passwordInput->text();

    if (email.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter email and password.");
        return;
    }

    QString filePath = "../database/users.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "File Error", "Unable to open users.txt file. Have you registered yet?");
        return;
    }

    QTextStream in(&file);
    bool loginSuccess = false;
    QString companyName, mobile, regNo;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList parts = line.split(',');

        if (parts.size() >= 5)  
        {
            QString savedEmail = parts[0].trimmed();
            QString savedPassword = parts[1].trimmed();

            if (email == savedEmail && password == savedPassword)
            {
                loginSuccess = true;
                companyName = parts[2].trimmed();
                mobile = parts[3].trimmed();
                regNo = parts[4].trimmed();
                break;
            }
        }
    }
    file.close();

    if (loginSuccess)
    {
        QMessageBox::information(this, "Login Successful", 
                               QString("Welcome to %1!")
                               .arg(companyName));
        DashboardWindow *dashboard = new DashboardWindow(email, companyName, mobile, regNo);
        dashboard->setAttribute(Qt::WA_DeleteOnClose);
        dashboard->show();
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "Login Failed", "Incorrect email or password.");
    }
}

void LoginWindow::on_registerButton_clicked()
{
    RegistrationWindow *regWindow = new RegistrationWindow();
    regWindow->setAttribute(Qt::WA_DeleteOnClose);
    regWindow->show();
    this->close();
}