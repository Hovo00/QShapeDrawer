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
    void logMessage(const QString &message);
public slots:
    void printCurrentCommand(const QString& command);
    void handleDublicateNameError(const QString& previousShapeType, const QString& shapeName);
    void handleSyntaxError(const QString& what);
    void handleOutOfCanvasError(const QString& );
private:
    QLabel *title;
    QTextEdit *logArea;
    QVBoxLayout *layout;
};

#endif // LOGWINDOW_HPP