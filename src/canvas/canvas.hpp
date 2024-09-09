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
private:
    void connectShapes(const QString& shape_name1, const QString& shape_name2);
    Shape* findShape(const QString& shape_name);
    // Refactor to use unordered_map 
    QVector<Shape*> shapes;
};

#endif // CANVAS_HPP