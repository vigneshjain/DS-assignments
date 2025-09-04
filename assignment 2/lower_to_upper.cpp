#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char a[] = "Ishaan is the creator of these assignments";
    int n = strlen(a);

    for(int i=0;i<n;i++){
        if(int(a[i])<123 && int(a[i])>96)
        a[i]= a[i]-32;
    }
     for(int i=0;i<n;i++){
        cout<<a[i];
}
}