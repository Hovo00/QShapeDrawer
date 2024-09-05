#include "shape.hpp"

void Line::draw(QWidget* canvas) {
    QPainter painter(canvas);
    painter.setBrush(Qt::red); 
    painter.setPen(Qt::red);
    painter.drawLine(10, 10, 100, 100);
}

void Triangle::draw(QWidget* canvas) {
    QPainter painter(canvas);
    QPolygon triangle;
    painter.setBrush(Qt::black);
    painter.setPen(Qt::black);
    triangle << QPoint(10, 10) << QPoint(50, 10) << QPoint(30, 50);
    painter.drawPolygon(triangle);
}

void Rectangle::draw(QWidget* canvas) {
    QPainter painter(canvas);
    QPolygon triangle;
    painter.setBrush(Qt::blue);  // Set brush color
    painter.drawRect(10, 10, 100, 100);
}