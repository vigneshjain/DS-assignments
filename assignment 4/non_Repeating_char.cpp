#include <stdio.h>
#include <string.h>
#define MAX 256

int main() {
    char str[]="aabc";
    int count[MAX]={0};
    char q[100]; int front=0,rear=-1;
    for(int i=0;i<strlen(str);i++) {
        char ch=str[i];
        count[ch]++;
        q[++rear]=ch;
        while(front<=rear && count[q[front]]>1) front++;
        if(front>rear) printf("-1 ");
        else printf("%c ",q[front]);
    }
    return 0;
}
