TEMPLATE += app
QT += quick
QT += widgets
QT += core gui

HEADERS += src/CommandConsole/CommandConsole.hpp
HEADERS += src/Parser/Parser.hpp
HEADERS += src/Canvas/Canvas.hpp
HEADERS += src/LogWindow/LogWindow.hpp
HEADERS += src/MainWindow/MainWindow.hpp
HEADERS += src/ToolBar/ToolBar.hpp

SOURCES += src/MainWindow/MainWindow.cpp
SOURCES += src/ToolBar/ToolBar.cpp
SOURCES += src/main.cpp
SOURCES += src/Shapes/Shape.cpp
SOURCES += src/Canvas/Canvas.cpp
SOURCES += src/CommandConsole/CommandConsole.cpp
SOURCES += src/Parser/Parser.cpp
SOURCES += src/LogWindow/LogWindow.cpp
SOURCES += src/Parser/CustomExceptions/ParserExceptions.cpp




