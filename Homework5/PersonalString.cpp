#include <iostream>
#include <string>
#include <cstring>

#include "PersonalString.h"

PersonalString::PersonalString() : PersonalString((char *) "") {}

PersonalString::PersonalString(char *newString) {
    mSize = 0;

    while (newString[mSize] != '\0') {
        ++mSize;
    }

    mString = new char[mSize + 1];
    strcpy(mString, newString);
    mString[mSize] = '\0';
}

PersonalString::PersonalString(char stringSymbol, int newSize) : mSize(newSize) {
    mString = new char[mSize + 1];

    std::fill(mString, mString + mSize, stringSymbol);
    mString[mSize] = '\0';
}

PersonalString::PersonalString(const PersonalString &otherString) : mSize(otherString.getSize()) {
    mString = new char[mSize + 1];
    strcpy(mString, otherString.getCStyleString());
    mString[mSize] = '\0';
}

int PersonalString::getSize() const {
    return mSize;
}

char *PersonalString::getCStyleString() const {
    return mString;
}

PersonalString &PersonalString::append(char *additionString) {
    int additionSize = 0;
    while (additionString[additionSize] != '\0') {
        ++additionSize;
    }

    int initialSize = mSize;
    char *initialString = new char[mSize + 1];
    strcpy(initialString, mString);

    mSize = 0;
    delete[] mString;

    mSize = initialSize + additionSize;
    mString = new char[mSize + 1];
    strcpy(mString, initialString);
    strcat(mString, additionString);
    mString[mSize] = '\0';

    delete[] initialString;

    return *this;
}

PersonalString &PersonalString::append(const PersonalString &other) {
    int additionSize = other.getSize();
    char *additionString = new char[additionSize + 1];
    strcpy(additionString, other.getCStyleString());

    int initialSize = mSize;
    char *initialString = new char[initialSize + 1];
    strcpy(initialString, mString);

    mSize = 0;
    delete[] mString;

    mSize = initialSize + additionSize;
    mString = new char[mSize + 1];
    strcpy(mString, initialString);
    strcat(mString, additionString);
    mString[mSize] = '\0';

    delete[] initialString;
    delete[] additionString;

    return *this;
}

PersonalString::~PersonalString() {
    delete[] mString;
    mSize = 0;
}

PersonalString &PersonalString::operator=(const PersonalString &other) {

    if (this != &other) {
        mSize = 0;
        delete[] mString;

        mSize = other.getSize();
        mString = new char[mSize + 1];
        strcpy(mString, other.getCStyleString());
        mString[mSize] = '\0';
    }

    return *this;
}

std::ostream &operator<<(std::ostream &os, const PersonalString &personalString) {
    os << "Data: " << personalString.getCStyleString() << " Size: " << personalString.getSize();

    return os;
}


