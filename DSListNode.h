#ifndef Node
#define Node
#include <iostream>

using namespace std;
template <typename T>

class DSListNode{
private:
    T data;
    DSListNode<T>* prev;
    DSListNode<T>* next;
public:
    template <typename> friend class DSList;

    DSListNode(){                   //Default constructor
        prev = nullptr;
        next = nullptr;
    };

    DSListNode(T val){        //Overloaded constructor
        data = val;
        prev = nullptr;
        next = nullptr;
    };

    DSListNode(const DSListNode<T>& rhs){       //Copy constructor
        data = rhs.data;
        next = rhs.next;
        prev = rhs.prev;
    };

    DSListNode& operator= (const DSListNode<T> rhs){         //Copy Assignment operator
        data = rhs.data;
        next = rhs.next;
        prev = rhs.prev;
        return *this;
    };

    T getData(){                       //Data member accessor
        return data;
    }

    DSListNode<T>* getNext(){
        return next;
    }

    void setNext(DSListNode<T>* rhs){
        next = rhs;
    }

    DSListNode<T>* getPrev(){
        return prev;
    }

    void setPrev(DSListNode<T>* rhs){
        prev = rhs;
    }

    friend ostream& operator<< (ostream& stream, const DSListNode<T>& rhs) {      //Stream insertion operator
        stream << rhs.data;
        return stream;
    }


};
#endif

