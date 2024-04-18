#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector <int> shortest(vector <vector <pair <int, int>>> &graph, int st){

    vector <int> dist(graph.size(), INT_MAX);
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, r, fn;
    cin >> v >> r >> fn;
    fn--;

    vector <vector <pair <int , int>>> graph(v);
    for (int i = 0; i < r; i++) {
        int ksv, ves;
        cin >> ksv >> ves;
        vector <int> sv(ksv);

        for (int j = 0; j < ksv; j++){
            cin >> sv[j];
            sv[j]--;
        }

        for (int j = 0; j < ksv - 1; j++){
            for (int k = j + 1; k < ksv; k++){
                graph[sv[k]].push_back({sv[j], ves});
                graph[sv[j]].push_back({sv[k], ves});
            }
        }
    }

    vector <int> itog = shortest(graph, 0);
    if (itog[fn] != INT_MAX)
        cout << itog[fn];
    else
        cout << -1;
    return 0;
}
