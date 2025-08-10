/********************************************************************************
** Form generated from reading UI file 'AddProductDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPRODUCTDIALOG_H
#define UI_ADDPRODUCTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddProductDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QWidget *formWidget;
    QFormLayout *formLayout;
    QLabel *labelProductId;
    QLineEdit *productIdEdit;
    QLabel *labelName;
    QLineEdit *productNameEdit;
    QLabel *labelCategory;
    QComboBox *categoryComboBox;
    QLabel *labelQuantity;
    QSpinBox *quantitySpinBox;
    QLabel *labelPrice;
    QDoubleSpinBox *priceSpinBox;
    QLabel *labelDescription;
    QTextEdit *descriptionTextEdit;
    QWidget *buttonWidget;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AddProductDialog)
    {
        if (AddProductDialog->objectName().isEmpty())
            AddProductDialog->setObjectName("AddProductDialog");
        AddProductDialog->resize(420, 400);
        verticalLayout = new QVBoxLayout(AddProductDialog);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(AddProductDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet(QString::fromUtf8("\n"
"       font-size: 22px;\n"
"       font-weight: bold;\n"
"       padding: 12px;\n"
"       color: #eaeef1ff;\n"
"      "));

        verticalLayout->addWidget(titleLabel);

        formWidget = new QWidget(AddProductDialog);
        formWidget->setObjectName("formWidget");
        formLayout = new QFormLayout(formWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelProductId = new QLabel(formWidget);
        labelProductId->setObjectName("labelProductId");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelProductId);

        productIdEdit = new QLineEdit(formWidget);
        productIdEdit->setObjectName("productIdEdit");
        productIdEdit->setReadOnly(true);
        productIdEdit->setStyleSheet(QString::fromUtf8("\n"
"          background-color: #ecf0f1;\n"
"          color: #34495e;\n"
"          font-weight: bold;\n"
"          padding: 4px 6px;\n"
"          border: 1px solid #bdc3c7;\n"
"          border-radius: 4px;\n"
"         "));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, productIdEdit);

        labelName = new QLabel(formWidget);
        labelName->setObjectName("labelName");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelName);

        productNameEdit = new QLineEdit(formWidget);
        productNameEdit->setObjectName("productNameEdit");
        productNameEdit->setStyleSheet(QString::fromUtf8("\n"
"          padding: 4px 6px;\n"
"          border: 1px solid #bdc3c7;\n"
"          border-radius: 4px;\n"
"         "));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, productNameEdit);

        labelCategory = new QLabel(formWidget);
        labelCategory->setObjectName("labelCategory");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelCategory);

        categoryComboBox = new QComboBox(formWidget);
        categoryComboBox->addItem(QString());
        categoryComboBox->addItem(QString());
        categoryComboBox->addItem(QString());
        categoryComboBox->addItem(QString());
        categoryComboBox->setObjectName("categoryComboBox");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, categoryComboBox);

        labelQuantity = new QLabel(formWidget);
        labelQuantity->setObjectName("labelQuantity");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelQuantity);

        quantitySpinBox = new QSpinBox(formWidget);
        quantitySpinBox->setObjectName("quantitySpinBox");
        quantitySpinBox->setMinimum(0);
        quantitySpinBox->setMaximum(10000);
        quantitySpinBox->setStyleSheet(QString::fromUtf8("\n"
"          padding: 2px 6px;\n"
"         "));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, quantitySpinBox);

        labelPrice = new QLabel(formWidget);
        labelPrice->setObjectName("labelPrice");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, labelPrice);

        priceSpinBox = new QDoubleSpinBox(formWidget);
        priceSpinBox->setObjectName("priceSpinBox");
        priceSpinBox->setMinimum(0.000000000000000);
        priceSpinBox->setMaximum(1000000.000000000000000);
        priceSpinBox->setDecimals(2);
        priceSpinBox->setSingleStep(1.000000000000000);
        priceSpinBox->setStyleSheet(QString::fromUtf8("\n"
"          padding: 2px 6px;\n"
"         "));

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, priceSpinBox);

        labelDescription = new QLabel(formWidget);
        labelDescription->setObjectName("labelDescription");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, labelDescription);

        descriptionTextEdit = new QTextEdit(formWidget);
        descriptionTextEdit->setObjectName("descriptionTextEdit");
        descriptionTextEdit->setStyleSheet(QString::fromUtf8("\n"
"          border: 1px solid #bdc3c7;\n"
"          border-radius: 4px;\n"
"          padding: 6px;\n"
"          font-size: 14px;\n"
"         "));
        descriptionTextEdit->setMinimumHeight(80);

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, descriptionTextEdit);


        verticalLayout->addWidget(formWidget);

        buttonWidget = new QWidget(AddProductDialog);
        buttonWidget->setObjectName("buttonWidget");
        buttonLayout = new QHBoxLayout(buttonWidget);
        buttonLayout->setObjectName("buttonLayout");
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        saveButton = new QPushButton(buttonWidget);
        saveButton->setObjectName("saveButton");
        saveButton->setStyleSheet(QString::fromUtf8("\n"
"          background-color: #27ae60;\n"
"          color: white;\n"
"          padding: 10px 20px;\n"
"          border-radius: 8px;\n"
"          font-weight: bold;\n"
"          font-size: 16px;\n"
"         "));

        buttonLayout->addWidget(saveButton);

        cancelButton = new QPushButton(buttonWidget);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setStyleSheet(QString::fromUtf8("\n"
"          background-color: #c0392b;\n"
"          color: white;\n"
"          padding: 10px 20px;\n"
"          border-radius: 8px;\n"
"          font-weight: bold;\n"
"          font-size: 16px;\n"
"         "));

        buttonLayout->addWidget(cancelButton);


        verticalLayout->addWidget(buttonWidget);


        retranslateUi(AddProductDialog);

        QMetaObject::connectSlotsByName(AddProductDialog);
    } // setupUi

    void retranslateUi(QDialog *AddProductDialog)
    {
        AddProductDialog->setWindowTitle(QCoreApplication::translate("AddProductDialog", "Add Product", nullptr));
        titleLabel->setText(QCoreApplication::translate("AddProductDialog", "Add New Product", nullptr));
        labelProductId->setText(QCoreApplication::translate("AddProductDialog", "Product ID:", nullptr));
        labelName->setText(QCoreApplication::translate("AddProductDialog", "Product Name:", nullptr));
        labelCategory->setText(QCoreApplication::translate("AddProductDialog", "Category:", nullptr));
        categoryComboBox->setItemText(0, QCoreApplication::translate("AddProductDialog", "Electronics", nullptr));
        categoryComboBox->setItemText(1, QCoreApplication::translate("AddProductDialog", "Apparel", nullptr));
        categoryComboBox->setItemText(2, QCoreApplication::translate("AddProductDialog", "Groceries", nullptr));
        categoryComboBox->setItemText(3, QCoreApplication::translate("AddProductDialog", "Books", nullptr));

        labelQuantity->setText(QCoreApplication::translate("AddProductDialog", "Quantity:", nullptr));
        labelPrice->setText(QCoreApplication::translate("AddProductDialog", "Price:", nullptr));
        labelDescription->setText(QCoreApplication::translate("AddProductDialog", "Description:", nullptr));
        saveButton->setText(QCoreApplication::translate("AddProductDialog", "Save", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddProductDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddProductDialog: public Ui_AddProductDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPRODUCTDIALOG_H
