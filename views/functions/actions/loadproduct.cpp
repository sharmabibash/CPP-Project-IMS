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

    int totalQuantity = 0; 
    int row = 0;
    
    for (const auto &prodVal : products) {
        QJsonObject product = prodVal.toObject();
        ui->productsTable->insertRow(row);
   
        ui->productsTable->setItem(row, 0, new QTableWidgetItem(QString::number(product["id"].toInt())));
        ui->productsTable->setItem(row, 1, new QTableWidgetItem(product["name"].toString()));
        ui->productsTable->setItem(row, 2, new QTableWidgetItem(product["description"].toString()));
        ui->productsTable->setItem(row, 3, new QTableWidgetItem(QString::number(product["price"].toDouble(), 'f', 2)));

        int quantity = product["quantity"].toInt();
        totalQuantity += quantity; 
        
        QTableWidgetItem *qtyItem = new QTableWidgetItem();
        qtyItem->setData(Qt::DisplayRole, quantity); 
        ui->productsTable->setItem(row, 4, qtyItem);
        
        row++;
    }
    ui->card1Value->setText(QString::number(totalQuantity));
}