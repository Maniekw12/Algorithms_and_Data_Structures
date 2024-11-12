#include <cassert>
#include <iostream>
#include "MyDeque.h"

void test_default_constructor() {
    MyDeque<int> deque;
    assert(deque.size() == 0);
    assert(deque.empty());
    assert(!deque.full());
    std::cout << "test_default_constructor passed\n";
}

void test_push_back_and_push_front() {
    MyDeque<int> deque(5);
    deque.push_back(10);
    deque.push_back(20);
    deque.push_front(5);
    assert(deque.size() == 3);
    assert(deque.front() == 5);
    assert(deque.back() == 20);
    std::cout << "test_push_back_and_push_front passed\n";
}

void test_pop_back_and_pop_front() {
    MyDeque<int> deque(5);
    deque.push_back(10);
    deque.push_back(20);
    deque.push_front(5);
    deque.pop_front();
    assert(deque.size() == 2);
    assert(deque.front() == 10);

    deque.pop_back();
    assert(deque.size() == 1);
    assert(deque.back() == 10);

    deque.pop_back();
    assert(deque.empty());
    std::cout << "test_pop_back_and_pop_front passed\n";
}

void test_clear() {
    MyDeque<int> deque(5);
    deque.push_back(10);
    deque.push_back(20);
    deque.clear();
    assert(deque.size() == 0);
    assert(deque.empty());
    std::cout << "test_clear passed\n";
}

void test_copy_constructor() {
    MyDeque<int> deque1(5);
    deque1.push_back(10);
    deque1.push_back(20);
    MyDeque<int> deque2 = deque1;

    assert(deque2.size() == 2);
    assert(deque2.front() == 10);
    assert(deque2.back() == 20);
    deque1.push_back(30);
    assert(deque1.size() != deque2.size());  // Ensure deep copy
    std::cout << "test_copy_constructor passed\n";
}

void test_assignment_operator() {
    MyDeque<int> deque1(5);
    deque1.push_back(10);
    deque1.push_back(20);
    MyDeque<int> deque2(5);
    deque2 = deque1;

    assert(deque2.size() == 2);
    assert(deque2.front() == 10);
    assert(deque2.back() == 20);
    deque1.push_back(30);
    assert(deque1.size() != deque2.size());
    std::cout << "test_assignment_operator passed\n";
}

void test_display() {
    MyDeque<int> deque(5);
    deque.push_back(10);
    deque.push_back(20);
    deque.push_back(30);
    std::cout<<"Test display:"<<std::endl;
    deque.display();
}

void test_display_reversed() {
    MyDeque<int> deque(5);
    deque.push_back(10);
    deque.push_back(20);
    deque.push_back(30);
    std::cout << "test_display_reversed\n";
    deque.display_reversed();
}

int main() {
    test_default_constructor();
    test_push_back_and_push_front();
    test_pop_back_and_pop_front();
    test_clear();
    test_copy_constructor();
    test_assignment_operator();
    test_display();
    test_display_reversed();
    std::cout << "All tests passed successfully.\n";
    return 0;
}
