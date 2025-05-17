#include <iostream>
#include <cassert>
#include "GraphList.h"  // jeśli masz klasę w osobnym pliku, inaczej wklej kod przed main

int main() {
    Graph g;

    // Dodawanie wierzchołków
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);

    assert(g.size() == 3);

    // Dodawanie krawędzi
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    assert(g.adjacent(1, 2));
    assert(g.adjacent(1, 3));
    assert(!g.adjacent(2, 1));

    // Sąsiedzi
    std::list<int> neighbours = g.getNeighbours(1);
    assert(neighbours.size() == 2);
    assert(std::find(neighbours.begin(), neighbours.end(), 2) != neighbours.end());
    assert(std::find(neighbours.begin(), neighbours.end(), 3) != neighbours.end());

    // Wartości wierzchołków
    g.setVertexValue(1, 42);
    assert(g.getVertexValue(1) == 42);

    g.setVertexValue(2, 7);
    assert(g.getVertexValue(2) == 7);

    assert(g.getVertexValue(999) == -1); // nieistniejący wierzchołek

    // Wartości krawędzi
    g.setEdgeValue(1, 2, 99);
    assert(g.getEdgeValue(1, 2) == 99);
    assert(g.getEdgeValue(1, 3) == 0); // domyślnie 0
    assert(g.getEdgeValue(2, 1) == -1); // brak krawędzi

    // Usuwanie krawędzi
    g.removeEdge(1, 2);
    assert(!g.adjacent(1, 2));
    assert(g.adjacent(1, 3));

    // Usuwanie wierzchołka
    g.removeVertex(3);
    assert(!g.adjacent(1, 3));
    assert(g.size() == 2);

    std::cout << "All tests passed successfully!\n";
    return 0;
}
