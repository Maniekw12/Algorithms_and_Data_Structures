#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <utility>

class Node{
public:
  int id;
  int value;
  std::list<Node*> neighbours;

    Node(int id, int value) : id(id), value(value) {}
};

class Edge{
public:
    Node* vertex1;
    Node* vertex2;
    int value;

    Edge(Node* vertex1, Node* vertex2, int value)
            : vertex1(vertex1), vertex2(vertex2), value(value) {}
};


class Graph{
private:
    int numVertices;
    std::vector<Node*> vertices;
    std::vector<Edge*> edges;
    int actualID = 0;
public:
    Graph(){
    }

    void addVertex(int value){
        Node* newNode = new Node(actualID, value);
        actualID++;
        vertices.push_back(newNode);
    }

    void setVertexValue(Node *node,int value){
        node->value = value;
    }

    void setEdgeValue(Node* vertex1, Node* vertex2, int value) {
        for (Edge* edge : edges) {
            if ((edge->vertex1 == vertex1 && edge->vertex2 == vertex2) ||
                (edge->vertex1 == vertex2 && edge->vertex2 == vertex1)) {
                edge->value = value;
                return;
            }
        }
        return;
    }

    void addEdge(Node* vertex1, Node* vertex2, int value) {
        vertex1->neighbours.push_back(vertex2);
        vertex2->neighbours.push_back(vertex1);
        Edge* newEdge = new Edge(vertex1, vertex2, value);
        edges.push_back(newEdge);
    }

    void removeEdge(Node* vertex1, Node* vertex2) {
        vertex1->neighbours.remove(vertex2);
        vertex2->neighbours.remove(vertex1);

        std::vector<Edge*> remainingEdges;
        for (Edge* edge : edges) {
            if ((edge->vertex1 == vertex1 && edge->vertex2 == vertex2) ||
                (edge->vertex1 == vertex2 && edge->vertex2 == vertex1)) {
                delete edge;
            } else {
                remainingEdges.push_back(edge);
            }
        }
        edges = remainingEdges;
    }

    std::list<Node*> getNeighbours(Node* node){
        return node->neighbours;
    }

    bool areNeighbours(Node* vertex1, Node* vertex2) {
        for (Node *neighbour: vertex1->neighbours) {
            if (neighbour == vertex2) {
                return true;
            }
        }
        return false;
    }

    int getEdgeValue(Node* vertex1, Node* vertex2) {
        for (Edge *edge: edges) {
            if ((edge->vertex1 == vertex1 && edge->vertex2 == vertex2) ||
                (edge->vertex1 == vertex2 && edge->vertex2 == vertex1)) {
                return edge->value;
            }
        }
        return 0;
    }

    void removeVertex(Node* node){
        for(Node* v : vertices){
            v->neighbours.remove(node);
        }

        std::vector<Edge*> remainingEdges;
        for(Edge* edge : edges){
            if (edge->vertex1 == node || edge->vertex2 == node) {
                delete edge;
            } else {
                remainingEdges.push_back(edge);
            }
        }
        std::vector<Node*> remainingVertices;
        for (Node* v : vertices) {
            if (v != node) {
                remainingVertices.push_back(v);
            }
        }
        vertices = remainingVertices;

        delete node;
    }

    Node* getVertexById(int id) {
        for (Node* v : vertices) {
            if (v->id == id) return v;
        }
        return nullptr;
    }


};


