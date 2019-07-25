#ifndef HOMEWORK8_MANBEARPIG_H
#define HOMEWORK8_MANBEARPIG_H

#include "../Man/Man.h"
#include "../Bear/Bear.h"
#include "../Pig/Pig.h"

class ManBearPig : public Man, Bear, Pig {
public:
    ManBearPig(size_t, size_t, size_t, long double, const std::string&, std::string);

    ~ManBearPig() = default;

    void fightWith(Unit &) override;
};


#endif
