#include "GraphList.h"
#include "iostream"
#include "cassert"
int main() {
    Graph g;

    // Dodawanie wierzchołków
    g.addVertex(10); // id = 0
    g.addVertex(20); // id = 1
    g.addVertex(30); // id = 2

    Node* n0 = g.getVertexById(0);
    Node* n1 = g.getVertexById(1);
    Node* n2 = g.getVertexById(2);

    assert(n0 != nullptr);
    assert(n1 != nullptr);
    assert(n2 != nullptr);
    assert(n0->value == 10);
    assert(n1->value == 20);
    assert(n2->value == 30);

    // Zmiana wartości wierzchołka
    g.setVertexValue(n0, 99);
    assert(n0->value == 99);

    // Dodawanie krawędzi
    g.addEdge(n0, n1, 5);
    assert(g.areNeighbours(n0, n1));
    assert(g.areNeighbours(n1, n0));
    assert(g.getEdgeValue(n0, n1) == 5);
    assert(g.getEdgeValue(n1, n0) == 5);

    // Zmiana wartości krawędzi
    g.setEdgeValue(n0, n1, 7);
    assert(g.getEdgeValue(n0, n1) == 7);

    // Dodawanie drugiej krawędzi
    g.addEdge(n1, n2, 3);
    assert(g.areNeighbours(n1, n2));
    assert(g.getEdgeValue(n1, n2) == 3);

    // Usuwanie krawędzi
    g.removeEdge(n0, n1);
    assert(!g.areNeighbours(n0, n1));
    assert(g.getEdgeValue(n0, n1) == 0);

    // Usuwanie wierzchołka (sprawdzenie czy usuwa krawędź też)
    g.removeVertex(n1);
    assert(g.getVertexById(1) == nullptr);
    assert(!g.areNeighbours(n2, n1));

    // Dodanie nowego wierzchołka i krawędzi do testu sąsiadów
    g.addVertex(40); // id = 3
    Node* n3 = g.getVertexById(3);
    g.addEdge(n2, n3, 6);
    std::list<Node*> neighbours = g.getNeighbours(n2);
    assert(neighbours.size() == 1);
    assert(neighbours.front() == n3);

    std::cout << "all tests passed successfully! :)\n";
    return 0;
}

