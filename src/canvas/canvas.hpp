#ifndef CANVAS_HPP
#define CANVAS_HPP
#include <QWidget>
#include <QSize>

#include "src/shapes/shape.hpp"

class Canvas : public QWidget {
    Q_OBJECT
public:
    Canvas();
public slots:
    void addShape(const ShapeInfo &info);
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
private:
    QVector<Shape*> shapes;
};

#endif // CANVAS_HPP