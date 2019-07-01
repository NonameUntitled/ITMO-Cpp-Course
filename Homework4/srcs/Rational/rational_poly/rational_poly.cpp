#include <vector>

#include "lib_rational.h"
#include "rational_poly.h"

Polynomial::Polynomial(const std::vector<RealNumber> &polynomial) : mCoefficients(polynomial) {}

RealNumber Polynomial::computeWithValue(RealNumber const &value) const {
    RealNumber answer = mCoefficients.back();

    for (size_t i = 1; i < mCoefficients.size(); i++) {
        answer = answer * value + mCoefficients[mCoefficients.size() - 1 - i];
    }
    return answer;
}
