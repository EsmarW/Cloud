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

    /**
     * @brief Copy constructor for the vector class.
     * @param myObject The vector to copy.
     */
    vector(const vector &myObject): size_v{myObject.size_v}, elem{new T[myObject.size_v]}, space{myObject.space} {
        std::copy(myObject.elem, myObject.elem + size_v, elem); // Copy elements
    }

    /**
     * @brief Move constructor for the vector class.
     * @param myObject The vector to move.
     */
    vector(vector &&myObject): size_v{0}, elem{nullptr}, space{myObject.space} {
        elem = myObject.elem;
        size_v = myObject.size_v;
        myObject.elem = nullptr;
        myObject.size_v = 0;
    }

    /**
     * @brief Copy assignment operator for the vector class.
     * @param myObject The vector to copy.
     * @return A reference to the copied vector.
     */
    vector &operator=(const vector &myObject) {
        T *p = new T[myObject.size_v];
        std::copy(myObject.elem, myObject.elem + myObject.size_v, p);
        delete[] elem;
        elem = p;
        size_v = myObject.size_v;
        return *this;
    }

    /**
     * @brief Move assignment operator for the vector class.
     * @param myObject The vector to move.
     * @return A reference to the moved vector.
     */
    vector &operator=(vector &&myObject) {
        if (this != &myObject) {
            delete[] elem;
            elem = myObject.elem;
            size_v = myObject.size_v;
            myObject.elem = nullptr;
            myObject.size_v = 0;
        }
        return *this;
    }

    /**
     * @brief Destructor for the vector class.
     */
    ~vector() {
        delete [] elem;
    }

    /**
     * @brief Access operator for accessing elements in the vector.
     * @param n The index of the element.
     * @return A reference to the element at the specified index.
     */
    T &operator[](int n) {
        return elem[n];
    }

    /**
     * @brief Const access operator for accessing elements in the vector.
     * @param n The index of the element.
     * @return A const reference to the element at the specified index.
     */
    const T &operator[](int n) const {
        return elem[n];
    }

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

    /**
     * @brief Adds an element to the end of the vector.
     * @param obj The element to add.
     */
    void push_back(const T &obj) {
        if (space == 0)
            reserve(8);
        else if (size_v == space)
            reserve(2 * space);
        elem[size_v] = obj;
        ++size_v;
    }

    /**
     * @brief Reserves space for the vector.
     * @param new_size The new size to reserve.
     */
    void reserve(int new_size) {
        try {
            T *p = new T[new_size];
            std::copy(elem, elem + size_v, p);
            delete[] elem;
            elem = p;
            space = new_size;
        }
        catch (std::bad_alloc& ba) {
            std::cerr << "bad_alloc caught: " << ba.what() << '\n';
        }
    }

    /**
     * @brief Iterator for iterating over elements in the vector.
     */
    using iterator = T *;

    /**
     * @brief Const iterator for iterating over elements in the vector.
     */
    using const_iterator = const T *;

    /**
     * @brief Returns an iterator to the beginning of the vector.
     * @return An iterator to the beginning of the vector.
     */
    iterator begin() {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    /**
     * @brief Returns a const iterator to the beginning of the vector.
     * @return A const iterator to the beginning of the vector.
     */
    const_iterator begin() const {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    /**
     * @brief Returns an iterator to the end of the vector.
     * @return An iterator to the end of the vector.
     */
    iterator end() {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    /**
     * @brief Returns a const iterator to the end of the vector.
     * @return A const iterator to the end of the vector.
     */
    const_iterator end() const {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    /**
     * @brief Inserts an element at the specified position in the vector.
     * @param p The position to insert the element.
     * @param myObject The element to insert.
     * @return An iterator to the inserted element.
     */
    iterator insert(iterator p, const T &myObject) {
        if (size_v == space) {
            reserve(2 * space);
        }
        if (p > end()) {
            std::cerr << "Invalid Position, Must be in Range" << std::endl;
            std::cerr << "Inserting the object in the end." << std::endl;
            elem[size_v] = myObject;
            ++size_v;
            return &elem[size_v];
        }
        std::copy(p, elem + size_v, p + 1);
        *p = myObject;
        ++size_v;
        return p;
    }

    /**
     * @brief Erases the element at the specified position from the vector.
     * @param p The position of the element to erase.
     * @return An iterator to the element after the erased element.
     */
    iterator erase(iterator p) {
        if (p == end()) {
            return p;
        }
        for (iterator i = p + 1; i != end(); ++i) {
            *(i - 1) = *i;
        }
        --size_v;
        return p;
    }

    /**
     * @brief Finds the lowest element in a range.
     * @param first The beginning of the range.
     * @param last The end of the range.
     * @return An iterator to the lowest element.
     */
    T low(T first, T last) {
        T low = first;
        for (T p = first; p != last; ++p) {
            if (*low > *p) {
                low = p;
                return low;
            }
        }
    }

    /**
     * @brief Sorts elements in a range using selection sort algorithm.
     * @param first The beginning of the range.
     * @param last The end of the range.
     */
    void selection_sort(T first, T last) {
        int n = last - first;
        for (int x = 0; x < n; x++) {
            int index_of_min = x;
            for (int y = x; y < n; y++) {
                if (*(first + index_of_min) > *(first + y)) {
                    index_of_min = y;
                }
            }
            auto temp = *(first + x);
            *(first + x) = *(first + index_of_min);
            *(first + index_of_min) = temp;
        }
    }

    /**
     * @brief Prints the elements of the vector.
     */
    void print_vector() {
        for (int i = 0; i < this->size(); i++) {
            std::cout << elem[i] << "\t";
        }
        std::cout << std::endl;
    }
};

} // namespace Vector

#endif // VECTOR_H
