#include <iostream>
using namespace std;

void dfs_top(vector <vector <int>> &inv_graph, int i, vector <int> &vis, vector <int> &top_sort){

    vis[i] = 1;
    for (int j = 0; j < inv_graph[i].size(); j++){
        int elem = inv_graph[i][j];
        if (vis[elem] == 0)
            dfs_top(inv_graph, elem, vis, top_sort);
    }
    top_sort.push_back(i);
}

void dfs_comp(vector <vector <int>> &graph, int i, vector <int> &vis, int &cnt_comp){
    vis[i] = cnt_comp;
    for (int j = 0; j < graph[i].size(); j++){
        int elem = graph[i][j];
        if (vis[elem] == 0)
            dfs_comp(graph, elem, vis, cnt_comp);
    }
}


int main() {

    int v, r, cnt_zap;
    cin >> v >> r >> cnt_zap;

    vector <vector <int>> graph(v), inv_graph(v);
    vector <int> vis(v, 0), top_sort;

    for (int k = 0; k < r; k++){
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        graph[i].push_back(j);
        inv_graph[j].push_back(i);
    }

    for (int i = 0; i < v; i++){
        if (vis[i] == 0)
            dfs_top(inv_graph, i, vis, top_sort);
    }

    reverse(top_sort.begin(), top_sort.end());

    int cnt_comp = 0;
    vector <int> vis1(v, 0);

    for (int i = 0; i < top_sort.size(); i++){
        int elem = top_sort[i];
        if (vis1[elem] == 0)
            dfs_comp(graph, elem, vis1, ++cnt_comp);
    }

    for (int k = 0; k < cnt_zap; k++){
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        if (vis1[i] == vis1[j])
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}