#ifndef BUBBLESORT_BUBBLESORT_HPP
#define BUBBLESORT_BUBBLESORT_HPP

using namespace std;

template <typename T>
void bubbleSort(T arr[], int size){
    bool swapped;

    for (int i = 0; i < size-1; i++) {
        swapped = false;
        for (int j = 0; j < size-i-1 ; j++) {
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }

    }
}


#endif
