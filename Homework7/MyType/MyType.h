#pragma once

class MyType {
public:
    MyType() = delete;

    explicit MyType(int);

    MyType(const MyType&);

    ~MyType() = default;

    MyType& operator=(const MyType&) = delete;

    int getValue() const;

private:
    int mField;
};