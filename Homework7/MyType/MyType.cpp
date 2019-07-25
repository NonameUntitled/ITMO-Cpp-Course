#include "MyType.h"

MyType::MyType(int value) : mField(value) {}

MyType::MyType(const MyType &other) {
    mField = other.getValue();
}

int MyType::getValue() const {
    return mField;
}
