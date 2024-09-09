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
    logMessage("Failed to execute command ");
    logMessage("Shape of type {" + previousShapeType + "} was previously defined with that name {" + shapeName + "}");
}

void LogWindow::printCurrentCommand(const QString& command) {
    logMessage("Executing command '" + command + "'");
}

void LogWindow::handleSyntaxError(const QString& what) {
    // Handle syntax error
    logMessage(what);
}

void LogWindow::handleOutOfCanvasError(const QString &message) {
    // Handle out of canvas error
    logMessage(message);
}

void LogWindow::logMessage(const QString &message) {
    logArea->append(message); // Append the message to the text area
}