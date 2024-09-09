#include "ParserExceptions.hpp"

const char* SyntaxError::what() const noexcept {
    return errorMessage.data();
}

SyntaxError::SyntaxError(const std::string& message) : errorMessage(message) {}

const char* UnknownFlag::what() const noexcept {
    auto message = "'" + errorMessage + "' flag is not defined";
    errorMessage = message;
    return errorMessage.data();
}

UnknownFlag::UnknownFlag(const std::string& message) : errorMessage(message) {}

IncompleteCommand::IncompleteCommand(const std::string& message) : errorMessage(message) {}

const char* IncompleteCommand::what() const noexcept {
    auto mes = errorMessage;
    errorMessage = "Incomplete command , expected token after '" + errorMessage;
    errorMessage += "' <--";
    return errorMessage.data();
}