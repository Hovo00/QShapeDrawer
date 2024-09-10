#ifndef PARSER_HPP
#define PARSER_HPP

#include <QString>
#include <QPointF>

#include "src/shapes/Shape.hpp"

class Parser {
public:
    static ShapeInfo parseCommand(const QString& command);
private:
    static QPointF parsePoint(const QString& point);
    static QString parseName(const QString& token);
    static QVector<QString> tokenizeCommand(const QString& command);
private:
    static ShapeInfo parseLine(const QVector<QString>& tokens);
    static ShapeInfo parseTriangle(const QVector<QString>& tokens);
    static ShapeInfo parseRectangle(const QVector<QString>& tokens);
    static ShapeInfo parseSquare(const QVector<QString>& tokens);
    static ShapeInfo parseConnect(const QVector<QString>& tokens);
private:
    static bool isAllowedInCoordinates(QChar ch);
};

#endif // PARSER_HPP