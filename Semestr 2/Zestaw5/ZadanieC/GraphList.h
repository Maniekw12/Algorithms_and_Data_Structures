#include <vector>
#include <algorithm>
#include <list>
#include <map>

class Graph{
private:
    struct Edge {
        int weight = 0;
        int endNode = -1;
    };

    struct Node {
        int weight = 0;
        std::list<Edge> edges;
    };

    std::map<int, Node> graph; // graf jest przechowywany w mapie id -> NOde, kazdy node zawiera liste wierzcholkow

public:
    void addVertex(int id) {
        Node node;
        graph[id] = node;
    }


    void removeVertex(int id) {
        graph.erase(id);

        for (auto& [key, node] : graph) {
            for (auto it = node.edges.begin(); it != node.edges.end(); ) {
                if (it->endNode == id)
                    it = node.edges.erase(it);
                else
                    ++it;
            }
        }
    }

    bool adjacent (int from, int to){
        for (const Edge& edge : graph.at(from).edges) {
            if (edge.endNode == to)
                return true;
        }
        return false;
    }

    std::list<int> getNeighbours(int id) {
        std::list<int> neighbours;
        for (const Edge& edge : graph.at(id).edges) {
            neighbours.push_back(edge.endNode);
        }
        return neighbours;
    }

    void addEdge(int from, int to) {
        if (graph.count(from) && graph.count(to)) {
            Edge edge;
            edge.endNode = to;
            graph[from].edges.push_back(edge);
        }
    }

    void removeEdge(int from, int to) {
        auto& edges = graph.at(from).edges;
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            if (it->endNode == to) {
                edges.erase(it);
                return;
            }
        }
    }

    void setVertexValue(int id, int value) {
        graph.at(id).weight = value;
    }

    int getVertexValue(int id) {
        if (!graph.count(id))
            return -1;
        return graph.at(id).weight;
    }

    void setEdgeValue(int from, int to, int value) {
        for (Edge& edge : graph.at(from).edges) {
            if (edge.endNode == to) {
                edge.weight = value;
                break;
            }
        }
    }

    int getEdgeValue(int from, int to) {
        for (const Edge& edge : graph.at(from).edges) {
            if (edge.endNode == to)
                return edge.weight;
        }
        return -1;
    }

    int size() const {
        return graph.size();
    }
};

