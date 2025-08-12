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

void DashboardWindow::writeProductsToFile(const QJsonArray &products)
{
    QString filePath = QDir(QCoreApplication::applicationDirPath()).filePath("../database/products.json");

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qWarning() << "Failed to open products.json for writing at:" << filePath;
        return;
    }
    QJsonDocument doc(products);
    file.write(doc.toJson());
    file.close();
}
