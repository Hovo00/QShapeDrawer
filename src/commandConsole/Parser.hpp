#ifndef PARSER_HPP
#define PARSER_HPP

#include <QString>
#include <QDebug>

#include <QStringList>
#include <QPointF>
#include "src/shapes/shape.hpp"

class Parser {
public:
    ShapeInfo parseCommand(const QString& command);
private:
    QPointF parsePoint(const QString& point);
    QString parseName(const QString& token);
private:
    ShapeInfo parseLine(const QStringList& tokens);
    ShapeInfo parseTriangle(const QStringList& tokens);
    ShapeInfo parseRectangle(const QStringList& tokens);
    ShapeInfo parseSquare(const QStringList& tokens);
    ShapeInfo parseConnect(const QStringList& tokens);
};

#endif // PARSER_HPP