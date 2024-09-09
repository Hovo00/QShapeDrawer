#ifndef PARSEREXCEPTIONS_HPP
#define PARSEREXCEPTIONS_HPP

#include <exception>
#include <string>

class SyntaxError : public std::exception {
public:
    SyntaxError(const std::string& message);
    const char* what() const noexcept override;

private:
    mutable std::string errorMessage;
};

class UnknownFlag : public std::exception {
public:
    UnknownFlag(const std::string& message);
    const char* what() const noexcept override;

private:
    mutable std::string errorMessage;
};

class IncompleteCommand : public std::exception {
public:
    IncompleteCommand(const std::string& message);
    const char* what() const noexcept override;

private:
    mutable std::string errorMessage;
};

#endif // PARSEREXCEPTIONS_HPP