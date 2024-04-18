#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct stack {

    Node* head = nullptr;

    void push(int val) {
        Node *node = new Node();
        node->data = val;
        node->next = head;
        head = node;
    }

    bool empty(){
        if (head == nullptr)
            return true;
        return false;
    }

    Node* pop() {
        if (empty())
            return nullptr;
        else{
            Node* node;
            node = head;
            head = head -> next;
            return node;
        }
    }

    int top(){
        if (head == nullptr)
            return -1;
        return head->data;
    }

    void print() {
        if (head == nullptr)
            return;
        Node *cur = head;
        while (cur != nullptr) {
            cout << cur->data << endl;
            cur = cur->next;
        }
    }
};

int main() {
    int n;
    cin >> n;

    stack stk;

    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        stk.push(val);
    }

    stk.print();

    return 0;
}
