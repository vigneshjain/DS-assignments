#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

char stackArr[MAX];
int top = -1;

void push(char c) {
    stackArr[++top] = c;
}

char pop() {
    return stackArr[top--];
}

int main() {
    char str[MAX];
    cout << "Enter string: ";
    cin >> str;

    for (int i = 0; i < strlen(str); i++) push(str[i]);

    cout << "Reversed: ";
    while (top != -1) cout << pop();
    cout << endl;
}
