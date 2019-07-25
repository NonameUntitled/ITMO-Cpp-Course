#ifndef HOMEWORK8_UNIT_H
#define HOMEWORK8_UNIT_H

#include <iostream>

class Unit {
public:
    Unit(size_t, size_t, size_t, long double, std::string);

    ~Unit() = default;

    size_t getUnitsCount() const;

    std::string getType() const;

    virtual void fightWith(Unit&) = 0;
private:
    static int counter;

    size_t mHealth;
    size_t mArmor;
    size_t mDamage;

    long double mMult;

    std::string mType;
};


#endif
