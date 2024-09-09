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

    if (shapeInfo.coordinates.size() == 2) {
        QPointF topLeft = shapeInfo.coordinates[0];
        QPointF bottomRight = shapeInfo.coordinates[1];
        QRect rect(topLeft.toPoint(), QSize(bottomRight.x() - topLeft.x(), bottomRight.y() - topLeft.y()));
        painter->drawRect(rect);
    } else if (shapeInfo.coordinates.size() == 4) {
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

Square::Square(const ShapeInfo &info) : Shape(info) {}

void Square::draw(QPainter* painter) {
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::blue);

    if (shapeInfo.coordinates.size() == 2) {
        QPointF topLeft = shapeInfo.coordinates[0];
        QPointF bottomRight = shapeInfo.coordinates[1];
        int sideLength = qMin(qAbs(bottomRight.x() - topLeft.x()), qAbs(bottomRight.y() - topLeft.y()));
        QRect rect(topLeft.toPoint(), QSize(sideLength, sideLength));
        painter->drawRect(rect);
    } else if (shapeInfo.coordinates.size() == 4) {
        int topLeftX = std::min({shapeInfo.coordinates[0].x(), shapeInfo.coordinates[1].x(), shapeInfo.coordinates[2].x(), shapeInfo.coordinates[3].x()});
        int topLeftY = std::min({shapeInfo.coordinates[0].y(), shapeInfo.coordinates[1].y(), shapeInfo.coordinates[2].y(), shapeInfo.coordinates[3].y()});
        int bottomRightX = std::max({shapeInfo.coordinates[0].x(), shapeInfo.coordinates[1].x(), shapeInfo.coordinates[2].x(), shapeInfo.coordinates[3].x()});
        int bottomRightY = std::max({shapeInfo.coordinates[0].y(), shapeInfo.coordinates[1].y(), shapeInfo.coordinates[2].y(), shapeInfo.coordinates[3].y()});
        int sideLength = qMin(bottomRightX - topLeftX, bottomRightY - topLeftY);
        QRect rect(topLeftX, topLeftY, sideLength, sideLength);
        painter->drawRect(rect);
    }
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