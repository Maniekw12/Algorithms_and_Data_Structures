#include <iostream>
#include <cassert>
#include "arraylist.h"

using namespace std;

void runTests() {
    ArrayList<int> list;

    cout << "Test 1: Is the list empty?" << endl;
    assert(list.empty() == true);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    cout << "Test 2: Verify the content after push_back" << endl;
    assert(list.get_size() == 3);
    assert(list.get(0) == 10);
    assert(list.get(1) == 20);
    assert(list.get(2) == 30);

    cout << "Test 3: Check size and capacity" << endl;
    assert(list.get_size() == 3);
    assert(list.get_capacity() == 4);

    cout << "Test 4: Front element" << endl;
    assert(list.front() == 10);

    cout << "Test 5: Back element" << endl;
    assert(list.back() == 30);

    cout << "Test 6: Popped front element" << endl;
    assert(list.pop_front() == 10);
    assert(list.get_size() == 2);
    assert(list.get(0) == 20);

    cout << "Test 7: Popped back element" << endl;
    assert(list.pop_back() == 30);
    assert(list.get_size() == 1);
    assert(list.get(0) == 20);

    cout << "Test 8: push_front" << endl;
    list.push_front(5);
    assert(list.get_size() == 2);
    assert(list.get(0) == 5);

    cout << "Test 9: Erase element at index 0" << endl;
    list.erase(0);
    assert(list.get_size() == 1);
    assert(list.get(0) == 20);

    cout << "Test 10: Verify reverse" << endl;
    ArrayList<int> other;
    other.push_back(15);
    other.push_back(25);
    other.reverse();
    assert(other.get(0) == 25);
    assert(other.get(1) == 15);

    cout << "Test 11: Clear the list" << endl;
    list.clear();
    assert(list.empty() == true);

    cout << "Test 12: Add multiple elements to check dynamic resizing" << endl;
    for (int i = 1; i <= 10; ++i) {
        list.push_back(i * 10);
    }
    assert(list.get_size() == 10);
    assert(list.get_capacity() >= 10);

    cout << "Test 13: Front and back elements" << endl;
    assert(list.front() == 10);
    assert(list.back() == 100);

    cout << "Test 14: Get element at index" << endl;
    assert(list.get(5) == 60);

    cout << "Test 15: Pop elements until the list is empty" << endl;
    while (!list.empty()) {
        list.pop_front();
    }
    assert(list.empty() == true);

    list.clear();
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(20);
    list.push_back(30);
    list.push_back(20);
    list.push_back(30);
    list.push_back(20);
    list.push_back(30);

    cout << "Test 16: Check capacity after multiple insertions" << endl;
    assert(list.get_capacity() == 16);
}



int main() {
    runTests();
    cout << "Tests successfully passed" << endl;
    return 0;
}


