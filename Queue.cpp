/*
 Name(s): Kevin Nguyen & Robert Posada
 Date: 11/20/2015
 Project #3
 */

#include <iostream>
#include "Queue.h"
using namespace std;

// getters for Qnode -
template <class T>
T Qnode<T>::getValue() {
    return value;
}

template <class T>
Qnode<T>* Qnode<T>::getNext() {
    return next;
}

template <class T>
Qnode<T>* Qnode<T>::getPrev() {
    return prev;
}

// constructors for Qlist

// default constructor -
template <class T>
Qlist<T>::Qlist() {
    front = back = nullptr;
    size = 0;
}

// array constructor -
template <class T>
Qlist<T>::Qlist(T arr[], int size) {
    front = back = nullptr;
    size = 0;
    for (int i = 0; i < size; i++) {
        push_back(arr[i]);
    }
}

// copy constructor -
template <class T>
Qlist<T>::Qlist(const Qlist<T>& list) {
    front = back = nullptr;
    size = 0;
    Qnode<T> *current = list->front;
    while (current != nullptr) {
        push_back(current->value);
        current = current->next;
    }
    return *this;
}

// destructor for Qlist -
template <class T>
Qlist<T>::~Qlist() {
    Qnode<T> *current = front;
    while (current != nullptr) {
        Qnode<T> *next = current->next;
        delete current;
        size--;
        current = next;
    }
    front = back = nullptr;
}

// getters for Qlist -
template <class T>
Qnode<T>* Qlist<T>::getFront() {
    return front;
}

template <class T>
Qnode<T>* Qlist<T>::getBack() {
    return back;
}

template <class T>
int Qlist<T>::getSize() {
    return size;
}

// is empty method -
template <class T>
bool Qlist<T>::empty() {
    if (front == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

// push front method -
template <class T>
void Qlist<T>::push_front(T value) {
    Qnode<T> *newNode = new Qnode<T>;
    newNode->value = value;
    if (empty()) {
        newNode->next = newNode->prev = nullptr;
        front = back = newNode;
    }
    else {
        front->prev = newNode;
        newNode->next = front;
        newNode->prev = nullptr;
        front = newNode;
    }
    size++;
    return;
}

// pop back method -
template <class T>
T Qlist<T>::pop_back() {
    Qnode<T> *temp = back;
    T ret = back->value;
    if (front == back) {
        front = back = nullptr;
    }
    else {
        back = back->prev;
        back->next = nullptr;
    }
    size--;
    delete temp;
    return ret;
}

// overloaded array access operator
template <class T>
T Qlist<T>::operator [] (const int index) {
    Qnode<T> *current = front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}



