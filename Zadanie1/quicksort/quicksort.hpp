#ifndef ALGORYTMY_I_STRUKTURY_DANYCH_QUICKSORT_HPP
#define ALGORYTMY_I_STRUKTURY_DANYCH_QUICKSORT_HPP


#include <algorithm>
#include "functional"

using namespace std;
template <typename Iterator>
Iterator partition(Iterator left,Iterator right){

    auto pivot = *right;

    Iterator i = left;


    for (Iterator j = left; j <= right - 1; j++) {
        if (*j < pivot) {
            swap(*i, *j);
            i++;
        }

    }

    swap(*i,*right);
    return i;
}


template <typename Iterator>
void quickSort(Iterator left, Iterator right) {
    if (left < right) {
        Iterator newPivotIndex = partition(left, right);
        quickSort(left, newPivotIndex - 1);
        quickSort(newPivotIndex + 1, right);
    }
}


// Template, ktory pozwala sortowac tablice
template <typename T>
void quickSort(T* arr, size_t size) {
    quickSort(arr, arr + size - 1);
}


#endif
