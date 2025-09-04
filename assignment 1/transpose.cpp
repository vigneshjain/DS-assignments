#include<iostream>
using namespace std;
int main(){
    int a[10][10],i,j,n,m;
    cout<<"Give number of rows and coloumns you want:";
    cin>>n>>m;
    cout<<"Give elements:";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
        cout<<"\n";
    }
    cout<<"Transpose of give matrix is as follows:\n";
        for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<a[j][i]<<"\t";
        }
        cout<<"\n";
    }
}