#include <stdio.h>

#define MAX 100
int stack[MAX], top=-1;
int minVal;

void push(int x) {
    if (top == -1) {
        stack[++top] = x;
        minVal = x;
    } else if (x >= minVal) {
        stack[++top] = x;
    } else {
        stack[++top] = 2*x - minVal; 
        minVal = x;
    }
}

void pop() {
    if (top == -1) return;
    int t = stack[top--];
    if (t < minVal) {
        minVal = 2*minVal - t;
    }
}

int getMin() {
    return minVal;
}

int peek() {
    int t = stack[top];
    if (t < minVal) return minVal;
    else return t;
}

int main() {
    push(3); push(5);
    printf("Min: %d\n", getMin()); 
    push(2); push(1);
    printf("Min: %d\n", getMin()); 
    pop();
    printf("Min: %d\n", getMin()); 
    return 0;
}
