#include <iostream>
#include "ADTgraph.h"

int main() {
    const int SIZE = 5;
    ADTgraph<SIZE> graph;

    std::cout << "Dodawanie wierzcholkow 0, 1, 2\n";
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);

    std::cout << "Dodawanie krawedzi 0->1, 1->2\n";
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);

    std::cout << "Sprawdzenie czy 0 i 1 sa polaczeni: ";
    std::cout << (graph.adjacent(0, 1) ? "TAK\n" : "NIE\n");

    std::cout << "Sprawdzenie czy 0 i 2 sa polaczeni: ";
    std::cout << (graph.adjacent(0, 2) ? "TAK\n" : "NIE\n");

    std::cout << "Ustawianie wartosci wierzcholka 1 = 42\n";
    graph.setVertexValue(1, 42);

    std::cout << "Wartosc wierzcholka 1: " << graph.getVertexValue(1) << "\n";

    std::cout << "Ustawianie wartosci krawedzi 0->1 = 99\n";
    graph.setEdgeValue(0, 1, 99);

    std::cout << "Wartosc krawedzi 0->1: " << graph.getEdgeValue(0, 1) << "\n";

    std::cout << "Sasiedzi wierzcholka 0: ";
    int count;
    int* neigh = graph.neighbours(0, count);
    for (int i = 0; i < count; i++) {
        std::cout << neigh[i] << " ";
    }
    std::cout << "\n";
    delete[] neigh;

    std::cout << "Rozmiar grafu: " << graph.sizeOfgraph() << "\n";

    std::cout << "Usuwanie wierzcholka 1\n";
    graph.removeVertex(1);

    std::cout << "Rozmiar grafu po usunieciu: " << graph.sizeOfgraph() << "\n";
    std::cout << "Czy krawedz 0->1 dalej istnieje? ";
    std::cout << (graph.adjacent(0, 1) ? "TAK\n" : "NIE\n");

    return 0;
}
