#include <iostream>
using namespace std;


void dfs_top(vector <vector <int>> &graph, int i, vector <int> &vis, int ish, bool &itog){

    vis[i] = 1;
    for (int j = 0; j < graph[i].size(); j++){
        int elem = graph[i][j];
        if (elem == ish)
            continue;
        else if (vis[elem] == 0)
            dfs_top(graph, elem, vis, i, itog);
        else if (vis[elem] == 1)
            itog = true;
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
        if (i == j)
            continue;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }

    vector <int> vis(v);
    bool itog = false;

    for (int i = 0; i < v; i++){
        if (itog == true)
            break;
        else if (vis[i] == 0)
            dfs_top(graph, i, vis, -1, itog);
    }

    if (itog == true)
        cout << "YES";
    else
        cout << "NO";



    return 0;
}
