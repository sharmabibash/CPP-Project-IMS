/********************************************************************************
** Form generated from reading UI file 'registrationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONWINDOW_H
#define UI_REGISTRATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QSpacerItem *topSpacer;
    QWidget *registrationCard;
    QVBoxLayout *formLayout;
    QLabel *titleLabel;
    QLineEdit *companyNameInput;
    QLineEdit *regNoInput;
    QLineEdit *emailInput;
    QLineEdit *mobileInput;
    QLineEdit *passwordInput;
    QLineEdit *confirmPasswordInput;
    QPushButton *registerButton;
    QSpacerItem *bottomSpacer;

    void setupUi(QMainWindow *RegistrationWindow)
    {
        if (RegistrationWindow->objectName().isEmpty())
            RegistrationWindow->setObjectName("RegistrationWindow");
        RegistrationWindow->resize(500, 650);
        RegistrationWindow->setMinimumSize(QSize(450, 600));
        RegistrationWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #5A67D8, stop:1 #2D3748);\n"
"    }\n"
"   "));
        centralwidget = new QWidget(RegistrationWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(20, 20, 20, 20);
        topSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        mainLayout->addItem(topSpacer);

        registrationCard = new QWidget(centralwidget);
        registrationCard->setObjectName("registrationCard");
        registrationCard->setMinimumSize(QSize(400, 550));
        registrationCard->setMaximumSize(QSize(450, 600));
        registrationCard->setStyleSheet(QString::fromUtf8("\n"
"        background-color: rgba(255, 255, 255, 0.98);\n"
"        border: 1px solid rgba(0, 0, 0, 0.08);\n"
"        border-radius: 12px;\n"
"        padding: 25px;\n"
"        box-shadow: 0 8px 16px rgba(0, 0, 0, 0.1);\n"
"       "));
        formLayout = new QVBoxLayout(registrationCard);
        formLayout->setSpacing(12);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        titleLabel = new QLabel(registrationCard);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet(QString::fromUtf8("\n"
"           font-size: 26px;\n"
"           font-weight: 700;\n"
"           color: #1A202C;\n"
"           padding-bottom: 20px;\n"
"           font-family: 'Inter', 'Segoe UI', Arial, sans-serif;\n"
"          "));

        formLayout->addWidget(titleLabel);

        companyNameInput = new QLineEdit(registrationCard);
        companyNameInput->setObjectName("companyNameInput");
        companyNameInput->setStyleSheet(QString::fromUtf8("\n"
"           padding: 12px 15px;\n"
"           border: 2px solid #E2E8F0;\n"
"           border-radius: 8px;\n"
"           font-size: 15px;\n"
"           background-color: #F8FAFC;\n"
"           font-family: 'Inter', 'Segoe UI', Arial, sans-serif;\n"
"           color: #2D3748;\n"
"           transition: border-color 0.2s;\n"
"          "));
        companyNameInput->setMinimumHeight(48);

        formLayout->addWidget(companyNameInput);

        regNoInput = new QLineEdit(registrationCard);
        regNoInput->setObjectName("regNoInput");
        regNoInput->setStyleSheet(QString::fromUtf8("\n"
"           padding: 12px 15px;\n"
"           border: 2px solid #E2E8F0;\n"
"           border-radius: 8px;\n"
"           font-size: 15px;\n"
"           background-color: #F8FAFC;\n"
"           font-family: 'Inter', 'Segoe UI', Arial, sans-serif;\n"
"           color: #2D3748;\n"
"           transition: border-color 0.2s;\n"
"          "));
        regNoInput->setMinimumHeight(48);

        formLayout->addWidget(regNoInput);

        emailInput = new QLineEdit(registrationCard);
        emailInput->setObjectName("emailInput");
        emailInput->setStyleSheet(QString::fromUtf8("\n"
"           padding: 12px 15px;\n"
"           border: 2px solid #E2E8F0;\n"
"           border-radius: 8px;\n"
"           font-size: 15px;\n"
"           background-color: #F8FAFC;\n"
"           font-family: 'Inter', 'Segoe UI', Arial, sans-serif;\n"
"           color: #2D3748;\n"
"           transition: border-color 0.2s;\n"
"          "));
        emailInput->setMinimumHeight(48);

        formLayout->addWidget(emailInput);

        mobileInput = new QLineEdit(registrationCard);
        mobileInput->setObjectName("mobileInput");
        mobileInput->setStyleSheet(QString::fromUtf8("\n"
"           padding: 12px 15px;\n"
"           border: 2px solid #E2E8F0;\n"
"           border-radius: 8px;\n"
"           font-size: 15px;\n"
"           background-color: #F8FAFC;\n"
"           font-family: 'Inter', 'Segoe UI', Arial, sans-serif;\n"
"           color: #2D3748;\n"
"           transition: border-color 0.2s;\n"
"          "));
        mobileInput->setMinimumHeight(48);

        formLayout->addWidget(mobileInput);

        passwordInput = new QLineEdit(registrationCard);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setEchoMode(QLineEdit::Password);
        passwordInput->setStyleSheet(QString::fromUtf8("\n"
"           padding: 12px 15px;\n"
"           border: 2px solid #E2E8F0;\n"
"           border-radius: 8px;\n"
"           font-size: 15px;\n"
"           background-color: #F8FAFC;\n"
"           font-family: 'Inter', 'Segoe UI', Arial, sans-serif;\n"
"           color: #2D3748;\n"
"           transition: border-color 0.2s;\n"
"          "));
        passwordInput->setMinimumHeight(48);

        formLayout->addWidget(passwordInput);

        confirmPasswordInput = new QLineEdit(registrationCard);
        confirmPasswordInput->setObjectName("confirmPasswordInput");
        confirmPasswordInput->setEchoMode(QLineEdit::Password);
        confirmPasswordInput->setStyleSheet(QString::fromUtf8("\n"
"           padding: 12px 15px;\n"
"           border: 2px solid #E2E8F0;\n"
"           border-radius: 8px;\n"
"           font-size: 15px;\n"
"           background-color: #F8FAFC;\n"
"           font-family: 'Inter', 'Segoe UI', Arial, sans-serif;\n"
"           color: #2D3748;\n"
"           transition: border-color 0.2s;\n"
"          "));
        confirmPasswordInput->setMinimumHeight(48);

        formLayout->addWidget(confirmPasswordInput);

        registerButton = new QPushButton(registrationCard);
        registerButton->setObjectName("registerButton");
        registerButton->setStyleSheet(QString::fromUtf8("\n"
"           QPushButton {\n"
"               background-color: #3182CE;\n"
"               width:50px;\n"
"               color: white;\n"
"               padding: 14px;\n"
"               border: none;\n"
"               border-radius: 8px;\n"
"               font-size: 16px;\n"
"               font-weight: 600;\n"
"               font-family: 'Inter', 'Segoe UI', Arial, sans-serif;\n"
"               transition: background-color 0.2s;\n"
"           }\n"
"           QPushButton:hover {\n"
"               background-color: #2B6CB0;\n"
"           }\n"
"           QPushButton:pressed {\n"
"               background-color: #2C5282;\n"
"               padding: 15px 14px 13px 14px;\n"
"           }\n"
"           QPushButton:disabled {\n"
"               background-color: #A0AEC0;\n"
"           }\n"
"          "));
        registerButton->setMinimumHeight(50);
        registerButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        formLayout->addWidget(registerButton);


        mainLayout->addWidget(registrationCard, 0, Qt::AlignHCenter);

        bottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        mainLayout->addItem(bottomSpacer);

        RegistrationWindow->setCentralWidget(centralwidget);

        retranslateUi(RegistrationWindow);

        QMetaObject::connectSlotsByName(RegistrationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RegistrationWindow)
    {
        RegistrationWindow->setWindowTitle(QCoreApplication::translate("RegistrationWindow", "KARRA NAMI ACCOUNT", nullptr));
        titleLabel->setText(QCoreApplication::translate("RegistrationWindow", "Create Your Account", nullptr));
        companyNameInput->setPlaceholderText(QCoreApplication::translate("RegistrationWindow", "Company Name", nullptr));
        regNoInput->setPlaceholderText(QCoreApplication::translate("RegistrationWindow", "Registration Number", nullptr));
        emailInput->setPlaceholderText(QCoreApplication::translate("RegistrationWindow", "Email Address", nullptr));
        mobileInput->setPlaceholderText(QCoreApplication::translate("RegistrationWindow", "Mobile Number", nullptr));
        passwordInput->setPlaceholderText(QCoreApplication::translate("RegistrationWindow", "Password", nullptr));
        confirmPasswordInput->setPlaceholderText(QCoreApplication::translate("RegistrationWindow", "Confirm Password", nullptr));
        registerButton->setText(QCoreApplication::translate("RegistrationWindow", "Create Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationWindow: public Ui_RegistrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWINDOW_H
