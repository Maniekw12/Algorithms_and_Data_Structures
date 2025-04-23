#include <iostream>
#include <algorithm>
#include <cstring>
#include "SortedList.h"

template <class T>
class setLinked{
private:

public:
    SortedList<T> *elements = nullptr;

    setLinked(){
        elements = new SortedList<T>;
    }
    ~setLinked() {
        delete elements;
    }

    void insert(T element) {
        if (!elements->contains(element)) {
            elements->insert(element);
        }
    }

    bool contains(T element){
        return elements->contains(element);
    }

    void remove(T element){
       elements->remove(element);
    }

    setLinked<T> operator+(setLinked<T>& otherSet) {
        setLinked<T> resultSet;

        auto itThis = this->elements->begin();
        auto itOther = otherSet.elements->begin();

        while (itThis != this->elements->end() || itOther != otherSet.elements->end()) {
            if (itThis != this->elements->end() &&
                (itOther == otherSet.elements->end() || *itThis < *itOther)) {
                resultSet.elements->insertEnd(*itThis);
                ++itThis;
            }
            else if (itOther != otherSet.elements->end() &&
                     (itThis == this->elements->end() || *itOther < *itThis)) {
                resultSet.elements->insertEnd(*itOther);
                ++itOther;
            }
            else {
                resultSet.elements->insertEnd(*itThis);
                ++itThis;
                ++itOther;
            }
        }

        return resultSet;
    }

    setLinked<T> operator-(setLinked<T>& otherSet) {
        setLinked<T> resultSet;

        auto itThis = this->elements->begin();
        auto itOther = otherSet.elements->begin();

        while (itThis != this->elements->end()) {
            if (itOther == otherSet.elements->end() || *itThis < *itOther) {
                resultSet.elements->insertEnd(*itThis);
                ++itThis;
            }
            else if (*itThis == *itOther) {
                ++itThis;
                ++itOther;
            }
            else {
                ++itOther;
            }
        }

        return resultSet;
    }
    setLinked operator*(setLinked& otherSet) {
        setLinked<T> resultSet;

        auto itThis = this->elements->begin();
        auto itOther = otherSet.elements->begin();

        while (itThis != this->elements->end() && itOther != otherSet.elements->end()){
            if(*itThis == *itOther){
                resultSet.elements->insertEnd(*itThis);
                ++itThis;
                ++itOther;
            }
            else if(*itThis < *itOther){
                ++itThis;
            }
            else{
                ++itOther;
            }
        }
        return resultSet;
    }

    void show(){
        this->elements->show();
    }

    T popHead(){
        return elements->getHead();
    }

    T popTail(){
        return elements->getTail();
    };

    bool operator==(setLinked<T>& otherSet) {
        if (this->elements->getSize() != otherSet.elements->getSize()) {
            return false;
        }
        return this->elements->equals(*otherSet.elements);
    }
};