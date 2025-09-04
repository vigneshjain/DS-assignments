#include<iostream>
using namespace std;
int main(){
    int i,j,a[]={7,6,5,4,3,9,2,8,1},temp;
    int n=sizeof(a)/sizeof(a[0]);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"Array sorted!!\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<"\t";
}