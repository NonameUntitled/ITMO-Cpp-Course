#pragma once

class Polynomial
{
    public:
        explicit Polynomial(const std::vector<RealNumber>&);

        ~Polynomial() = default;

        RealNumber computeWithValue(RealNumber const &) const;

    private:
        std::vector<RealNumber> mCoefficients;
};
