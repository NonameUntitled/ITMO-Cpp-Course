#include <iostream>
#include <vector>

#include "lib_rational.h"
#include "rational_poly.h"

using namespace std;

int main() {
    RealNumber coefsArray[4] = {
            RealNumber(1, 1, true),
            RealNumber(1, 1, false),
            RealNumber(1, 1, true),
            RealNumber(1, 1, false)
    };

    vector<RealNumber> coefs;
    coefs.reserve(4);

    for (const auto &i : coefsArray) {
        coefs.push_back(i);
    }

    Polynomial poly(coefs);

    RealNumber firstNumber = poly.computeWithValue(RealNumber(5, 5, true));

    return ((firstNumber == RealNumber(0, 0, false)) ? 0 : 1);
}
