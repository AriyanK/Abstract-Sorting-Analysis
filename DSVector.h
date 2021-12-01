#ifndef Vector
#define Vector
#include <iostream>

using namespace std;
template<typename T>

class DSVector{
private:
    int size;
    int capacity;
    T* data;

    void resize(){                          //Doubles capacity of array
        T* temp = new T[capacity * 2];
        for(int x = 0; x < size; x++){
            temp[x] = data[x];
        }
        delete [] data;
        data = temp;
        capacity *= 2;
    }

public:
    struct ForwardIterator{
        using iterator_category = forward_iterator_tag;
        using difference_type = ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        ForwardIterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }


        ForwardIterator& operator++() { m_ptr++; return *this; }


        ForwardIterator operator++(int) { ForwardIterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const ForwardIterator& a, const ForwardIterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const ForwardIterator& a, const ForwardIterator& b) { return a.m_ptr != b.m_ptr; };
    private:
        pointer m_ptr;
    };

    struct RAiterator{
        using iterator_category = random_access_iterator_tag;
        using difference_type = ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        RAiterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }

        RAiterator& operator++() { m_ptr++; return *this; }
        RAiterator& operator--() { m_ptr--; return *this; }

        RAiterator operator++(int) { RAiterator tmp = *this; ++(*this); return tmp; }
        RAiterator operator--(int) { RAiterator tmp = *this; --(*this); return tmp; }

        friend bool operator== (const RAiterator& a, const RAiterator& b) { return a.m_ptr == b.m_ptr; }
        friend bool operator!= (const RAiterator& a, const RAiterator& b) { return a.m_ptr != b.m_ptr; }
        friend RAiterator operator+ (const difference_type& lhs, const RAiterator& rhs) { return RAiterator(lhs+rhs.m_ptr); }
        friend RAiterator operator- (const difference_type& lhs, const RAiterator& rhs) { return RAiterator(lhs-rhs.m_ptr); }


        RAiterator operator[] (const difference_type& off) { return m_ptr[off]; }
        RAiterator operator+ (const difference_type& rhs) const { return RAiterator(m_ptr + rhs); }
        RAiterator operator- (const difference_type& rhs) const { return RAiterator(m_ptr - rhs); }

        difference_type operator+(const RAiterator& other) const { return m_ptr + other.m_ptr; }
        difference_type operator-(const RAiterator& other) const { return m_ptr - other.m_ptr; }

        bool operator> (const RAiterator& rhs) const { return m_ptr > rhs.m_ptr; }
        bool operator< (const RAiterator& rhs) const { return m_ptr < rhs.m_ptr; }
        bool operator>= (const RAiterator& rhs) const { return m_ptr >= rhs.m_ptr; }
        bool operator<= (const RAiterator& rhs) const { return m_ptr <= rhs.m_ptr; }
        RAiterator& operator+= (difference_type rhs) { m_ptr += rhs; return *this; }
        RAiterator& operator-= (difference_type rhs) { m_ptr -= rhs; return *this; }

    private:
        pointer m_ptr;
    };

    DSVector(){                             //Default constructor
        data = new T[1];
        size = 0;
        capacity = 1;
    }

    explicit DSVector(int initSize){        //Overloaded constructor
        data = new T[initSize];
        size = initSize;
        capacity = initSize;
    }

    DSVector(const DSVector<T>& rhs){       //Copy constructor
        if(data == nullptr)
            delete [] data;
        data = new T[rhs.size];
        size = rhs.size;
        capacity = rhs.capacity;

        for(int x = 0; x < capacity; x++){
            data[x] = rhs[x];
        }
    }

    DSVector(const T* rhs, const int initSize){
        if(data == nullptr)
            delete [] data;
        size = initSize;
        data = new T[size];
        capacity = size;

        for(int x = 0; x < size; x++){
            data[x] = rhs[x];
        }
    }

    ~DSVector(){                            //Destructor
        delete [] data;
    }

    DSVector<T>& operator= (const DSVector<T>& rhs){        //Copy assignment operator
        if(this == &rhs) {
            return *this;
        }
        if(data != nullptr){
            delete [] data;
        }
        capacity = rhs.capacity;
        size = rhs.size;

        data = new T[capacity];

        for(int x = 0; x < rhs.size; x++){
           data[x] = rhs[x];
        }

        return *this;
    }

    void setVector(T* arr, int arrSize){
        for(int x = 0; x < arrSize; x++){
            data[x] = arr[x];
        }
    }


    /*T& operator[](const T location) const{            //Returns value at location T = string
        return *data;
    }*/

    T& operator[](const int location) const{            //Returns value at location T = string
        return data[location];
    }


    void push_back(T val){                              //Appends value to end of array
        if(size < capacity){
            data[size] = val;
            size++;
        }
        else {
            resize();
            data[size] = val;
            size++;
        }
    }

    T pop_back() {                       //Removes and returns value from end of array
        size--;
        return data[size];
    }

    int getCapacity(){                  //Returns capacity of array
        return capacity;
    }

    int getSize(){                      //Returns size of array
        return size;
    }

    ForwardIterator Forwardbegin() { return ForwardIterator(&data[0]); }
    ForwardIterator Forwardend()   { return ForwardIterator(&data[size]); }

    RAiterator begin() { return RAiterator( &data[0]); }
    RAiterator end()   { return RAiterator( &data[size]); }

};


#endif
