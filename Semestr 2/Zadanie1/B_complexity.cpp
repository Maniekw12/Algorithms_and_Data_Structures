#include <iostream>
#include "setLinked.h"
#include <random>
#include <chrono>
#include <sstream>

#define N 700
#define MEASUREMENTS 100.0
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
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < N; ++i) {
        setLinked<int>* mySet = new setLinked<int>();
        std::uniform_int_distribution<> dis(0, i - 1);

        for (int j = 0; j < i; ++j) {
            int randomNumber = dis(gen);
            mySet->insert(randomNumber);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            int randomNumberToAdd = dis(gen);
            totalDuration += measure_time([&] { mySet->insert(randomNumberToAdd); })/MEASUREMENTS;
        }

        delete mySet;
        std::cout << i << " " << totalDuration << std::endl;
    }
}

void showRemoveComplexity() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < N; ++i) {
        setLinked<int>* mySet = new setLinked<int>();
        std::uniform_int_distribution<> dis(0, i - 1);

        for (int j = 0; j < i; ++j) {
            int randomNumber = dis(gen);
            mySet->insert(randomNumber);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            int randomNumberToRemove = dis(gen);
            mySet->insert(randomNumberToRemove);  // Ensure the number exists in the set

            double duration = measure_time([&] { mySet->remove(randomNumberToRemove); });
            mySet->insert(randomNumberToRemove);  // Re-insert for next measurement
            totalDuration += duration;
        }

        delete mySet;
        std::cout << i << " " << totalDuration/MEASUREMENTS << std::endl;
    }
}

void showSumComplexity() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < N; ++i) {
        std::uniform_int_distribution<> dis(0, i - 1);

        setLinked<int>* set1 = new setLinked<int>();
        setLinked<int>* set2 = new setLinked<int>();

        // Fill both sets with i elements
        for (int j = 0; j < i; ++j) {
            int randomNumber1 = dis(gen);
            int randomNumber2 = dis(gen);
            set1->insert(randomNumber1);
            set2->insert(randomNumber2);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            double duration = measure_time([&] { *set1 + *set2; });
            totalDuration += duration;
        }

        delete set1;
        delete set2;
        std::cout << i << " " << totalDuration/MEASUREMENTS << std::endl;
    }
}

void showIntersectionComplexity() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < N; ++i) {
        std::uniform_int_distribution<> dis(0, i - 1);

        setLinked<int>* set1 = new setLinked<int>();
        setLinked<int>* set2 = new setLinked<int>();

        for (int j = 0; j < i; ++j) {
            int randomNumber = dis(gen);
            set1->insert(randomNumber);
            set2->insert(randomNumber);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            double duration = measure_time([&] { *set1 * *set2; })/MEASUREMENTS;
            totalDuration += duration;
        }

        delete set1;
        delete set2;

        double averageDuration = totalDuration;
        std::cout << i << " " << averageDuration << std::endl;
    }
}

void showContainsComplexity() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < N; ++i) {
        setLinked<int>* mySet = new setLinked<int>();
        std::uniform_int_distribution<> dis(0, i - 1);

        // Fill the set with i elements
        std::vector<int> insertedNumbers;
        for (int j = 0; j < i; ++j) {
            int randomNumber = dis(gen);
            mySet->insert(randomNumber);
            insertedNumbers.push_back(randomNumber);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            // Choose a random number from those we inserted
            int numberToCheck;
            if (!insertedNumbers.empty()) {
                std::uniform_int_distribution<> idxDis(0, insertedNumbers.size() - 1);
                int idx = idxDis(gen);
                numberToCheck = insertedNumbers[idx];
            } else {
                numberToCheck = dis(gen);
                mySet->insert(numberToCheck);
            }

            double duration = measure_time([&] { mySet->contains(numberToCheck); });
            totalDuration += duration;
        }

        delete mySet;
        std::cout << i << " " << totalDuration/MEASUREMENTS << std::endl;
    }
}

void showEqualityComplexity() {


    for (int i = 0; i < N; ++i) {

       setLinked<int>* set1 = new setLinked<int>();
       setLinked<int>* set2 = new setLinked<int>();

        // Fill both sets with the same i elements
        for (int j = 0; j < i; ++j) {
            set1->insert(j);
            set2->insert(j);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] { bool ye = (*set1 == *set2); });
        }

        delete set1;
        delete set2;
        std::cout << i << " " << totalDuration/MEASUREMENTS << std::endl;
    }
}

void showDifferenceComplexity() {
    //std::random_device rd;
    //std::mt19937 gen(rd());
    //std::uniform_int_distribution<> dis(0, N - 1);

    for (int i = 0; i < N; ++i) {
        setLinked<int>* set1 = new setLinked<int>();
        setLinked<int>* set2 = new setLinked<int>();

        for (int j = 0; j < i; ++j) {
            //int randomNumber = dis(gen);
            set1->insert(j);
            set2->insert(j);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            double duration = measure_time([&] { *set1 - *set2; });
            totalDuration += duration;
        }

        double averageDuration = totalDuration;
        std::cout << i << " " << averageDuration/MEASUREMENTS << std::endl;

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
    std::cout << "4. Intersection Complexity" << std::endl;
    std::cout << "5. Contains Complexity" << std::endl;
    std::cout << "6. Equals complexity" << std::endl;
    std::cout << "7. Difference complexity "<< std::endl;
    std::cout << "Enter choice (1-7): "<< std::endl;
    std::cin >> choice;

    switch(choice) {
        case 1: showInsertComplexity(); break;
        case 2: showRemoveComplexity(); break;
        case 3: showSumComplexity(); break;
        case 4: showIntersectionComplexity(); break;
        case 5: showContainsComplexity(); break;
        case 6: showEqualityComplexity(); break;
        case 7: showDifferenceComplexity(); break;
        default: std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}