#include <iostream>
using namespace std;

// ---------------------------
// Doubly Linked List Section
// ---------------------------
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) {
        data = val;
        prev = next = NULL;
    }
};

// Insert node at end of DLL
void insertEndDLL(DNode*& head, int val) {
    DNode* newNode = new DNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    DNode* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Find size of Doubly Linked List
int sizeDLL(DNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// ---------------------------
// Circular Linked List Section
// ---------------------------
struct CNode {
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

// Insert node at end of CLL
void insertEndCLL(CNode*& head, int val) {
    CNode* newNode = new CNode(val);
    if (!head) {
        head = newNode;
        newNode->next = head; // circular link
        return;
    }
    CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// Find size of Circular Linked List
int sizeCLL(CNode* head) {
    if (!head)
        return 0;
    int count = 0;
    CNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    // Doubly Linked List
    DNode* dhead = NULL;
    insertEndDLL(dhead, 10);
    insertEndDLL(dhead, 20);
    insertEndDLL(dhead, 30);
    cout << "Size of Doubly Linked List: " << sizeDLL(dhead) << endl;

    // Circular Linked List
    CNode* chead = NULL;
    insertEndCLL(chead, 5);
    insertEndCLL(chead, 15);
    insertEndCLL(chead, 25);
    insertEndCLL(chead, 35);
    cout << "Size of Circular Linked List: " << sizeCLL(chead) << endl;

    return 0;
}
