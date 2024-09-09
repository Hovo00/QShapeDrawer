#ifndef PARSEREXCEPTIONS_HPP
#define PARSEREXCEPTIONS_HPP

#include <exception>
#include <QString>

class SyntaxError : public std::exception {
public:
    const char* what() const noexcept override;
};

class UnknownCommand : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif // PARSEREXCEPTIONS_HPP