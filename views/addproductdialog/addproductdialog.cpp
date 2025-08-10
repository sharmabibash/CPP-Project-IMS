#include "AddProductDialog.h"
#include "ui_AddProductDialog.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>
#include <QMessageBox>

AddProductDialog::AddProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProductDialog)
{
    ui->setupUi(this);

    // Make productIdEdit read-only (assuming you added this QLineEdit in UI)
    ui->productIdEdit->setReadOnly(true);

    // Connect buttons to slots
    connect(ui->saveButton, &QPushButton::clicked, this, &AddProductDialog::onSaveClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &AddProductDialog::reject);

    // Set initial product ID
    int nextId = calculateNextProductId();
    ui->productIdEdit->setText(QString::number(nextId));
}

AddProductDialog::~AddProductDialog()
{
    delete ui;
}

// Helper function to get the next product ID
int AddProductDialog::calculateNextProductId()
{
    QString dirPath = QDir::currentPath() + "/../database";
    QString filePath = dirPath + "/products.json";

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        // File doesn't exist or can't open, so start from 1
        return 1;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) {
        return 1;
    }

    QJsonArray productsArray = doc.array();

    int maxId = 0;
    for (const QJsonValue &val : productsArray) {
        if (val.isObject()) {
            QJsonObject obj = val.toObject();
            if (obj.contains("id") && obj["id"].isDouble()) {
                int id = obj["id"].toInt();
                if (id > maxId) maxId = id;
            }
        }
    }

    return maxId + 1;
}

void AddProductDialog::onSaveClicked()
{
    QString name = ui->productNameEdit->text().trimmed();
    QString category = ui->categoryComboBox->currentText();
    int quantity = ui->quantitySpinBox->value();
    double price = ui->priceSpinBox->value();
    QString description = ui->descriptionTextEdit->toPlainText().trimmed();

    // Basic validation
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a product name.");
        return;
    }

    if (price <= 0.0) {
        QMessageBox::warning(this, "Input Error", "Price must be greater than 0.");
        return;
    }

    // Get current product ID from UI
    int newId = ui->productIdEdit->text().toInt();

    // Ensure database directory exists
    QString dirPath = QDir::currentPath() + "/../database";
    QDir dir(dirPath);
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    QString filePath = dirPath + "/products.json";

    // Read existing JSON array
    QJsonArray productsArray;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (doc.isArray()) {
            productsArray = doc.array();
        }
    }

    // Prepare JSON object for new product
    QJsonObject newProduct;
    newProduct["id"] = newId;
    newProduct["name"] = name;
    newProduct["category"] = category;
    newProduct["quantity"] = quantity;
    newProduct["price"] = price;
    newProduct["description"] = description;

    // Append new product
    productsArray.append(newProduct);

    // Write back to file
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QMessageBox::critical(this, "File Error", "Unable to open file for writing.");
        return;
    }

    QJsonDocument saveDoc(productsArray);
    file.write(saveDoc.toJson());
    file.close();

    emit productAdded(name, category, quantity, price, description);

    // Show success message
    QMessageBox::information(this, "Success", "Product added successfully!");

    // Clear input fields for next entry (except productId)
    ui->productNameEdit->clear();
    ui->categoryComboBox->setCurrentIndex(0);
    ui->quantitySpinBox->setValue(1);
    ui->priceSpinBox->setValue(0.01);
    ui->descriptionTextEdit->clear();

    // Update product ID to next value
    ui->productIdEdit->setText(QString::number(newId + 1));

    // Keep dialog open for more entries
}
