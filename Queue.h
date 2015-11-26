/*
Name(s): Kevin Nguyen & Robert Posada
Date: 11/20/2015
Project #3
*/

#ifndef Queue_h
#define Queue_h

#include <iostream>
using namespace std;

template <class T>
class Qnode {
private:
    template <class U>
    friend class Qlist;
    T value;
    Qnode<T> *next;
    Qnode<T> *prev;
public:
    T getValue();
    Qnode<T>* getNext();
    Qnode<T>* getPrev();
};

template <class T>
class Qlist {
private:
    Qnode<T> *front;
    Qnode<T> *back;
    int size;
public:
    // Constructors
    Qlist();
    Qlist(T arr[], int size);
    Qlist(const Qlist<T>& list);
    
    // Destructor
    ~Qlist();
    
    // Getters
    Qnode<T>* getFront();
    Qnode<T>* getBack();
    int getSize();

    // Methods
    bool empty();
    void push_back(T value);
    T pop_front();
    
    // Overloaded operators
    Qlist<T>& operator =(const Qlist<T>& list);
    T operator [] (const int index);
};

#endif