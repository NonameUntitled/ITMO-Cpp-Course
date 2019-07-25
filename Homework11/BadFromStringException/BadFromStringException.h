#pragma once

#include <stdexcept>

class BadFromStringException : public std::invalid_argument {
public:
    BadFromStringException();

    explicit BadFromStringException(const char *) noexcept;

    explicit BadFromStringException(const std::string &) noexcept;

    BadFromStringException(const BadFromStringException &) noexcept;
};