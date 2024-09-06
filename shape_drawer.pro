TEMPLATE += app
QT += quick
QT += widgets
QT += core gui

HEADERS += src/commandConsole/commandConsole.hpp
HEADERS += src/commandConsole/Parser.hpp
HEADERS += src/canvas/canvas.hpp

SOURCES += src/MainWindow/MainWindow.cpp
SOURCES += src/shapes/shape.cpp
SOURCES += src/canvas/canvas.cpp
SOURCES += src/commandConsole/commandConsole.cpp
SOURCES += src/commandConsole/Parser.cpp

