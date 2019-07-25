#ifndef HOMEWORK8_MAN_H
#define HOMEWORK8_MAN_H


#include "../Unit/Unit.h"

class Man : public virtual Unit {
public:
    Man(size_t, size_t, size_t, long double, std::string);

    ~Man() = default;

    std::string getName() const;

    void fightWith(Unit &) override;

private:
    std::string mName;
};


#endif