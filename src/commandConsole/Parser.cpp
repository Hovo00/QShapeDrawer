#include "Parser.hpp"

ShapeInfo Parser::parseCommand(const QString& command) {
    qDebug() << "command:" << command;
    QStringList tokens = command.split(' ');
    qDebug() << "Tokens:" << tokens;
    if (tokens[0] == "create_line") {
        return parseLine(tokens);
    } else if (tokens[0] == "create_triangle") {
        return parseTriangle(tokens);
    } else if (tokens[0] == "create_rectangle") {
        return parseRectangle(tokens);
    }
    else if (tokens[0] == "create_square") {
        return parseSquare(tokens);
    }
    else if (tokens[0] == "connect") {
        return parseConnect(tokens);
    }
    else {
        return ShapeInfo();
    }
}

QPointF Parser::parsePoint(const QString& point) {
    QString cleaned = point.mid(1, point.size() - 2);  // Remove the braces
    QStringList coords = cleaned.split(',');
    // qDebug() << "toDouble" << coords[0].trimmed().toDouble();
    // qDebug() << "trimmed" << coords[0].trimmed();
    return QPointF(coords[0].trimmed().toDouble(), coords[1].trimmed().toDouble());
}
QString Parser::parseName(const QString& token) {
    QString cleaned = token.mid(1, token.size() - 2);  // Remove the braces
    return cleaned;
}

ShapeInfo Parser::parseLine(const QStringList& tokens) {
    QString name = parseName(tokens[2]);
    QPointF coord1 = parsePoint(tokens[4]);
    QPointF coord2 = parsePoint(tokens[6]);
    return {"line", name, QVector<QPointF>{coord1, coord2}};
}

ShapeInfo Parser::parseTriangle(const QStringList& tokens) {
    QString name = parseName(tokens[2]);
    QPointF coord1 = parsePoint(tokens[4]);
    QPointF coord2 = parsePoint(tokens[6]);
    QPointF coord3 = parsePoint(tokens[8]);
    return {"triangle", name, QVector<QPointF>{coord1, coord2, coord3}};
}

ShapeInfo Parser::parseRectangle(const QStringList& tokens) {
    QString name = parseName(tokens[2]);
    QPointF coord1 = parsePoint(tokens[4]);
    QPointF coord2 = parsePoint(tokens[6]);
    if (tokens.size() > 7) {
        QPointF coord3 = parsePoint(tokens[8]);
        QPointF coord4 = parsePoint(tokens[10]);
        return {"rectangle", name, QVector<QPointF>{coord1, coord2, coord3, coord4}};
    } else {
        return {"rectangle", name, QVector<QPointF>{coord1, coord2}};
    }
}

ShapeInfo Parser::parseSquare(const QStringList& tokens) {
    QString name = parseName(tokens[2]);
    QPointF coord1 = parsePoint(tokens[4]);
    QPointF coord2 = parsePoint(tokens[6]);
    if (tokens.size() > 7) {
        QPointF coord3 = parsePoint(tokens[8]);
        QPointF coord4 = parsePoint(tokens[10]);
        return {"square", name, QVector<QPointF>{coord1, coord2, coord3, coord4}};
    } else {
        return {"square", name, QVector<QPointF>{coord1, coord2}};
    }
}

ShapeInfo Parser::parseConnect(const QStringList& tokens) {
    QString objectName1 = parseName(tokens[2]);
    QString objectName2 = parseName(tokens[4]);
    QString name = objectName1 + " " + objectName2;
    return {"connect", name};
}
