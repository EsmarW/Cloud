#include "vector.h"

template<class T>
vector<T>::vector() : size_v{0}, elem{nullptr}, space{0} {}

template<class T>
vector<T>::vector(int s) : size_v{s}, elem{new T[s]}, space{s} {}

template<class T>
vector<T>::vector(const vector<T>& other) : size_v{other.size_v}, elem{new T[other.size_v]}, space{other.size_v} {
    std::copy(other.elem, other.elem + other.size_v, elem);
}

template<class T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
    if (this != &other) {
        delete[] elem;
        size_v = other.size_v;
        elem = new T[size_v];
        std::copy(other.elem, other.elem + other.size_v, elem);
        space = size_v;
    }
    return *this;
}

template<class T>
vector<T>::vector(vector<T>&& other) noexcept : size_v{other.size_v}, elem{other.elem}, space{other.space} {
    other.size_v = 0;
    other.elem = nullptr;
    other.space = 0;
}

template<class T>
vector<T>& vector<T>::operator=(vector<T>&& other) noexcept {
    if (this != &other) {
        delete[] elem;
        size_v = other.size_v;
        elem = other.elem;
        space = other.space;
        other.size_v = 0;
        other.elem = nullptr;
        other.space = 0;
    }
    return *this;
}

template<class T>
vector<T>::~vector() {
    delete[] elem;
}

template<class T>
T& vector<T>::operator[](int n) {
    return elem[n];
}

template<class T>
const T& vector<T>::operator[](int n) const {
    return elem[n];
}

template<class T>
int vector<T>::size() const {
    return size_v;
}

template<class T>
int vector<T>::capacity() const {
    return space;
}

template<class T>
void vector<T>::resize(int newsize) {
    reserve(newsize);
    for (int i = size_v; i < newsize; ++i) elem[i] = T();
    size_v = newsize;
}

template<class T>
void vector<T>::reserve(int newalloc) {
    if (newalloc <= space) return;
    T* p = new T[newalloc];
    for (int i = 0; i < size_v; ++i) p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = newalloc;
}

template<class T>
void vector<T>::push_back(T val) {
    if (space == 0) reserve(8);
    else if (size_v == space) reserve(2 * space);
    elem[size_v] = val;
    ++size_v;
}

template<class T>
typename vector<T>::iterator vector<T>::begin() {
    return elem;
}

template<class T>
typename vector<T>::const_iterator vector<T>::begin() const {
    return elem;
}

template<class T>
typename vector<T>::iterator vector<T>::end() {
    return elem + size_v;
}

template<class T>
typename vector<T>::const_iterator vector<T>::end() const {
    return elem + size_v;
}

template<class T>
typename vector<T>::iterator vector<T>::insert(iterator p, const T& v) {
    int index = p - begin();
    if (size_v == space) reserve(2 * space);
    iterator pp = begin() + index;
    for (iterator pos = end(); pos != pp; --pos) *pos = *(pos - 1);
    *(begin() + index) = v;
    ++size_v;
    return begin() + index;
}

template<class T>
typename vector<T>::iterator vector<T>::erase(iterator p) {
    if (p == end()) return p;
    for (iterator pos = p + 1; pos != end(); ++pos) *(pos - 1) = *pos;
    --size_v;
    return p;
}

//Add template types you plan on using
template class vector<int>;
