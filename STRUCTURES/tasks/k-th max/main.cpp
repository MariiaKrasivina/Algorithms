#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* l;
    Node* r;
    int cnt;
};

struct Tree {

    Node* create(int val) {
        Node* newnode = new Node;
        newnode->val = val;
        newnode->l = newnode->r = nullptr;
        newnode->cnt = 1;
        return newnode;
    }

    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return create(val);

        if (val < node->val)
            node->l = insert(node->l, val);
        else if (val > node->val)
            node->r = insert(node->r, val);

        node->cnt++;

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
        node->cnt = 1 + (node->l != nullptr ? node->l->cnt : 0) + (node->r != nullptr ? node->r->cnt : 0);

        return node;
    }

    int maxi(Node* node, int k) {
        if (node == nullptr || k <= 0 || k > node->cnt)
            return -1;

        int cnt = (node->r != nullptr) ? node->r->cnt : 0;

        if (cnt >= k) {
            return maxi(node->r, k);
        } else if (cnt + 1 == k) {
            return node->val;
        } else {
            return maxi(node->l, k - cnt - 1);
        }
    }
};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int act;
    Tree a;
    Node* node = nullptr;

    while (n > 0){
        cin >> act;
        int k;
        cin >> k;

        if (act == 1)
            node = a.insert(node, k);

        if (act == 0)
            cout << "\n" << a.maxi(node, k);

        if (act == -1)
            node = a.remove(node, k);

        n--;
    }

    return 0;
}
