#include <QApplication>
#include "src/MainWindow/MainWindow.hpp"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow main;
    main.show();

    return app.exec();
}