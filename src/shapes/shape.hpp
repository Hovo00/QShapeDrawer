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
public:
    virtual void draw(QPainter* painter) = 0;
    virtual QPointF center() const = 0;
    virtual QString getName();
public:
    virtual ~Shape() = default;
protected:
    ShapeInfo shapeInfo;
};

class Line : public Shape {
public:
    Line(const ShapeInfo &info);
    void draw(QPainter* painter) override;
    QPointF center() const override;
};

class Triangle : public Shape {
public:
    Triangle(const ShapeInfo &info);
    void draw(QPainter* painter) override;
    QPointF center() const override;
};

class Rectangle : public Shape {
public:
    Rectangle(const ShapeInfo &info);
    void draw(QPainter* painter) override;
    QPointF center() const override;
};

class Square : public Shape {
public:
    Square(const ShapeInfo &info);
    void draw(QPainter* painter) override;
    QPointF center() const override;
};

#endif // SHAPE_HPP