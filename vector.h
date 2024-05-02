#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>
#include <new>

/**
 * @brief Namespace containing classes for vector implementation.
 */
namespace Vector {

/**
 * @brief The vector class implements a dynamic array.
 * @tparam T The type of elements in the vector.
 */
template <class T>
class vector {
private:
    int size_v; /**< Number of elements inside the vector. */
    T *elem; /**< Pointer to the elements (or nullptr). */
    int space; /**< Number of elements plus number of free slots. */

public:
    /**
     * @brief Default constructor for the vector class.
     */
    vector(): size_v{0}, elem{nullptr}, space{0} {}

    /**
     * @brief Constructor for the vector class with specified size.
     * @param s The size of the vector.
     */
    explicit vector(int s): size_v{0}, elem{new T[s]}, space{s} {
        for (int i = 0; i < space; ++i)
            elem[i] = T(); // Elements are initialized
    }

    // Additional constructors, destructor, and operators...

    /**
     * @brief Destructor for the vector class.
     */
    ~vector() {
        delete [] elem; // Destructor
    }

    // Methods for accessing and modifying elements...

    /**
     * @brief Returns the size of the vector.
     * @return The size of the vector.
     */
    int size() const {
        return size_v;
    }

    /**
     * @brief Returns the capacity of the vector.
     * @return The capacity of the vector.
     */
    int capacity() const {
        return space;
    }

    // Additional methods...

    /**
     * @brief Resizes the vector to a new size.
     * @param newsize The new size.
     */
    void resize(int newsize) {
        reserve(newsize);
        for (int i = 0; i < newsize; ++i) {
            elem[i] = T(); // Initialize new elements
        }
        size_v = newsize;
    }

    // Additional methods...
};

} // namespace Vector

#endif // VECTOR_H
