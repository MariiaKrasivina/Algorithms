#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* l;
    Node* r;
};

struct Tree {

    bool exist(Node* node, string name) {
        if (node == nullptr)
            return false;
        if (node->name == name)
            return true;
        else if (node->name > name)
            return exist(node->l, name);
        else
            return exist(node->r, name);
    }

    Node* create(string name) {
        Node* newnode = new Node;
        newnode->name = name;
        newnode->l = newnode->r = nullptr;
        return newnode;
    }

    Node* insert(Node* node, string name) {
        if (node == nullptr)
            return create(name);

        if (name < node->name)
            node->l = insert(node->l, name);
        else if (name > node->name)
            node->r = insert(node->r, name);

        return node;
    }

    Node* remove(Node* node, string name) {
        if (node == nullptr)
            return node;

        if (name < node->name)
            node->l = remove(node->l, name);
        else if (name > node->name)
            node->r = remove(node->r, name);
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
            node->name = tmp->name;
            node->r = remove(node->r, tmp->name);
        }
        return node;
    }

    bool empty(Node* node){
        if (node == nullptr)
            return true;
        return false;
    }
};

int main() {
    int n;
    cin >> n;

    Tree a;
    Node* aroot = nullptr;
    Tree ha;
    Node* haroot = nullptr;
    Tree b;
    Node* broot = nullptr;
    Tree hb;
    Node* hbroot = nullptr;
    Tree c;
    Node* croot = nullptr;
    string name;

    for (int i = 0; i < 3*n; i++){
        cin >> name;
        if (i < n) {
            aroot = a.insert(aroot, name);
            haroot = ha.insert(haroot, name);
        }
        if (i >= n && i < 2*n){
            broot = b.insert(broot, name);
            hbroot = hb.insert(hbroot, name);
        }
        else if (i >= 2*n && i < 3*n) {
            croot = c.insert(croot, name);
        }
    }

    int cnt = 0;
    int ia = 0, ib = 0, ic = 0;

    while (cnt < 3){
        while (!a.empty(aroot)) {
            name = aroot->name;
            aroot = a.remove(aroot, name);
            if (b.exist(broot, name) && c.exist(croot, name)) {
                ia += 0;
            }
            if ((b.exist(broot, name) && !c.exist(croot, name)) || (!b.exist(broot, name) && c.exist(croot, name))) {
                ia += 1;
            }
            if (!b.exist(broot, name) && !c.exist(croot, name)) {
                ia += 3;
            }
        }
        cnt++;
        while (!b.empty(broot)) {
            name = broot->name;
            broot = b.remove(broot, name);
            if (ha.exist(haroot, name) && c.exist(croot, name)) {
                ib += 0;
            }
            if ((ha.exist(haroot, name) && !c.exist(croot, name)) || (!ha.exist(haroot, name) && c.exist(croot, name))) {
                ib += 1;
            }
            if (!ha.exist(haroot, name) && !c.exist(croot, name)) {
                ib += 3;
            }
        }
        cnt++;
        while (!c.empty(croot)) {
            name = croot->name;
            croot = c.remove(croot, name);
            if (ha.exist(haroot, name) && hb.exist(hbroot, name)) {
                ic += 0;
            }
            if ((ha.exist(haroot, name) && !hb.exist(hbroot, name)) || (!ha.exist(haroot, name) && hb.exist(hbroot, name))) {
                ic += 1;
            }
            if (!ha.exist(haroot, name) && !hb.exist(hbroot, name)) {
                ic += 3;
            }
        }
        cnt++;
    }

    cout << ia << " " << ib << " " << ic;

    return 0;
}
