#include<iostream>
using namespace std;
int main(){
    char first[100]="ishaan";
    char second[]=" sharma";
    int i=0,j=0;
    while(first[i]!='\0'){
    i++;
    }
    while(second[j]!='\0'){
        first[i]=second[j];
        j++;
        i++;
    }
 int n= i+j;
 for(i=0;i<n;i++){
    cout<<first[i];
 }
}