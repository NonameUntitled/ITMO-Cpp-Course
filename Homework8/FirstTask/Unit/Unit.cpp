#include <utility>

#include "Unit.h"

Unit::Unit(size_t health, size_t armor, size_t damage, long double mult, std::string type)
        : mHealth(health), mArmor(armor), mDamage(damage), mMult(mult), mType(std::move(type)) {
    std::cout << "Unit number " << ++counter << " was created" << std::endl;
}

size_t Unit::getUnitsCount() const {
    return counter;
}

std::string Unit::getType() const {
    return mType;
}