#ifndef CANVAS_HPP
#define CANVAS_HPP
#include <QWidget>
#include <QSize>

#include "src/shapes/shape.hpp"

class Canvas : public QWidget {
public:
    Canvas();
public:
    void addShape(Shape* shape);
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
private:
    QVector<Shape*> shapes;
};

#endif // CANVAS_HPP