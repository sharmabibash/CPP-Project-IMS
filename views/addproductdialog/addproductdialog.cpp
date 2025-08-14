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
    ui->productIdEdit->setReadOnly(true);
    connect(ui->saveButton, &QPushButton::clicked, this, &AddProductDialog::onSaveClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &AddProductDialog::reject);
    int nextId = calculateNextProductId();
    ui->productIdEdit->setText(QString::number(nextId));
}

AddProductDialog::~AddProductDialog()
{
    delete ui;
}

int AddProductDialog::calculateNextProductId()
{
    QString dirPath = QDir::currentPath() + "/../database";
    QString filePath = dirPath + "/products.json";

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        
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
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a product name.");
        return;
    }

    if (price <= 0.0) {
        QMessageBox::warning(this, "Input Error", "Price must be greater than 0.");
        return;
    }
    emit productAdded(name, category, quantity, price, description);
    QMessageBox::information(this, "Success", "Product added successfully!");
    ui->productNameEdit->clear();
    ui->categoryComboBox->setCurrentIndex(0);
    ui->quantitySpinBox->setValue(1);
    ui->priceSpinBox->setValue(0.01);
    ui->descriptionTextEdit->clear();
    int nextId = calculateNextProductId();
    ui->productIdEdit->setText(QString::number(nextId));
}
