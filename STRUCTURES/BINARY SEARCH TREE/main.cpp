#include <iostream>
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

    void next(Node* node, int key) {
        Node* current = node;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            if (current->val > key) {
                nextNode = current;
                current = current->l;
            } else {
                current = current->r;
            }
        }

        if (nextNode != nullptr) {
            cout << "\n" << nextNode->val;
        } else {
            cout << "\n" << "none";
        }
    }

    void prev(Node* node, int key) {
        Node* current = node;
        Node* prevNode = nullptr;

        while (current != nullptr) {
            if (current->val < key) {
                prevNode = current;
                current = current->r;
            } else {
                current = current->l;
            }
        }

        if (prevNode != nullptr) {
            cout << "\n" << prevNode->val;
        } else {
            cout << "\n" << "none";
        }
    }
};

int main() {
    string act;
    Tree a;
    Node* node = nullptr;

    while (cin >> act) {
        if (act == "insert") {
            int x;
            cin >> x;
            node = a.insert(node, x);
        }

        if (act == "delete") {
            int x;
            cin >> x;
            node = a.remove(node, x);
        }

        if (act == "exists") {
            int x;
            cin >> x;
            if (a.exists(node, x))
                cout << "\n" << "true";
            else
                cout << "\n" << "false";
        }

        if (act == "next") {
            int x;
            cin >> x;
            a.next(node, x);
        }

        if (act == "prev") {
            int x;
            cin >> x;
            a.prev(node, x);
        }
    }

    return 0;
}
