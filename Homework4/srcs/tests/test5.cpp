#include <iostream>
#include <vector>

#include "lib_rational.h"
#include "rational_poly.h"

using namespace std;

int main() {
    vector<RealNumber> coefs;
    coefs.reserve(5);

    for (int i = 0; i < 5; i++) {
        coefs.emplace_back(i, i, true);
    }

    Polynomial poly(coefs);

    RealNumber firstNumber = poly.computeWithValue(RealNumber(7, 1, true));

    RealNumber secondNumber = poly.computeWithValue(RealNumber(6, 1, false));

    return ((firstNumber > secondNumber) ? 0 : 1);
}
