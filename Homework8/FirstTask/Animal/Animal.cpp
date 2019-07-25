#include <utility>

#include "Animal.h"

Animal::Animal(size_t health, size_t armor, size_t damage, long double mult, std::string type, std::string roar)
        : Unit(health, armor, damage, mult, std::move(type)), mBattleRoar(std::move(roar)) {
    std::cout << "Animal was created!" << std::endl;
}

std::string Animal::getBattleRoar() const {
    return mBattleRoar;
}