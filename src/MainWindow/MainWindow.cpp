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

class MainWindow : public QWidget {
    Q_OBJECT
public:
    MainWindow() {
        // canvas.setFixedSize(500, 500);  // Set a fixed size
        // canvas.addShape(new Line());
        // canvas.addShape(new Triangle());
        connect(&commandConsole, &CommandConsole::commandParsed, &canvas, &Canvas::addShape);
        // Set up the log window
        logWindow.setReadOnly(true);

        // Add the widgets to the layout
        mainLayout.addWidget(&canvas);
        mainLayout.addWidget(&commandConsole);
        mainLayout.addWidget(&logWindow);

        // Set the layout of the main window
        setLayout(&mainLayout);
    }

private:
    QVBoxLayout mainLayout;
    Canvas canvas;
    CommandConsole commandConsole;
    QTextEdit logWindow;
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