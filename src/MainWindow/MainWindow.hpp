#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QVBoxLayout>

#include "src/shapes/shape.hpp"
#include "src/canvas/canvas.hpp"
#include "src/commandConsole/commandConsole.hpp"
#include "src/LogWindow/LogWindow.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
private:
    QVBoxLayout mainLayout;
    Canvas canvas;
    CommandConsole commandConsole;
    LogWindow logWindow;
};

#endif // MAINWINDOW_HPP