#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* l;
    Node* r;
};

struct Tree {

    bool exists(Node* node, int val) {
        if (node == nullptr)
            return false;
        if (node->val == val)
            return true;
        else if (node->val > val)
            return exists(node->l, val);
        else
            return exists(node->r, val);
    }

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

    int sum(Node* zap){
        if (zap == nullptr)
            return 0;

        int suml = sum(zap->l);
        int sumr = sum(zap->r);

        int itog = suml + sumr + zap->val;
        return itog;
    }

    void inorder(Node* node, vector <int> &a){
        if (node == nullptr)
            return;
        inorder(node->l, a);
        a.push_back(node->val);
        inorder(node->r, a);
    }

    Node* merge(Node* osn,  Node* zap){
        while (zap != nullptr) {
            osn = insert(osn, zap->val);
            zap = remove(zap, zap->val);
        }
        return osn;
    }
};

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    Tree a, b;
    Node* osn = nullptr;
    Node* zap = nullptr;
    string act;

    while (cnt != n){
        cin >> act;
        if (act == "buy"){
            int x;
            cin >> x;
            int val;
            cin >> val;
            if (x == 1){
                osn = a.insert(osn, val);
            }
            else if (x == 2){
                zap = b.insert(zap, val);
            }
        }

        if (act == "sell"){
            int x, val;
            cin >> x;
            cin >> val;
            if (x == 1)
                osn = a.remove(osn, val);
            else if (x == 2)
                zap = b.remove(zap, val);
        }

        else if (act == "merge"){
            osn = a.merge(osn, zap);
            zap = nullptr;
            vector <int> itog;
            a.inorder(osn, itog);
            if (!itog.empty()) {
                for (int i = 0; i < itog.size(); i++) {
                    if (i == itog.size() - 1)
                        cout << itog[i] << "\n";
                    else
                        cout << itog[i] << " ";
                }
            }
        }
        cnt++;
    }

    return 0;
}
