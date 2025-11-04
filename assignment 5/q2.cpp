#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void displayList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int countAndDeleteKey(int key) {
    int count = 0;

    while (head != nullptr && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    
    if (head == nullptr) return count;

    Node* current = head;

    
    while (current->next != nullptr) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = current->next->next; // skip the node
            delete temp;
            count++;
        } else {
            current = current->next;
        }
    }

    return count;
}


int main() {
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(3);
    insertAtEnd(1);

    cout << "Original Linked List: ";
    displayList();

    int key = 1;
    int count = countAndDeleteKey(key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    displayList();

    return 0;
}
