#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char a[] = "Ishaan is the creator of these assignments";
    int n = strlen(a);


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                char temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "Sorted string: " << a;
    return 0;
}
