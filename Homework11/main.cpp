#include <iostream>
#include <sstream>

#include "BadFromStringException/BadFromStringException.h"

using namespace std;

template<class T>
T toString(const string &someString) {
    istringstream is(someString);
    T value;
    is >> std::noskipws >> value;
    if (!is.eof()) {
        ostringstream os;
        os << "Error: " << '\'' << someString << '\'' << " is incorrect string to convert" << '\n';
        throw BadFromStringException(os.str());
    }
    return value;
}

int main() {
    try {
        cout << toString<double>("123.3") << endl;
    } catch (BadFromStringException &exception) {
        cout << exception.what() << endl;
    }

    return 0;
}
