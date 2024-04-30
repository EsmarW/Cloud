#ifndef VECTOR_H
#define VECTOR_H


#include <iostream>
#include <algorithm>
#include <new>

namespace Vector{

template <class T>
class vector
{
private:

    int size_v;   /*< Number of the elemments inside the vector*/
    T *elem;      /*< pointer to the elements (or 0)*/
    int space;    /*< number of elements plus number of free slots*/

public:

    vector(): size_v{0}, elem{nullptr}, space{0} {

    }

    explicit vector(int s): size_v{0}, elem{new T[s]}, space{s}
    {
        for (int i = 0; i < space; ++i)
            elem[i] = T(); // elements are initialized
    }

    vector(const vector &myObject): size_v{myObject.size_v}, elem{new T[myObject.size_v]}, space{myObject.space} // copy constructo
    {
        std::copy(myObject.elem, myObject.elem + size_v, elem); // copy elements - std::copy() algorithm
    }

    vector(vector &&myObject): size_v{0}, elem{nullptr}, space{myObject.space}
    {
        elem = myObject.elem;
        size_v = myObject.size_v;
        myObject.elem = nullptr;
        myObject.size_v = 0;
    }

    vector &operator=(const vector &myObject)
    {


        T *p = new T[myObject.size_v];
        std::copy(myObject.elem, myObject.elem + myObject.size_v, p);
        delete[] elem;
        elem = p;
        size_v = myObject.size_v;
        return *this;   // return a self-reference
    }

    vector &operator=(vector &&myObject)
    {

        if(this != &myObject)
        {
            delete[] elem;
            elem = myObject.elem;
            size_v = myObject.size_v;
            myObject.elem = nullptr;
            myObject.size_v = 0;
        }
        return *this;
    }

    ~vector()
    {
        delete [] elem; // destructor
    }


    T &operator[](int n)

    {

        return elem[n]; // access: return reference
    }


    const T &operator[](int n) const
    {
        return elem[n];
    }


    int size() const
    {

        return size_v;
    }



    int capacity() const
    {
        return space;
    }

    void resize(int newsize)

    {
        reserve(newsize);
        for (int i = 0; i < newsize; ++i)
        {
            elem[i] = T(); // initialize new elements
        }
        size_v = newsize;
    }

    void push_back(const T &obj)
    {
        if (space == 0)         //For the First time, it will reserve 8 elements
            reserve(8);
        else if (size_v == space) // if all spaces have filled up,
            reserve(2 * space);   // then will reserve twice the current spaces
        elem[size_v] = obj;   // assgining the object to the next index
        ++size_v;                 // Incrementing the Index
    }

    void reserve(int new_size)
    {
        try{
            T *p = new T[new_size];             // Create the new pointer array of the same type
            std::copy(elem, elem + size_v, p);       //Copy the same vector in the new array with new capacity.
            delete[] elem;                      //Delete the content of the previous elements
            elem = p;                           //Assigning the elements to the Originial array
            space = new_size;

        }
        catch (std::bad_alloc& ba)
        {
            std::cerr << "bad_alloc caught: " << ba.what() << '\n';
        }
    }


    using iterator = T *; // defining iterator to be T *
    using const_iterator = const T *; // defining iterator to be const T *


    iterator begin()
    {
        if (size_v == 0)        // If the vector is empty
            return nullptr;     // return a pointer 0, since no elements exist
        return &elem[0];        // Return the address of the first element
    }

    const_iterator begin() const
    {
        if (size_v == 0)        // If the vector is empty
            return nullptr;     // return a pointer 0, since no elements exist
        return &elem[0];        // Return the address of the first element
    }

    iterator end()
    {

        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    const_iterator end() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    iterator insert(iterator p, const T &myObject)
    {

        if (size_v == space){ //If completely filled up capacity,
            // will need to allocate more space.
            reserve(2 * space);}
        if (p > end())
        {
            std::cerr << "Invalid Position, Must be in Range" << std::endl;
            std::cerr << "Inserting the object in the end." << std::endl;
            elem[size_v] = myObject;
            ++size_v;
            return &elem[size_v];
        }
        std::copy(p, elem + size_v, p + 1);  //Copy the elements from the Target position till the end of the Vector to skip only one element to make room for the new Object.
        *p = myObject;
        ++size_v;           //Increment the Size by one.
        return p;
    }

    iterator erase(iterator p)
    {

        if (p == end()){ // IF both iterators are the same, Then Return itself and decrease the size_v
            return p;}
        for (iterator i = p + 1; i != end(); ++i) {// Iterator over the Elements in the Vector till the end and shit all to the Left
            *(i - 1) = *i;}
        --size_v;
        return p;
    }

    T low(T first, T last)
    {
        T low = first;
        for (T p=first; p!=last; ++p){
            if (*low > *p){
                low = p;return low;}
        }
    }

    void selection_sort(T first, T last)
    {
        int n = last - first;
        for(int x=0; x<n; x++){
            int index_of_min = x;
            for(int y=x; y<n; y++){
                if(*(first+index_of_min) > *(first+y)){index_of_min = y;
                }
            }
            auto temp = *(first+x);*(first+x) = *(first+index_of_min);
            *(first+index_of_min) = temp;
        }

    }

    void print_vector(){
        for (int i=0; i<this->size(); i++) //Will iterate through the vector's elements, as many times as the vector holds elements.
            std::cout << elem[i] << "\t"; //Outputs the elements with a "\t" gap.
        std::cout << std::endl;       // Move the output buffer to the next line once the iteration has finished.

    }
};
}

#endif
