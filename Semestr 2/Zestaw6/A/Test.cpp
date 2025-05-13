#include <iostream>
#include <vector>
#include <algorithm>
#include "KnightTour.h"

int main() {
    int size;
    std::cout << "Podaj rozmiar szachownicy:";
    std::cin >> size;

    int start_x, start_y;
    std::cout << "Podaj pozycję początkową skoczka (0-" << size-1 << "): " << std::endl;
    std::cout << "Wiersz: ";
    std::cin >> start_x;
    std::cout << "Kolumna: ";
    std::cin >> start_y;

    KnightTour tour(size);

    std::cout << "\nSzukanie trasy skoczka..." << std::endl;

    if (tour.solve(start_x, start_y)) {
        std::cout << "\nZnaleziono trasę! Numeracja pól oznacza kolejne ruchy skoczka:" << std::endl;
        tour.print_solution();
    } else {
        std::cout << "Nie znaleziono rozwiązania dla podanej pozycji startowej." << std::endl;
    }

    return 0;
}
