#include <iostream>
#include "ADTgraph.h"
#include <random>
#include <chrono>

#define N 1000
#define MEASUREMENTS 50.0

using namespace std;
using namespace std::chrono;

template<typename Func>
long long measure_time(Func func) {
    const auto beg = high_resolution_clock::now();
    func();
    const auto end = high_resolution_clock::now();
    return duration_cast<nanoseconds>(end - beg).count();
}

template<int SIZE>
void showAddEdgeComplexity() {
    for (int i = 1; i < SIZE; ++i) {
        ADTgraph<SIZE> graph;

        for (int j = 0; j <= i; ++j) {
            graph.addVertex(j);
        }
        double totalDuration = 0.0;

        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] {
                graph.addEdge(j % i, (j + 1) % i);
            }) / MEASUREMENTS;
        }

        std::cout << i << " " << totalDuration << std::endl;
    }
}



int main() {
    int choice;
    std::cout << "Select operation to test:" << std::endl;
    std::cout << "1. AddEdge Complexity" << std::endl;
    std::cin >> choice;

    switch(choice) {
        case 1:showAddEdgeComplexity<500>(); break;
        default: std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}