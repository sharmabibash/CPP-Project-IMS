#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>

class AddProductDialog;  // Forward declaration

namespace Ui {
class DashboardWindow;
}

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashboardWindow(const QString &email = "", 
                             const QString &companyName = "", 
                             const QString &mobile = "", 
                             const QString &regNo = "",
                             QWidget *parent = nullptr);
    ~DashboardWindow();

private slots:
    void handleLogin();
    void openAddProductDialog();
    void onProductAdded(const QString &name, const QString &category, int quantity, double price, const QString &description);

private:
    Ui::DashboardWindow *ui;
    QString userEmail;
    QString companyName;
    QString mobile;
    QString regNo;

    AddProductDialog *addProductDialog;
};

#endif // DASHBOARDWINDOW_H
