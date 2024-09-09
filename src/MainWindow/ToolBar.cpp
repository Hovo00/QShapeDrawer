#include "ToolBar.hpp"
#include "src/Parser/Parser.hpp"
#include <QDebug>
#include <QFileDialog>

ToolBar::ToolBar() {
    QAction *fileAction = addAction("File");
    connect(fileAction, &QAction::triggered, this, &ToolBar::onFileActionTriggered);

    QAction *helpAction = addAction("Help");
    connect(helpAction, &QAction::triggered, this, &ToolBar::onHelpActionTriggered);
}

void ToolBar::onFileActionTriggered() {
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
        while (!in.atEnd()) {
            QString line = in.readLine();
            qDebug() << "Line content:" << line;
            auto result = Parser::parseCommand(line); // Assuming parse() returns a bool
            emit commandParsed(result);
        }

        file.close();
    } else {
        qDebug() << "User did not select a file";
    }
}

void ToolBar::onHelpActionTriggered() {
    qDebug() << "Help action triggered";
    // logic for the Help action here
}