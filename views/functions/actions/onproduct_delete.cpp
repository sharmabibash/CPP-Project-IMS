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

void DashboardWindow::onProductsDelete()
{
    QList<QTableWidgetSelectionRange> selectedRanges = ui->productsTable->selectedRanges();
    if (selectedRanges.isEmpty()) {
        QMessageBox::warning(this, "Delete Product", "Please select a product to delete.");
        return;
    }

    int row = selectedRanges.first().topRow();
    int id = ui->productsTable->item(row, 0)->text().toInt();

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Delete Product",
        QString("Are you sure you want to delete product with ID %1?").arg(id),
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QJsonArray products = readProductsFromFile();
        QJsonArray updatedProducts;

        for (const auto &prodVal : products) {
            QJsonObject product = prodVal.toObject();
            if (product["id"].toInt() != id) {
                updatedProducts.append(product);
            }
        }

        writeProductsToFile(updatedProducts);
        loadProductsToTable();
    }
}