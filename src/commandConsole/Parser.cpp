#include "Parser.hpp"

ShapeInfo Parser::parseCommand(const QString& command) {
    QStringList tokens = command.split(' ');

    if (tokens[0] == "create_line") {
        return parseLine(tokens);
    } else if (tokens[0] == "create_triangle") {
        return parseTriangle(tokens);
    } else if (tokens[0] == "create_rectangle") {
        return parseRectangle(tokens);
    }
    // else if (tokens[0] == "create_square") {
    //     return parseSquare(tokens);
    // }
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

ShapeInfo Parser::parseLine(const QStringList& tokens) {
    qDebug() << " tokens ";
    for (auto & str : tokens) {
        qDebug() << str;
    }
    QString name = tokens[2];
    QPointF coord1 = parsePoint(tokens[4]);
    QPointF coord2 = parsePoint(tokens[6]);
    return {"line", name, QVector<QPointF>{coord1, coord2}};
}

ShapeInfo Parser::parseTriangle(const QStringList& tokens) {
    QString name = tokens[2];
    QPointF coord1 = parsePoint(tokens[4]);
    QPointF coord2 = parsePoint(tokens[6]);
    QPointF coord3 = parsePoint(tokens[8]);
    return {"triangle", name, QVector<QPointF>{coord1, coord2, coord3}};
}

ShapeInfo Parser::parseRectangle(const QStringList& tokens) {
    QString name = tokens[2];
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

// Square* Parser::parseSquare(const QStringList& tokens) {
//     QString name = tokens[2];
//     QPointF coord1 = parsePoint(tokens[4]);
//     QPointF coord2 = parsePoint(tokens[6]);
//     if (tokens.size() > 7) {
//         QPointF coord3 = parsePoint(tokens[8]);
//         QPointF coord4 = parsePoint(tokens[10]);
//         return new Square(name, coord1, coord2, coord3, coord4);
//     } else {
//         return new Square(name, coord1, coord2);
//     }
// }