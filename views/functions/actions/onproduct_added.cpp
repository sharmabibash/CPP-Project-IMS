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

void DashboardWindow::openAddProductDialog()
{
    addProductDialog->exec();
}

void DashboardWindow::onProductAdded(const QString &name, const QString &category, int quantity, double price, const QString &description)
{
    qDebug() << "Product added:" << name << category << quantity << price << description;

    QJsonArray products = readProductsFromFile();

    int newId = 1;
    if (!products.isEmpty()) {
        QJsonObject lastProduct = products.last().toObject();
        newId = lastProduct["id"].toInt() + 1;
    }

    QJsonObject newProduct;
    newProduct["id"] = newId;
    newProduct["name"] = name;
    newProduct["category"] = category;
    newProduct["quantity"] = quantity;
    newProduct["price"] = price;
    newProduct["description"] = description;

    products.append(newProduct);

    writeProductsToFile(products);
    loadProductsToTable();
}