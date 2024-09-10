#ifndef CANVAS_HPP
#define CANVAS_HPP
#include <QWidget>
#include <QSize>

#include "src/shapes/shape.hpp"

class Canvas : public QWidget {
    Q_OBJECT
public:
    Canvas();
    ~Canvas();
QSize sizeHint() const override;
public slots:
    void addShape(const ShapeInfo &info);
    void paintEvent(QPaintEvent *event) override;
signals:
    void dublicateNameFound(const QString& previousDefinedName, const QString& shapeName);
    void shapeNotFound(const QString& name);
    void outOfCanvas(const QString& name);
    void drawSuccess();
private:
    bool isWithinCanvas(const ShapeInfo &info);
    void connectShapes(const QString& shape1_name, const QString& shape2_name);
    Shape* findShape(const QString& shape_name);
    // Refactor to use unordered_map 
    QVector<Shape*> shapes;
};

#endif // CANVAS_HPP