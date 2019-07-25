#ifndef HOMEWORK8_ANIMAL_H
#define HOMEWORK8_ANIMAL_H


#include "../Unit/Unit.h"

class Animal : public virtual Unit {
public:
    Animal(size_t, size_t, size_t, long double, std::string, std::string);

    ~Animal() = default;

    std::string getBattleRoar() const;

private:
    std::string mBattleRoar;
};


#endif
