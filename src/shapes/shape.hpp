#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <QWidget>
#include <QPainter>
#include <QPointF>
#include <QString>
#include <QVector>

struct ShapeInfo {
    QString shape_type;
    QString name;
    QVector<QPointF> coordinates;
};

class Shape {
public:
    Shape(const ShapeInfo &info);
    virtual void draw(QPainter* painter) = 0;
    virtual ~Shape() = default;
protected:
    ShapeInfo shapeInfo;
};

class Line : public Shape {
public:
    Line(const ShapeInfo &info);
    void draw(QPainter* painter) override;
};

class Triangle : public Shape {
public:
    Triangle(const ShapeInfo &info);
    void draw(QPainter* painter) override;
};

class Rectangle : public Shape {
public:
    Rectangle(const ShapeInfo &info);
    void draw(QPainter* painter) override;
};

#endif // SHAPE_HPP