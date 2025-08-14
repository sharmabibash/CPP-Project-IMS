cmake_minimum_required(VERSION 3.14)
project(IMS VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt6 auto features
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find Qt6 packages (added PrintSupport)
find_package(Qt6 REQUIRED COMPONENTS 
    Widgets
    Core
    PrintSupport
)

# Source files
set(SOURCES
    main.cpp
    views/dashboardwindow/dashboardwindow.cpp
    views/loginwindow/loginwindow.cpp
    views/registrationwindow/registrationwindow.cpp
    views/addproductdialog/addproductdialog.cpp
)

# Header files
set(HEADERS
    views/dashboardwindow/dashboardwindow.h
    views/loginwindow/loginwindow.h
    views/registrationwindow/registrationwindow.h
    views/addproductdialog/addproductdialog.h
)

# UI files
set(UIS
    views/dashboardwindow/dashboardwindow.ui
    views/loginwindow/loginwindow.ui
    views/registrationwindow/registrationwindow.ui
    views/addproductdialog/addproductdialog.ui
)

# Add the executable
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UIS}
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/views
    ${CMAKE_CURRENT_SOURCE_DIR}/views/dashboardwindow
    ${CMAKE_CURRENT_SOURCE_DIR}/views/loginwindow
    ${CMAKE_CURRENT_SOURCE_DIR}/views/registrationwindow
    ${CMAKE_CURRENT_SOURCE_DIR}/views/addproductdialog
)

# Link libraries (added Qt6::PrintSupport)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::Core
    Qt6::PrintSupport
)
