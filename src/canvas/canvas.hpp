#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QWidget>
#include <QHash>

#include "src/Shapes/Shape.hpp"

class Canvas : public QWidget {
    Q_OBJECT
public:
    Canvas();
    ~Canvas();
public:
    QSize sizeHint() const override;
public slots:
    void addShape(const ShapeInfo &info);
    void paintEvent(QPaintEvent *event) override;
signals:
    void drawSuccess();
    void outOfCanvas(const QString& name);
    void shapeNotFound(const QString& name);
    void dublicateNameFound(const QString& previousDefinedName, const QString& shapeName);
private:
    bool isWithinCanvas(const ShapeInfo &info);
    Shape* findShape(const QString& shapeName);
    void connectShapes(const QString& shapeName1, const QString& shapeName2);
private:
    QHash<QString, Shape*> shapes;
};

#endif // CANVAS_HPP