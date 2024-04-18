#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int inf = 1e9;

bool bfs(vector<int> &rel, vector <vector<int>> &graph, int v, vector <vector<int>> &proh) {
    queue<int> q;
    q.push(0);
    rel.assign(v, -1);

    while (!q.empty()) {
        int tek = q.front();
        q.pop();

        for (int elem : graph[tek]) {
            if (rel[elem] == -1 && proh[tek][elem] > 0) {

                rel[elem] = tek;
                q.push(elem);
            }
        }
    }

    return rel[v - 1] != -1;
}


int maxpotok(vector <vector<int>> &graph, int v, vector <vector<int>> &proh) {
    vector <int> rel(v, -1);
    int itog = 0;

    while (bfs(rel, graph, v, proh)) {
        int tekp = inf;

        for (int i = v - 1; i != 0; i = rel[i]) {
            int a = rel[i];
            tekp = min(tekp, proh[a][i]);
        }

        for (int i = v - 1; i != 0; i = rel[i]) {
            int a = rel[i];
            proh[a][i] -= tekp;
            proh[i][a] += tekp;
        }

        itog += tekp;
    }

    return itog;
}

int main() {
    int v, r;
    cin >> v >> r;

    vector <vector<int>> graph(v);
    vector <vector<int>> proh(v, vector<int>(v, 0));

    for (int i = 0; i < r; i++) {
        int a, b, ves;
        cin >> a >> b >> ves;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
        proh[a][b] += ves;
    }


    int itog = maxpotok(graph, v, proh);
    cout << itog;

    return 0;
}