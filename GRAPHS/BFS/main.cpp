#include <iostream>
using namespace std;
#include <queue>

const int inf = 1e9;

void bfs(vector <vector <int>> &graph, int st, int kostr, vector <int> &itog){
    vector <int> dist(graph.size(), inf);
    queue <int> que;

    dist[st] = 0;
    que.push(st);

    while (!que.empty()){
        int v = que.front();
        que.pop();

        for (int j = 0; j < graph[v].size(); j++){
            int elem = graph[v][j];

            if (dist[elem] > dist[v] + 1) {
                dist[elem] = dist[v] + 1;
                que.push(elem);

                if (dist[elem] == kostr) {
                    int tmp = elem + 1;
                    itog.push_back(tmp);
                }
            }
        }
    }
}


int main() {

    int v, r, kostr;
    cin >> v >> r >> kostr;

    vector <vector <int>> graph(v);
    for (int k = 0; k < r; k++){
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }

    int st = 0;
    vector <int> itog;

    bfs(graph, st, kostr, itog);


    sort(begin(itog), end(itog));

    if (itog.size() != 0) {
        for (int i = 0; i < itog.size(); i++) {
            cout << itog[i] << "\n";
        }
    }
    else
        cout << "NO";

    return 0;
}
