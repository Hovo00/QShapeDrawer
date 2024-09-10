#include "commandConsole.hpp"

#include "src/Parser/Parser.hpp"
#include "src/Parser/CustomExceptions/ParserExceptions.hpp"

CommandConsole::CommandConsole(QWidget *parent) : QLineEdit(parent) {
    setPlaceholderText("Command Console");
    setStyleSheet("background-color: white; color: black;");

    connect(this, &QLineEdit::returnPressed, this, &CommandConsole::handleCommand);
}

void CommandConsole::handleCommand() {
    QString command = text();
    emit commandEntered(command);

    try {
        ShapeInfo info = Parser::parseCommand(command);
        emit commandParsed(info);
    } catch (const std::exception& excep) {
        emit syntaxError(excep.what());
    }
    clear();
}

QSize CommandConsole::sizeHint() const  {
    return QSize(1000, 10);
}
