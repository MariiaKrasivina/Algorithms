#include <iostream>
using namespace std;


void dfs(vector <vector <int>> &graph, int i, vector <int> &vis){

    vis[i] = 1;
    for (int j = 0; j < graph[i].size(); j++){
        int elem = graph[i][j];
        if (vis[elem] == 0)
            dfs(graph, elem, vis);
    }
}


int main() {

    int v, r;
    cin >> v >> r;

    vector <vector <int>> graph(v);
    for (int k = 0; k < r; k++){
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        graph[i].push_back(i);
        graph[i].push_back(j);
        graph[j].push_back(i);
    }

    vector <int> vis(v);
    int cnt = 0;

    for (int i = 0; i < v; i++){
        if (vis[i] == 0)
            cnt++;
        dfs(graph, i, vis);
    }

    cout << cnt;

    return 0;
}
