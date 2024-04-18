#include <iostream>
using namespace std;


void dfs_top(vector <vector <int>> &graph, int i, vector <int> &vis, int pred, vector <int> &tekp, int &cnt_cikl){

    vis[i] = 1;
    tekp[i] = 1;

    for (int j = 0; j < graph[i].size(); j++){
        int elem = graph[i][j];
        if (vis[elem] == 0) {
            dfs_top(graph, elem, vis, i, tekp, cnt_cikl);
        }
        else if (tekp[elem] == 1 && elem != pred) {
            cnt_cikl++;
        }
    }

    tekp[i] = 0;
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

    vector <int> vis(v, 0);
    vector <int> tekp(v, 0);
    int cnt_cikl = 0;
    int cnt_comp = 0;

    for (int i = 0; i < v; i++){
        if (vis[i] == 0) {
            cnt_comp++;
            dfs_top(graph, i, vis, -1, tekp, cnt_cikl);
        }
    }

    if (cnt_comp == 1 && cnt_cikl == 1)
        cout << "ARCHIMEDES";
    else
        cout << "EUCLID";




    return 0;
}
