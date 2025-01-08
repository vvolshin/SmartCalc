cmake_minimum_required(VERSION 3.5)

project(SmartCalc VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(MACOSX_BUNDLE_GUI_IDENTIFIER "author:VitalyVolshin")

include_directories(view/qcustomplot)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(QCustomPlot_DIR "view/qcustomplot")

file(GLOB PROJECT_SOURCES_VIEW
    view/s21_CalculatorView.h 
    view/s21_CalculatorView.cpp 
    view/s21_CalculatorView.ui 
    view/main.cpp
    view/icons/icons.qrc
    view/qcustomplot/qcustomplot.h 
    view/qcustomplot/qcustomplot.cpp
    view/s21_menu.cpp
    view/s21_graph.cpp
    view/s21_connections.cpp
    view/s21_credits.cpp
    view/font.qrc
)

file(GLOB PROJECT_SOURCES_MODEL
    model/*.cc
    model/*.h
)

file(GLOB PROJECT_SOURCES_CONTROLLER
    controller/*.cc
    controller/*.h
)

set(PROJECT_SOURCES
        ${PROJECT_SOURCES_VIEW}
        ${PROJECT_SOURCES_MODEL}
        ${PROJECT_SOURCES_CONTROLLER}
        )
        
add_executable(SmartCalc
    ${PROJECT_SOURCES}
)

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS PrintSupport REQUIRED)

target_link_libraries(SmartCalc PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::PrintSupport
)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.frontend)
endif()
set_target_properties(SmartCalc PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SmartCalc
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartCalc)
endif()
