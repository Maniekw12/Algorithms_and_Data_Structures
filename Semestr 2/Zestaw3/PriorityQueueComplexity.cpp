#include <iostream>
#include "PriorityQueue.h"
#include <random>
#include <chrono>

#define N 1000
#define MEASUREMENTS 5.0

using namespace std;
using namespace std::chrono;

template<typename Func>
long long measure_time(Func func) {
    const auto beg = high_resolution_clock::now();
    func();
    const auto end = high_resolution_clock::now();
    return duration_cast<nanoseconds>(end - beg).count();
}

void showInsertComplexity() {

    for (int i = 1; i < N; ++i) {
        PriorityQueue<int>* myQueue = new PriorityQueue<int>();

        for (int j = 1; j < i; ++j) {
            myQueue->insertElement(j, j+N);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            myQueue->getMinValue();
            totalDuration += measure_time([&] { myQueue->insertElement(j,1); })/MEASUREMENTS;

        }

        delete myQueue;
        std::cout << i << " " << totalDuration << std::endl;
    }
}

void showRemoveComplexity() {
    for (int i = 0; i < N; ++i) {
        PriorityQueue<int>* myQueue = new PriorityQueue<int>();
        for (int j = 0; j <= i; ++j) {
            myQueue->insertElement(j, j);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            myQueue->insertElement(j, j);

            totalDuration += measure_time([&] {
                myQueue->getMinValue();
            })/ MEASUREMENTS;
        }

        delete myQueue;

        std::cout << i << " " << totalDuration  << std::endl;
    }
}



int main() {
    int choice;
    std::cout << "Select operation to test:" << std::endl;
    std::cout << "1. Insert Complexity" << std::endl;
    std::cout << "2. Remove Complexity" << std::endl;
    std::cin >> choice;

    switch(choice) {
        case 1:showInsertComplexity(); break;
        case 2: showRemoveComplexity(); break;

        default: std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}