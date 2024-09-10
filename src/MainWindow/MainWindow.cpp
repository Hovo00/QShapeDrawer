#include "MainWindow.hpp"

MainWindow::MainWindow() {
    addToolBar(&toolBar);
    connectSlotsAndSignals();

    toolBar.setMinimumSize(100, 20);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    mainLayout->addWidget(&canvas);
    mainLayout->addWidget(&logWindow);
    mainLayout->addWidget(&commandConsole);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

void MainWindow::connectSlotsAndSignals() {
    connect(&commandConsole, &CommandConsole::commandEntered, &logWindow, &LogWindow::printCurrentCommand);
    connect(&commandConsole, &CommandConsole::commandParsed, &canvas, &Canvas::addShape);
    connect(&commandConsole, &CommandConsole::syntaxError, &logWindow, &LogWindow::handleSyntaxError);
    connect(&canvas, &Canvas::outOfCanvas, &logWindow, &LogWindow::handleOutOfCanvasError);

    connect(&canvas, &Canvas::dublicateNameFound, &logWindow, &LogWindow::handleDublicateNameError);
    connect(&canvas, &Canvas::shapeNotFound, &logWindow, &LogWindow::handleNameNotFound);
    connect(&canvas, &Canvas::drawSuccess, &logWindow, &LogWindow::handleCommandSuccess);

    connect(&toolBar, &ToolBar::commandParsed, &canvas, &Canvas::addShape);
    connect(&toolBar, &ToolBar::commandEntered, &logWindow, &LogWindow::printCurrentCommand);
    connect(&toolBar, &ToolBar::syntaxError, &logWindow, &LogWindow::handleSyntaxError);
}
