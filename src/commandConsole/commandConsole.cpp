#include "commandConsole.hpp"

CommandConsole::CommandConsole(QWidget *parent) : QLineEdit(parent) {
    setPlaceholderText("Enter command here...");
    connect(this, &QLineEdit::returnPressed, this, &CommandConsole::handleCommand);
}

void CommandConsole::handleCommand() {
    QString command = text();
    ShapeInfo info = parser.parseCommand(command);
    emit commandParsed(info);
    clear();
}
// void CommandConsole::handleCommand() {
//     QString command = text();
//     auto parseOutput = parser.parseCommand(command);

//     qDebug() << "After Parse \n" << "shape type " << parseOutput.shape_type << " \n "<< "shape name " << parseOutput.name << " \n";

//     qDebug() << "coordinates ";
//     for (auto & coord : parseOutput.coordinates) {
//         qDebug() << coord << " ";
//     }
//     clear();  // Clear the command console
// }
