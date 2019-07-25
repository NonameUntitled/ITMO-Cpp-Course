#ifndef HOMEWORK8_BEAR_H
#define HOMEWORK8_BEAR_H


#include "../Animal/Animal.h"

class Bear : public virtual Animal {
public:
    Bear(size_t, size_t, size_t, long double, std::string);

    ~Bear() = default;

    void fightWith(Unit &) override;
};


#endif
