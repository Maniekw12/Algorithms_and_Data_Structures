#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <limits>
#include <fstream>

using namespace std;

const int INF = 1e9;


int main() {
    vector<tuple<string, string, int>> edges = {
            {"Poznań",               "Łódź",                 140},
            {"Łódź",                 "Warszawa",             98},
            {"Warszawa",             "Białystok",            132},
            {"Białystok",            "Augustów",             75},
            {"Augustów",             "Olsztyn",              170},
            {"Olsztyn",              "Elbląg",               74},
            {"Elbląg",               "Gdańsk",               39},
            {"Gdańsk",               "Gdynia",               31},
            {"Gdańsk",               "Grudziądz",            76},
            {"Grudziądz",            "Bydgoszcz",            73},
            {"Bydgoszcz",            "Włocławek",            79},
            {"Bydgoszcz",            "Poznań",               107},
            {"Włocławek",            "Łódź",                 81},
            {"Łódź",                 "Piotrków_Trybunalski", 51},
            {"Piotrków_Trybunalski", "Radom",                99},
            {"Radom",                "Warszawa",             92},
            {"Warszawa",             "Lublin",               133},
            {"Lublin",               "Białystok",            214},
            {"Radom",                "Lublin",               93},
            {"Lublin",               "Rzeszów",              156},
            {"Rzeszów",              "Tarnów",               58},
            {"Tarnów",               "Kraków",               70},
            {"Kraków",               "Kielce",               102},
            {"Kielce",               "Radom",                60},
            {"Kraków",               "Katowice",             59},
            {"Katowice",             "Częstochowa",          55},
            {"Częstochowa",          "Piotrków_Trybunalski", 89},
            {"Warszawa",             "Olsztyn",              159},
            {"Katowice",             "Opole",                77},
            {"Opole",                "Wrocław",              77},
            {"Wrocław",              "Poznań",               115},
            {"Gdynia",               "Koszalin",             160},
            {"Koszalin",             "Szczecin",             105},
            {"Szczecin",             "Piła",                 144},
            {"Piła",                 "Bydgoszcz",            90},
            {"Piła",                 "Poznań",               103},
            {"Szczecin",             "Gorzów_Wielkopolski",  68},
            {"Gorzów_Wielkopolski",  "Nowy_Dworek",          47},
            {"Nowy_Dworek",          "Poznań",               77},
            {"Nowy_Dworek",          "Legnica",              100},
            {"Legnica",              "Wrocław",              61},
            {"Kraków",               "Zakopane",             116},
            {"Rzeszów",              "Przemyśl",             62}
    };
    // etap budowania grafu
    map<string, int> cityToIndex;
    vector<string> indexToCity;
    int index = 0;

    for (auto &[a, b, time] : edges) {
        if(cityToIndex.find(a) == cityToIndex.end()){
            cityToIndex[a] = index++;
            indexToCity.push_back(a);
        }
        if(cityToIndex.find(b) == cityToIndex.end()){
            cityToIndex[b] = index++;
            indexToCity.push_back(b);
        }
    }

    int n = indexToCity.size();

    // macierz początkowa - reprezentuje graf
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    for(auto &[a,b,time] : edges){
        int u = cityToIndex[a];
        int v = cityToIndex[b];
        dist[u][v] = time;
        dist[v][u] = time;

    }

    for(int k = 0; k < n; ++k)
        for(int i=0; i < n; ++i)
            for(int j=0; j < n; ++j)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    ofstream out("wyniki.txt");
    if(!out.is_open()){
        cerr <<"nie mozna ostworzyc pliku!"<< endl;
        return 1;
    }
    out << "Najkrótsze czasy podróży między miastami (w minutach):\n\n";
    out << setw(18) << left << "Miasto";
    for (int i = 0; i < n; ++i)
        out << setw(18) << left << indexToCity[i];
    out << "\n";

    for (int i = 0; i < n; ++i) {
        out << setw(18) << left << indexToCity[i];
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                out << setw(18) << left << "INF";
            else
                out << setw(18) << left << dist[i][j];
        }
        out << "\n";
    }

    out.close();
    cout << "Wyniki zapisano do pliku 'wyniki.txt'\n";

    return 0;
}