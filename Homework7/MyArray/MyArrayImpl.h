template<class T>
MyArray<T>::MyArray() : mSize(0), mData(nullptr) {}

template<class T>
MyArray<T>::MyArray(size_t size, const T &value) : mSize(size) {
    mData = static_cast<T *>(operator new[](mSize * sizeof(T)));

    for (size_t i = 0; i < mSize; ++i) {
        new(mData + i) T(value);
    }
}

template<class T>
MyArray<T>::MyArray(const MyArray &other) : mSize(other.size()) {
    mData = static_cast<T *>(operator new[](mSize * sizeof(T)));

    for (size_t i = 0; i < mSize; ++i) {
        new(mData + i) T(other[i]);
    }
}

template<class T>
MyArray<T>::~MyArray() {
    if (mData != nullptr) {
        for (size_t i = 0; i < mSize; ++i) {
            mData[i].~T();
        }
        delete[] (char *) mData;
    }
    mSize = 0;
}

template<class T>
MyArray<T> &MyArray<T>::operator=(const MyArray &other) {
    if (this != &other) {
        for (size_t i = 0; i < mSize; ++i) {
            mData[i].~T();
        }
        delete[] (char *) mData;

        mSize = other.size();
        mData = static_cast<T *>(operator new[](mSize * sizeof(T)));
        for (size_t i = 0; i < mSize; ++i) {
            new(mData + i) T(other[i]);
        }
    }

    return *this;
}

template<class T>
size_t MyArray<T>::size() const {
    return mSize;
}

template<class T>
T &MyArray<T>::operator[](size_t index) {
    return mData[index];
}

template<class T>
const T &MyArray<T>::operator[](size_t index) const {
    return mData[index];
}