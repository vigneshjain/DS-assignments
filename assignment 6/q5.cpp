#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

bool isCircular(Node* head) {
    if (!head) return false;

    Node* temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;

    return (temp == head);
}

int main() {
    Node* head = NULL;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    if (isCircular(head))
        cout << "It is a circular linked list.\n";
    else
        cout << "It is NOT a circular linked list.\n";

    return 0;
}
