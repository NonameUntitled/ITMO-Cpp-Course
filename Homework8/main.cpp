#include <iostream>

#include "FirstTask/Unit/Unit.h"
#include "FirstTask/ManBearPig/ManBearPig.h"

using namespace std;

int Unit::counter = 0;

// Second task: begin
typedef int firstArgument;

typedef int (*secondArgument)(double);

typedef int *(*returnValue)(char const *);

typedef returnValue (*complexFunction)(firstArgument, secondArgument);
// Second task: end

// Third task: begin
template<typename T1, typename T2>
bool compare(T1 const &first, T1 const &second, T2(T1::*somefunc)() const) {
    return (*first.someFunc)() < (*second.someFunc)();
}
// Third task: end

// Fourth task: begin
template<typename T>
bool isSameObject(T const *p, T const *q) {
    return dynamic_cast<void const *>(p) == dynamic_cast<void const *>(q);
}
// Fourth task: end

int main() {
    ManBearPig someBadExperiment = ManBearPig(100, 10, 250, 1.5, "???", "Noname_Untitled");
    std::cout << "Type: " << someBadExperiment.getType() << " Name: " << someBadExperiment.getName() << std::endl;
    return 0;
}