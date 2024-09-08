#include "commandConsole.hpp"

CommandConsole::CommandConsole(QWidget *parent) : QLineEdit(parent) {
    setPlaceholderText("Command Console");
    connect(this, &QLineEdit::returnPressed, this, &CommandConsole::handleCommand);

    setStyleSheet("background-color: white; color: black;");
}

void CommandConsole::handleCommand() {
    QString command = text();
    ShapeInfo info = parser.parseCommand(command);
    // emit syntaxError("there was some syntax error");
    emit commandParsed(info);
    clear();
}

QSize CommandConsole::sizeHint() const  {
    return QSize(1000, 10);  // Return a suitable size
}
