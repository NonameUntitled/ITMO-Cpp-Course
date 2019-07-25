#ifndef HOMEWORK8_PIG_H
#define HOMEWORK8_PIG_H


#include "../Animal/Animal.h"

class Pig : public virtual Animal {
public:
    Pig(size_t, size_t, size_t, long double, std::string);

    ~Pig() = default;

    void fightWith(Unit &) override;
};


#endif
