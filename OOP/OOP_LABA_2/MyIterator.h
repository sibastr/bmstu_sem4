//
// Created by alexey on 09.04.17.
//

#ifndef OOP_LABA_2_MYITERATOR_H
#define OOP_LABA_2_MYITERATOR_H

#include "MyList.h"
#include "MException.h"

template<typename T>
class MyIterator {

public:
    MyIterator(const MyList<T> &list);

    ~MyIterator();

    void UseFront();

    void UseBack();

    const T &value() const;

    const T &operator*() const;

    bool valid() const;

    bool next();

    bool operator++();

    bool prev();

    bool operator--();

    bool equal(const MyIterator &other) const;

    bool operator==(const MyIterator &other) const;

    bool operator!=(const MyIterator &other) const;

private:
    const MyList<T> *plist;
    const Node<T> *pnode;
    size_t cur;

};

template<typename T>
MyIterator<T>::MyIterator(const MyList<T> &list): plist(&list), cur(0) {  UseFront(); }

template<typename T>
void MyIterator<T>::UseFront() {
    pnode = plist->getHead();
    cur=0;

}
template<typename T>
void MyIterator<T>::UseBack() {
    pnode = plist->getTail();
    cur=plist->getCount();
}


template<typename T>
MyIterator<T>::~MyIterator() {}

template<typename T>
const T &MyIterator<T>::value() const {

    if (!valid()) {
        throw MExcOutOfRange();
    }

    return pnode->object;
}


template<typename T>
const T &MyIterator<T>::operator*() const {
    return value();
}

template<typename T>
bool MyIterator<T>::valid() const {
    return (cur >= 0) && (cur < plist->getCount());
}

template<typename T>
bool MyIterator<T>::next() {
    cur++;
    pnode = pnode->next;
    return valid();
}

template<typename T>
bool MyIterator<T>::operator++() {
    return next();
}

template<typename T>
bool MyIterator<T>::prev() {
    cur--;
    pnode = pnode->prev;
    return valid();
}

template<typename T>
bool MyIterator<T>::operator--() {
    return prev();
}

template<typename T>
bool MyIterator<T>::equal(const MyIterator<T> &other) const {
    if (plist != other.plist) {
        throw MExcObjectPointer();
    }

    return (cur == other.cur);
}

template<typename T>
bool MyIterator<T>::operator==(const MyIterator<T> &other) const {
    return equal(other);
}

template<typename T>
bool MyIterator<T>::operator!=(const MyIterator<T> &other) const {
    return !equal(other);
}


#endif //OOP_LABA_2_MYITERATOR_H