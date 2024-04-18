#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void degcheck(vector <vector<int>> &graph, int v, vector <int> &deg, bool &ncdeg){

    for (int i = 0; i < v; i++){
        if (deg[i] % 2 != 0) {
            ncdeg = true;
            break;
        }
    }
}

void dfs(vector <vector <int>> &graph, int i, vector <int> &vis){

    vis[i] = 1;
    for (int j = 0; j < graph[i].size(); j++){
        int elem = graph[i][j];
        if (vis[elem] == 0)
            dfs(graph, elem, vis);
    }
}

void compcheck(vector <vector<int>> &graph, int v, bool &ccheck){

    int cnt = 0;
    vector <int> vis(v, 0);

    for (int i = 0; i < v; i++){
        if ((vis[i] == 0) && (!graph[i].empty())){
            dfs(graph, i, vis);
            cnt++;
        }

        if (cnt > 1){
            ccheck = true;
            break;
        }
    }
}


int main() {
    int v, r;
    cin >> v >> r;
    vector <vector<int>> graph(v);
    vector <int> deg(v);

    for (int i = 0; i < r; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    bool ncdeg = false;
    degcheck(graph, v, deg, ncdeg);
    bool ccheck = false;
    compcheck(graph, v, ccheck);

    if (ncdeg || ccheck)
        cout << ":(";

    else {

        stack <int> s;
        s.push(0);
        vector <int> itog;

        while (!s.empty()){

            int a = s.top();

            if (!graph[a].empty()){
                int b = graph[a].front();
                graph[a].erase(graph[a].begin());
                graph[b].erase(find(graph[b].begin(), graph[b].end(), a));
                s.push(b);
            }

            else {
                itog.push_back(a);
                s.pop();
            }
        }

        if (itog.size() != r + 1)
            cout << ":(";

        else {
            for (int i = itog.size() - 1; i >= 0; i--){
                cout << itog[i] + 1 << " ";
            }
        }
    }


    return 0;
}