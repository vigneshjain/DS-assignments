#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, new Node{3, new Node{4, new Node{5, nullptr}}}};

    Node* slow = head;
    Node* fast = head;

    // Move fast by 2 and slow by 1
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->data << endl;

    return 0;
}
