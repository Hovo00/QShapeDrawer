#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QVector>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QDialog>

//** TO-DO create some env variable
#include "src/shapes/shape.hpp"
#include "src/canvas/canvas.hpp"
#include "src/commandConsole/commandConsole.hpp"
#include "src/LogWindow/LogWindow.hpp"

class MainWindow : public QWidget {
    Q_OBJECT
public:
    MainWindow() {
        connect(&commandConsole, &CommandConsole::commandParsed, &canvas, &Canvas::addShape);
        connect(&commandConsole, &CommandConsole::syntaxError, &logWindow, &LogWindow::handleSyntaxError);
        connect(&commandConsole, &CommandConsole::outOfCanvas, &logWindow, &LogWindow::handleOutOfCanvasError);

        // Add the widgets to the layout
        mainLayout.addWidget(&canvas);
        mainLayout.addWidget(&logWindow);
        mainLayout.addWidget(&commandConsole);

        // Set the layout of the main window
        setLayout(&mainLayout);
    }

private:
    QVBoxLayout mainLayout;
    Canvas canvas;
    CommandConsole commandConsole;
    LogWindow logWindow;
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow main;
    Canvas canvas;

    main.show();

    return app.exec();
}

#include "MainWindow.moc"