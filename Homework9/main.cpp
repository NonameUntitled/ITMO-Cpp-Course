#include <iostream>
#include <tuple>

#include "SecondTask/Array.h"

using namespace std;

// First task: begin
template<typename T>
void printValues(T const &elem) {
    cout << typeid(elem).name() << ": " << elem << endl;
}

template<typename T, typename... Args>
void printValues(T const &head, Args... tail) {
    cout << typeid(head).name() << ": " << head << endl;
    printValues(tail...);
}
// First task: end

// Third task: begin
template<size_t N1, size_t N2, typename ...Args>
auto toPair(std::tuple<Args...> const &tuple) -> decltype(std::make_pair(get<N1>(tuple), get<N2>(tuple))) {
    return std::make_pair(get<N1>(tuple), get<N2>(tuple));
}
// Third task: end

int main() {
    auto t = std::make_tuple(0, 3.5, "Hello");
    std::pair<double, char const *> p = toPair<1, 2>(t);
    cout << p.first << endl << p.second << endl;
    return 0;
}