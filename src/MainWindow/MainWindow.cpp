#include "MainWindow.hpp"
#include "ToolBar.hpp"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow() {
    ToolBar *toolbar = new ToolBar;
    addToolBar(toolbar);

    connect(toolbar, &ToolBar::fileActionTriggered, this, &MainWindow::onFileAction);
    connect(toolbar, &ToolBar::helpActionTriggered, this, &MainWindow::onHelpAction);
    toolbar->setMinimumSize(100, 20);


    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    connect(&commandConsole, &CommandConsole::commandParsed, &canvas, &Canvas::addShape);
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

void MainWindow::onFileAction() {
    qDebug() << "File action triggered";

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*)"));

    if (!fileName.isEmpty()) {
        qDebug() << "User selected file:" << fileName;

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Failed to open file";
            return;
        }

        QTextStream in(&file);
        QString fileContent = in.readAll();
        qDebug() << "File content:" << fileContent;

        file.close();
    } else {
        qDebug() << "User did not select a file";
    }
}

void MainWindow::onHelpAction() {
    qDebug() << "Help action triggered";
    // logic for the Help action here
};