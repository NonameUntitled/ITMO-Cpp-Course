#ifndef HOMEWORK9_ARRAY_H
#define HOMEWORK9_ARRAY_H

#include <iostream>

template<typename T>
class Array {
public:
    explicit Array(size_t size = 0);

    Array(Array const &);

    Array(Array &&) noexcept;

    ~Array();

    size_t size() const;

    T *data() const;

    void setSize(size_t);

    void nullData();

    Array<T> &operator=(Array const &);

    Array<T> &operator=(Array &&) noexcept;

    T const &operator[](size_t) const;

    T &operator[](size_t);

private:
    size_t mSize;
    T *mData;
};

#include "ArrayTemplateImpl.h"

#endif
