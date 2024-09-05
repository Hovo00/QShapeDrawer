#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <QWidget>
#include <QPainter>


// ** TO-DO Replace QWidget with QPaint device
class Shape {
public:
    virtual void draw(QWidget* canvas) = 0;
public:
    virtual ~Shape() = default;
protected:
    std::string obj_name;
};

class Line : public Shape {
public:
    void draw(QWidget* canvas) override;

};

class Triangle : public Shape {
public:
    void draw(QWidget* canvas) override;
};

class Rectangle : public Shape {
public:
    void draw(QWidget* canvas) override;
};

#endif // SHAPE_HPP