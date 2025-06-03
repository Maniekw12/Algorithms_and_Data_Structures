#include <map>
#include <iostream>
#include <fstream>
#include <list>
#include "Graph.h"

std::map<int, int> colorGraph(ADTgraph& graph) {
    std::map<int, int> colors;
    std::list<int> nodes = graph.getAllVertices();

    while (!nodes.empty()) {
        unsigned long max_neighbors = 0;
        int max_node;

        for (int node : nodes) {
            unsigned long neighbors = graph.neighbors(node).size();
            if (neighbors >= max_neighbors) {
                max_node = node;
                max_neighbors = neighbors;
            }
        }

        int color = 0;
        bool allDifferent = false;
        while (!allDifferent) {
            allDifferent = true;
            for (int neighbor : graph.neighbors(max_node)) {
                if (colors.count(neighbor) == 1 && colors[neighbor] == color) {
                    color++;
                    allDifferent = false;
                    break;
                }
            }
        }

        colors[max_node] = color;
        nodes.remove(max_node);
    }

    return colors;
}

// Save the colored graph to a DOT format file for visualization
void save(const std::string& filename, const std::map<int, int>& colors, ADTgraph& graph) {
    std::ofstream file;
    std::string dotColors[] = {"green", "lightblue", "red", "yellow", "orange", "purple", "pink", "brown", "gray"};
    file.open(filename + ".txt");

    if (!file.is_open()) {
        std::cerr << "Can't open the file " << filename << ".txt" << std::endl;
        return;
    }

    file << "digraph G {\n";
    for (const auto& pair : colors) {
        file << "\"" << graph.getVertexCaption(pair.first) << "\" [fillcolor=\""
             << dotColors[pair.second] << "\", style=filled]\n";
    }
    file << "}";
    file.close();
}

int main() {
    ADTgraph graph;

    // Adding vertices with labels
    graph.addVertex(1, "A-D");
    graph.addVertex(2, "D-A");
    graph.addVertex(3, "D-B");
    graph.addVertex(4, "D-C");
    graph.addVertex(5, "A-B");
    graph.addVertex(6, "A-C");
    graph.addVertex(7, "B-A");
    graph.addVertex(8, "E-D");
    graph.addVertex(9, "E-A");
    graph.addVertex(10, "E-B");
    graph.addVertex(11, "E-C");
    graph.addVertex(12, "B-C");
    graph.addVertex(13, "B-D");

    // Adding edges
    graph.addEdge(1, 10); graph.addEdge(1, 6); graph.addEdge(1, 5); graph.addEdge(1, 7);
    graph.addEdge(1, 11); graph.addEdge(1, 8);
    graph.addEdge(2, 10); graph.addEdge(2, 6); graph.addEdge(2, 5); graph.addEdge(2, 11);
    graph.addEdge(2, 12); graph.addEdge(2, 7); graph.addEdge(2, 8); graph.addEdge(2, 9);
    graph.addEdge(3, 10); graph.addEdge(3, 11); graph.addEdge(3, 12); graph.addEdge(3, 13); graph.addEdge(3, 6);
    graph.addEdge(4, 7); graph.addEdge(4, 10);
    graph.addEdge(5, 1); graph.addEdge(5, 11); graph.addEdge(5, 7); graph.addEdge(5, 8); graph.addEdge(5, 9);
    graph.addEdge(5, 2); graph.addEdge(5, 12);
    graph.addEdge(6, 7); graph.addEdge(6, 1); graph.addEdge(6, 2); graph.addEdge(6, 3);
    graph.addEdge(6, 11); graph.addEdge(6, 12); graph.addEdge(6, 13);
    graph.addEdge(7, 12); graph.addEdge(7, 11); graph.addEdge(7, 2);
    graph.addEdge(7, 5); graph.addEdge(7, 6); graph.addEdge(7, 4); graph.addEdge(7, 10);
    graph.addEdge(8, 2); graph.addEdge(8, 1); graph.addEdge(8, 5); graph.addEdge(8, 12); graph.addEdge(8, 11);
    graph.addEdge(9, 2); graph.addEdge(9, 12); graph.addEdge(9, 5);
    graph.addEdge(10, 1); graph.addEdge(10, 2); graph.addEdge(10, 3); graph.addEdge(10, 7); graph.addEdge(10, 4);
    graph.addEdge(11, 3); graph.addEdge(11, 2); graph.addEdge(11, 1); graph.addEdge(11, 7);
    graph.addEdge(11, 8); graph.addEdge(11, 5); graph.addEdge(11, 6);
    graph.addEdge(12, 3); graph.addEdge(12, 2); graph.addEdge(12, 6); graph.addEdge(12, 5);
    graph.addEdge(12, 7); graph.addEdge(12, 8); graph.addEdge(12, 9);
    graph.addEdge(13, 3); graph.addEdge(13, 6);

    std::map<int, int> colors = colorGraph(graph);

    for (const auto& pair : colors) {
        std::cout << graph.getVertexCaption(pair.first) << " - " << pair.second << std::endl;
    }

    save("colors", colors, graph);

    return 0;
}
