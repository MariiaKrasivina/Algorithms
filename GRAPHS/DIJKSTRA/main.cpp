#include <iostream>
#include <set>
using namespace std;


vector <int> shortest(vector <vector <pair <int, int>>> &graph, int st){

    vector <int> dist(graph.size(), 1e9);
    dist[st] = 0;
    set <pair <int, int>> unvis;
    unvis.insert({dist[st], st});

    while (!unvis.empty()){
        int bv = unvis.begin()->second;
        unvis.erase(unvis.begin());

        for (pair <int, int> &tmp : graph[bv]){
            int &elem = tmp.first;
            int &ves = tmp.second;
            if (dist[elem] > dist[bv] + ves){
                unvis.erase({dist[elem], elem});
                dist[elem] = dist[bv] + ves;
                unvis.insert({dist[elem], elem});
            }
        }

    }

    return dist;
}


int main() {
    int v, r;
    cin >> v >> r;

    vector <vector <pair <int , int>>> graph(v);
    for (int k = 0; k < r; k++) {
        int i, j, ves;
        cin >> i >> j >> ves;
        i--;
        j--;
        graph[i].push_back({j, ves});
    }

    vector <int> itog = shortest(graph, 0);

    if (itog[v - 1] != 1e9)
        cout << itog[v - 1];
    else
        cout << -1;


    return 0;
}