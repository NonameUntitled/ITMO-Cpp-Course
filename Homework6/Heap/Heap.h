#pragma once

class Heap {
public:
    explicit Heap(const std::vector<int> &);

    ~Heap() = default;

    void showHeap() const;

    std::vector<int> getHeap() const;

    Heap &operator=(Heap const &);

    Heap operator+(int);

    Heap &operator+=(int);

    Heap operator-(int);

    Heap &operator-=(int);

    Heap operator*(int);

    Heap &operator*=(int);

    Heap operator/(int);

    Heap &operator/=(int);

    Heap operator%(int);

    Heap &operator%=(int);

    bool operator==(Heap const &) const;

    bool operator!=(Heap const &) const;

    bool operator>(Heap const &) const;

    bool operator>=(Heap const &) const;

    bool operator<(Heap const &) const;

    bool operator<=(Heap const &) const;

    bool operator&&(Heap const &) const;

    bool operator&(Heap const &) const;

    bool operator||(Heap const &) const;

    bool operator|(Heap const &) const;

    Heap operator<<(Heap const &);

    Heap &operator<<=(Heap const &);

    Heap operator>>(Heap &) const;

    Heap &operator>>=(Heap &);

    Heap operator^(Heap const &);

    Heap &operator^=(Heap const &);

    Heap &operator!();

    Heap &operator~();

    Heap operator++();

    Heap operator++(int);

    Heap operator--();

    Heap operator--(int);

    Heap &operator+();

    Heap &operator-();

    Heap operator,(Heap const &other);

    int operator[](int) const;

    std::vector<int> operator()(int) const;

    explicit operator int();

private:
    std::vector<int> mHeap;

    void siftUp(size_t, std::vector<int> &);

    void siftDown(int, std::vector<int> &);
};