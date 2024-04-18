#include <iostream>
using namespace std;

struct Tree{
    int val;
    Tree *l;
    Tree *r;
    Tree(int k): val(k), l(nullptr), r(nullptr) {};
};

void preorder(Tree *root){
    if (root == nullptr)
        return;
    cout << root->val << " ";
    preorder(root->l);
    preorder(root->r);
}

Tree* doTree(int mas[], int s, int f){

    if (s > f)
        return nullptr;

    int mid = (s + f) / 2;
    Tree* root = new Tree(mas[mid]);
    root->l = doTree(mas, s, mid - 1);
    root->r = doTree(mas, mid + 1, f);

    return root;
}


int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){cin >> a[i];}

    Tree* root = doTree(a, 0, n - 1);
    preorder(root);

    return 0;
}
