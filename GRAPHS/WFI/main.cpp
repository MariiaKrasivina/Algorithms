#include <iostream>
#include <vector>

using namespace std;

int INF = LLONG_MAX;

int main() {
    unsigned long long v, r;
    cin >> v >> r;

    vector<vector<unsigned long long>> graph(v, vector<unsigned long long>(v, INF));

    for (unsigned long long k = 0; k < r; k++) {
        unsigned long long i, j, ves;
        cin >> i >> j >> ves;
        i--;
        j--;

        graph[i][j] = min(graph[i][j], ves);
        graph[j][i] = min(graph[i][j], ves);
    }

    for (unsigned long long i = 0; i < v; i++) {
        graph[i][i] = 0;
    }

    for (unsigned long long k = 0; k < v; k++) {
        for (unsigned long long i = 0; i < v; i++) {
            for (unsigned long long j = 0; j < v; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF && graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    unsigned long long itog_ves = INF;
    unsigned long long itog_v;

    for (unsigned long long i = 0; i < v; i++) {
        unsigned long long summ = 0;

        for (unsigned long long j = 0; j < v; j++) {
            summ += graph[i][j];
        }

        if (itog_ves > summ) {
            itog_ves = summ;
            itog_v = i;
        }
    }
    itog_v++;

    cout << itog_v << '\n';

    return 0;
}