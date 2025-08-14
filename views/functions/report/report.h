#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
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
#include <QInputDialog>
#include <QCoreApplication>
#include <QAbstractItemView>
#include "../functions/transactions/load_transactions.cpp"
void DashboardWindow::onGenerateInvoiceClicked()
{
    bool ok;
    QString customerName = QInputDialog::getText(this, "Customer Name",
                                               "Enter Customer Name:", QLineEdit::Normal,
                                               "", &ok);
    if (!ok || customerName.isEmpty()) return;
    QString mobileNo = QInputDialog::getText(this, "Mobile Number",
                                           "Enter Mobile Number:", QLineEdit::Normal,
                                           "", &ok);
    if (!ok || mobileNo.isEmpty()) return;
    QJsonArray transactions = readTransactionsFromFile();
    QJsonArray customerTransactions;
    double grandTotal = 0.0;
    for (const auto &t : transactions) {
        if (!t.isObject()) continue;
        QJsonObject obj = t.toObject();

        if (obj.value("customerName").toString().toLower() == customerName.toLower() &&
            obj.value("mobileNo").toString() == mobileNo)
        {
            customerTransactions.append(obj);
            grandTotal += obj.value("totalPrice").toDouble();
        }
    }

    if (customerTransactions.isEmpty()) {
        QMessageBox::information(this, "No Transactions", 
                               QString("No transactions found for customer '%1' with mobile '%2'")
                               .arg(customerName).arg(mobileNo));
        return;
    }
    QList<QJsonObject> transactionList;
    for (const auto &t : customerTransactions) {
        transactionList.append(t.toObject());
    }
    std::sort(transactionList.begin(), transactionList.end(), 
        [](const QJsonObject &a, const QJsonObject &b) {
            QDateTime dateA = QDateTime::fromString(a.value("date").toString(), Qt::ISODate);
            QDateTime dateB = QDateTime::fromString(b.value("date").toString(), Qt::ISODate);
            return dateA > dateB;
        });
    QString fileName = QFileDialog::getSaveFileName(this, "Save Invoice PDF",
                                                  QCoreApplication::applicationDirPath() + "/../database/" + 
                                                  customerName + "_" + QDate::currentDate().toString("yyyyMMdd") + ".pdf",
                                                  "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15), QPageLayout::Millimeter);
    QTextDocument doc;
    QString html = R"(
    <html>
    <head>
    <style>
        body { font-family: Arial, sans-serif; margin: 0; padding: 0; color: #333; }
        .invoice-container { max-width: 800px; margin: 0 auto; padding: 20px; }
        .header { display: flex; justify-content: space-between; margin-bottom: 20px; }
        .company-info { text-align: left; }
        .invoice-title { text-align: center; margin: 20px 0; }
        .customer-info { margin-bottom: 20px; background: #f5f5f5; padding: 15px; border-radius: 5px; }
        .invoice-table { width: 100%; border-collapse: collapse; margin-bottom: 20px; }
        .invoice-table th { background: #2c3e50; color: white; padding: 10px; text-align: left; }
        .invoice-table td { padding: 10px; border-bottom: 1px solid #ddd; }
        .invoice-table tr:nth-child(even) { background: #f9f9f9; }
        .total-row { font-weight: bold; background: #ecf0f1 !important; }
        .footer { margin-top: 30px; text-align: center; font-size: 0.9em; color: #777; }
    </style>
    </head>
    <body>
    <div class="invoice-container">
    )";
    html += R"(
    <div class="header">
        <div class="company-info">
            <h2 style="color: #2c3e50; margin-bottom: 5px;">)" + companyName + R"(</h2>
            <p>)" + userEmail + R"(<br>
            Registration Number : )" + mobile + R"(<br>
            Company Mobile Number : )" + regNo + R"(</p>
        </div>
        <div style="text-align: right;">
            <h2 style="color: #2c3e50; margin-bottom: 5px;">INVOICE</h2>
            <p>Date: )" + QDate::currentDate().toString("yyyy-MM-dd") + R"(<br>
            Invoice #: INV-)" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + R"(</p>
        </div>
    </div>
    )";
    html += R"(
    <div class="customer-info">
        <h3 style="margin-top: 0; margin-bottom: 10px;">Bill To:</h3>
        <p style="margin: 5px 0;"><strong>Name:</strong> )" + customerName + R"(</p>
        <p style="margin: 5px 0;"><strong>Mobile:</strong> )" + mobileNo + R"(</p>
    </div>
    )";
    html += R"(
    <table class="invoice-table">
        <thead>
            <tr>
                <th>Date & Time</th>
                <th>Product</th>
                <th>Price</th>
                <th>Qty</th>
                <th>Total</th>
            </tr>
        </thead>
        <tbody>
    )";

    for (const auto &obj : transactionList) {
        QDateTime transactionDateTime = QDateTime::fromString(obj.value("date").toString(), Qt::ISODate);
        
        html += R"(
            <tr>
                <td>)" + transactionDateTime.toString("yyyy-MM-dd hh:mm:ss") + R"(</td>
                <td>)" + obj.value("productName").toString() + R"(</td>
                <td>)" + QString::number(obj.value("price").toDouble(), 'f', 2) + R"(</td>
                <td>)" + QString::number(obj.value("quantity").toInt()) + R"(</td>
                <td>)" + QString::number(obj.value("totalPrice").toDouble(), 'f', 2) + R"(</td>
            </tr>
        )";
    }
    html += R"(
            <tr class="total-row">
                <td colspan="4" style="text-align: right;">Grand Total:</td>
                <td>)" + QString::number(grandTotal, 'f', 2) + R"(</td>
            </tr>
        </tbody>
    </table>
    )";
    html += R"(
    <div class="footer">
        <p>Thank you for your business!</p>
        <p>)" + companyName + R"( | )" + userEmail + R"( | )" + mobile + R"(</p>
    </div>
    </div>
    </body>
    </html>
    )";

    doc.setHtml(html);
    doc.setPageSize(printer.pageRect(QPrinter::Point).size());
    doc.print(&printer);

    QMessageBox::information(this, "Invoice Generated", "Invoice saved to: " + fileName);
}
void DashboardWindow::onExportTodaySalesClicked()
{
    QString filePath = QCoreApplication::applicationDirPath() + "/../database/todays_sales.csv";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Export Failed", "Could not open file to write");
        return;
    }

    QTextStream out(&file);
    out << "Time,Customer,Mobile,Price,Product ID,Product,Quantity,Total Price\n";

    QJsonArray transactions = readTransactionsFromFile();
    QDate today = QDate::currentDate();
    double grandTotal = 0.0;

    for (const auto &t : transactions)
    {
        if (!t.isObject())
            continue;
        QJsonObject obj = t.toObject();

        QString dateStr = obj.value("date").toString();
        QDateTime dt = QDateTime::fromString(dateStr, Qt::ISODate);
        if (!dt.isValid())
            continue;

        if (dt.date() == today)
        {
            QString customerName = obj.value("customerName").toString();
            QString mobile = obj.value("mobileNo").toString();
            double price = obj.value("price").toDouble();
            int productId = obj.value("productId").toInt();
            QString productName = obj.value("productName").toString();
            int quantity = obj.value("quantity").toInt();
            double totalPrice = obj.value("totalPrice").toDouble();

            grandTotal += totalPrice;

            out << dt.toString("yyyy-MM-dd hh:mm:ss") << ","
                << customerName << ","
                << mobile << ","
                << price << ","
                << productId << ","
                << productName << ","
                << quantity << ","
                << totalPrice << "\n";
        }
    }
    out << ",,,,,,,Grand Total," << grandTotal << "\n";

    file.close();
    QMessageBox::information(this, "Export Success", "Today's sales exported to " + filePath);
}

void DashboardWindow::onExportStockCsv()
{
    QString filePath = QCoreApplication::applicationDirPath() + "/../database/stock.csv";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Export Failed", "Could not open file to write");
        return;
    }

    QTextStream out(&file);
    out << "ID,Name,Category,Description,Price,Quantity\n";

    QJsonArray products = readProductsFromFile();

    for (const auto &p : products)
    {
        QJsonObject obj = p.toObject();
        out << obj["id"].toInt() << ","
            << obj["name"].toString() << ","
            << obj["category"].toString() << ","
            << obj["description"].toString() << ","
            << obj["price"].toDouble() << ","
            << obj["quantity"].toInt() << "\n";
    }

    file.close();
    QMessageBox::information(this, "Export Success", "Stock exported to " + filePath);
}

void DashboardWindow::onExportTransactionsCsv()
{
    QString filePath = QCoreApplication::applicationDirPath() + "/../database/transactions.csv";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Export Failed", "Could not open file to write");
        return;
    }

    QTextStream out(&file);
    out << "Customer Name,Date,Mobile No,Price,Product ID,Product Name,Quantity,Total Price\n";

    QJsonArray transactions = readTransactionsFromFile();
    double grandTotal = 0.0;

    for (const QJsonValue &value : transactions)
    {
        if (!value.isObject())
            continue;
        QJsonObject obj = value.toObject();

        QString customerName = obj.value("customerName").toString();
        QString dateStr = obj.value("date").toString();
        QString mobileNo = obj.value("mobileNo").toString();
        double price = obj.value("price").toDouble();
        int productId = obj.value("productId").toInt();
        QString productName = obj.value("productName").toString();
        int quantity = obj.value("quantity").toInt();
        double totalPrice = obj.value("totalPrice").toDouble();

        grandTotal += totalPrice;

        out << customerName << ","
            << dateStr << ","
            << mobileNo << ","
            << price << ","
            << productId << ","
            << productName << ","
            << quantity << ","
            << totalPrice << "\n";
    }

    out << ",,,,,,,Grand Total," << grandTotal << "\n";

    file.close();
    QMessageBox::information(this, "Export Success", "Transactions exported to " + filePath);
}

void DashboardWindow::loadTodaySalesToTable()
{
    ui->todaySalesTable->setRowCount(0); 
    QJsonArray transactions = readTransactionsFromFile();
    QDate today = QDate::currentDate();
    int row = 0;
    double grandTotal = 0.0;

    for (const QJsonValue &t : transactions)
    {
        if (!t.isObject())
            continue;
        QJsonObject obj = t.toObject();

        QString dateStr = obj.value("date").toString();
        QDateTime dt = QDateTime::fromString(dateStr, Qt::ISODate);
        if (!dt.isValid())
            continue;
        if (dt.date() == today)
        {
            ui->todaySalesTable->insertRow(row);
            ui->todaySalesTable->setItem(row, 0, new QTableWidgetItem(dt.toString("yyyy-MM-dd hh:mm:ss")));
            ui->todaySalesTable->setItem(row, 1, new QTableWidgetItem(obj.value("customerName").toString()));
            ui->todaySalesTable->setItem(row, 2, new QTableWidgetItem(obj.value("mobileNo").toString()));
            ui->todaySalesTable->setItem(row, 3, new QTableWidgetItem(QString::number(obj.value("price").toDouble())));
            ui->todaySalesTable->setItem(row, 4, new QTableWidgetItem(QString::number(obj.value("productId").toInt())));
            ui->todaySalesTable->setItem(row, 5, new QTableWidgetItem(obj.value("productName").toString()));
            ui->todaySalesTable->setItem(row, 6, new QTableWidgetItem(QString::number(obj.value("quantity").toInt())));
            ui->todaySalesTable->setItem(row, 7, new QTableWidgetItem(QString::number(obj.value("totalPrice").toDouble())));

            grandTotal += obj.value("totalPrice").toDouble();
            row++;
        }
    }
    if (row > 0)
    {
        ui->todaySalesTable->insertRow(row);
        ui->todaySalesTable->setItem(row, 6, new QTableWidgetItem("Grand Total"));
        ui->todaySalesTable->setItem(row, 7, new QTableWidgetItem(QString::number(grandTotal)));
    }
}
