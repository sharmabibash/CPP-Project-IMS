#include <QApplication>
     #include "views/dashboardwindow/dashboardwindow.h"

     int main(int argc, char *argv[])
     {
         QApplication app(argc, argv);
         DashboardWindow window;
         window.show();
         return app.exec();
     }