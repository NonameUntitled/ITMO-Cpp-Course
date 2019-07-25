#include <iostream>
#include <vector>

#include "Heap/Heap.h"

using namespace std;

int main() {
    vector<int> ar;
    ar.reserve(8);

    for (size_t i = 0; i < 8; i++) {
        ar.push_back(i);
    }

    Heap a = Heap(ar);

    a += 10;

    a.showHeap();

    cout << '\n' << static_cast<int>(a);
}
