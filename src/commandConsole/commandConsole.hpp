#include <QLineEdit>
#include <QWidget>

#include "src/Shapes/Shape.hpp"

class CommandConsole : public QLineEdit {
    Q_OBJECT
public:
    CommandConsole(QWidget *parent = nullptr);
public slots:
    void handleCommand();
    QSize sizeHint() const override;
signals:
    void syntaxError(const QString& what);
    void commandParsed(const ShapeInfo& info);
    void commandEntered(const QString& command);
};