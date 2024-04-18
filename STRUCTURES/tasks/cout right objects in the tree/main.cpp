#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* l;
    Node* r;
};

struct Tree {

    Node* create(int val) {
        Node* newnode = new Node;
        newnode->val = val;
        newnode->l = newnode->r = nullptr;
        return newnode;
    }

    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return create(val);

        if (val < node->val)
            node->l = insert(node->l, val);
        else if (val > node->val)
            node->r = insert(node->r, val);

        return node;
    }

    Node* remove(Node* node, int val) {
        if (node == nullptr)
            return node;

        if (val < node->val)
            node->l = remove(node->l, val);
        else if (val > node->val)
            node->r = remove(node->r, val);
        else {
            if (node->l == nullptr) {
                Node* tmp = node->r;
                delete node;
                return tmp;
            } else if (node->r == nullptr) {
                Node* tmp = node->l;
                delete node;
                return tmp;
            }
            Node* tmp = node->r;
            while (tmp && tmp->l != nullptr)
                tmp = tmp->l;
            node->val = tmp->val;
            node->r = remove(node->r, tmp->val);
        }

        return node;
    }

    void itog(Node* node, int l, int &maxil){
        if (node == nullptr)
            return;

        if (l > maxil){
            cout << node->val << " ";
            maxil = l;
        }

        itog(node->r, l + 1, maxil);
        itog(node->l, l + 1, maxil);
    }
};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    Tree a;
    Node* node = nullptr;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        node = a.insert(node, x);
    }

    int maxil = 0;
    a.itog(node, 1, maxil);

    return 0;
}
