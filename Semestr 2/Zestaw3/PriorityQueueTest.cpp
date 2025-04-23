#include <iostream>
#include <cassert>
#include "PriorityQueue.h"

void shouldReturnMinValue() {
    PriorityQueue<std::string> pq;
    pq.insertElement("A", 3);
    pq.insertElement("B", 1);
    pq.insertElement("C", 2);

    assert(pq.getMinValue() == "B");
    assert(pq.getMinValue() == "C");
    assert(pq.getMinValue() == "A");

    std::cout << "✔ shouldReturnMinValue passed\n";
}

void shouldIgnoreDuplicates() {
    PriorityQueue<std::string> pq;
    pq.insertElement("Email", 1);
    pq.insertElement("Email", 1);

    assert(pq.getMinValue() == "Email");

    try {
        pq.getMinValue();
        assert(false);
    } catch (std::out_of_range&) {
        std::cout << "✔ shouldIgnoreDuplicates passed\n";
    }
}

void shouldHandleEqualPriorities() {
    PriorityQueue<std::string> pq;
    pq.insertElement("Second", 2);
    pq.insertElement("Third", 2);
    pq.insertElement("Lowest", 1);

    assert(pq.getMinValue() == "Lowest");

    std::string a = pq.getMinValue();
    std::string b = pq.getMinValue();

    assert(a == "Third");
    assert(b == "Second");

    std::cout << "✔ shouldHandleEqualPriorities passed\n";
}


void shouldThrowOnEmpty() {
    PriorityQueue<std::string> pq;
    try {
        pq.getMinValue();
        assert(false);
    } catch (const std::out_of_range&) {
        std::cout << "✔ shouldThrowOnEmpty passed\n";
    }
}

int main() {
    shouldReturnMinValue();
    shouldIgnoreDuplicates();
    shouldThrowOnEmpty();
    shouldHandleEqualPriorities();
    std::cout << "✅ All manual unit tests passed!\n";
    return 0;
}
