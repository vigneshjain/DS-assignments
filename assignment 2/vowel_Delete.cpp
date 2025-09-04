#include <iostream>
#include <cstring>
using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'A' || 
            c == 'e' || c == 'E' || 
            c == 'i' || c == 'I' || 
            c == 'o' || c == 'O' || 
            c == 'u' || c == 'U');
}

int main() {
    char a[] = "Ishaan is the creator of these assignments";
    int n = strlen(a);
    int j = 0; 

    for (int i = 0; i < n; i++) {
        if (!isVowel(a[i])) {
            a[j++] = a[i]; 
    }
    a[j] = '\0'; 

    cout << a << endl;
    return 0;
}
}
