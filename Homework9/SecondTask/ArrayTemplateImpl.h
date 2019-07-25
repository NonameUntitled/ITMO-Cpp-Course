#ifndef HOMEWORK9_ARRAYTEMPLATEIMPL_H
#define HOMEWORK9_ARRAYTEMPLATEIMPL_H

template<typename T>
Array<T>::Array(size_t size) : mSize(size), mData(new T[mSize]) {
    for (size_t i = 0; i < mSize; ++i) {
        mData[i] = T();
    }
}

template<typename T>
Array<T>::Array(Array const &other) : mSize(other.size()), mData(new T[mSize]) {
    for (size_t i = 0; i < mSize; ++i) {
        mData[i] = other[i];
    }
}

template<typename T>
Array<T>::Array(Array &&other) noexcept: mSize(other.size()), mData(other.data()) {
    other.setSize(0);
    other.nullData();
}

template<typename T>
Array<T>::~Array() {
    mSize = 0;

    if (!mData) {
        delete[] mData;
    }

    mData = nullptr;
}

template<typename T>
size_t Array<T>::size() const {
    return mSize;
}

template<typename T>
T *Array<T>::data() const {
    return mData;
}

template<typename T>
void Array<T>::setSize(size_t newSize) {
    mSize = newSize;
}

template<typename T>
void Array<T>::nullData() {
    mData = nullptr;
}

template<typename T>
Array<T> &Array<T>::operator=(Array const &other) {

    if (this != &other) {
        mSize = other.size();
        other.setSize(0);

        mData = other.data();
        other.nullData();
    }

    return *this;
}

template<typename T>
Array<T> &Array<T>::operator=(Array &&other) noexcept {

    mSize = other.size();
    mData = other.data();

    other.setSize(0);
    other.nullData();

    return *this;
}

template<typename T>
T const &Array<T>::operator[](size_t index) const {
    return mData[index];
}

template<typename T>
T &Array<T>::operator[](size_t index) {
    return mData[index];
}

#endif
