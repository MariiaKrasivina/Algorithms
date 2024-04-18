#include <iostream>
#include "string"
using namespace std;

const int inf = INT_MAX;


struct rebro{
    int a, b, ves;
};


int negative(vector <rebro> &graph, int v, int r){

    vector <int> dist(v);
    vector <int> ocikl(v, -1);
    int tmp;

    for (int i = 0; i < v; i++){
        tmp = -1;

        for (int j = 0; j < r; j++){
            if (dist[graph[j].b] > dist[graph[j].a] + graph[j].ves) {
                dist[graph[j].b] = max(dist[graph[j].a] + graph[j].ves, -inf);
                ocikl[graph[j].b] = graph[j].a;
                tmp = graph[j].b;
            }
        }
    }

    if (tmp == -1)
        return 0;

    else {

        for (int i = 0; i < v; i++){tmp = ocikl[tmp];}

        vector <int> dlina;

        for (int i = tmp; ; i = ocikl[i]){
            dlina.push_back(i);

            if ((i == tmp) && (dlina.size() > 1))
                break;
        }

        return dlina.size();
    }
}


int main() {
    int cnt_graphs, maxi_cikl, cnt = 0;
    cin >> cnt_graphs >> maxi_cikl;
    vector <string> otvet;

    while (cnt < cnt_graphs){
        int v, r;
        cin >> v >> r;

        vector <rebro> graph(r);
        for (auto &[a, b, ves] : graph){
            cin >> a >> b >> ves;
            a--;
            b--;
        }

        int dlina = negative(graph, v, r);

        if ((dlina == 0) || (maxi_cikl > dlina - 1))
            otvet.push_back("YES");

        else
            otvet.push_back("NO");

        cnt++;
    }

    for (int i = 0; i < otvet.size(); i++){
        cout << otvet[i] << "\n";
    }
    return 0;
}