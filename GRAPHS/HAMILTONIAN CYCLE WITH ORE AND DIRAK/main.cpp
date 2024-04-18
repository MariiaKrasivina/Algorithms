#include <iostream>
#include <vector>
#include <deque>
//#include "blazingio.hpp"
using namespace std;

bool findelem(vector <int> &gde, int isk){
    for (int i = 0; i < gde.size(); i++){
        if (gde[i] == isk)
            return true;
    }
    return false;
}

int main() {

    int v, r;
    cin >> v >> r;

    deque <int> cikl;
    vector <vector <int>> graph(v);
    vector <int> pov(v, -1);

    for (int i = 0; i < r; i++) {
        int a, b;
        cin >> a >> b;

        if (pov[a] == -1){
            pov[a] = 0;
            cikl.push_back(a);
        }

        if (pov[b] == -1){
            pov[b] = 0;
            cikl.push_back(b);
        }

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (v > 2){

        for (int i = 0; i < v * (v - 1); i++){

            if (!findelem(graph[cikl[0]], cikl[1])) {

                int k = 2;

                while (!findelem(graph[cikl[0]], cikl[k]) || !findelem(graph[cikl[1]], cikl[k + 1])) {
                    k++;
                }

                for (int j = 1; j < k / 2 + 1; j++){
                    swap(cikl[j], cikl[k + 1 - j]);
                }
            }

            cikl.push_back(cikl.front());
            cikl.pop_front();
        }

        for (int i = 0; i < v; i++){
            cout << cikl[i] << " ";
        }

    }
    return 0;
}