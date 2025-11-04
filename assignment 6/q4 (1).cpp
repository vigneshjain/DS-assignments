#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char c) {
        data = c;
        next = prev = NULL;
    }
};

void insertEnd(Node*& head, char c) {
    Node* newNode = new Node(c);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next)
        return true; // 0 or 1 node = palindrome

    
    Node* tail = head;
    while (tail->next)
        tail = tail->next;

    
    while (head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node* head = NULL;
    string s;
    cout << "Enter characters (no spaces, e.g. radar): ";
    cin >> s;

    for (char c : s)
        insertEnd(head, c);

    if (isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}
