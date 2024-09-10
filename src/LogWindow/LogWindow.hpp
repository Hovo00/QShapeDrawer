#ifndef LOGWINDOW_HPP
#define LOGWINDOW_HPP

#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>

class LogWindow : public QWidget {
    Q_OBJECT
public:
    LogWindow(QWidget *parent = nullptr);
public slots:
    void handleCommandSuccess();
    void printCurrentCommand(const QString& command);
public slots:
    void handleSyntaxError(const QString& what);
    void handleNameNotFound(const QString& shapeName);
    void handleOutOfCanvasError(const QString& shapeName);
    void handleDublicateNameError(const QString& previousShapeType, const QString& shapeName);
private:
    void logMessage(const QString &message);
    void logColoredMessage(const QString &message);
private:
    QLabel *title;
    QTextEdit *logArea;
    QVBoxLayout *layout;
};

#endif // LOGWINDOW_HPP