#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct Que {

    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    bool empty() {
        return size == 0;
    }

    void push(int val) {
        Node* node = new Node();
        node->data = val;
        node->next = nullptr;
        if (size == 0) {
            node->prev = nullptr;
            head = tail = node;
        }
        else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        size++;
    }

    Node* pop() {
        if (empty()) {
            return nullptr;
        }
        else {
            size--;
            Node* node = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            return node;
        }
    }

    int top() {
        if (size == 0)
            return -1;
        return head->data;
    }
};


int main(){

    return 0;
}
