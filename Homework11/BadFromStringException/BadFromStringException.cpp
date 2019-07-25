#include "BadFromStringException.h"

BadFromStringException::BadFromStringException() : invalid_argument("Unknown reason") {}

BadFromStringException::BadFromStringException(const char *message) noexcept : invalid_argument(message) {}

BadFromStringException::BadFromStringException(const std::string &message) noexcept : invalid_argument(message) {}

BadFromStringException::BadFromStringException(const BadFromStringException &other) noexcept : invalid_argument(
        other.what()) {}
