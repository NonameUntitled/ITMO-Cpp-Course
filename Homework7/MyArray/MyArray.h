#pragma once

#include <iostream>

template<class T>
class MyArray {
public:
    MyArray();

    explicit MyArray(size_t size, const T &value = T());

    MyArray(const MyArray &other);

    virtual ~MyArray();

    MyArray &operator=(const MyArray &other);

    size_t size() const;

    T &operator[](size_t index);

    const T &operator[](size_t index) const;

private:
    size_t mSize{};
    T *mData;
};

#include "MyArrayImpl.h"