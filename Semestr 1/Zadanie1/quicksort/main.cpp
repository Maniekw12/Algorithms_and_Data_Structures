#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include "quicksort.hpp"
using namespace std;

int main() {
    int arr1[] = {10, 7, 8, 9, 1, 5};
    vector<double> arr2 = {10.2, 7.1, 8.5, 9.0, 1.3, 5.5};
    vector<char> arr3 = {'g', 'e', 'a', 'b', 'f', 'd', 'c'};

    quickSort(arr1, sizeof(arr1) / sizeof(arr1[0]));
    assert(std::is_sorted(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]))); 
    cout << "quickSort dla tablicy (int): ";
    for (const auto &num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    quickSort(arr2.begin(), arr2.end() - 1);
    assert(std::is_sorted(arr2.begin(), arr2.end()));
    cout << "QuickSort dla vectora (double): ";
    for (const auto &num : arr2) {
        cout << num << " ";
    }
    cout << endl;



    quickSort(arr3.begin(), arr3.end() - 1);
    assert(std::is_sorted(arr3.begin(), arr3.end()));
    cout << "QuickSort dla vectora (char): ";
    for (const auto &num : arr3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
