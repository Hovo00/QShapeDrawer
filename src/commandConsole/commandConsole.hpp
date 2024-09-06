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
signals:
    void commandParsed(const ShapeInfo &info);
private:
    Parser parser;
};