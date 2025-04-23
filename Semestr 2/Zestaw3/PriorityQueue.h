#include <iostream>
#include "setLinked.h"
#include <functional>
#include <utility>

template <typename T>
class element {
public:
    T value;
    int priority;

    element() = default;
    element(T v, int p) : value(v), priority(p) {}

    bool operator<(const element& other) const {
        return priority < other.priority;
    }

    bool operator==(const element& other) const {
        return value == other.value && priority == other.priority;
    }

    friend std::ostream& operator<<(std::ostream& os, const element<T>& el) {
        os << "[" << el.value << ", p=" << el.priority << "]";
        return os;
    }
};

template <typename T>
class PriorityQueue{
private:
    setLinked<element<T>>* elements;
public:

    PriorityQueue(){
        elements = new setLinked<element<T>>();
    }

    ~PriorityQueue(){
        delete elements;
    }

    T getMinValue(){
        element<T> minElement = elements->popHead();
        return minElement.value;
    }

    void insertElement(const T& value, int priority){
        element<T> element(value,priority);
        elements->insert(element);
    }

    void show() {
        elements->show();
    }

};


