#include <stdio.h>

void dailyTemp(int T[], int n) {
    int ans[100];
    for (int i = 0; i < n; i++) {
        ans[i] = 0; 
        for (int j = i+1; j < n; j++) {
            if (T[j] > T[i]) {
                ans[i] = j - i;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
}

int main() {
    int T[8] = {73,74,75,71,69,72,76,73};
    dailyTemp(T, 8);
    return 0;
}
