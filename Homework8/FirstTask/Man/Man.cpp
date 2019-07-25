#include <utility>

#include "Man.h"

Man::Man(size_t health, size_t armor, size_t damage, long double multiplier, std::string name)
        : Unit(health, armor, damage, multiplier, "Man"), mName(std::move(name)) {
    std::cout << "Man was created!" << std::endl;
}

std::string Man::getName() const {
    return mName;
}

void Man::fightWith(Unit &enemy) {
    std::cout << "TODO: " << getType() << " with name " << getName() << " fights with representation of type: "
              << enemy.getType() << std::endl;
}

