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

void DashboardWindow::onProductsSearch()
{
    QString term = ui->productsSearch->text().trimmed().toLower();
    qDebug() << "Search products for:" << term;

    QJsonArray products = readProductsFromFile();

    ui->productsTable->setRowCount(0);

    int row = 0;
    for (const auto &prodVal : products) {
        QJsonObject product = prodVal.toObject();
        QString name = product["name"].toString().toLower();
        QString description = product["description"].toString().toLower();

        if (term.isEmpty() || name.contains(term) || description.contains(term)) {
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
}