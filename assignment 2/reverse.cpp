#include<iostream>
using namespace std;
int main(){
    char a[]="racecar si os looc";
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n/2;i++){
        char temp=a[i];
        a[i]=a[n-1-i-1];
        a[n-1-i-1]=temp;
    }
 for(int i=0;i<n-1;i++){
    cout<<a[i];
 }
}