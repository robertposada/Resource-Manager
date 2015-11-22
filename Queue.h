#ifndef BLIST_H

#define BLIST_H

/*
 Name(s): Kevin Nguyen & Robert Posada
 Date: 11/09/2015
 CS-102
 Project #2
 */

template <class T>
class Bnode{
    template <class U>
    friend class Blist;
    T value;
    Bnode<T> *next, *prev;
public:
    T getVal();
    Bnode<T>* getNext();
    Bnode<T>* getPrev();
};

template <class T>
class Blist {
    Bnode<T> *front, *back;
    int size;
public:
    // getters
    Bnode<T>* getFront();
    Bnode<T>* getBack();
    int getSize();
    
    // constructors
    Blist<T>();
    Blist<T>(T arr[], int sz);
    Blist<T>(const Blist<T>& list);
    
    // destructor
    ~Blist<T>(void);
    
    // methods
    bool empty(void);
    T pop_back(void);
    T pop_front(void);
    void push_back(T value);
    void push_front(T value);
    void print(char symbol, void (*printM)(T value));
    int counter(void);
    void bsort(Bnode<T> *left, Bnode<T> *right);
    void bsort(Bnode<T> *left, Bnode<T> *right, int (*cmp)(T val, T val2));
    void insert(Bnode<T> *p, T val);
    void del(Bnode<T>* p);
    Blist<T> sublist(Bnode<T>* b, Bnode<T> *e);
    Bnode<T>* at(const int& index);
    int getPos(Bnode<T> *p);
    
    // overloaded operators
    T operator [] (const int index);
    Blist<T>& operator = (const Blist<T>& list);
};

#endif