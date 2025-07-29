#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>

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

private:
    Ui::DashboardWindow *ui;
    QString userEmail;
    QString companyName;
    QString mobile;
    QString regNo;
};

#endif 