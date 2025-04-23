#include <cassert>
#include <iostream>
#include "priorityQueueBinary.h"

void testInsertOneElement() {
    priorityQueueBinary<int> pq;
    pq.insert(42, 5);
    element<int> root = pq.getRoot();
    assert(root.value == 42);
    assert(root.priority == 5);
    std::cout << "testInsertOneElement passed\n";
}

void testInsertMultipleElements() {
    priorityQueueBinary<int> pq;
    pq.insert(100, 20);
    pq.insert(50, 10);
    pq.insert(200, 30);
    pq.insert(10, 5);

    element<int> root = pq.getRoot();
    assert(root.value == 10);
    assert(root.priority == 5);
    std::cout << "testInsertMultipleElements passed\n";
}

void testPercolateOrder() {
    priorityQueueBinary<int> pq;
    pq.insert(300, 30);
    pq.insert(200, 20);
    pq.insert(100, 10);
    pq.insert(400, 40);

    assert(pq.getRoot().priority == 10);
    std::cout << "testPercolateOrder passed\n";
}

void testRemoveElement() {
    priorityQueueBinary<int> pq;
    pq.insert(300, 30);
    pq.insert(200, 20);
    pq.insert(100, 10);
    pq.insert(400, 40);

    pq.delete_min();
    assert(pq.getRoot().priority == 20);
    std::cout << "testPercolateOrder passed\n";
}

int main() {
    testInsertOneElement();
    testInsertMultipleElements();
    testPercolateOrder();
    testRemoveElement();
    std::cout << "All tests passed successfully!\n";
    return 0;
}
