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

    int size_v;
    T *elem;
    int space;

public:

    vector(): size_v{0}, elem{nullptr}, space{0} {

    }

    explicit vector(int s): size_v{0}, elem{new T[s]}, space{s}
    {
        for (int i = 0; i < space; ++i)
            elem[i] = T();
    }

    vector(const vector &myObject): size_v{myObject.size_v}, elem{new T[myObject.size_v]}, space{myObject.space}
    {
        std::copy(myObject.elem, myObject.elem + size_v, elem);
    }

    void clear(){
        delete[] elem;
        elem = nullptr;
        size_v = 0;
        space = 0;
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
        return *this;
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
        if (space == 0)
            reserve(8);
        else if (size_v == space)
            reserve(2 * space);
        elem[size_v] = obj;
        ++size_v;
    }

    void reserve(int new_size)
    {
        try{
            T *p = new T[new_size];
            std::copy(elem, elem + size_v, p);
            delete[] elem;
            elem = p;
            space = new_size;

        }
        catch (std::bad_alloc& b)
        {
            std::cout << "bad_alloc caught: " << b.what() << '\n';
        }
    }


    using iterator = T *;
    using const_iterator = const T *;


    iterator begin()
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    const_iterator begin() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
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

        if (size_v == space){
            reserve(2 * space);}
        if (p > end())
        {
            std::cout << "Invalid Position, Must be in Range" << std::endl;
            std::cout << "Inserting the object in the end." << std::endl;
            elem[size_v] = myObject;
            ++size_v;
            return &elem[size_v];
        }
        std::copy(p, elem + size_v, p + 1);
        *p = myObject;
        ++size_v;
        return p;
    }

    iterator erase(iterator p)
    {

        if (p == end()){
            return p;}
        for (iterator i = p + 1; i != end(); ++i) {
            *(i - 1) = *i;}
        --size_v;
        return p;
    }

    T low(T first, T last)
    {
        T low = first;
        for (T p=first; p!=last; ++p){
            if (*low > *p){
                low = p;
                return low;}
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
        for (int i=0; i<this->size(); i++)
            std::cout << elem[i] << "\t";
        std::cout << std::endl;

    }
};
}

#endif
