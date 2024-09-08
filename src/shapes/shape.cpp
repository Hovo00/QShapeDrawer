#include "shape.hpp"

Shape::Shape(const ShapeInfo &info) : shapeInfo(info) {}

QString Shape::getName() {
    return shapeInfo.name;
}

Line::Line(const ShapeInfo &info) : Shape(info) {}

void Line::draw(QPainter* painter) {
    painter->setBrush(Qt::red);
    painter->setPen(Qt::red);
    painter->drawLine(shapeInfo.coordinates[0].x(), shapeInfo.coordinates[0].y(),
                      shapeInfo.coordinates[1].x(), shapeInfo.coordinates[1].y());
}

QPointF Line::center() const {
    return (shapeInfo.coordinates[0] + shapeInfo.coordinates[1]) / 2;
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

QPointF Triangle::center() const {
    return (shapeInfo.coordinates[0] + shapeInfo.coordinates[1] + shapeInfo.coordinates[2]) / 3;
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


Square::Square(const ShapeInfo &info) : Shape(info) {}

void Square::draw(QPainter* painter) {
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

QPointF Rectangle::center() const {
    if(shapeInfo.coordinates.size() == 2) {
        return (shapeInfo.coordinates[0] + shapeInfo.coordinates[1]) / 2;
    }
    else if(shapeInfo.coordinates.size() == 4) {
        QPointF topLeft = shapeInfo.coordinates[0];
        QPointF bottomRight = shapeInfo.coordinates[2];
        return (topLeft + bottomRight) / 2;
    }
    return QPointF();
}

QPointF Square::center() const {
    if(shapeInfo.coordinates.size() == 2) {
        return (shapeInfo.coordinates[0] + shapeInfo.coordinates[1]) / 2;
    }
    else if(shapeInfo.coordinates.size() == 4) {
        QPointF topLeft = shapeInfo.coordinates[0];
        QPointF bottomRight = shapeInfo.coordinates[2];
        return (topLeft + bottomRight) / 2;
    }
    return QPointF();
}