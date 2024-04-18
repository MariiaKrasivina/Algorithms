#include <iostream>
using namespace std;

struct Node {
    int index;
    int data;
    Node* next;
};

struct Stack {
    Node* head = nullptr;

    void push(int val, int index1) {
        Node *node = new Node();
        node->data = val;
        node->index = index1;
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
            head = head->next;
            return node;
        }
    }

    int topindex() {
        if (empty())
            return -1;
        return head->index;
    }

    int topval() {
        if (empty())
            return -1;
        return head->data;
    }
};

int main() {
    int n;
    cin >> n;

    int sloz[n];
    for (int i = 0; i < n; i++){cin >> sloz[i];}

    Stack stk;
    int itog[n];

    for (int i = n - 1; i >= 0; i--){
        while ((!stk.empty()) && stk.topval() <= sloz[i])
            stk.pop();
        if (!stk.empty()) {
            if ((stk.topindex() - i) > 0)
                itog[i] = stk.topindex() - i;
            else if ((stk.topindex() - i) <= 0)
                itog[i] = -1;
        }
        else
            itog[i] = -1;
        stk.push(sloz[i], i);
    }

    for (int i = 0; i < n; i++){cout << itog[i] << " ";}

    return 0;
}