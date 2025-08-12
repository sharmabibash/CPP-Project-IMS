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

QJsonArray DashboardWindow::readProductsFromFile()
{
    QString filePath = QDir(QCoreApplication::applicationDirPath()).filePath("../database/products.json");

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open products.json for reading at:" << filePath;
        return QJsonArray();
    }
    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) {
        qWarning() << "products.json is not a JSON array";
        return QJsonArray();
    }

    return doc.array();
}
