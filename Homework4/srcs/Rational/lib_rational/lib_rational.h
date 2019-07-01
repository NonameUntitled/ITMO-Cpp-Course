#pragma once

class RealNumber {
public:
    explicit RealNumber(long long, long long, bool);

    ~RealNumber() = default;

    void shorten();

    long long getNumerator() const;

    long long getDenominator() const;

    bool getSign() const;

    void show() const;

    RealNumber operator+(RealNumber const &) const;

    RealNumber operator-(RealNumber const &) const;

    RealNumber operator*(RealNumber const &) const;

    RealNumber operator/(RealNumber const &) const;

    bool operator<(RealNumber const &) const;

    bool operator>(RealNumber const &) const;

    bool operator==(RealNumber const &) const;

    bool operator!=(RealNumber const &) const;

private:
    long long mNumerator;
    long long mDenominator;
    bool mIsPositive;

    long long gcd(long long, long long) const;
};
