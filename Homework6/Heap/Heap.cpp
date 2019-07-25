#include <iostream>
#include <vector>

#include "Heap.h"

Heap::Heap(const std::vector<int> &elements) : mHeap(elements) {
    for (int i = (int) mHeap.size() / 2 - 1; i >= 0; i--) {
        siftDown(i, mHeap);
    }
}

void Heap::showHeap() const {
    for (int i : mHeap) {
        std::cout << i << ' ';
    }

    std::cout << '\n';
}

std::vector<int> Heap::getHeap() const {
    return mHeap;
}

Heap &Heap::operator=(Heap const &other) {
    if (this != &other) {
        mHeap = other.getHeap();
    }

    return *this;
}

Heap Heap::operator+(int newElement) {
    std::vector<int> newHeap = mHeap;

    newHeap.push_back(newElement);
    siftUp(newHeap.size() - 1, newHeap);

    return Heap(newHeap);
}

Heap &Heap::operator+=(int newElement) {
    mHeap.push_back(newElement);
    siftUp(mHeap.size() - 1, mHeap);

    return *this;
}

Heap Heap::operator-(int element) {
    std::vector<int> newHeap = mHeap;

    for (size_t i = 0; i < newHeap.size(); i++) {
        if (newHeap[i] == element) {
            newHeap[i] = newHeap.back();
            newHeap.pop_back();
            siftDown(i, newHeap);
            break;
        }
    }

    return Heap(newHeap);
}

Heap &Heap::operator-=(int element) {
    for (size_t i = 0; i < mHeap.size(); i++) {
        if (mHeap[i] == element) {
            mHeap[i] = mHeap.back();
            mHeap.pop_back();
            siftDown(i, mHeap);
            break;
        }
    }

    return *this;
}

Heap Heap::operator*(int times) {
    std::vector<int> newHeap;

    for (int i = 0; i < times; i++) {
        for (size_t j = 0; j < mHeap.size(); i++) {
            newHeap.push_back(mHeap[i]);
            siftUp(newHeap.size() - 1, newHeap);
        }
    }

    return Heap(newHeap);
}

Heap &Heap::operator*=(int times) {
    std::vector<int> oldHeap = mHeap;

    for (size_t i = 1; i < times; i++) {
        for (size_t j = 0; j < oldHeap.size(); j++) {
            mHeap.push_back(oldHeap[i]);
            siftUp(mHeap.size() - 1, mHeap);
        }
    }

    return *this;
}

Heap Heap::operator/(int times) {
    size_t newSize = mHeap.size() / times;
    std::vector<int> tmpHeap = mHeap;
    std::vector<int> newHeap;

    for (size_t i = 0; i < newSize; i++) {
        newHeap.push_back(tmpHeap[0]);
        tmpHeap[0] = tmpHeap.back();
        tmpHeap.pop_back();
        siftDown(0, tmpHeap);
    }

    return Heap(newHeap);
}

Heap &Heap::operator/=(int times) {
    if (mHeap.empty()) {
        return *this;
    }

    size_t newSize = mHeap.size() / times;
    std::vector<int> oldHeap = mHeap;
    mHeap.clear();

    for (size_t i = 0; i < newSize; i++) {
        mHeap.push_back(oldHeap[0]);
        oldHeap[0] = oldHeap.back();
        oldHeap.pop_back();
        siftDown(0, mHeap);
    }

    return *this;
}

Heap Heap::operator%(int times) {
    size_t newSize = mHeap.size() % times;
    std::vector<int> tmpHeap = mHeap;
    std::vector<int> newHeap;

    for (size_t i = 0; i < newSize; i++) {
        newHeap.push_back(tmpHeap[0]);
        tmpHeap[0] = tmpHeap.back();
        tmpHeap.pop_back();
        siftDown(0, tmpHeap);
    }

    return Heap(newHeap);
}

Heap &Heap::operator%=(int times) {
    if (mHeap.empty()) {
        return *this;
    }

    size_t newSize = mHeap.size() % times;
    std::vector<int> oldHeap = mHeap;
    mHeap.clear();

    for (size_t i = 0; i < newSize; i++) {
        mHeap.push_back(oldHeap[0]);
        oldHeap[0] = oldHeap.back();
        oldHeap.pop_back();
        siftDown(0, mHeap);
    }

    return *this;
}

Heap Heap::operator,(Heap const &other) {
    return other;
}

bool Heap::operator==(Heap const &other) const {
    if (mHeap.empty() || other.getHeap().empty()) {
        return false;
    }

    return mHeap[0] == other.getHeap()[0];
}

bool Heap::operator!=(Heap const &other) const {
    if (mHeap.empty() || other.getHeap().empty()) {
        return true;
    }
    return mHeap[0] != other.getHeap()[0];
}

bool Heap::operator>(Heap const &other) const {
    if (mHeap.empty() || other.getHeap().empty()) {
        return false;
    }

    return mHeap[0] > other.getHeap()[0];
}

bool Heap::operator>=(Heap const &other) const {
    if (mHeap.empty() || other.getHeap().empty()) {
        return false;
    }

    return mHeap[0] >= other.getHeap()[0];
}

bool Heap::operator<(Heap const &other) const {
    if (mHeap.empty() || other.getHeap().empty()) {
        return false;
    }

    return mHeap[0] < other.getHeap()[0];
}

bool Heap::operator<=(Heap const &other) const {
    if (mHeap.empty() || other.getHeap().empty()) {
        return false;
    }

    return mHeap[0] <= other.getHeap()[0];
}

bool Heap::operator&&(Heap const &other) const {
    return !mHeap.empty() && !other.getHeap().empty();
}

bool Heap::operator&(Heap const &other) const {
    return mHeap.size() & other.getHeap().size();
}

bool Heap::operator||(Heap const &other) const {
    return !mHeap.empty() || !other.getHeap().empty();
}

bool Heap::operator|(Heap const &other) const {
    return mHeap.size() | other.getHeap().size();
}

Heap Heap::operator<<(Heap const &other) {
    std::vector<int> otherHeap = other.getHeap();
    std::vector<int> newHeap = mHeap;

    for (size_t i = 0; i < otherHeap.size(); i++) {
        newHeap.push_back(otherHeap.back());
        siftUp(newHeap.size() - 1, newHeap);
        otherHeap.pop_back();
    }

    return Heap(newHeap);
}

Heap &Heap::operator<<=(Heap const &other) {
    std::vector<int> otherHeap = other.getHeap();

    for (size_t i = 0; i < otherHeap.size(); i++) {
        mHeap.push_back(otherHeap.back());
        siftUp(mHeap.size() - 1, mHeap);
        otherHeap.pop_back();
    }

    return *this;
}

Heap Heap::operator>>(Heap &other) const {
    return (other << *this);
}

Heap &Heap::operator>>=(Heap &other) {
    other <<= *this;

    std::vector<int> newHeap(0);
    mHeap = newHeap;

    return *this;
}

Heap &Heap::operator!() {
    if (!mHeap.empty()) {
        mHeap[0] = mHeap.back();
        mHeap.pop_back();
    }

    return *this;
}

Heap Heap::operator++() {
    Heap tmp(mHeap);

    mHeap.push_back(0);
    siftUp(mHeap.size() - 1, mHeap);

    return tmp;
}

Heap Heap::operator++(int) {
    mHeap.push_back(0);
    siftUp(mHeap.size() - 1, mHeap);

    return *this;
}

Heap Heap::operator--() {
    Heap tmp(mHeap);

    if (!mHeap.empty()) {
        mHeap.pop_back();
    }

    return tmp;
}

Heap Heap::operator--(int) {
    mHeap.pop_back();

    return *this;
}

Heap &Heap::operator+() {
    return *this;
}

Heap &Heap::operator-() {
    if (!mHeap.empty()) {
        mHeap.pop_back();
    }

    return *this;
}

Heap &Heap::operator~() {
    std::vector<int> tmpHeap;
    tmpHeap.push_back(mHeap.front());
    mHeap = tmpHeap;

    return *this;
}

Heap Heap::operator^(Heap const &other) {
    std::vector<int> tmpHeap = mHeap;
    tmpHeap.push_back(other.getHeap().front());
    siftUp(tmpHeap.size() - 1, tmpHeap);

    return Heap(tmpHeap);
}

Heap &Heap::operator^=(Heap const &other) {
    mHeap.push_back(other.getHeap().front());
    siftUp(mHeap.size() - 1, mHeap);

    return *this;
}

int Heap::operator[](int index) const {
    if (index < mHeap.size())
        return mHeap[index];

    return 0;
}

std::vector<int> Heap::operator()(int amount) const {
    std::vector<int> res;

    if (amount < mHeap.size())
        for (int i = 0; i <= amount; i++) {
            res.push_back(mHeap[i]);
        }

    return res;
}

Heap::operator int() {
    return mHeap[0];
}

void Heap::siftDown(int index, std::vector<int> &heap) {
    if (2 * index + 1 < heap.size()) {
        int firstElem = heap[2 * index + 1];

        if (2 * index + 2 < heap.size()) {
            int secondElem = heap[2 * index + 2];

            if (firstElem > secondElem) {
                if (firstElem > heap[index]) {
                    int tmp = heap[index];
                    heap[index] = heap[2 * index + 1];
                    heap[2 * index + 1] = tmp;

                    siftDown(2 * index + 1, heap);
                }
            } else {
                if (secondElem > heap[index]) {
                    int tmp = heap[index];
                    heap[index] = heap[2 * index + 2];
                    heap[2 * index + 2] = tmp;

                    siftDown(2 * index + 2, heap);
                }
            }
        } else {
            if (firstElem > heap[index]) {
                int tmp = heap[index];
                heap[index] = heap[2 * index + 1];
                heap[2 * index + 1] = tmp;

                siftDown(2 * index + 1, heap);
            }
        }
    }
}

void Heap::siftUp(size_t index, std::vector<int> &heap) {
    if (index == 0) {
        return;
    }

    size_t parentIndex = (index - 1) / 2;

    if (heap[parentIndex] < heap[index]) {
        int tmp = heap[index];
        heap[index] = heap[parentIndex];
        heap[parentIndex] = tmp;

        siftUp(parentIndex, heap);
    }
}
