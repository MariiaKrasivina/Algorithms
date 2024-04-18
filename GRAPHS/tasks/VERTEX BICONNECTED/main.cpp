#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void paint(stack <int> &s, int i, vector <int> &colors, int &cntcol){
    cntcol++;
    int last = -1;

    while ((last != i) && (!s.empty())){
        colors[s.top()] = cntcol;
        last = s.top();
        s.pop();
    }
}

void dfs(vector<vector<int>> &graph, int i, vector<int> &vis, vector<int> &timein, vector<int> &mini, int time, int predok, stack <int> &s, vector <int> &colors, int &cntcol) {
    vis[i] = 1;
    timein[i] = time++;
    mini[i] = time++;
    s.push(i);

    for (int j = 0; j < graph[i].size(); j++) {
        int elem = graph[i][j];

        if (elem == predok)
            continue;

        if (vis[elem] == 1)
            mini[i] = min(mini[i], timein[elem]);

        else {
            dfs(graph, elem, vis, timein, mini, time, i, s, colors, cntcol);
            mini[i] = min(mini[i], mini[elem]);

            if (mini[elem] > timein[i])
                paint(s, elem, colors, cntcol);
        }
    }
}

int main() {
    int v, r, kz;
    cin >> v >> r >> kz;
    v++;

    vector<vector<int>> graph(v);
    for (int k = 0; k < r; k++) {
        int i, j;
        cin >> i >> j;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }

    vector<int> vis(v, 0);
    vector<int> timein(v);
    vector<int> mini(v);
    stack <int> s;
    vector <int> colors(v);
    int cntcol = 0;
    int time = 0;

    for (int i = 0; i < v; i++) {
        if (vis[i] == 0)
            dfs(graph, i, vis, timein, mini, time, -1, s, colors, cntcol);
    }

    for (int i = 0; i < kz; i++){
        int a, b;
        cin >> a >> b;

        if (colors[a] == colors[b])
            cout << "YES" << "\n";

        else
            cout << "NO" << "\n";
    }

    return 0;
}

