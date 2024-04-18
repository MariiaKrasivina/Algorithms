#include <iostream>
using namespace std;

struct Node {
    long data;
    Node* next;
};

struct Stack {

    Node *head = nullptr;

    void push(long val) {
        Node *node = new Node();
        node->data = val;
        node->next = head;
        head = node;
    }

    void pop() {
        if (empty())
            return;
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }

    long top(){
        if (empty())
            return -1;
        return head->data;
    }

    bool empty(){
        return head == nullptr;
    }
};

int main(){
    long n;
    cin >> n;

    long doski[n];
    for (long i = 0; i < n; i++){cin >> doski[i];}

    Stack v;
    long maxi = 0;

    for (long i = 0; i <= n; i++){
        while ((!v.empty()) && ((doski[i] < doski[v.top()]) || i == n)){
            long vis = doski[v.top()];
            v.pop();
            long sh;

            if (v.empty())
                sh = i;
            else
                sh = i - v.top() - 1;

            long tmp = vis * sh;
            maxi = max(maxi, tmp);
        }
        v.push(i);
    }

    cout << maxi;

    return 0;
}