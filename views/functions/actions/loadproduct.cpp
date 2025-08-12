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
void DashboardWindow::loadProductsToTable()
{
    QJsonArray products = readProductsFromFile();
    ui->productsTable->setRowCount(0);

    int row = 0;
    for (const auto &prodVal : products) {
        QJsonObject product = prodVal.toObject();
        ui->productsTable->insertRow(row);
        
        // ID column (0)
        ui->productsTable->setItem(row, 0, new QTableWidgetItem(QString::number(product["id"].toInt())));
        
        // Name column (1)
        ui->productsTable->setItem(row, 1, new QTableWidgetItem(product["name"].toString()));
        
        // Description column (2)
        ui->productsTable->setItem(row, 2, new QTableWidgetItem(product["description"].toString()));
        
        // Price column (3)
        ui->productsTable->setItem(row, 3, new QTableWidgetItem(QString::number(product["price"].toDouble(), 'f', 2)));
        
        // Quantity column (4) - with validation
        int quantity = product["quantity"].toInt(); // Force integer conversion
        QTableWidgetItem *qtyItem = new QTableWidgetItem();
        qtyItem->setData(Qt::DisplayRole, quantity); // Store as integer
        ui->productsTable->setItem(row, 4, qtyItem);
        
        row++;
    }
    
    // Update the overview with total products count
    ui->card1Value->setText(QString::number(products.size()));
}