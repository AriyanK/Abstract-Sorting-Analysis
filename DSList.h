#ifndef List
#define List
#include "DSListNode.h"
#include <iostream>
using namespace std;
template <typename T>

class DSList{
public:
    struct ForwardIterator{
        using iterator_category = forward_iterator_tag;
        using difference_type = ptrdiff_t;
        using value_type = DSListNode<T>;
        using pointer = DSListNode<T>*;
        using reference = DSListNode<T>&;

        ForwardIterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }


        ForwardIterator& operator++() { m_ptr = m_ptr->getNext(); return *this; }


        ForwardIterator operator++(int) { ForwardIterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const ForwardIterator& a, const ForwardIterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const ForwardIterator& a, const ForwardIterator& b) { return a.m_ptr != b.m_ptr; };
    private:
        pointer m_ptr;
    };

    ForwardIterator begin() { return ForwardIterator(&(*head)); }
    ForwardIterator end()   { return ForwardIterator(&(*tail->getNext())); }

    DSListNode<T>* head;
    DSListNode<T>* tail;
    DSListNode<T>* iterator;
    int size;
    DSList(){                       //Default constructor
        head = nullptr;
        tail = nullptr;
        iterator = head;
        size = 0;
    }

    DSList(const DSList<T>& list) {        //Copy constructor
        if (list.head == nullptr) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = new DSListNode<T>(list.head->data);
            iterator = head;
            DSListNode<T>* curr = list.head->next;
            while(curr != nullptr){
                iterator->next = new DSListNode<T>(curr->data);
                iterator->prev = iterator;
                iterator = iterator->next;
                curr = curr->next;
            }
            size = list.size;
            tail = iterator;
        }
    }

    DSList& operator= (const DSList<T>& rhs){       //Copy assignment operator
        delete head;
        delete tail;
        head = new DSListNode<T>(rhs.head->data);
        tail = new DSListNode<T>(rhs.tail->data);

        if(rhs.head == nullptr){
            head = nullptr;
            tail = nullptr;
        }
        else{
            iterator = head;
            DSListNode<T>* curr = rhs.head->next;
            while(curr != nullptr){
                iterator->next = new DSListNode<T>(curr->data);
                iterator->next->prev = iterator;
                iterator = iterator->next;
                curr = curr->next;
            }
        }
        size = rhs.size;
        tail = iterator;
        return *this;
    }


    ~DSList(){                                      //Destructor
        iterator = head;
        while(iterator != nullptr){
            head = iterator->next;
            iterator->~DSListNode<T>();
            iterator = head;
        }
        tail = head;
    }

    void insertFront(T toBeAdded){               //Inserts node at front of list
        DSListNode<T>* newNode;
        newNode = new DSListNode<T>(toBeAdded);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void append(T toBeAdded){                     //Inserts node at end of list
        DSListNode<T>* newNode;
        newNode = new DSListNode<T>(toBeAdded);

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            tail->next = nullptr;
        }
        size++;
    }

    void remove(DSListNode<T>* value){          //Removes specified value from list
        iterator = head;
        while(iterator != nullptr){
            if(iterator == value)
                break;
            iterator = iterator->next;
        }

        if(iterator == value){
            if(iterator == head){
                head = iterator->next;
            }
            if(iterator == tail){
                tail = iterator->prev;
            }
            if(iterator->prev != nullptr){
                iterator->prev->next = iterator->next;
            }
            if(iterator->next != nullptr){
                iterator->next->prev = iterator->prev;
            }
            delete iterator;
            iterator = head;
        }
        size--;
    }

    DSListNode<T>& operator[](int index){               //Returns value at index
        iterator = head;
        for(int x = 0; x < index; x++){
            iterator = iterator->next;
        }
        return *iterator;
    }

    void printList(){                                   //Print function
        iterator = head;
        while(iterator != nullptr){
            cout << iterator << " <--> ";
            iterator = iterator->next;
        }
    }

    bool isEmpty(){                                     //Returns true if the list is empty
        if(head->next == nullptr){
            return true;
        }else{
            return false;
        }
    }
};

#endif
