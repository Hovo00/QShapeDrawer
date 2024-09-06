#include "canvas.hpp"
#include <QApplication>
#include <QDesktopWidget>

Canvas::Canvas() {
    QPalette palette = this->palette();
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);
    this->setAutoFillBackground(true);
}

QSize Canvas::sizeHint() const  {
    return QSize(2000, 1000);  // Return a suitable size
}

void Canvas::addShape(const ShapeInfo &info) {
    Shape *shape = nullptr;
    if (info.shape_type == "line") {
        shape = new Line(info);
    } else if (info.shape_type == "triangle") {
        shape = new Triangle(info);
    } else if (info.shape_type == "rectangle") {
        shape = new Rectangle(info);
    }
    // else if (info.shape_type == "square") {
    //     shape = new Square(info.name, info.coordinates[0], info.coordinates[1], info.coordinates[2], info.coordinates[3]);
    // }

    if (shape != nullptr) {
        shapes.append(shape);
        update();
    }
}
void Canvas::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    for (Shape* shape : shapes) {
        shape->draw(&painter);
    }
}