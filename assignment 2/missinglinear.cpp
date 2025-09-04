#include<iostream>
using namespace std;
int main(){
   int a[]={1,2,3,4,6,7,8,9},i;
   int n=sizeof(a)/sizeof(a[0]);
   for(i=0;i<n;i++){
    if(a[i]!=i+1){
        cout<<i<<" is the missing number.";
        break;
    }
   }
}