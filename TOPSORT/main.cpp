#include <iostream>
using namespace std;


void dfs_top(vector <vector <int>> &graph, int i, vector <int> &vis, vector <int> &top_sort){

    vis[i] = 1;
    for (int j = 0; j < graph[i].size(); j++){
        int elem = graph[i][j];
        if (vis[elem] == 0)
            dfs_top(graph, elem, vis, top_sort);
    }
    top_sort.push_back(i);
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
        graph[i].push_back(j);
    }

    vector <int> vis(v);
    vector <int> top_sort;

    for (int i = 0; i < v; i++){
        if (vis[i] == 0)
            dfs_top(graph, i, vis, top_sort);
    }

    reverse(top_sort.begin(), top_sort.end());

    int itog[v];
    int cnt = 1;

    for (int i = 0; i < v; i++){
        itog[top_sort[i]] = cnt;
        cnt++;
    }

    for (int i = 0; i < v; i++){
        cout << itog[i] << "\n";
    }

    return 0;
}
