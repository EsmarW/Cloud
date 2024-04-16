#include "vector.h"
#include <algorithm> // For std::copy, std::move, std::fill

template<typename T>
Vector<T>::Vector() : m_data(nullptr), m_capacity(0), m_size(0) {}

template<typename T>
Vector<T>::Vector(size_t size) : m_capacity(size), m_size(size) {
    m_data = new T[size]();
}

template<typename T>
Vector<T>::Vector(size_t size, const T& value) : m_capacity(size), m_size(size) {
    m_data = new T[size];
    std::fill(m_data, m_data + size, value);
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) {
    copy(other);
}

template<typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept {
    m_data = other.m_data;
    m_capacity = other.m_capacity;
    m_size = other.m_size;

    other.m_data = nullptr;
    other.m_capacity = 0;
    other.m_size = 0;
}

template<typename T>
Vector<T>::~Vector() {
    delete[] m_data;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        delete[] m_data;
        copy(other);
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept {
    if (this != &other) {
        delete[] m_data;
        m_data = other.m_data;
        m_capacity = other.m_capacity;
        m_size = other.m_size;

        other.m_data = nullptr;
        other.m_capacity = 0;
        other.m_size = 0;
    }
    return *this;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin() const {
    return m_data;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end() const {
    return m_data + m_size;
}

template<typename T>
size_t Vector<T>::size() const {
    return m_size;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (m_size >= m_capacity) {
        size_t new_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
        T* new_data = new T[new_capacity];
        std::copy(m_data, m_data + m_size, new_data);
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
    m_data[m_size++] = value;
}

template<typename T>
void Vector<T>::pop_back() {
    if (m_size > 0) {
        --m_size;
    }
}

template<typename T>
void Vector<T>::clear() {
    m_size = 0;
}

template<typename T>
T& Vector<T>::at(size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template<typename T>
const T& Vector<T>::at(size_t index) const {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template<typename T>
void Vector<T>::copy(const Vector<T>& other) {
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_data = new T[m_capacity];
    std::copy(other.m_data, other.m_data + other.m_size, m_data);
}

// Explicit instantiation of Vector class templates for specific types
template class Vector<int>;
template class Vector<double>;
// Add more instantiations as needed for custom types
