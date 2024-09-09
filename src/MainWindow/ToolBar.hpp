#ifndef ToolBar_HPP
#define ToolBar_HPP

#include <QToolBar>
#include <QAction>

#include "src/shapes/shape.hpp"

class ToolBar : public QToolBar {
    Q_OBJECT
public:
    ToolBar();
signals:
    void commandParsed(const ShapeInfo &info);
    void commandEntered(const QString& command);
    void syntaxError(const QString& command);
private slots:
    void onFileActionTriggered();
    void onHelpActionTriggered();
};

#endif // ToolBar_HPP