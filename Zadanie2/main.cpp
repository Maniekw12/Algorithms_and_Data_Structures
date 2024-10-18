#include <iostream>
#include "arraylist.h" // Include the header for the ArrayList

using namespace std;

void runTests() {
    ArrayList<int> list;

    cout << "Test 1: Is the list empty? Expected: 1, Actual: " << list.empty() << endl;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    cout << "Test 2: List after push_back(10, 20, 30): ";
    list.display();

    cout << "Test 3: Size (Expected: 3): " << list.get_size() << ", Capacity (Expected: 3): " << list.get_capacity() << endl;

    cout << "Test 4: Front element (Expected: 10): " << list.front() << endl;
    cout << "Test 5: Back element (Expected: 30): " << list.back() << endl;

    cout << "Test 6: Popped front element (Expected: 10): " << list.pop_front() << endl;
    cout << "List after pop_front: ";
    list.display();

    cout << "Test 7: Popped back element (Expected: 30): " << list.pop_back() << endl;
    cout << "List after pop_back: ";
    list.display();

    list.push_front(5);
    cout << "Test 8: List after push_front(5): ";
    list.display();

    list.erase(0);
    cout << "Test 9: List after erase(0): ";
    list.display();

    ArrayList<int> other;
    other.push_back(15);
    other.push_back(25);
    cout << "Test 10: Other list before merge: ";
    other.display();

    other.reverse();
    cout << "Test 11: other after reverse: ";
    other.display();


    list.clear();
    cout << "Test 12: List after clear: ";
    list.display();

    for (int i = 1; i <= 10; ++i) {
        list.push_back(i * 10); // List should resize as we add elements
    }
    cout << "Test 13: List after adding 10 elements: ";
    list.display();

    cout << "Test 14: Front element (Expected: 10): " << list.front() << endl;
    cout << "Test 15: Back element (Expected: 100): " << list.back() << endl;

    cout << "Test 16: Get element at index 5 (Expected: 60): " << list.get(5) << endl;

    while (!list.empty()) {
        cout << "Popped front: " << list.pop_front() << ", ";
        cout << "Popped back: " << list.pop_back() << endl;
    }

    cout << "Test 17: Is the list empty after popping all elements? Expected: 1, Actual: " << list.empty() << endl;


}


int main() {
    runTests();
    return 0;
}
