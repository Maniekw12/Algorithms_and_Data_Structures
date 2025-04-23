#include <iostream>
#include <cassert>
#include <algorithm>
#include "bubblesort.hpp"
using namespace std;

int main() {
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    char charArr[] = {'a', 'm', 'e', 'e', 'l', 'a'};

    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    int charSize = sizeof(charArr) / sizeof(charArr[0]);

    bubbleSort(intArr, intSize);

    assert(std::is_sorted(intArr, intArr + intSize));

    cout<<"sortowanie dla (int array) ";
    for (int i : intArr) {
        cout << i << " ";
    }
    cout << endl;

    bubbleSort(charArr, charSize);

    assert(std::is_sorted(charArr, charArr + charSize));
    cout<<"sortowanie dla (Char array) ";
    for (char i : charArr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
