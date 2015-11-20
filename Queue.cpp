/*
Name(s): Kevin Nguyen & Robert Posada
Date: 11/20/2015
Project #3
*/

#include <iostream>
#include "Queue.h"
using namespace std;

// Getters for Qnode
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

// Getters for Qlist
template <class T>
Qnode<T>* Qlist<T>::getFront() {
    return front;
}

template <class T>
Qnode<T>* Qlist<T>::getBack() {
    return back;
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

// push back method -
template <class T>
void Qlist<T>::push_back(T value) {
    Qnode<T> *newNode = new Qnode<T>;
    newNode->value = value;
    if (empty()) {
        newNode->next = newNode->prev = nullptr;
        front = back = newNode;
    }
    else {
        back->next = newNode;
        newNode->prev = back;
        newNode->next = nullptr;
        back = newNode;
    }
    return;
}

// pop front method -
template <class T>
T Qlist<T>::pop_front() {
    Qnode<T> *temp = front;
    T ret = front->value;
    if (front == back) {
        front = back = nullptr;
    }
    else {
        front = front->next;
        front->prev = nullptr;
    }
    size--;
    delete temp;
    return ret;
}




