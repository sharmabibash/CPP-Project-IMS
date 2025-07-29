/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QSpacerItem *verticalSpacerTop;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacerLeft;
    QVBoxLayout *centerContentLayout;
    QWidget *loginCard;
    QVBoxLayout *cardLayout;
    QLabel *titleLabel;
    QLineEdit *emailInput;
    QLineEdit *passwordInput;
    QHBoxLayout *buttonLayout;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QLabel *forgotPasswordLabel;
    QSpacerItem *horizontalSpacerRight;
    QSpacerItem *verticalSpacerBottom;
    QLabel *footerLabel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 600);
        LoginWindow->setMinimumSize(QSize(600, 500));
        LoginWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #4B5EAA, stop:1 #1E2A44);\n"
"    }\n"
"   "));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacerTop = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        mainLayout->addItem(verticalSpacerTop);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacerLeft = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacerLeft);

        centerContentLayout = new QVBoxLayout();
        centerContentLayout->setSpacing(30);
        centerContentLayout->setObjectName("centerContentLayout");
        centerContentLayout->setContentsMargins(0, 0, 0, 0);
        loginCard = new QWidget(centralwidget);
        loginCard->setObjectName("loginCard");
        loginCard->setMinimumWidth(350);
        loginCard->setMaximumWidth(450);
        loginCard->setStyleSheet(QString::fromUtf8("\n"
"            background-color: rgba(255, 255, 255, 0.97);\n"
"            border: 1px solid rgba(0, 0, 0, 0.1);\n"
"            border-radius: 15px;\n"
"            padding: 25px;\n"
"            box-shadow: 0 10px 20px rgba(0, 0, 0, 0.15);\n"
"           "));
        cardLayout = new QVBoxLayout(loginCard);
        cardLayout->setSpacing(20);
        cardLayout->setObjectName("cardLayout");
        cardLayout->setContentsMargins(20, 15, 20, 15);
        titleLabel = new QLabel(loginCard);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet(QString::fromUtf8("\n"
"               font-size: 28px;\n"
"               font-weight: bold;\n"
"               color: #1a202c;\n"
"               padding-bottom: 10px;\n"
"               font-family: 'Segoe UI', Arial, sans-serif;\n"
"              "));

        cardLayout->addWidget(titleLabel);

        emailInput = new QLineEdit(loginCard);
        emailInput->setObjectName("emailInput");
        emailInput->setStyleSheet(QString::fromUtf8("\n"
"               padding: 12px 15px;\n"
"               border: 2px solid #e2e8f0;\n"
"               border-radius: 10px;\n"
"               font-size: 16px;\n"
"               background-color: #f7fafc;\n"
"               font-family: 'Segoe UI', Arial, sans-serif;\n"
"               color: black;\n"
"              "));
        emailInput->setMinimumHeight(50);

        cardLayout->addWidget(emailInput);

        passwordInput = new QLineEdit(loginCard);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setEchoMode(QLineEdit::Password);
        passwordInput->setStyleSheet(QString::fromUtf8("\n"
"               padding: 12px 15px;\n"
"               border: 2px solid #e2e8f0;\n"
"               border-radius: 10px;\n"
"               font-size: 16px;\n"
"               background-color: #f7fafc;\n"
"               font-family: 'Segoe UI', Arial, sans-serif;\n"
"               color:black;\n"
"              "));
        passwordInput->setMinimumHeight(50);

        cardLayout->addWidget(passwordInput);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(15);
        buttonLayout->setObjectName("buttonLayout");
        loginButton = new QPushButton(loginCard);
        loginButton->setObjectName("loginButton");
        loginButton->setStyleSheet(QString::fromUtf8("\n"
"                 QPushButton {\n"
"                   background-color: #3182ce;\n"
"                   color: white;\n"
"                   padding: 12px;\n"
"                   border: none;\n"
"                   border-radius: 10px;\n"
"                   font-size: 16px;\n"
"                   font-weight: bold;\n"
"                   font-family: 'Segoe UI', Arial, sans-serif;\n"
"                 }\n"
"                 QPushButton:hover {\n"
"                   background-color: #2c5282;\n"
"                 }\n"
"                 QPushButton:pressed {\n"
"                   background-color: #1a365d;\n"
"                   padding-top: 13px;\n"
"                   padding-bottom: 11px;\n"
"                 }\n"
"                "));
        loginButton->setMinimumHeight(50);
        loginButton->setMinimumWidth(150);
        loginButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        buttonLayout->addWidget(loginButton);

        registerButton = new QPushButton(loginCard);
        registerButton->setObjectName("registerButton");
        registerButton->setStyleSheet(QString::fromUtf8("\n"
"                 QPushButton {\n"
"                   background-color: transparent;\n"
"                   color: #3182ce;\n"
"                   padding: 12px;\n"
"                   border: 2px solid #3182ce;\n"
"                   border-radius: 10px;\n"
"                   font-size: 16px;\n"
"                   font-weight: bold;\n"
"                   font-family: 'Segoe UI', Arial, sans-serif;\n"
"                 }\n"
"                 QPushButton:hover {\n"
"                   background-color: rgba(49, 130, 206, 0.1);\n"
"                   border-color: #2c5282;\n"
"                   color: #2c5282;\n"
"                 }\n"
"                 QPushButton:pressed {\n"
"                   background-color: rgba(49, 130, 206, 0.2);\n"
"                   padding-top: 13px;\n"
"                   padding-bottom: 11px;\n"
"                 }\n"
"                "));
        registerButton->setMinimumHeight(50);
        registerButton->setMinimumWidth(150);
        registerButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        buttonLayout->addWidget(registerButton);


        cardLayout->addLayout(buttonLayout);

        forgotPasswordLabel = new QLabel(loginCard);
        forgotPasswordLabel->setObjectName("forgotPasswordLabel");
        forgotPasswordLabel->setAlignment(Qt::AlignCenter);
        forgotPasswordLabel->setOpenExternalLinks(true);
        forgotPasswordLabel->setStyleSheet(QString::fromUtf8("\n"
"               font-size: 14px;\n"
"               margin-top: 5px;\n"
"               font-family: 'Segoe UI', Arial, sans-serif;\n"
"              "));

        cardLayout->addWidget(forgotPasswordLabel);


        centerContentLayout->addWidget(loginCard);


        horizontalLayout->addLayout(centerContentLayout);

        horizontalSpacerRight = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacerRight);


        mainLayout->addLayout(horizontalLayout);

        verticalSpacerBottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        mainLayout->addItem(verticalSpacerBottom);

        footerLabel = new QLabel(centralwidget);
        footerLabel->setObjectName("footerLabel");
        footerLabel->setAlignment(Qt::AlignCenter);
        footerLabel->setStyleSheet(QString::fromUtf8("\n"
"        font-size: 12px;\n"
"        color: rgba(226, 232, 240, 0.8);\n"
"        padding: 10px;\n"
"        font-family: 'Segoe UI', Arial, sans-serif;\n"
"       "));

        mainLayout->addWidget(footerLabel);

        LoginWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "IMS Secure Login", nullptr));
        titleLabel->setText(QCoreApplication::translate("LoginWindow", "Admin Access", nullptr));
        emailInput->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Enter your email", nullptr));
        passwordInput->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Enter your password", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "\360\237\224\220 Sign In", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginWindow", "Register Now", nullptr));
        forgotPasswordLabel->setText(QCoreApplication::translate("LoginWindow", "<a href=\"#\" style=\"text-decoration:none; color:#3182ce;\">Forgot password?</a>", nullptr));
        footerLabel->setText(QCoreApplication::translate("LoginWindow", "\302\251 2025 IMS. Secure Access Portal. v2.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
