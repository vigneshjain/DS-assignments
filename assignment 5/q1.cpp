#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

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

void insertBeforeValue(int value, int beforeValue) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        cout << "List is empty.\n";
        delete newNode;
        return;
    }

    
    if (head->data == beforeValue) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data != beforeValue) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value " << beforeValue << " not found.\n";
        delete newNode;
        return;
    }

    prev->next = newNode;
    newNode->next = temp;
}

void insertAfterValue(int value, int afterValue) {
    Node* temp = head;

    while (temp != nullptr && temp->data != afterValue)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Value " << afterValue << " not found.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}

void deleteValue(int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value " << value << " not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
}

void searchNode(int value) {
    Node* temp = head;
    int pos = 1;

    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Node with value " << value << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Node with value " << value << " not found.\n";
}

void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value, key;

    while (true) {
        cout << "\n--- Singly Linked List Operations ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a value\n";
        cout << "4. Insert after a value\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific value\n";
        cout << "8. Search for a node\n";
        cout << "9. Display all nodes\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter value before which to insert: ";
                cin >> key;
                insertBeforeValue(value, key);
                break;

            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter value after which to insert: ";
                cin >> key;
                insertAfterValue(value, key);
                break;

            case 5:
                deleteFromBeginning();
                break;

            case 6:
                deleteFromEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteValue(value);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;

            case 9:
                displayList();
                break;

            case 10:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}
