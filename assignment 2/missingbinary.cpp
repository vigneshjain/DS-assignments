#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 6, 7, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int start = 0, end = n - 1;
    int missing = -1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (a[mid] != mid + 1) {
            missing = mid + 1;
            end = mid - 1; 
        } else {
            start = mid + 1; 
        }
    }

    cout << "Missing number (Binary Search): " << missing<<"\n";
}
