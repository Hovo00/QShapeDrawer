#include "ToolBar.hpp"
#include "src/Parser/Parser.hpp"

#include <QDebug>
#include <QFileDialog>
#include <exception>

ToolBar::ToolBar() {
    QAction *fileAction = addAction("File");
    connect(fileAction, &QAction::triggered, this, &ToolBar::onFileActionTriggered);

    QAction *helpAction = addAction("Help");
    connect(helpAction, &QAction::triggered, this, &ToolBar::onHelpActionTriggered);
}

void ToolBar::onFileActionTriggered() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Failed to open file";
            return;
        }

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            emit commandEntered(line);
            try {
                auto result = Parser::parseCommand(line);
                // If parsing was successful without exceptions, emit the commandParsed signal
                emit commandParsed(result);
            } catch (const std::exception& excep) {
                emit syntaxError(excep.what());
            }
        }

        file.close();
    } else {
        qDebug() << "User did not select a file";
    }
}

void ToolBar::onHelpActionTriggered() {
    qDebug() << "Help action triggered";
}