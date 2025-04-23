#include <iostream>
#include <random>
#include <chrono>
#include "setSimple.h"

#define N 800
#define MEASUREMENTS 1.0
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
    setSimple mySet(N);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, N - 1);

    for (int i = 0; i < N; ++i) {

        long long totalDuration = 0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            int randomNumberToAdd = dis(gen);
            totalDuration += measure_time([&] { mySet.insert(randomNumberToAdd); }) / MEASUREMENTS;
        }

        std::cout << i << " " << totalDuration << std::endl;
    }
}

void showRemoveComplexity() {
    setSimple mySet(N);
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < N; ++i) {
        std::uniform_int_distribution<> dis(0, N - 1);
        int randomNumber = dis(gen);
        mySet.insert(randomNumber);

        long long totalDuration = 0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            int randomNumberToRemove = dis(gen);
            totalDuration += measure_time([&] { mySet.remove(randomNumberToRemove); }) / MEASUREMENTS;
        }

        std::cout << i << " " << totalDuration << std::endl;
    }
}

void showSumComplexity() {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Funkcja do pomiaru czasu wykonania operacji
    auto measure_time = [](auto &&func) {
        auto start = std::chrono::high_resolution_clock::now();
        func();
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double>(end - start).count();
    };

    for (int i = 1; i <= N; ++i) {
        std::uniform_int_distribution<> dis(0, i-1);

        setSimple *set1 = new setSimple(i);
        setSimple *set2 = new setSimple(i);

        for (int j = 0; j < i; ++j) {
            set1->insert(dis(gen));
            set2->insert(dis(gen));
        }

        double totalDuration = 0.0;

        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] {setSimple result = (*set1) + (*set2);})/MEASUREMENTS;
        }

        std::cout << i << " " << totalDuration << std::endl;

        // Zwalniamy pamięć
        delete set1;
        delete set2;
    }
}
void showContainsComplexity() {
    setSimple mySet(N);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, N - 1);

    for (int i = 0; i < N; ++i) {
        mySet.insert(dis(gen));
        long long totalDuration = 0;

        for (int j = 0; j < MEASUREMENTS; ++j) {
            int randomNumber = dis(gen);
            totalDuration += measure_time([&] { mySet.contains(randomNumber); }) / MEASUREMENTS;
        }

        std::cout << i << " " << totalDuration << std::endl;
    }
}

void showEqualityComplexity() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 1; i <= N; ++i) {
        std::uniform_int_distribution<> dis(0, i-1);

        setSimple *set1 = new setSimple(i);
        setSimple *set2 = new setSimple(i);

        for (int j = 0; j < i; ++j) {
            int value = dis(gen);
            set1->insert(value);
            set2->insert(value); // Wstawiamy tę samą wartość do obu zbiorów
        }

        double totalDuration = 0.0;

        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] {(*set1) == (*set2);})/MEASUREMENTS;
        }
        std::cout << i << " " << totalDuration << std::endl;

        delete set1;
        delete set2;
    }
}
void showIntersectionComplexity(){
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 1; i <= N; ++i) {
        std::uniform_int_distribution<> dis(0, i-1);

        setSimple *set1 = new setSimple(i);
        setSimple *set2 = new setSimple(i);

        for (int j = 0; j < i; ++j) {
            int value = dis(gen);
            set1->insert(value);
            set2->insert(value);
        }

        double totalDuration = 0.0;

        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] {(*set1) | (*set2);})/MEASUREMENTS;
        }
        std::cout << i << " " << totalDuration << std::endl;

        delete set1;
        delete set2;
    }
}

void showDifferenceComplexity(){
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 1; i <= N; ++i) {
        std::uniform_int_distribution<> dis(0, i-1);

        setSimple *set1 = new setSimple(i);
        setSimple *set2 = new setSimple(i);

        for (int j = 0; j < i; ++j) {
            int value = dis(gen);
            set1->insert(value);
            set2->insert(value);
        }

        double totalDuration = 0.0;

        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] {(*set1) - (*set2);})/MEASUREMENTS;
        }
        std::cout << i << " " << totalDuration << std::endl;

        delete set1;
        delete set2;
    }
}




int main() {
    int choice;
    std::cout << "Select operation to test:" << std::endl;
    std::cout << "1. Insert Complexity" << std::endl;
    std::cout << "2. Remove Complexity" << std::endl;
    std::cout << "3. Sum Complexity" << std::endl;
    std::cout << "4. Contains Complexity" << std::endl;
    std::cout << "5. Equals Complexity" << std::endl;
    std::cout <<"6. Intersection Complexity" << std::endl;
    std::cout <<"7. Difference Complexity"<<std::endl;
    std::cout << "Enter choice (1-5): " << std::endl;
    std::cin >> choice;

    switch(choice) {
        case 1: showInsertComplexity(); break;
        case 2: showRemoveComplexity(); break;
        case 3: showSumComplexity(); break;
        case 4: showContainsComplexity(); break;
        case 5: showEqualityComplexity(); break;
        case 6: showIntersectionComplexity(); break;
        case 7: showDifferenceComplexity(); break;
        default: std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
