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
        newNode->next = head; 
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Function to display all node values including repeating head
void displayCircular(Node* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    
    // repeat head node value at the end
    cout << head->data << endl;
}

// Main function
int main() {
    Node* head = NULL;
    
    insertEnd(head, 20);
    insertEnd(head, 100);
    insertEnd(head, 40);
    insertEnd(head, 80);
    insertEnd(head, 60);

    cout << "Circular Linked List: ";
    displayCircular(head);

    return 0;
}
