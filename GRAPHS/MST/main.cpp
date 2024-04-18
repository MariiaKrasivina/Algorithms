#include <iostream>
#include <vector>
using namespace std;

int find(int v, vector<int> &rel, vector<int> &rank) {

    if (v == rel[v])
        return v;

    return rel[v] = find(rel[v], rel, rank);
}

void unite(int a, int b, vector<int> &rel, vector<int> &rank) {

    a = find(a, rel, rank);
    b = find(b, rel, rank);

    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);

        rel[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, r;
    cin >> v >> r;

    vector <pair <int, pair <int, int>>> graph(r);

    for (int i = 0; i < r; i++) {
        int a, b, ves;
        cin >> a >> b >> ves;
        a--;
        b--;

        graph[i].first = ves;
        graph[i].second.first = a;
        graph[i].second.second = b;
    }

    sort(graph.begin(), graph.end());
    vector<int> rel(v);
    vector<int> rank(v, 0);
    int itog = 0;

    for (int i = 0; i < v; i++) { rel[i] = i; }

    for (int i = 0; i < r; i++) {

        int ves = graph[i].first;
        int a = graph[i].second.first;
        int b = graph[i].second.second;

        if (find(a, rel, rank) != find(b, rel, rank)) {
            unite(a, b, rel, rank);
            itog += ves;
        }
    }

    cout << itog;

    return 0;
}
