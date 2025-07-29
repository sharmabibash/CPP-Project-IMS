cmake_minimum_required(VERSION 3.14)
project(IMS)

set(CMAKE_CXX_STANDARD 17)

# Enable auto features for signals/slots and UI headers
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Qt6 required
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Source files (update this as you add more)
set(SOURCES
    main.cpp
    views/dashboardwindow/dashboardwindow.cpp
)

# Header files
set(HEADERS
    views/dashboardwindow/dashboardwindow.h
)

# UI files
set(UIS
    views/dashboardwindow/dashboardwindow.ui
)

# Add the executable
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UIS}
)

# Link with Qt6 Widgets
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
