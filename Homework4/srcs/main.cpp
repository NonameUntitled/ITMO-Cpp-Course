#include <iostream>
#include <vector>

#include "lib_rational.h"
#include "rational_poly.h"

using namespace std;

int main() {
    vector<RealNumber> myPolynomial;

    myPolynomial.reserve(5);
    for (size_t i = 0; i < 5; ++i) {
        myPolynomial.emplace_back(i + 1, i + 1, true);
    }

    Polynomial poly(myPolynomial);
    poly.computeWithValue(RealNumber(5, 5, true)).show();

    return 0;
}
