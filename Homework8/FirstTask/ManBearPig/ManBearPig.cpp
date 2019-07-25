#include <utility>

#include "ManBearPig.h"

ManBearPig::ManBearPig(size_t health, size_t armor, size_t damage, long double mult, const std::string &roar, std::string name)
        : Unit(health, armor, damage, mult, "ManBearPig"), Animal(health, armor, damage, mult, "ManBearPig", roar),
          Man(health, armor, damage, mult, std::move(name)), Bear(health, armor, damage, mult, roar),
          Pig(health, armor, damage, mult, roar) {

    std::cout << "ManBearPig was created!" << std::endl;
}

void ManBearPig::fightWith(Unit &enemy) {
    std::cout << "TODO: Some strange things happened!!!" << std::endl;
}
