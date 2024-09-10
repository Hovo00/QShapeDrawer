#include "canvas.hpp"
#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>

Canvas::Canvas() {
    QPalette palette = this->palette();
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);
    this->setAutoFillBackground(true);
}

QSize Canvas::sizeHint() const  {
    return QSize(1000, 1000);  // Return a suitable size
}

bool Canvas::isWithinCanvas(const ShapeInfo &info) {
    // Check if all points are within the canvas
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
    if (info.shape_type != "connect" && !isWithinCanvas(info)) {
        emit outOfCanvas(info.name);
        return;
    }

    Shape *shape = nullptr;
    if (info.shape_type == "line") {
        shape = new Line(info);
    } else if (info.shape_type == "triangle") {
        shape = new Triangle(info);
    } else if (info.shape_type == "rectangle") {
        shape = new Rectangle(info);
    }
    else if (info.shape_type == "square") {
        shape = new Square(info);
    }
    if (info.shape_type == "connect") {
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

void Canvas::connectShapes(const QString& shape1_name, const QString& shape2_name) {
    QPointF centerOfFirstShape;
    QPointF centerOfSecondShape;
    qDebug() << "shape1_name = " << shape1_name << "  shape2_name = " << shape2_name;

    // To-do handle case when shape not found
    auto shape1 = findShape(shape1_name);
    auto shape2 = findShape(shape2_name);
    if (shape1 && shape2) {
        centerOfFirstShape = shape1->center();
        centerOfSecondShape = shape2->center();
        shapes.insert("", new Line({"line", "", QVector<QPointF>{centerOfFirstShape, centerOfSecondShape}}));
        update();
        emit drawSuccess();
    }
    if (!shape1) {
        emit shapeNotFound(shape1_name);
    }
    if (!shape2) {
        qDebug() << " I reach here";
        emit shapeNotFound(shape2_name);
    }
}

Shape* Canvas::findShape(const QString& shape_name) {
    return shapes.value(shape_name, nullptr);
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
