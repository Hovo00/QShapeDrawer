#include "LogWindow.hpp"

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
void LogWindow::handleSyntaxError(const QString &message) {
    // Handle syntax error
    logMessage(message);
}

void LogWindow::handleOutOfCanvasError(const QString &message) {
    // Handle out of canvas error
    logMessage(message);
}

void LogWindow::logMessage(const QString &message) {
    logArea->append(message); // Append the message to the text area
}