#include <iostream>
#include <list>
#include <map>
#include "Graph.h"
using namespace std;

void topologicalSortUtil(ADTgraph& graph, string v, map<string, bool>& seen, list<string>& stack) {

    seen[v] = true;

    for(string i : graph.neighbours(v)){
        if(!seen[i]){
            topologicalSortUtil(graph,i,seen,stack);
        }
    }
    stack.push_front(v);

}

list<string> topologicalSort(ADTgraph& adTgraph){
    map<string,bool> seen;
    list<string> stack;

    // set false for every vertice
    for(string i : adTgraph.getVertices()){
        seen[i] = false;
    }

    for(string i : adTgraph.getVertices()){
        if(!seen[i]){
            topologicalSortUtil(adTgraph,i,seen,stack);
        }
    }
    return stack;

}

int main() {

    ADTgraph graf;

    // lista kroków
    graf.addVertex ("1", "Weź 1 jajko");
    graf.addVertex ("2", "Weź 1 łyżkę oleju");
    graf.addVertex ("3", "Weź ¾ szklanki mleka");
    graf.addVertex ("4", "Zmieszaj składniki");
    graf.addVertex ("5", "Podgrzej syrop klonowy");
    graf.addVertex ("6", "Zjedz rumiany naleśnik polany ciepłym syropem klonowym");
    graf.addVertex ("7", "Nagrzej patelnię");
    graf.addVertex ("8", "Wylej część ciasta naleśnikowego na patelnię");
    graf.addVertex ("9", "Gdy naleśnik jest rumiany od spodu przewróć go i podpiecz z drugiej strony");
    // lista zależności pomiędzy krokami
    graf.addEdge("1", "4");
    graf.addEdge("2", "4");
    graf.addEdge("3", "4");
    graf.addEdge("4", "5");
    graf.addEdge("4", "8");
    graf.addEdge("7", "8");
    graf.addEdge("8", "9");
    graf.addEdge("9", "6");
    graf.addEdge("5", "6");

    cout << "Kolejność wykonywania kroków" << endl << endl;

    int i = 1;
    for (string node : topologicalSort(graf)) {
        cout << i << ". " << graf.getVertexValue (node) << endl;
        i++;
    }

    return 0;
}

