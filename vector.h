#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept> // Include <stdexcept> for std::out_of_range
#include <algorithm> // For std::copy, std::move, std::fill

using namespace std;

template<typename T>
class Vector {
public:
    // Constructors
    Vector(); // Default constructor
    explicit Vector(size_t size); // Constructor with initial size
    Vector(size_t size, const T& value); // Constructor with initial size and value
    Vector(const Vector<T>& other); // Copy constructor
    Vector(Vector<T>&& other) noexcept; // Move constructor

    // Destructor
    ~Vector();

    // Copy assignment operator
    Vector<T>& operator=(const Vector<T>& other);

    // Move assignment operator
    Vector<T>& operator=(Vector<T>&& other) noexcept;

    // Iterator
    typedef T* iterator;

    // Member functions
    iterator begin() const;
    iterator end() const;
    size_t size() const;
    void push_back(const T& value);
    void pop_back();
    void clear();
    T& at(size_t index);
    const T& at(size_t index) const;

private:
    T* m_data; // Pointer to dynamically allocated array
    size_t m_capacity; // Current capacity of the vector
    size_t m_size; // Number of elements in the vector

    // Helper function for deep copy
    void copy(const Vector<T>& other);
};

#endif // VECTOR_H
