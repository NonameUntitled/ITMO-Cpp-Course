#include <iostream>
#include <vector>

#include "lib_rational.h"
#include "rational_poly.h"

using namespace std;

int main() {
    vector<RealNumber> coefs;
    coefs.reserve(5);

    for (int i = 0; i < 5; i++) {
        coefs.emplace_back((i % 2 == 0 ? i + 1 : 0), i + 1, true);
    }

    Polynomial poly(coefs);

    RealNumber firstNumber = poly.computeWithValue(RealNumber(1, 1, true));

    RealNumber secondNumber = poly.computeWithValue(RealNumber(1, 1, false));

    return ((firstNumber == secondNumber) ? 0 : 1);
}
