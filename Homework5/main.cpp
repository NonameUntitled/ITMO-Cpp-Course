#include <iostream>

#include "PersonalString.h"

using namespace std;

int main() {
    PersonalString personalString1 = PersonalString((char *) "Hello ");
    PersonalString personalString2 = PersonalString((char *) "world!");
    PersonalString personalString3 = PersonalString('s', 25);

    cout << personalString1 << endl;
    cout << personalString2 << endl;
    cout << personalString3 << endl;

    personalString1.append(personalString2);
    personalString1.append((char *)" Noname Untitled!!!");

    PersonalString personalString = PersonalString((char *)"Hello ");
    personalString.append(personalString);

    cout << personalString << endl;

    personalString = personalString1;

    cout << personalString << endl;
}
