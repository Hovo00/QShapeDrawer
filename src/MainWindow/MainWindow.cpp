#include "MainWindow.hpp"
#include "ToolBar.hpp"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow() {
    ToolBar *toolbar = new ToolBar;
    addToolBar(toolbar);

    toolbar->setMinimumSize(100, 20);


    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    connect(&commandConsole, &CommandConsole::commandParsed, &canvas, &Canvas::addShape);
    connect(toolbar, &ToolBar::commandParsed, &canvas, &Canvas::addShape);
    connect(&commandConsole, &CommandConsole::syntaxError, &logWindow, &LogWindow::handleSyntaxError);
    connect(&commandConsole, &CommandConsole::outOfCanvas, &logWindow, &LogWindow::handleOutOfCanvasError);

    // Add the widgets to the layout
    mainLayout->addWidget(&canvas);
    mainLayout->addWidget(&logWindow);
    mainLayout->addWidget(&commandConsole);

    // Set the layout of the central widget
    centralWidget->setLayout(mainLayout);

    // Set the central widget of the main window
    setCentralWidget(centralWidget);
}
