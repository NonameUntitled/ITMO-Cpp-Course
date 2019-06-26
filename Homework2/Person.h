//
// Created by Noname Untitled on 10.09.18.
//

#pragma once

class Person {
public:
    Person();

    Person(const std::string&);

    Person(const std::string&, const std::string&);

    std::string getName() const;

    std::string getSurName() const;

private:
    const std::string mName;
    const std::string mSurName;
};
