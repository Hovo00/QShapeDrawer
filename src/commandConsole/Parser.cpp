#include "Parser.hpp"

QVector<QString> Parser::tokenizeCommand(const QString& command) {
    QVector<QString> tokens;
    QString currentToken = "";
    for (int i = 0; i < command.length(); ++i) {
        if (command[i] != ' ') {
            currentToken += command[i];
        } else {
            if (!currentToken.isEmpty()) {
                tokens.push_back(currentToken);
                currentToken = "";
            }
        }
    }
    // Add the last token if it's not empty
    if (!currentToken.isEmpty()) {
        tokens.push_back(currentToken);
    }
    return tokens;
}

ShapeInfo Parser::parseCommand(const QString& command) {
    qDebug() << "command " << command;
    auto tokens = tokenizeCommand(command);
    qDebug() << "tokens" << tokens;
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
    QString xCoord = "";
    QString yCoord = "";
    bool commaEncountered = false;
    for (int i = 0; i < point.length(); ++i) {
        if (point[i] == '{' || point[i] == '}' || point[i] == ' ') {
            continue;
        }
        if (point[i] == ',') {
            commaEncountered = true;
            continue;
        }
        if (!commaEncountered) {
            xCoord += point[i];
        } else {
            yCoord += point[i];
        }
    }
    return QPointF(xCoord.toDouble(), yCoord.toDouble());
}

QString Parser::parseName(const QString& token) {
    QString name = "";
    bool insideBraces = false;
    for (int i = 0; i < token.length(); ++i) {
        if (token[i] == ' ') {
            continue;
        }
        if (token[i] == '{') {
            insideBraces = true;
            continue;
        }
        if (token[i] == '}') {
            break;
        }
        if (insideBraces) {
            name += token[i];
        }
    }
    return name;
}

ShapeInfo Parser::parseLine(const QVector<QString>& tokens) {
    QString name = parseName(tokens[2]);
    QPointF coord1 = parsePoint(tokens[4]);
    QPointF coord2 = parsePoint(tokens[6]);
    return {"line", name, QVector<QPointF>{coord1, coord2}};
}

ShapeInfo Parser::parseTriangle(const QVector<QString>& tokens) {
    QString name = parseName(tokens[2]);
    QPointF coord1 = parsePoint(tokens[4]);
    QPointF coord2 = parsePoint(tokens[6]);
    QPointF coord3 = parsePoint(tokens[8]);
    return {"triangle", name, QVector<QPointF>{coord1, coord2, coord3}};
}

ShapeInfo Parser::parseRectangle(const QVector<QString>& tokens) {
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

ShapeInfo Parser::parseSquare(const QVector<QString>& tokens) {
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

ShapeInfo Parser::parseConnect(const QVector<QString>& tokens) {
    QString objectName1 = parseName(tokens[2]);
    QString objectName2 = parseName(tokens[4]);
    QString name = objectName1 + " " + objectName2;
    return {"connect", name};
}
