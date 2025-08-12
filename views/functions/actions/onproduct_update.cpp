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

    int id = ui->productsTable->item(row, 0)->text().toInt();

    for (int i = 0; i < products.size(); ++i) {
        QJsonObject product = products[i].toObject();
        if (product["id"].toInt() == id) {
            // Update based on column edited:
            bool ok;
            switch (column) {
                case 1: // Name
                    product["name"] = ui->productsTable->item(row, column)->text();
                    break;
                case 2: // Category
                    product["category"] = ui->productsTable->item(row, column)->text();
                    break;
                case 3: // Quantity
                    product["quantity"] = ui->productsTable->item(row, column)->text().toInt(&ok);
                    if (!ok) {
                        QMessageBox::warning(this, "Invalid Input", "Quantity must be an integer.");
                        loadProductsToTable(); // revert
                        return;
                    }
                    break;
                case 4: // Price
                    product["price"] = ui->productsTable->item(row, column)->text().toDouble(&ok);
                    if (!ok) {
                        QMessageBox::warning(this, "Invalid Input", "Price must be a number.");
                        loadProductsToTable(); // revert
                        return;
                    }
                    break;
                case 5: // Description
                    product["description"] = ui->productsTable->item(row, column)->text();
                    break;
                default:
                    break;
            }
            products[i] = product;
            writeProductsToFile(products);
            //qDebug() << "Product updated in JSON file.";
            return;
        }
    }
}