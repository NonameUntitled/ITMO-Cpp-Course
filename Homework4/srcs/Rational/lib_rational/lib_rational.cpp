#include <iostream>

#include "lib_rational.h"

RealNumber::RealNumber(long long numerator, long long denominator, bool isPositive) :
        mNumerator(numerator),
        mDenominator(denominator),
        mIsPositive(isPositive) {

    if (mDenominator == 0) {
        mDenominator = 1;
    }

    if (!mIsPositive && mNumerator == 0) {
        mIsPositive = true;
    }

    shorten();
}

void RealNumber::shorten() {
    long long greatestCommonDivider = gcd(mNumerator, mDenominator);

    mNumerator /= greatestCommonDivider;
    mDenominator /= greatestCommonDivider;
}

long long RealNumber::getNumerator() const {
    return mNumerator;
}

long long RealNumber::getDenominator() const {
    return mDenominator;
}

bool RealNumber::getSign() const {
    return mIsPositive;
}

void RealNumber::show() const {
    if (!mIsPositive) {
        std::cout << '-';
    }
    std::cout << mNumerator << "/" << mDenominator << std::endl;
}

RealNumber RealNumber::operator+(RealNumber const &other) const {
    long long newNumerator = mNumerator * other.getDenominator();
    long long newDenominator = mDenominator * other.getDenominator();
    bool newSign = true;

    if (!mIsPositive && !other.getSign()) {
        newNumerator += other.getNumerator() * mDenominator;
        newSign = false;
    } else if (!mIsPositive) {
        newNumerator *= -1;
        newNumerator += other.getNumerator() * mDenominator;

        if (newNumerator < 0) {
            newSign = !newSign;
            newNumerator *= -1;
        }
    } else if (!other.getSign()) {
        newNumerator -= other.getNumerator() * mDenominator;

        if (newNumerator < 0) {
            newSign = !newSign;
            newNumerator *= -1;
        }
    } else {
        newNumerator += other.getNumerator() * mDenominator;
    }

    return RealNumber(newNumerator, newDenominator, newSign);
}

RealNumber RealNumber::operator-(RealNumber const &other) const {
    long long newNumerator = mNumerator * other.getDenominator();
    long long newDenominator = mDenominator * other.getDenominator();
    bool newSign = true;

    if (!mIsPositive && !other.getSign()) {
        newNumerator = other.getNumerator() * mDenominator - newNumerator;
        if (newNumerator < 0) {
            newSign = !newSign;
            newNumerator *= -1;
        }
    } else if (!mIsPositive) {
        newNumerator *= -1;
        newNumerator -= other.getNumerator() * mDenominator;

        if (newNumerator < 0) {
            newSign = !newSign;
            newNumerator *= -1;
        }
    } else if (!other.getSign()) {
        newNumerator += other.getNumerator() * mDenominator;
    } else {
        newNumerator -= other.getNumerator() * mDenominator;

        if (newNumerator < 0) {
            newSign = !newSign;
            newNumerator *= -1;
        }
    }

    return RealNumber(newNumerator, newDenominator, newSign);
}

RealNumber RealNumber::operator*(RealNumber const &other) const {
    long long newNumerator = mNumerator * other.getNumerator();
    long long newDenominator = mDenominator * other.getDenominator();
    bool newSign = !(mIsPositive ^ other.getSign());

    return RealNumber(newNumerator, newDenominator, newSign);
}

RealNumber RealNumber::operator/(RealNumber const &other) const {
    long long newNumerator = mNumerator * other.getDenominator();
    long long newDenominator = mDenominator * other.getNumerator();
    bool newSign = !(mIsPositive ^ other.getSign());

    return RealNumber(newNumerator, newDenominator, newSign);
}

bool RealNumber::operator<(RealNumber const &other) const {
    if (mIsPositive && !other.getSign()) {
        return false;
    } else if (other.getSign() && !mIsPositive) {
        return true;
    } else if (mIsPositive && other.getSign()) {
        unsigned long long first = mNumerator * other.getDenominator();
        unsigned long long second = mDenominator * other.getNumerator();

        return (first < second);
    } else {
        unsigned long long first = mNumerator * other.getDenominator();
        unsigned long long second = mDenominator * other.getNumerator();

        return (first > second);
    }
}

bool RealNumber::operator>(RealNumber const &other) const {
    return other < *this;
}

bool RealNumber::operator==(RealNumber const &other) const {
    return !(*this < other && *this > other);
}

bool RealNumber::operator!=(RealNumber const &other) const {
    return *this < other || *this > other;
}

long long RealNumber::gcd(long long a, long long b) const {
    if (b > a) {
        long long tmp = a;
        a = b;
        b = tmp;
    }
    if (b != 0) {
        return gcd(b, a % b);
    } else {
        return a;
    }
}