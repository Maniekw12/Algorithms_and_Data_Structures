#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct EdgeTo{
    int v;
    int parent;
    double weight;

    EdgeTo(int vv, int pp, double ww) : v(vv), parent(pp), weight(ww) {}
};

struct CompareEdge {
    bool operator()(const EdgeTo &a, const EdgeTo &b) const {
        return a.weight > b.weight;
    }
};

int main() {
    const int N = 128;

    vector<vector<pair<int, double>>> adj(N+1);
    // czytanie pliku
    ifstream fin("C:\\Users\\Manie\\Desktop\\zestaw2ITD\\Algorithms_and_Data_Structures\\Semestr 2\\Zestaw9\\randgraph.txt");
    if (!fin.is_open()) {
        cerr << "can't open file randgraph.txt\n";
        return 1;
    }
    int v, u;
    double w;
    while (fin >> u >> v >> w) {
        if (u < 1 || u > N || v < 1 || v > N) {
            cerr << "Ostrzeżenie: pominięto krawędź z nieprawidłowym numerem wierzchołka: "
                 << u << " – " << v << "\n";
            continue;
        }
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    fin.close();

    vector<bool> visited(N+1, false);

    priority_queue<EdgeTo, vector<EdgeTo>, CompareEdge> pq;

    vector<tuple<int,int,double>> mst_edges;
    mst_edges.reserve(N-1);

    int start = 1;
    visited[start] = true;
    int visited_count = 1;

    // dodajemy do kolejki, wszyskie krawędzie wychodzace z 1
    for (auto &pair : adj[start]) {
        int next = pair.first;
        double wgt = pair.second;
        pq.emplace(next, start, wgt);
    }

    while (visited_count < N && !pq.empty()) {
        EdgeTo e = pq.top();
        pq.pop();

        int x = e.v;

        if( visited[x]){
            continue;
        }

        visited[x] = true;
        visited_count++;
        mst_edges.emplace_back(e.parent, x, e.weight);

        for (auto &p2 : adj[x]) {
            int y = p2.first;
            double w2 = p2.second;
            if (!visited[y]) {
                pq.emplace(y, x, w2);
            }

        }
    }

    // Każda linia: "u v w" (numer węzła u, numer węzła v, waga w postaci zmiennoprzecinkowej)
    cout << fixed << setprecision(6);
    for (auto &t : mst_edges) {
        int pu = get<0>(t);
        int pv = get<1>(t);
        double pw = get<2>(t);
        cout << pu << " " << pv << " " << pw << "\n";
    }

    return 0;
}