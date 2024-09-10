#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QVBoxLayout>

#include "src/Shapes/Shape.hpp"
#include "src/Canvas/Canvas.hpp"
#include "src/ToolBar/ToolBar.hpp"
#include "src/LogWindow/LogWindow.hpp"
#include "src/CommandConsole/CommandConsole.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
private:
    void connectSlotsAndSignals();
private:
    Canvas canvas;
    ToolBar toolBar;
    LogWindow logWindow;
    QVBoxLayout mainLayout;
    CommandConsole commandConsole;
};

#endif // MAINWINDOW_HPP