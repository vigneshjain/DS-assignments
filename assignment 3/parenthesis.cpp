#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

char stackArr[MAX];
int top = -1;

void push(char c) { stackArr[++top] = c; }
char pop() { return stackArr[top--]; }
bool isEmpty() { return top == -1; }
char peek() { return stackArr[top]; }

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main() {
    char expr[MAX];
    cout << "Enter expression: ";
    cin >> expr;

    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{')
            push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty() || !isMatching(pop(), c)) {
                cout << "Not Balanced\n";
                return 0;
            }
        }
    }

    if (isEmpty()) cout << "Balanced\n";
    else cout << "Not Balanced\n";
}
