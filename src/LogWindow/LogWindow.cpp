#include "LogWindow.hpp"
#include <QDebug>

LogWindow::LogWindow(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    title = new QLabel("LOG", this);
    title->setStyleSheet("background-color: black; color: white;");
    layout->addWidget(title);

    logArea = new QTextEdit(this);
    logArea->setStyleSheet("background-color: white; color: black;");
    logArea->setReadOnly(true); // Make the text area read-only
    layout->addWidget(logArea);

    setLayout(layout);
}

void LogWindow::handleDublicateNameError(const QString& previousShapeType, const QString& shapeName) {
    logArea->setTextColor(Qt::red);
    logMessage("Failed to execute command: Shape of type {" + previousShapeType + "} was previously defined with that name {" + shapeName + "}");
}

void LogWindow::printCurrentCommand(const QString& command) {
    logArea->setTextColor(Qt::black);
    logMessage("Executing command '" + command + "'");
}

void LogWindow::handleUnknownFlag(const QString& what) {
    logMessage("");
    logArea->setTextColor(Qt::red);
    logArea->insertPlainText("Failed to execute command: ");

    // Set the text color back to black for the 'what' message
    logArea->setTextColor(Qt::black);
    logArea->insertPlainText(what);
}

void LogWindow::handleOutOfCanvasError(const QString &message) {
    // Handle out of canvas error
    logMessage(message);
}

void LogWindow::logMessage(const QString &message) {
    logArea->append(message);
}

void LogWindow::handleCommandSuccess() {
    logArea->setTextColor(Qt::green);
    logMessage("success");
}