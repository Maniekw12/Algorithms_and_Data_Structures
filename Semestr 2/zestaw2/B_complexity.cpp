#include <iostream>
#include "setHashed.h"
#include <random>
#include <chrono>

#define N 1000
#define MEASUREMENTS 30.0

using namespace std;
using namespace std::chrono;

template<typename Func>
long long measure_time(Func func) {
    const auto beg = high_resolution_clock::now();
    func();
    const auto end = high_resolution_clock::now();
    return duration_cast<nanoseconds>(end - beg).count();
}

void showInsertComplexity1() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 1; i < N; ++i) {
        setHashed<int>* mySet = new setHashed<int>();
        std::uniform_int_distribution<> dis(1, (i - 1) > 1 ? i-1 : 1);

        for (int j = 0; j < i; ++j) {
            int randomNumber = dis(gen);
            mySet->insertElement(randomNumber);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            int randomNumberToAdd = dis(gen);
            totalDuration += measure_time([&] { mySet->insertElement(randomNumberToAdd); })/MEASUREMENTS;
        }

        delete mySet;
        std::cout << i << " " << totalDuration << std::endl;
    }
}

void showInsertComplexity2() {

    for (int i = 0; i < N; ++i) {
        double totalDuration = 0.0;
        setHashed<int>* mySet = new setHashed<int>();

        for (int j = 0; j < i; ++j) {
            mySet->insertElement(j);
        }

        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] { mySet->insertElement(i); })/MEASUREMENTS;
            mySet->deleteElement(i);
        }
        std::cout << i << " " << totalDuration << std::endl;
        delete mySet;
    }
}
void showInsertComplexity() {

    for (int i = 0; i < N; ++i) {
        double totalDuration = 0.0;
        setHashed<int>* mySet = new setHashed<int>();

        for (int j = 0; j < 50 * N; ++j) {
            mySet->insertElement(j);
        }

        for (int j = 0; j < MEASUREMENTS; ++j) {
          totalDuration += measure_time([&] { mySet->insertElement(0); })/MEASUREMENTS;
          mySet->deleteElement(i);
        }

        std::cout << i << " " << totalDuration << std::endl;
        delete mySet;
    }
}




void showRemoveComplexity1() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 1; i < N; ++i) {
        setHashed<int>* mySet = new setHashed<int>();
        std::uniform_int_distribution<> dis(0, i - 1);

        for (int j = 0; j < i; ++j) {
            int randomNumber = dis(gen);
            mySet->insertElement(randomNumber);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            int randomNumberToRemove = dis(gen);
            mySet->insertElement(randomNumberToRemove);  // Ensure the number exists in the set

            double duration = measure_time([&] { mySet->insertElement(randomNumberToRemove); });
            mySet->insertElement(randomNumberToRemove);  // Re-insert for next measurement
            totalDuration += duration;
        }

        delete mySet;
        std::cout << i << " " << totalDuration/MEASUREMENTS << std::endl;
    }
}

void showRemoveComplexity() {
    setHashed<int>* mySet = new setHashed<int>();

    for (int i = 1; i < N; ++i) {
        double totalDuration = 0.0;

        for (int j = 0; j < MEASUREMENTS; ++j) {
            double duration = measure_time([&] { mySet->deleteElement(i); });
            totalDuration += duration;
        }
        std::cout << i << " " << totalDuration/MEASUREMENTS << std::endl;
    }
    delete mySet;

}

void showSumComplexity2() {
    for (int i = 1; i < N; ++i) {
        setHashed<int> set1;
        setHashed<int> set2;

        if (i < N / 3) {
            for (int j = 0; j < i; ++j) {
                set1.insertElement(j);
                set2.insertElement(i + j);
            }
        } else if (i < 2 * N / 3) {
            for (int j = 0; j < 4 * i; ++j) {
                set1.insertElement(j);
                set2.insertElement(i + j);
            }
        } else {
            for (int j = 0; j < 7 * i; ++j) {
                set1.insertElement(j);
                set2.insertElement(i + j);
            }
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] {
                volatile auto result = set1 + set2; // volatile zapobiega optymalizacji
            });
        }

        double averageDuration = totalDuration / MEASUREMENTS;
        std::cout << i << " " << averageDuration << std::endl;
    }
}

void showSumComplexity() {
    for (int i = 1; i < N; ++i) {
        setHashed<int> set1;
        setHashed<int> set2;

        for (int j = 0; j < i; ++j) {
            set1.insertElement(j);
            set2.insertElement(i + j);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] {
                volatile auto result = set1 + set2;
            });
        }

        double averageDuration = totalDuration / MEASUREMENTS;
        std::cout << i << " " << averageDuration << std::endl;
    }
}


void showIntersectionComplexity1() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 1; i < N; ++i) {
        std::uniform_int_distribution<> dis(0, i - 1);

        setHashed<int>* set1 = new setHashed<int>();
        setHashed<int>* set2 = new setHashed<int>();

        for (int j = 0; j < i; ++j) {
            int randomNumber = dis(gen);
            set1->insertElement(randomNumber);
            set2->insertElement(randomNumber);
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

void showIntersectionComplexity() {

    for (int i = 1; i < N; ++i) {
        setHashed<int>* set1 = new setHashed<int>();
        setHashed<int>* set2 = new setHashed<int>();

        for(int j= 0; j<i ; j++){
            set1->insertElement(j);
            set2->insertElement(j);
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

void showContainsComplexity1() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 1; i < N; ++i) {
        setHashed<int>* mySet = new setHashed<int>();
        std::uniform_int_distribution<> dis(0, i - 1);

        std::vector<int> insertedNumbers;
        for (int j = 0; j < i; ++j) {
            int randomNumber = dis(gen);
            mySet->insertElement(randomNumber);
            insertedNumbers.push_back(randomNumber);
        }

        double totalDuration = 0.0;
        for (int j = 1; j < MEASUREMENTS; ++j) {
            int numberToCheck;
            if (!insertedNumbers.empty()) {
                std::uniform_int_distribution<> idxDis(0, insertedNumbers.size() - 1);
                int idx = idxDis(gen);
                numberToCheck = insertedNumbers[idx];
            } else {
                numberToCheck = dis(gen);
                mySet->insertElement(numberToCheck);
            }

            double duration = measure_time([&] { mySet->contains(numberToCheck); })/MEASUREMENTS;
            totalDuration += duration;
        }

        delete mySet;
        std::cout << i << " " << totalDuration << std::endl;
    }
}

void showContainsComplexity() {

    for (int i = 1; i < N; ++i) {
        setHashed<int>* mySet = new setHashed<int>();

        for (int j = 0; j < i; ++j) {
            mySet->insertElement(j);
        }

        double totalDuration = 0.0;
        for (int j = 1; j < MEASUREMENTS; ++j) {
            double duration = measure_time([&] { mySet->contains(i + i); });
            totalDuration += duration;
        }

        delete mySet;
        std::cout << i << " " << totalDuration/MEASUREMENTS << std::endl;
    }
}

void showEqualityComplexity() {

    for (int i = 1; i < N; ++i) {

        setHashed<int>* set1 = new setHashed<int>();
        setHashed<int>* set2 = new setHashed<int>();

        for (int j = 0; j < i; ++j) {
            set1->insertElement(j);
            set2->insertElement(j);
        }

        double totalDuration = 0.0;
        for (int j = 0; j < MEASUREMENTS; ++j) {

            totalDuration += measure_time([&] {(*set1 == *set2); })/MEASUREMENTS;
        }

        delete set1;
        delete set2;
        std::cout << i << " " << totalDuration << std::endl;
    }
}


void showDifferenceComplexity() {

    for (int i = 1; i < N; ++i) {
        setHashed<int>* set1 = new setHashed<int>();
        setHashed<int>* set2 = new setHashed<int>();

        for (int j = 0; j < i; ++j) {
            set1->insertElement(j);
            set2->insertElement(j);
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
        case 1:
            showInsertComplexity(); break;
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