#include <iostream>
using namespace std;

void dfs(vector <vector <int>> &graph, int i, vector <int> &vis, int fn, bool &itog){

    vis[i] = 1;
    for (int j = 0; j < graph[i].size(); j++){
        int elem = graph[i][j];
        if (elem == fn) {
            itog = true;
            return;
        }

        if (vis[elem] == 0 && elem != -1)
            dfs(graph, elem, vis, fn, itog);
    }
}

int main() {
    int v, r, q;
    cin >> v >> r >> q;

    vector <vector <int>> graph(v);
    for (int k = 0; k < r; k++) {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }

    vector <int> vis(v, 0);

    cout << "\n";


    for (int i = 0; i < q; i++) {
        char sign;
        int a, b;
        cin >> sign >> a >> b;

        const int tmp_a = a;
        const int tmp_b = b;

        if (sign == '?') {
            if (tmp_a == tmp_b)
                cout << "YES" << "\n";

            else {
                bool itog = false;
                dfs(graph, tmp_a - 1, vis, tmp_b - 1, itog);

                if (itog)
                    cout << "YES" << "\n";
                else
                    cout << "NO" << "\n";

                for (int i = 0; i < vis.size(); i++) {vis[i] = 0;}
            }
        }

        else if (sign == '-') {
            for (int j = 0; j < graph[tmp_a - 1].size(); j++) {
                if (graph[tmp_a - 1][j] == tmp_b - 1) {
                    graph[tmp_a - 1][j] = -1;
                    break;
                }
            }

            for (int j = 0; j < graph[tmp_b - 1].size(); j++) {
                if (graph[tmp_b - 1][j] == tmp_a - 1) {
                    graph[tmp_b - 1][j] = -1;
                    break;
                }
            }
        }

    }

    return 0;
}