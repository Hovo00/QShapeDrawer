TEMPLATE += app
QT += quick
QT += widgets
QT += core gui

HEADERS += src/commandConsole/commandConsole.hpp
HEADERS += src/Parser/Parser.hpp
HEADERS += src/Canvas/Canvas.hpp
HEADERS += src/LogWindow/LogWindow.hpp
HEADERS += src/MainWindow/MainWindow.hpp
HEADERS += src/ToolBar/ToolBar.hpp

SOURCES += src/MainWindow/MainWindow.cpp
SOURCES += src/ToolBar/ToolBar.cpp
SOURCES += src/main.cpp
SOURCES += src/shapes/shape.cpp
SOURCES += src/Canvas/Canvas.cpp
SOURCES += src/commandConsole/commandConsole.cpp
SOURCES += src/Parser/Parser.cpp
SOURCES += src/LogWindow/LogWindow.cpp
SOURCES += src/Parser/CustomExceptions/ParserExceptions.cpp




