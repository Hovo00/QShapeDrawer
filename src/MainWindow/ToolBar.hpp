#ifndef ToolBar_HPP
#define ToolBar_HPP

#include <QToolBar>
#include <QAction>

class ToolBar : public QToolBar {
    Q_OBJECT
public:
    ToolBar();

signals:
    void fileActionTriggered();
    void helpActionTriggered();

private slots:
    void onFileActionTriggered();
    void onHelpActionTriggered();
};

#endif // ToolBar_HPP