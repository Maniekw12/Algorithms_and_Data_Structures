#include <iostream>
#include "../zestaw2/setHashed.h"
#ifndef ZESTAW2ITD_BINARYHEAP_H
#define ZESTAW2ITD_BINARYHEAP_H

#define SIZE 5000

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

    bool operator>(const element& other) const {
        return priority > other.priority;
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
class priorityQueueBinary {
private:
    element<T>* items = nullptr;
    int currIndex;
    setHashed<element<T>> setOfElements;

public:
    priorityQueueBinary() {
        items = new element<T>[SIZE];
        currIndex = 1;
    }

    ~priorityQueueBinary() {
        delete[] items;
    }

    void insert(T value, int priority) {
        element<T> item(value, priority);
        items[currIndex] = item;
        percolate_up(currIndex);
        currIndex++;
    }

    void percolate_up(int index) {
        while (index / 2 > 0) {
            if (items[index] < items[index / 2]) {
                element<T> dummy = items[index];
                items[index] = items[index / 2];
                items[index / 2] = dummy;
                index = index / 2;
            } else {
                break;
            }
        }
    }

    void displayHeap() {
        for (int i = 1; i < currIndex; ++i) {
            std::cout << items[i] << " ";
        }
        std::cout << std::endl;
    }

    element<T> getRoot() {
        return items[1];
    }

    int percolate_down(int index) {
        while (index * 2 <= currIndex - 1) {
            int min_index = min_child(index);
            if (items[index] > items[min_index]) {
                element<T> dummy = items[index];
                items[index] = items[min_index];
                items[min_index] = dummy;
            }
            index = min_index;
        }
        return index;
    }

    int min_child(int index) {
        if (index * 2 + 1 >= currIndex) {
            return index * 2;
        }
        if (items[index * 2 + 1] < items[index * 2]) {
            return index * 2 + 1;
        }
        return index * 2;
    }

    element<T> delete_min() {
        if (currIndex == 1) {
            return element<T>();
        }
        element<T> return_value = items[1];
        items[1] = items[currIndex - 1];  // Fixed index
        currIndex--;
        percolate_down(1);

        return return_value;
    }
};
#endif
