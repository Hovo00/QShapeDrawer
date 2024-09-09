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
    void handleDublicateNameError(const QString& previousShapeType, const QString& shapeName);
    void handleSyntaxError(const QString& what);
    void handleNameNotFound(const QString& name);
    void handleOutOfCanvasError(const QString& );
private:
    void logMessage(const QString &message);
    void logPlainMessage(const QString &message);
private:
    QLabel *title;
    QTextEdit *logArea;
    QVBoxLayout *layout;
};

#endif // LOGWINDOW_HPP