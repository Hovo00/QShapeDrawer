#include <QLineEdit>
#include <QWidget>
#include <QDebug>

#include "src/Parser/Parser.hpp"

class CommandConsole : public QLineEdit {
    Q_OBJECT
public:
    CommandConsole(QWidget *parent = nullptr);
public slots:
    void handleCommand();
    QSize sizeHint() const override;
signals:
    void commandParsed(const ShapeInfo& info);
    void commandEntered(const QString& command);
    void syntaxError(const QString& what);
    void outOfCanvas(const QString &message);
};