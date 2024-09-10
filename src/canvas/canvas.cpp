#include "Canvas.hpp"
#include <QApplication>
#include <QDesktopWidget>

Canvas::Canvas() {
    QPalette palette = this->palette();
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);
    this->setAutoFillBackground(true);
}

QSize Canvas::sizeHint() const  {
    return QSize(1000, 1000);  
}

bool Canvas::isWithinCanvas(const ShapeInfo &info) {
    // Check if all points are within the Canvas
    for (const QPointF &point : info.coordinates) {
        if (point.x() < 0 || point.x() > this->width() || point.y() < 0 || point.y() > this->height()) {
            return false;
        }
    }
    return true;
}

void Canvas::addShape(const ShapeInfo &info) {
    auto prevShape = findShape(info.name);
    if (prevShape) {
        dublicateNameFound(prevShape->getShapeType(), info.name);
        return;
    }
    if (info.shapeType != "connect" && !isWithinCanvas(info)) {
        emit outOfCanvas(info.name);
        return;
    }

    Shape *shape = nullptr;
    if (info.shapeType == "line") {
        shape = new Line(info);
    } else if (info.shapeType == "triangle") {
        shape = new Triangle(info);
    } else if (info.shapeType == "rectangle") {
        shape = new Rectangle(info);
    }
    else if (info.shapeType == "square") {
        shape = new Square(info);
    }
    if (info.shapeType == "connect") {
        QStringList shapeNames = info.name.split(' ');
        QString shapeName1 = shapeNames[0];
        QString shapeName2 = shapeNames[1];
        connectShapes(shapeName1, shapeName2);
        return;
    }
    if (shape != nullptr) {
        shapes.insert(info.name, shape);
        update();
        emit drawSuccess();
    }
}

void Canvas::connectShapes(const QString& shapeName1, const QString& shapeName2) {
    QPointF centerOfFirstShape;
    QPointF centerOfSecondShape;

    auto shape1 = findShape(shapeName1);
    auto shape2 = findShape(shapeName2);
    if (shape1 && shape2) {
        centerOfFirstShape = shape1->center();
        centerOfSecondShape = shape2->center();
        shapes.insert("", new Line({"line", "", QVector<QPointF>{centerOfFirstShape, centerOfSecondShape}}));
        update();
        emit drawSuccess();
    }
    if (!shape1) {
        emit shapeNotFound(shapeName1);
    }
    if (!shape2) {
        emit shapeNotFound(shapeName2);
    }
}

Shape* Canvas::findShape(const QString& shapeName) {
    return shapes.value(shapeName, nullptr);
}

void Canvas::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    for (Shape* shape : shapes) {
        shape->draw(&painter);
    }
}

Canvas::~Canvas() {
    qDeleteAll(shapes);
}
