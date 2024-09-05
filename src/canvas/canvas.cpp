#include "canvas.hpp"
#include <QApplication>
#include <QDesktopWidget>

Canvas::Canvas() {
    setStyleSheet("background-color: white;");
}

QSize Canvas::sizeHint() const  {
    return QSize(500, 500);  // Return a suitable size
}

void Canvas::addShape(Shape* shape) {
    shapes.push_back(shape);
    update();
}
void Canvas::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    for (Shape* shape : shapes) {
        shape->draw(this);
    }
}