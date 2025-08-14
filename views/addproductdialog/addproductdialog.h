#ifndef ADDPRODUCTDIALOG_H
#define ADDPRODUCTDIALOG_H

#include <QDialog>

namespace Ui {
class AddProductDialog;
}

class AddProductDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddProductDialog(QWidget *parent = nullptr);
    ~AddProductDialog();

signals:
    void productAdded(const QString &name, const QString &category, int quantity, double price, const QString &description);

private slots:
    void onSaveClicked();

private:
    Ui::AddProductDialog *ui;

    int calculateNextProductId();  
};

#endif 
