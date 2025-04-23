#include <iostream>
#include "dictionarySimple.h"
#include <random>
#include <chrono>
#include <sstream>

#define N 700
#define STRING_SIZE 5
#define MEASUREMENTS 2

using namespace std::chrono;

std::string generateRandomString(size_t length) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, characters.size() - 1);
    std::string randomString;
    for (size_t i = 0; i < length; ++i) {
        randomString += characters[dis(gen)];
    }
    return randomString;
}

template<typename Func>
long long measure_time(Func func) {
    const auto beg = high_resolution_clock::now();
    func();
    const auto end = high_resolution_clock::now();
    return duration_cast<nanoseconds>(end - beg).count();
}
void showInsertComplexity() {
    std::vector<std::string> fillStrings;
    for (int i = 0; i < N; ++i) {
        fillStrings.push_back(generateRandomString(STRING_SIZE));
    }

    std::vector<std::string> testStrings;
    for (int i = 0; i < MEASUREMENTS; ++i) {
        testStrings.push_back(generateRandomString(STRING_SIZE));
    }

    for (int i = 0; i < N; ++i) {
        dictionarySimple *mySet = new dictionarySimple;

        for(int j = 0; j < i && j < fillStrings.size(); ++j) {
            mySet->insert(fillStrings[j]);
        }

        long long totalDuration = 0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] {
                mySet->insert(testStrings[j]);
            });
        }

        long long averageDuration = totalDuration / MEASUREMENTS;

        std::cout << i << " " << averageDuration << std::endl;
        delete mySet;
    }
}

void showRemoveComplexity() {
    std::vector<std::string> fillStrings;
    for (int i = 0; i < N; ++i) {
        fillStrings.push_back(generateRandomString(STRING_SIZE));
    }

    std::vector<std::string> testStrings;
    for (int i = 0; i < MEASUREMENTS; ++i) {
        testStrings.push_back(generateRandomString(STRING_SIZE));
    }

    for (int i = 0; i < N; i += 1) {
        dictionarySimple *mySet = new dictionarySimple;

        for (int j = 0; j < i; ++j) {
            mySet->insert(fillStrings[j]);
        }

        for (int j = 0; j < MEASUREMENTS; ++j) {
            mySet->insert(testStrings[j]);
        }

        long long totalDuration = 0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] {
                mySet->remove(testStrings[j]);
            });
        }

        long long averageDuration = totalDuration / MEASUREMENTS;

        std::cout << i << " " << averageDuration << std::endl;
        delete mySet;
    }
}

void showContainsComplexity() {
    std::vector<std::string> fillStrings;
    for (int i = 0; i < N; ++i) {
        fillStrings.push_back(generateRandomString(STRING_SIZE));
    }

    std::vector<std::string> testStrings;
    for (int i = 0; i < MEASUREMENTS; ++i) {
        testStrings.push_back(generateRandomString(STRING_SIZE));
    }

    for (int i = 0; i < N; i += 1) {
        dictionarySimple *mySet = new dictionarySimple;

        for (int j = 0; j < i; ++j) {
            mySet->insert(fillStrings[j]);
        }

        long long totalDuration = 0;
        for (int j = 0; j < MEASUREMENTS; ++j) {
            totalDuration += measure_time([&] {
                mySet->contains(testStrings[j]);
            });
        }

        long long averageDuration = totalDuration / MEASUREMENTS;

        std::cout << i << " " << averageDuration << std::endl;
        delete mySet;
    }
}

int main() {
    int choice;
    std::cout << "Select operation to test:" << std::endl;
    std::cout << "1. Insert Complexity" << std::endl;
    std::cout << "2. Remove Complexity" << std::endl;
    std::cout << "3. Contains Complexity" << std::endl;
    std::cout << "Enter choice (1-3): " << std::endl;
    std::cin >> choice;

    switch(choice) {
        case 1: showInsertComplexity(); break;
        case 2: showRemoveComplexity(); break;
        case 3: showContainsComplexity(); break;
        default: std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}