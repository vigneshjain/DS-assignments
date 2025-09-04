#include <iostream>
using namespace std;

int main() {
    int i, n = 0, ele, pos, op, arr[1000];

    while (1) {
        cout << "\nWhat operation do you want to perform?\n"
             << "1. CREATE\n"
             << "2. DISPLAY\n"
             << "3. INSERT\n"
             << "4. DELETE\n"
             << "5. LINEAR SEARCH\n"
             << "6. EXIT\n";
        cin >> op;

        switch (op) {
        case 1: // CREATE
            cout << "Give number of elements you want in array: ";
            cin >> n;
            cout << "Give elements of the array:\n";
            for (i = 0; i < n; i++) {
                cin >> arr[i];
            }
            cout << "Array created successfully!\n";
            break;

        case 2: // DISPLAY
            if (n == 0) {
                cout << "Array is empty, kindly create an array first.\n";
            } else {
                cout << "Array elements: ";
                for (i = 0; i < n; i++) {
                    cout << arr[i] << "\t";
                }
                cout << "\n";
            }
            break;

        case 3: // INSERT
            if (n == 0) {
                cout << "Array is empty, kindly create an array first.\n";
            } else {
                cout << "Enter the element you want to insert: ";
                cin >> ele;
                cout << "Enter the position you want it entered in (1 to " << n + 1 << "): ";
                cin >> pos;

                if (pos < 1 || pos > n + 1) {
                    cout << "Invalid position!\n";
                } else {
                    for (i = n; i >= pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos - 1] = ele;
                    n++;
                    cout << "Element added successfully! New array is:\n";
                    for (i = 0; i < n; i++) {
                        cout << arr[i] << "\t";
                    }
                    cout << "\n";
                }
            }
            break;

        case 4: // DELETE
            if (n == 0) {
                cout << "Array is empty, kindly create an array first.\n";
            } else {
                cout << "Enter the position you want to delete (1 to " << n << "): ";
                cin >> pos;
                if (pos < 1 || pos > n) {
                    cout << "Invalid position!\n";
                } else {
                    for (i = pos - 1; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    cout << "Element deleted successfully! New array is:\n";
                    for (i = 0; i < n; i++) {
                        cout << arr[i] << "\t";
                    }
                    cout << "\n";
                }
            }
            break;

        case 5: // LINEAR SEARCH
            if (n == 0) {
                cout << "Array is empty, kindly create an array first.\n";
            } else {
                cout << "Enter the element to search: ";
                cin >> ele;
                bool found = false;
                for (i = 0; i < n; i++) {
                    if (arr[i] == ele) {
                        cout << "Element found at position " << i + 1 << ".\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Element not found in the array.\n";
                }
            }
            break;

        case 6: // EXIT
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}
