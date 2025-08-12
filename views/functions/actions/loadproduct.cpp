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
        ui->productsTable->setItem(row, 0, new QTableWidgetItem(QString::number(product["id"].toInt())));
        ui->productsTable->setItem(row, 1, new QTableWidgetItem(product["name"].toString()));
        ui->productsTable->setItem(row, 2, new QTableWidgetItem(product["category"].toString()));
        ui->productsTable->setItem(row, 3, new QTableWidgetItem(QString::number(product["quantity"].toInt())));
        ui->productsTable->setItem(row, 4, new QTableWidgetItem(QString::number(product["price"].toDouble(), 'f', 2)));
        ui->productsTable->setItem(row, 5, new QTableWidgetItem(product["description"].toString()));
        row++;
    }
}