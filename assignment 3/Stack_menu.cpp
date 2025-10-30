#include <iostream>
#include <cstdlib>
#define MAX 100
using namespace std;

int stackArr[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    stackArr[++top] = x;
}

int pop() {
    if (top == -1) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    return stackArr[top--];
}

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MAX - 1);
}

int peek() {
    if (isEmpty()) {
        cout << "Stack Empty!" << endl;
        return -1;
    }
    return stackArr[top];
}

void display() {
    if (isEmpty()) {
        cout << "Stack Empty!" << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--) cout << stackArr[i] << " ";
    cout << endl;
}

int main() {
    int choice, val;
    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; push(val); break;
            case 2: val = pop(); if (val != -1) cout << "Popped: " << val << endl; break;
            case 3: cout << (isEmpty() ? "Stack Empty" : "Not Empty") << endl; break;
            case 4: cout << (isFull() ? "Stack Full" : "Not Full") << endl; break;
            case 5: display(); break;
            case 6: val = peek(); if (val != -1) cout << "Top = " << val << endl; break;
            case 7: exit(0);
            default: cout << "Invalid choice!\n";
        }
    }
}
