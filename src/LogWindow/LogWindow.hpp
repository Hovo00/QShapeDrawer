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
    void handleSyntaxError(const QString &message);
    void handleOutOfCanvasError(const QString &message);
private:
    QLabel *title;
    QTextEdit *logArea;
    QVBoxLayout *layout;
};

#endif // LOGWINDOW_HPP