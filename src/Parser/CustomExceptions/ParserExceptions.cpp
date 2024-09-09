#include "ParserExceptions.hpp"

const char* SyntaxError::what() const noexcept {
    return "Syntax Error";
}

const char* UnknownCommand::what() const noexcept {
    return "Unknown Command";
}