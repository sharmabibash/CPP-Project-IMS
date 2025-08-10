#include <QApplication>
     #include "views/dashboardwindow/dashboardwindow.h"
     #include "views/loginwindow/loginwindow.h"
     #include "views/registrationwindow/registrationwindow.h"

     int main(int argc, char *argv[])
     {
         QApplication app(argc, argv);
         DashboardWindow window;
         window.show();
         return app.exec();
     }