#include <stdio.h>

int main() {
    int Q[100]={4,7,11,20,5,9};
    int n=6, ans[100],k=0;
    for(int i=0;i<n/2;i++) {
        ans[k++]=Q[i];
        ans[k++]=Q[i+n/2];
    }
    for(int i=0;i<n;i++) printf("%d ",ans[i]);
    return 0;
}
