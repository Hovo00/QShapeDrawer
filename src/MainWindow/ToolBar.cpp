#include "ToolBar.hpp"

ToolBar::ToolBar() {
    QAction *fileAction = addAction("File");
    connect(fileAction, &QAction::triggered, this, &ToolBar::onFileActionTriggered);

    QAction *helpAction = addAction("Help");
    connect(helpAction, &QAction::triggered, this, &ToolBar::onHelpActionTriggered);
}

void ToolBar::onFileActionTriggered() {
    emit fileActionTriggered();
}

void ToolBar::onHelpActionTriggered() {
    emit helpActionTriggered();
}