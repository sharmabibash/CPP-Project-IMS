#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>
#include <QJsonArray>
#include <QDateTime>

namespace Ui {
class DashboardWindow;
}

class AddProductDialog;

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

    void showOverviewPage();
    void showProductsPage();
    void showTransactionsPage();
    void showUsersPage();
    void showReportsPage();
    void showSuppliersPage();

    void onProductsSearch();
    void onProductsAdd();
    void onProductsEdit();
    void onProductsDelete();
    void onProductsUpdate(int row, int column);

    void onExportStockCsv();
    void onExportTransactionsCsv();
    void onSellProductClicked();
    void onSearchProductClicked();
    void onConfirmCheckoutClicked();
    void loadTodaySalesToTable();


    void onGenerateInvoiceClicked();
    void onExportTodaySalesClicked();

    void loadProductsToTable();
    void loadTransactionsToTable();

private:
    Ui::DashboardWindow *ui;

    QString userEmail;
    QString companyName;
    QString mobile;
    QString regNo;

    AddProductDialog *addProductDialog;

    // Helper functions for JSON file handling
    QJsonArray readProductsFromFile();
    void writeProductsToFile(const QJsonArray &products);
    
    // Transaction helper functions
    QString getTransactionsFilePath() const;
    QJsonArray readTransactionsFromFile() const;
    void saveTransactionsToFile(const QJsonArray &transactions);
    void processCheckout(const QString &customerName, const QString &mobileNo, 
                         const QString &productName, int quantity, double totalPrice);
};

#endif // DASHBOARDWINDOW_H