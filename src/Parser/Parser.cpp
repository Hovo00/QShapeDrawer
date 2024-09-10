#include "Parser.hpp"

#include "src/Shapes/Shape.hpp"
#include "src/Parser/CustomExceptions/ParserExceptions.hpp"

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
    auto tokens = tokenizeCommand(command);
    if (tokens[0] == "connect") {
        return parseConnect(tokens);
    }
    else if (tokens[0] == "create_line") {
        return parseLine(tokens);
    }
    else if (tokens[0] == "create_square") {
        return parseSquare(tokens);
    }
    else if (tokens[0] == "create_triangle") {
        return parseTriangle(tokens);
    } else if (tokens[0] == "create_rectangle") {
        return parseRectangle(tokens);
    }
    else {
        throw UnknownFlag(tokens[0].toStdString());
    }
}

QPointF Parser::parsePoint(const QString& point) {
    QString cleanedPoint = point.simplified(); // Remove extra spaces and newline characters
    QString xCoord = "";
    QString yCoord = "";
    bool commaEncountered = false;
    int commaCount = 0;
    int braceCount = 0;

    if (cleanedPoint.isEmpty() || cleanedPoint[0] != '{' || cleanedPoint[cleanedPoint.size() - 1] != '}') {
        throw SyntaxError("Coordinates should start with '{' and end with '}' : " + cleanedPoint.toStdString());
    }

    for (int i = 0; i < cleanedPoint.length(); ++i) {
        QChar ch = cleanedPoint[i];
        if (!isAllowedInCoordinates(ch)) {
            throw SyntaxError("Invalid character in coordinates: " + cleanedPoint.toStdString());
        }
        if (ch == '{' || ch == '}') {
            braceCount++;
            if (braceCount > 2) {
                throw SyntaxError("Multiple braces in coordinates: " + cleanedPoint.toStdString());
            }
            continue;
        }
        if (ch == ',') {
            commaCount++;
            if (commaCount > 1) {
                throw SyntaxError("Multiple commas in coordinates");
            }
            commaEncountered = true;
            continue;
        }
        if (!commaEncountered) {
            xCoord += ch;
        } else {
            yCoord += ch;
        }
    }

    if (xCoord.isEmpty() || yCoord.isEmpty()) {
        throw SyntaxError("Coordinates are incomplete : " + cleanedPoint.toStdString());
    }

    return QPointF(xCoord.toDouble(), yCoord.toDouble());
}

bool Parser::isAllowedInCoordinates(QChar ch) {
    return ch.isDigit() || ch == '.' || ch == ',' || ch == '{' || ch == '}';
}

QString Parser::parseName(const QString& token) {
    QString cleanedToken = token.simplified(); // Remove extra spaces and newline characters
    QString name = "";
    bool insideBraces = false;

    for (int i = 0; i < cleanedToken.length(); ++i) {
        if (cleanedToken[i] == '{') {
            insideBraces = true;
            continue;
        }
        if (cleanedToken[i] == '}') {
            break;
        }
        if (insideBraces) {
            name += cleanedToken[i];
        }
    }

    if (name.isEmpty()) {
        throw SyntaxError("Shape name can't be empty : " + cleanedToken.toStdString() + " <---");
    }

    return name;
}

ShapeInfo Parser::parseLine(const QVector<QString>& tokens) {
    if (tokens.size() < 7) {
        throw IncompleteCommand((tokens[tokens.size() - 1]).toStdString());
    }
    if (tokens[1] != "-name" || tokens[3] != "-coord_1" || tokens[5] != "-coord_2") {
        throw SyntaxError("Invalid syntax for '-' flags , should be '-name', '-coord{1-2}'");
    }

    QString name = parseName(tokens[2]);
    QPointF coord1 = parsePoint(tokens[4]);
    QPointF coord2 = parsePoint(tokens[6]);
    return {"line", name, QVector<QPointF>{coord1, coord2}};
}

ShapeInfo Parser::parseTriangle(const QVector<QString>& tokens) {
    if (tokens.size() < 9) {
        throw IncompleteCommand((tokens[tokens.size() - 1]).toStdString());
    }
    if (tokens[1] != "-name" || tokens[3] != "-coord_1" || tokens[5] != "-coord_2" || tokens[7] != "coord_3") {
        throw SyntaxError("Invalid syntax for '-' flags , should be '-name', '-coord{1-3}'");
    }
    QString name = parseName(tokens[2]);
    QPointF coord1 = parsePoint(tokens[4]);
    QPointF coord2 = parsePoint(tokens[6]);
    QPointF coord3 = parsePoint(tokens[8]);
    return {"triangle", name, QVector<QPointF>{coord1, coord2, coord3}};
}

ShapeInfo Parser::parseRectangle(const QVector<QString>& tokens) {
    if (tokens.size() < 7) {
        throw IncompleteCommand((tokens[tokens.size() - 1]).toStdString());
    }
    if (tokens[1] != "-name" || tokens[3] != "-coord_1" || tokens[5] != "-coord_2") {
        throw SyntaxError("Invalid syntax for '-' flags , should be '-name', '-coord{1-2}'");
    }

    QString name = parseName(tokens[2]);
    QPointF coord1 = parsePoint(tokens[4]);
    QPointF coord2 = parsePoint(tokens[6]);
    if (tokens.size() > 7) {
        if (tokens[7] != "-coord_3" || tokens[9] != "-coord_4") {
            throw SyntaxError("Invalid syntax for '-' flags , should be '-name'. '-coord{1-4}'");
        }
        QPointF coord3 = parsePoint(tokens[8]);
        QPointF coord4 = parsePoint(tokens[10]);
        return {"rectangle", name, QVector<QPointF>{coord1, coord2, coord3, coord4}};
    } else {
        return {"rectangle", name, QVector<QPointF>{coord1, coord2}};
    }
}

ShapeInfo Parser::parseSquare(const QVector<QString>& tokens) {
    if (tokens.size() < 7) {
        throw IncompleteCommand((tokens[tokens.size() - 1]).toStdString());
    }
    if (tokens[1] != "-name" || tokens[3] != "-coord_1" || tokens[5] != "-coord_2") {
        throw SyntaxError("Invalid syntax for '-' flags , should be '-name', '-coord{1-2}'");
    }

    QString name = parseName(tokens[2]);
    QPointF coord1 = parsePoint(tokens[4]);
    QPointF coord2 = parsePoint(tokens[6]);
    if (tokens.size() > 7) {
        if (tokens[7] != "-coord_3" || tokens[9] != "-coord_4") {
            throw SyntaxError("Invalid syntax for '-' flags , should be '-name'. '-coord{1-4}'");
        }
        QPointF coord3 = parsePoint(tokens[8]);
        QPointF coord4 = parsePoint(tokens[10]);
        return {"square", name, QVector<QPointF>{coord1, coord2, coord3, coord4}};
    } else {
        return {"square", name, QVector<QPointF>{coord1, coord2}};
    }
}

ShapeInfo Parser::parseConnect(const QVector<QString>& tokens) {
    if (tokens[1] != "-object_name_1" || tokens[3] != "-object_name_2") {
        throw SyntaxError("Invalid syntax for '-' flags , should be 'object_name_{1-2}'");
    }
    QString objectName1 = parseName(tokens[2]);
    QString objectName2 = parseName(tokens[4]);
    QString name = objectName1 + " " + objectName2;
    return {"connect", name};
}
