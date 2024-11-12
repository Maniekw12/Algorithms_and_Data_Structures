#include <iostream>
#include <cassert>
#include "doublelist.h"

void testSingleList() {
    DoubleList<int> list;

    assert(list.empty() == true);
    std::cout << "Test 1 - Is empty: Passed\n";

    list.push_front(10);
    assert(list.front() == 10);
    std::cout << "Test 2 - Front: Passed\n";
    std::cout <<"List display: ";
    list.display();

    list.push_back(20);
    assert(list.back() == 20);
    std::cout << "Test 3 - Back: Passed\n";

    std::cout <<"List display: ";
    list.display();


    list.push_front(5);
    assert(list.front() == 5);
    std::cout << "Test 4 - Front: Passed\n";

    std::cout <<"List display: ";
    list.display();

    assert(list.size() == 3);
    std::cout << "Test 5 - Size: Passed\n";

    list.pop_front();
    assert(list.front() == 10);
    std::cout << "Test 6 - Front after pop: Passed\n";
    std::cout <<"List display: ";
    list.display();


    list.pop_back();
    assert(list.back() == 10);
    std::cout << "Test 7 - Back after pop: Passed\n";
    std::cout <<"List display: ";
    list.display();


    list.clear();
    assert(list.empty() == true);
    std::cout << "Test 8 - Is empty after clear: Passed\n";

    list.push_back(30);
    list.push_back(40);
    assert(list.size() == 2);
    std::cout << "Test 9 - Size after adding elements: Passed\n";
    std::cout <<"List display: ";
    list.display();


    list.display_reversed();
    std::cout << "Test 10 - Reversed list: ";
    list.display();

    list.pop_front();
    list.pop_front();
    assert(list.empty() == true);
    std::cout << "Test 11 - Is empty after popping all: Passed\n";

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    assert(list.front() == 0);
    assert(list.back() == 3);
    assert(list.size() == 4);
    std::cout << "Test 12 - Multiple pushes: Passed\n";
    std::cout <<"List display: ";
    list.display();

    list.clear();
    std::cout <<"List display: ";
    list.display();

    list.push_back(100);
    list.push_back(200);
    list.pop_back();
    list.pop_front();

    assert(list.size() == 0);
    std::cout << "Test 13 - Size after operations: Passed\n";
    std::cout <<"List display: ";
    list.display();

}

int main() {
    testSingleList();
    return 0;
}