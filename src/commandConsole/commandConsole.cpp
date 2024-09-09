#include "commandConsole.hpp"
#include "src/Parser/CustomExceptions/ParserExceptions.hpp"

CommandConsole::CommandConsole(QWidget *parent) : QLineEdit(parent) {
    setPlaceholderText("Command Console");
    connect(this, &QLineEdit::returnPressed, this, &CommandConsole::handleCommand);

    setStyleSheet("background-color: white; color: black;");
}

void CommandConsole::handleCommand() {
    QString command = text();
    emit commandEntered(command);
    try {
        ShapeInfo info = Parser::parseCommand(command);
    }
    catch (const std::exception& excep) {
        qDebug() << "esim";
        emit syntaxError(excep.what());
    }
    // emit commandParsed(info);
    clear();
}

QSize CommandConsole::sizeHint() const  {
    return QSize(1000, 10);  // Return a suitable size
}
