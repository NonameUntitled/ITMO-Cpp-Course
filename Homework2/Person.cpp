//
// Created by Noname Untitled on 10.09.18.
//

#include <iostream>
#include <string>

#include "Person.h"

Person::Person() : Person("Noname", "Untitled") {}

Person::Person(const std::string &newName) : Person(newName, "Untitled") {}

Person::Person(const std::string &newName, const std::string &newSurname) : mName(newName), mSurName(newSurname) {}

std::string Person::getName() const {
    return mName;
}

std::string Person::getSurName() const {
    return mSurName;
}
