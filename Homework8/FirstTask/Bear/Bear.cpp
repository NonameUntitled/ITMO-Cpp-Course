#include "Bear.h"

Bear::Bear(size_t health, size_t armor, size_t damage, long double mult, std::string) :
        Unit(health, armor, damage, mult, "Bear"), Animal(health, armor, damage, mult, "Bear", "RRR???") {
    std::cout << "Bear was created!" << std::endl;
}

void Bear::fightWith(Unit &enemy) {
    std::cout << "TODO: " << getType() << " with roar: " << getBattleRoar() << " do something with a representation of "
              << enemy.getType() << std::endl;
}