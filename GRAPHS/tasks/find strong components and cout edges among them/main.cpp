#include <iostream>
#include <set>
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

void dfs_comp(vector <vector <int>> &graph, int i, vector <int> &comps, int &cnt_comp, vector <vector <int>> &c){
    comps[i] = cnt_comp;
    for (int j = 0; j < graph[i].size(); j++){
        int elem = graph[i][j];
        if (comps[elem] == 0) {
            c[cnt_comp - 1].push_back(elem);
            dfs_comp(graph, elem, comps, cnt_comp, c);
        }
    }
}

void cnt_roads(vector <vector <int>> &graph, int i, vector <int> &vis, set <pair<int, int>> &dorogi){
    for (int j = 0; j < graph[i].size(); j++){
        int elem = graph[i][j];
        if (vis[i] == vis[elem])
            continue;
        else {
            dorogi.insert(make_pair(vis[i], vis[elem]));
        }
    }
}


int main() {

    int v, r;
    cin >> v >> r;

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
    vector <int> comps(v, 0);
    vector <vector <int>> c(v);

    for (int i = 0; i < top_sort.size(); i++) {
        int elem = top_sort[i];
        if (comps[elem] == 0) {
            c[cnt_comp].push_back(elem);
            dfs_comp(graph, elem, comps, ++cnt_comp, c);
        }
    }

    for (int i = 0; i < cnt_comp; i++){
        sort(c[i].begin(), c[i].end());
    }

    for (int i = 0; i < v; i++){
        comps[i] = c[comps[i] - 1][0] + 1;
    }

    set <pair<int, int>> dorogi;

    for (int i = 0; i < v; i++){
        cnt_roads(graph, i, comps, dorogi);
    }

    cout << cnt_comp << " " << dorogi.size() << "\n";
    if (!dorogi.empty()) {
        for (auto i: dorogi) {
            cout << i.first << " " << i.second << "\n";
        }
    }


    return 0;
}

/*
5 6
5 2
2 3
3 5
4 1
1 4
5 1
 */