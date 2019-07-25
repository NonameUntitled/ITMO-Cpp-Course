#include "Pig.h"

Pig::Pig(size_t health, size_t armor, size_t damage, long double mult, std::string) :
        Unit(health, armor, damage, mult, "Pig"), Animal(health, armor, damage, mult, "Pig", "RRR???") {
    std::cout << "Pig was created!" << std::endl;
}

void Pig::fightWith(Unit &enemy) {
    std::cout << "TODO: " << getType() << " with roar: " << getBattleRoar() << " do something with a representation of "
              << enemy.getType() << std::endl;
}