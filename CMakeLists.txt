cmake_minimum_required(VERSION 3.14)
project(IMS VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS 
    Widgets
    Core
    PrintSupport
)

set(SOURCES
    main.cpp
    views/dashboardwindow/dashboardwindow.cpp
    views/loginwindow/loginwindow.cpp
    views/registrationwindow/registrationwindow.cpp
    views/addproductdialog/addproductdialog.cpp
)

set(HEADERS
    views/dashboardwindow/dashboardwindow.h
    views/loginwindow/loginwindow.h
    views/registrationwindow/registrationwindow.h
    views/addproductdialog/addproductdialog.h
)

set(UIS
    views/dashboardwindow/dashboardwindow.ui
    views/loginwindow/loginwindow.ui
    views/registrationwindow/registrationwindow.ui
    views/addproductdialog/addproductdialog.ui
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UIS}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/views
    ${CMAKE_CURRENT_SOURCE_DIR}/views/dashboardwindow
    ${CMAKE_CURRENT_SOURCE_DIR}/views/loginwindow
    ${CMAKE_CURRENT_SOURCE_DIR}/views/registrationwindow
    ${CMAKE_CURRENT_SOURCE_DIR}/views/addproductdialog
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::Core
    Qt6::PrintSupport
)
