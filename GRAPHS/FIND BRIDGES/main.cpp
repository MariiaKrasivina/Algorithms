#include <iostream>
#include <set>
#include <vector>
using namespace std;


void most(vector<vector<int>> &graph, int i, vector<int> &vis, vector<int> &cnt_vis, vector<int> &min_vis, int cnt, int predok, set<pair<int, int>> &itog) {
    vis[i] = 1;
    cnt_vis[i] = cnt++;
    min_vis[i] = cnt++;

    for (int j = 0; j < graph[i].size(); j++) {
        int elem = graph[i][j];

        if (elem == predok)
            continue;

        if (vis[elem] == 1)
            min_vis[i] = min(min_vis[i], cnt_vis[elem]);
        else {
            most(graph, elem, vis, cnt_vis, min_vis, cnt, i, itog);
            min_vis[i] = min(min_vis[i], min_vis[elem]);

            if (min_vis[elem] > cnt_vis[i])
                itog.insert(make_pair(min(i, elem), max(i,elem)));
        }
    }
}

int main() {
    int v, r;
    cin >> v >> r;

    vector<vector<int>> graph(v);
    for (int k = 0; k < r; k++) {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }

    vector<int> vis(v, 0);
    set<pair<int, int>> itog;
    vector<int> cnt_vis(v);
    vector<int> min_vis(v);
    int cnt = 0;

    for (int i = 0; i < v; i++) {
        if (vis[i] == 0)
            most(graph, i, vis, cnt_vis, min_vis, cnt, -1, itog);
    }

    for (auto i : itog)
        cout << i.first + 1 << " " << i.second + 1 << "\n";

    return 0;
}

