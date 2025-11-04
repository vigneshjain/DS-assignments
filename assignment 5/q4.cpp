#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // Create linked list: 1->2->3->4->NULL
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, new Node{3, new Node{4, nullptr}}};

    // Reverse logic
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;   // store next node
        current->next = prev;   // reverse the link
        prev = current;         // move prev one step forward
        current = next;         // move current one step forward
    }

    head = prev; // update head to the new first node

    // Display reversed list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
