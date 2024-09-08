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
    QVector<QString> tokenizeCommand(const QString& command);
private:
    ShapeInfo parseLine(const QVector<QString>& tokens);
    ShapeInfo parseTriangle(const QVector<QString>& tokens);
    ShapeInfo parseRectangle(const QVector<QString>& tokens);
    ShapeInfo parseSquare(const QVector<QString>& tokens);
    ShapeInfo parseConnect(const QVector<QString>& tokens);
};

#endif // PARSER_HPP