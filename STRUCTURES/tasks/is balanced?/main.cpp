#include <iostream>
using namespace std;

struct Node {
    int l;
    int r;
};

int balance(int cnt, Node tree[], int itog[]){
    if (cnt == 0)
        return 0;

    int l = balance(tree[cnt].l, tree, itog);
    int r = balance(tree[cnt].r, tree, itog);

    int height = max(l, r) + 1;
    itog[cnt] = r - l;
    return height;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    Node Tree[n + 1];
    int itog[n + 1];

    for (int cnt = 1; cnt <= n; ++cnt) {
        int v, l, r;
        cin >> v >> l >> r;
        Tree[cnt].l = l;
        Tree[cnt].r = r;
    }

    balance(1, Tree, itog);

    for (int i = 1; i <= n; i++) {cout << itog[i] << "\n";}

    return 0;
}
