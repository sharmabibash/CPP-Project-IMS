#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"

DashboardWindow::DashboardWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DashboardWindow)
{
    ui->setupUi(this);
    setWindowTitle("Inventory Dashboard");
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}