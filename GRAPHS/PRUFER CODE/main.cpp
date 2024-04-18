#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &graph, int i, vector<int> &rel) {

    for (int elem : graph[i]) {

        if (elem != rel[i]) {
            rel[elem] = i;
            dfs(graph, elem, rel);
        }
    }
}

void code(vector<vector<int>> &graph, int v, vector<int> &rel, vector<int> &stv) {

    rel[v - 1] = -1;
    dfs(graph, v - 1, rel);

    int mblist = -1;
    for (int i = 0; i < v; ++i) {
        stv[i] = (int) graph[i].size();

        if (stv[i] == 1 && mblist == -1)
            mblist = i;
    }

    int list = mblist;
    for (int i = 0; i < v - 2; ++i) {

        int smez = rel[list];

        cout << smez + 1 << " ";
        --stv[smez];

        if (stv[smez] == 1 && smez < mblist)
            list = smez;

        else {
            ++mblist;
            while (mblist < v && stv[mblist] != 1)
                ++mblist;

            list = mblist;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, r;
    cin >> v >> r;

    vector<vector<int>> graph(v);
    for (int k = 0; k < r; ++k) {
        int i, j;
        cin >> i >> j;
        --i;
        --j;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }

    vector<int> stv(v);
    vector<int> rel(v);

    code(graph, v, rel, stv);

    return 0;
}
