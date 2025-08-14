#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
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

void DashboardWindow::loadTransactionsToTable()
{
    QJsonArray transactions = readTransactionsFromFile();

    ui->transactionsTable->clearContents();
    ui->transactionsTable->setRowCount(transactions.size());

    for (int i = 0; i < transactions.size(); ++i) {
        QJsonObject transaction = transactions[i].toObject();

        QString date = transaction["date"].toString("-");
        QString customerName = transaction["customerName"].toString("-");
        QString mobileNo = transaction["mobileNo"].toString("-");
        int productId = transaction["productId"].toInt(-1);
        QString productName = transaction["productName"].toString("-");
        int quantity = transaction["quantity"].toInt(0);
        double price = transaction["price"].toDouble(0.0);
        double totalPrice = transaction["totalPrice"].toDouble(0.0);
        QTableWidgetItem *itemDate = new QTableWidgetItem(date);
        QTableWidgetItem *itemCustomerName = new QTableWidgetItem(customerName);
        QTableWidgetItem *itemMobileNo = new QTableWidgetItem(mobileNo);
        QTableWidgetItem *itemProductId = new QTableWidgetItem(QString::number(productId));
        QTableWidgetItem *itemProductName = new QTableWidgetItem(productName);
        QTableWidgetItem *itemQuantity = new QTableWidgetItem(QString::number(quantity));
        QTableWidgetItem *itemPrice = new QTableWidgetItem(QString::number(price, 'f', 2));
        QTableWidgetItem *itemTotalPrice = new QTableWidgetItem(QString::number(totalPrice, 'f', 2));
        QList<QTableWidgetItem*> items = {
            itemDate, itemCustomerName, itemMobileNo, itemProductId,
            itemProductName, itemQuantity, itemPrice, itemTotalPrice
        };
        for (auto &item : items) {
            item->setTextAlignment(Qt::AlignCenter);
            item->setForeground(QBrush(QColor(Qt::white)));
        }
        ui->transactionsTable->setItem(i, 0, itemDate);
        ui->transactionsTable->setItem(i, 1, itemCustomerName);
        ui->transactionsTable->setItem(i, 2, itemMobileNo);
        ui->transactionsTable->setItem(i, 3, itemProductId);
        ui->transactionsTable->setItem(i, 4, itemProductName);
        ui->transactionsTable->setItem(i, 5, itemQuantity);
        ui->transactionsTable->setItem(i, 6, itemPrice);
        ui->transactionsTable->setItem(i, 7, itemTotalPrice);
    }
}

QJsonArray DashboardWindow::readTransactionsFromFile() const {
    QFile file(getTransactionsFilePath());
    if (!file.open(QIODevice::ReadOnly)) {
        return QJsonArray();
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    return doc.isArray() ? doc.array() : QJsonArray();
}

void DashboardWindow::processCheckout(const QString &customerName, const QString &mobileNo,
                                    const QString &productName, int quantity, double totalPrice) {
    QJsonArray transactions = readTransactionsFromFile();
    QJsonArray products = readProductsFromFile();
    int productId = -1;
    double price = 0.0;
    for (const auto &productVal : products) {
        QJsonObject product = productVal.toObject();
        if (product["name"].toString() == productName) {
            productId = product["id"].toInt();
            price = product["price"].toDouble();
            break;
        }
    }

    if (productId == -1) {
        QMessageBox::warning(this, "Error", "Product not found");
        return;
    }
    QJsonObject transaction;
    transaction["date"] = QDateTime::currentDateTime().toString(Qt::ISODate);
    transaction["customerName"] = customerName;
    transaction["mobileNo"] = mobileNo;
    transaction["productId"] = productId;
    transaction["productName"] = productName;
    transaction["quantity"] = quantity;
    transaction["price"] = price;
    transaction["totalPrice"] = totalPrice;

    transactions.append(transaction);
    saveTransactionsToFile(transactions);
    loadTransactionsToTable();
}

void DashboardWindow::saveTransactionsToFile(const QJsonArray &transactions) {
    QFile file(getTransactionsFilePath());
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Error", "Could not save transactions file");
        return;
    }

    file.write(QJsonDocument(transactions).toJson());
    file.close();
}

QString DashboardWindow::getTransactionsFilePath() const {
    QDir dataDir(QCoreApplication::applicationDirPath());
    return dataDir.filePath("../database/transactions.json");
}

void DashboardWindow::onConfirmCheckoutClicked() {
    QString customerName = ui->customerNameInput->text().trimmed();
    QString mobileNo = ui->mobileNoInput->text().trimmed();
    QString productName = ui->checkoutProductNameInput->text().trimmed();
    QString quantityStr = ui->checkoutQuantityInput->text().trimmed();

    // Validation
    if (customerName.isEmpty() || mobileNo.isEmpty() || productName.isEmpty() || quantityStr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill all fields");
        return;
    }

    bool ok;
    int quantity = quantityStr.toInt(&ok);
    if (!ok || quantity <= 0) {
        QMessageBox::warning(this, "Error", "Invalid quantity");
        return;
    }

    // Find product and price
    QJsonArray products = readProductsFromFile();
    for (int i = 0; i < products.size(); ++i) {
        QJsonObject product = products[i].toObject();
        if (product["name"].toString() == productName) {
            int currentQty = product["quantity"].toInt();
            if (currentQty < quantity) {
                QMessageBox::warning(this, "Error", "Not enough stock available");
                return;
            }

            double price = product["price"].toDouble();
            double totalPrice = price * quantity;

            // Show confirmation dialog
            QString confirmMsg = QString("Confirm Purchase:\n\nProduct: %1\nTotal Price: NPR %2")
                                     .arg(productName)
                                     .arg(QString::number(totalPrice, 'f', 2));
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Confirm Checkout", confirmMsg,
                                          QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::No) {
                // User canceled
                return;
            }

            // User confirmed, process checkout
            processCheckout(customerName, mobileNo, productName, quantity, totalPrice);

            // Update product quantity
            int newQty = currentQty - quantity;
            if (newQty <= 0) {
                products.removeAt(i);
            } else {
                product["quantity"] = newQty;
                products[i] = product;
            }
            writeProductsToFile(products);
            loadProductsToTable();

            // Clear form
            ui->customerNameInput->clear();
            ui->mobileNoInput->clear();
            ui->checkoutProductNameInput->clear();
            ui->checkoutQuantityInput->clear();
            ui->checkoutTotalPriceInput->clear();

            QMessageBox::information(this, "Success", "Transaction completed");
            return;
        }
    }
    QMessageBox::warning(this, "Error", "Product not found in inventory");
}

// In DashboardWindow constructor
void DashboardWindow::onSearchProductClicked() {
    QString searchTerm = ui->searchProduct->text().trimmed();
    if (searchTerm.isEmpty()) return;

    bool ok;
    int searchId = searchTerm.toInt(&ok);

    QJsonArray products = readProductsFromFile();

    for (const auto &productVal : products) {
        QJsonObject product = productVal.toObject();
        QString productName = product["name"].toString();
        int productId = product["id"].toInt();

        if ((ok && productId == searchId) || productName.contains(searchTerm, Qt::CaseInsensitive)) {
            ui->checkoutProductNameInput->setText(productName);
            ui->checkoutQuantityInput->setText("1");
            ui->checkoutTotalPriceInput->setText(QString::number(product["price"].toDouble(), 'f', 2));
            return;
        }
    }
    QMessageBox::information(this, "Not Found", "Product not found");
}

void DashboardWindow::onSellProductClicked() {
    ui->customerNameInput->clear();
    ui->mobileNoInput->clear();
    ui->checkoutProductNameInput->clear();
    ui->checkoutQuantityInput->clear();
    ui->checkoutTotalPriceInput->clear();
    ui->searchProduct->setFocus();
}