#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#define MAX 100
using namespace std;

int stackArr[MAX];
int top = -1;

void push(int x) { stackArr[++top] = x; }
int pop() { return stackArr[top--]; }

int evaluatePostfix(char postfix[]) {
    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(ch - '0'); 
        }
        else {
            int operand2 = pop();
            int operand1 = pop();
            int result = 0;

            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '^': result = pow(operand1, operand2); break;
            }
            push(result);
        }
    }
    return pop(); 
}

int main() {
    char postfix[MAX];
    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation result: " << result << endl;
    return 0;
}
