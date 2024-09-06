#include "shape.hpp"

Shape::Shape(const ShapeInfo &info) : shapeInfo(info) {}

Line::Line(const ShapeInfo &info) : Shape(info) {}

void Line::draw(QPainter* painter) {
    painter->setBrush(Qt::red);
    painter->setPen(Qt::red);
    painter->drawLine(shapeInfo.coordinates[0].x(), shapeInfo.coordinates[0].y(),
                      shapeInfo.coordinates[1].x(), shapeInfo.coordinates[1].y());
}

Triangle::Triangle(const ShapeInfo &info) : Shape(info) {}

void Triangle::draw(QPainter* painter) {
    QPolygon triangle;
    painter->setBrush(Qt::black);
    painter->setPen(Qt::black);
    triangle << shapeInfo.coordinates[0].toPoint()
             << shapeInfo.coordinates[1].toPoint()
             << shapeInfo.coordinates[2].toPoint();
    painter->drawPolygon(triangle);
}

Rectangle::Rectangle(const ShapeInfo &info) : Shape(info) {}

void Rectangle::draw(QPainter* painter) {
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::blue);

    // If only two points are provided, they are considered as diagonal points
    if(shapeInfo.coordinates.size() == 2) {
        QPoint topLeft = shapeInfo.coordinates[0].toPoint();
        QPoint bottomRight = shapeInfo.coordinates[1].toPoint();
        QRect rect(topLeft, bottomRight - topLeft);
        painter->drawRect(rect);
    }
    // If four points are provided, they are considered as the four corners
    else if(shapeInfo.coordinates.size() == 4) {
        int topLeftX = std::min({shapeInfo.coordinates[0].x(), shapeInfo.coordinates[1].x(), shapeInfo.coordinates[2].x(), shapeInfo.coordinates[3].x()});
        int topLeftY = std::min({shapeInfo.coordinates[0].y(), shapeInfo.coordinates[1].y(), shapeInfo.coordinates[2].y(), shapeInfo.coordinates[3].y()});
        int bottomRightX = std::max({shapeInfo.coordinates[0].x(), shapeInfo.coordinates[1].x(), shapeInfo.coordinates[2].x(), shapeInfo.coordinates[3].x()});
        int bottomRightY = std::max({shapeInfo.coordinates[0].y(), shapeInfo.coordinates[1].y(), shapeInfo.coordinates[2].y(), shapeInfo.coordinates[3].y()});
        QRect rect(topLeftX, topLeftY, bottomRightX - topLeftX, bottomRightY - topLeftY);
        painter->drawRect(rect);
    }
}