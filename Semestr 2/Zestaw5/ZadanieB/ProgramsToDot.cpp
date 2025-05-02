#include "ADTgraph.h"
#include "iostream"

int main() {
    ADTgraph<6> graph;

    for (int i = 0; i < 6; i++) {
        graph.addVertex(i);
    }

    graph.setVertexValue(0, 10);
    graph.setVertexValue(1, 20);
    graph.setVertexValue(2, 30);
    graph.setVertexValue(3, 40);
    graph.setVertexValue(4, 50);
    graph.setVertexValue(5, 60);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(0, 5);

    graph.exportToDot("example_graph.dot");

    std::cout << "Graf został zapisany do pliku example_graph.dot" << std::endl;
    return 0;
}
