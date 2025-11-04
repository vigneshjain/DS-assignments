#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int v) : data(v), next(nullptr) {}
};

class CircularList {
    CNode* head; // if head == nullptr => empty
public:
    CircularList() : head(nullptr) {}

    // Display
    void display() {
        if (!head) { cout << "List is empty.\n"; return; }
        CNode* cur = head;
        cout << "Circular List: ";
        do {
            cout << cur->data;
            cur = cur->next;
            if (cur != head) cout << "->";
        } while (cur != head);
        cout << " (back to head)\n";
    }

    // Insert at beginning (makes new node the head)
    void insertBeginning(int val) {
        CNode* node = new CNode(val);
        if (!head) {
            head = node;
            head->next = head;
            return;
        }
        // Find tail to link it to new head
        CNode* tail = head;
        while (tail->next != head) tail = tail->next;
        node->next = head;
        tail->next = node;
        head = node;
    }

    // Insert at end
    void insertEnd(int val) {
        CNode* node = new CNode(val);
        if (!head) {
            head = node;
            head->next = head;
            return;
        }
        CNode* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = node;
        node->next = head;
    }

    // Insert after a node having value key (first occurrence)
    void insertAfter(int key, int val) {
        if (!head) { cout << "List is empty.\n"; return; }
        CNode* cur = head;
        do {
            if (cur->data == key) {
                CNode* node = new CNode(val);
                node->next = cur->next;
                cur->next = node;
                // if inserted after tail, no change to head needed
                return;
            }
            cur = cur->next;
        } while (cur != head);
        cout << "Value " << key << " not found.\n";
    }

    // Insert before a node having value key (first occurrence)
    void insertBefore(int key, int val) {
        if (!head) { cout << "List is empty.\n"; return; }
        // special case: head is key
        if (head->data == key) {
            insertBeginning(val);
            return;
        }
        CNode* prev = head;
        CNode* cur = head->next;
        while (cur != head) {
            if (cur->data == key) {
                CNode* node = new CNode(val);
                prev->next = node;
                node->next = cur;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
        cout << "Value " << key << " not found.\n";
    }

    // Delete a node by value (first occurrence)
    void deleteValue(int key) {
        if (!head) { cout << "List is empty.\n"; return; }

        // single node case
        if (head->next == head) {
            if (head->data == key) {
                delete head;
                head = nullptr;
            } else {
                cout << "Value " << key << " not found.\n";
            }
            return;
        }

        // if head is to be deleted
        if (head->data == key) {
            // find tail
            CNode* tail = head;
            while (tail->next != head) tail = tail->next;
            CNode* toDel = head;
            head = head->next;
            tail->next = head;
            delete toDel;
            return;
        }

        // general case: find previous of node to delete
        CNode* prev = head;
        CNode* cur = head->next;
        while (cur != head) {
            if (cur->data == key) {
                prev->next = cur->next;
                delete cur;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
        cout << "Value " << key << " not found.\n";
    }

    // Search and print position(s) starting from 1 at head, return count
    int search(int key) {
        if (!head) { cout << "List is empty.\n"; return 0; }
        int pos = 1, found = 0;
        CNode* cur = head;
        do {
            if (cur->data == key) {
                cout << "Found " << key << " at position " << pos << " (from head)\n";
                found++;
            }
            cur = cur->next;
            pos++;
        } while (cur != head);
        if (!found) cout << "Value " << key << " not found.\n";
        return found;
    }
};

/* ------------------------- Doubly Linked List ------------------------- */
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int v) : data(v), next(nullptr), prev(nullptr) {}
};

class DoublyList {
    DNode* head;
public:
    DoublyList() : head(nullptr) {}

    // Display forward
    void display() {
        if (!head) { cout << "List is empty.\n"; return; }
        DNode* cur = head;
        cout << "Doubly List: ";
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << "->";
            cur = cur->next;
        }
        cout << endl;
    }

    // Insert at beginning
    void insertBeginning(int val) {
        DNode* node = new DNode(val);
        node->next = head;
        if (head) head->prev = node;
        head = node;
    }

    // Insert at end
    void insertEnd(int val) {
        DNode* node = new DNode(val);
        if (!head) { head = node; return; }
        DNode* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
        node->prev = cur;
    }

    // Insert after first occurrence of key
    void insertAfter(int key, int val) {
        DNode* cur = head;
        while (cur) {
            if (cur->data == key) {
                DNode* node = new DNode(val);
                node->next = cur->next;
                node->prev = cur;
                cur->next = node;
                if (node->next) node->next->prev = node;
                return;
            }
            cur = cur->next;
        }
        cout << "Value " << key << " not found.\n";
    }

    // Insert before first occurrence of key
    void insertBefore(int key, int val) {
        DNode* cur = head;
        if (!cur) { cout << "List is empty.\n"; return; }
        while (cur) {
            if (cur->data == key) {
                DNode* node = new DNode(val);
                node->next = cur;
                node->prev = cur->prev;
                cur->prev = node;
                if (node->prev) node->prev->next = node;
                else head = node; // inserted before head
                return;
            }
            cur = cur->next;
        }
        cout << "Value " << key << " not found.\n";
    }

    // Delete first occurrence of key
    void deleteValue(int key) {
        DNode* cur = head;
        while (cur) {
            if (cur->data == key) {
                if (cur->prev) cur->prev->next = cur->next;
                else head = cur->next; // deleting head
                if (cur->next) cur->next->prev = cur->prev;
                delete cur;
                return;
            }
            cur = cur->next;
        }
        cout << "Value " << key << " not found.\n";
    }

    // Search and print position(s)
    int search(int key) {
        DNode* cur = head;
        int pos = 1, found = 0;
        while (cur) {
            if (cur->data == key) {
                cout << "Found " << key << " at position " << pos << " (from head)\n";
                found++;
            }
            cur = cur->next;
            pos++;
        }
        if (!found) cout << "Value " << key << " not found.\n";
        return found;
    }
};

/* ------------------------------ UI Menus ------------------------------ */

void circularMenu(CircularList &cl) {
    while (true) {
        cout << "\n-- Circular List Menu --\n"
             << "1. Insert at beginning\n"
             << "2. Insert at end\n"
             << "3. Insert after value\n"
             << "4. Insert before value\n"
             << "5. Delete a value\n"
             << "6. Search for a value\n"
             << "7. Display list\n"
             << "8. Back\n"
             << "Enter choice: ";
        int ch; cin >> ch;
        int val, key;
        switch (ch) {
            case 1: cout << "Value: "; cin >> val; cl.insertBeginning(val); break;
            case 2: cout << "Value: "; cin >> val; cl.insertEnd(val); break;
            case 3: cout << "After which value? "; cin >> key; cout << "Value to insert: "; cin >> val; cl.insertAfter(key, val); break;
            case 4: cout << "Before which value? "; cin >> key; cout << "Value to insert: "; cin >> val; cl.insertBefore(key, val); break;
            case 5: cout << "Value to delete: "; cin >> key; cl.deleteValue(key); break;
            case 6: cout << "Value to search: "; cin >> key; cl.search(key); break;
            case 7: cl.display(); break;
            case 8: return;
            default: cout << "Invalid choice.\n";
        }
    }
}

void doublyMenu(DoublyList &dl) {
    while (true) {
        cout << "\n-- Doubly List Menu --\n"
             << "1. Insert at beginning\n"
             << "2. Insert at end\n"
             << "3. Insert after value\n"
             << "4. Insert before value\n"
             << "5. Delete a value\n"
             << "6. Search for a value\n"
             << "7. Display list\n"
             << "8. Back\n"
             << "Enter choice: ";
        int ch; cin >> ch;
        int val, key;
        switch (ch) {
            case 1: cout << "Value: "; cin >> val; dl.insertBeginning(val); break;
            case 2: cout << "Value: "; cin >> val; dl.insertEnd(val); break;
            case 3: cout << "After which value? "; cin >> key; cout << "Value to insert: "; cin >> val; dl.insertAfter(key, val); break;
            case 4: cout << "Before which value? "; cin >> key; cout << "Value to insert: "; cin >> val; dl.insertBefore(key, val); break;
            case 5: cout << "Value to delete: "; cin >> key; dl.deleteValue(key); break;
            case 6: cout << "Value to search: "; cin >> key; dl.search(key); break;
            case 7: dl.display(); break;
            case 8: return;
            default: cout << "Invalid choice.\n";
        }
    }
}

int main() {
    CircularList cl;
    DoublyList dl;

    while (true) {
        cout << "\n=== Main Menu ===\n"
             << "1. Work with Circular Singly Linked List\n"
             << "2. Work with Doubly Linked List\n             "
             << "3. Exit\n"
             << "Enter choice: ";
        int ch; cin >> ch;
        if (ch == 1) circularMenu(cl);
        else if (ch == 2) doublyMenu(dl);
        else if (ch == 3) { cout << "Exiting...\n"; break; }
        else cout << "Invalid choice.\n";
    }
    return 0;
}
