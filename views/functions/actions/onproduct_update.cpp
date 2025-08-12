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

void DashboardWindow::onProductsUpdate(int row, int column)
{
    if (row < 0 || column < 0) return;

    QJsonArray products = readProductsFromFile();
    QTableWidgetItem* editedItem = ui->productsTable->item(row, column);

    if (!editedItem) {
        qWarning() << "Invalid item at row" << row << "column" << column;
        return;
    }

    int id = ui->productsTable->item(row, 0)->text().toInt();
    bool conversionOk = false;
    QString errorMessage;

    for (int i = 0; i < products.size(); ++i) {
        QJsonObject product = products[i].toObject();
        if (product["id"].toInt() == id) {
            QString newValue = editedItem->text();

            switch (column) {
                case 1: // Name
                    if (newValue.isEmpty()) {
                        errorMessage = "Name cannot be empty";
                        break;
                    }
                    product["name"] = newValue;
                    break;

                case 2: // Description
                    product["description"] = newValue;
                    break;

                case 3: // Price
                {
                    double price = newValue.toDouble(&conversionOk);
                    if (!conversionOk || price < 0) {
                        errorMessage = "Price must be a positive number";
                        break;
                    }
                    product["price"] = price;
                    break;
                }

                case 4: // Quantity
                {
                    int quantity = newValue.toInt(&conversionOk);
                    if (!conversionOk || quantity < 0) {
                        errorMessage = "Quantity must be a positive integer";
                        break;
                    }
                    product["quantity"] = quantity;
                    break;
                }

                default:
                    qWarning() << "Unhandled column update:" << column;
                    return;
            }

            if (!errorMessage.isEmpty()) {
                QMessageBox::warning(this, "Invalid Input", errorMessage);
                loadProductsToTable(); // Revert changes
                return;
            }

            products[i] = product;
            writeProductsToFile(products);

            return;
        }
    }

    qWarning() << "Product with ID" << id << "not found";
}
