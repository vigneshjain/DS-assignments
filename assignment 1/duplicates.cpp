#include <iostream>
using namespace std;
int main() {
    int n, i, j, k;
    cout<<"Enter length of array:";
    cin >> n;
    int arr[100];
    for (i = 0; i < n; i++) cin >> arr[i];
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (k = j; k < n - 1; k++) arr[k] = arr[k + 1];
                n--; j--;
            }
        }
    }
    for (i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
