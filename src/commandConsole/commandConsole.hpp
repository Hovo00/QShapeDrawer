#include <QLineEdit>
#include <QWidget>
#include <QDebug>

#include "Parser.hpp"

class CommandConsole : public QLineEdit {
    Q_OBJECT
public:
    CommandConsole(QWidget *parent = nullptr);
public slots:
    void handleCommand();
    QSize sizeHint() const override;
signals:
    void commandParsed(const ShapeInfo &info);
    void syntaxError(const QString &message);
    void outOfCanvas(const QString &message);
private:
    Parser parser;
};