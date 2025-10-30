#include <stdio.h>

void nearestSmaller(int A[], int n) {
    int ans[100];
    for (int i = 0; i < n; i++) {
        ans[i] = -1;  
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] < A[i]) {
                ans[i] = A[j];
                break;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
}

int main() {
    int A[5] = {4, 5, 2, 10, 8};
    nearestSmaller(A, 5);
    return 0;
}
