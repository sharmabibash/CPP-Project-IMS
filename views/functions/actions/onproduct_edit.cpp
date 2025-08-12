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

void DashboardWindow::onProductsEdit()
{
    QList<QTableWidgetSelectionRange> selectedRanges = ui->productsTable->selectedRanges();
    if (selectedRanges.isEmpty()) {
        QMessageBox::warning(this, "Edit Product", "Please select a product to edit.");
        return;
    }

    int row = selectedRanges.first().topRow();
    // Focus on first editable column (e.g. Name)
    ui->productsTable->editItem(ui->productsTable->item(row, 1));
}
