#pragma once

class PersonalString {
public:
    explicit PersonalString();

    explicit PersonalString(char *);

    explicit PersonalString(char, int);

    PersonalString(const PersonalString &);

    ~PersonalString();


    int getSize() const;

    char *getCStyleString() const;


    PersonalString &append(const PersonalString &);

    PersonalString &append(char *);

    PersonalString &operator=(const PersonalString &);

private:
    int mSize;
    char *mString;
};

std::ostream &operator<<(std::ostream &os, const PersonalString &personalString);



