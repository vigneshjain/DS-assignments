#include<iostream>
using namespace std;
int main(){
    int soc=0,sor=0;
     int a[10][10],i,j,n,m,op,r,c;
    cout<<"Give number of rows and coloumns you want:\n";
    cin>>n>>m;
    cout<<"Give elements:\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
        cout<<"\n";
    }
    cout<<"Sum of 1.row needed or 2.coloumn?\n";
    cin>>op;
    switch(op){
        case 1: cout<<"enter row number whose sum you want to find:\n";
        cin>>r;
        if(r-1>n)cout<<"Invalid row number";
        for(j=0;j<m;j++)
        sor+=a[r-1][j];
        cout<<"Sum of elements in row is:"<<" "<<sor;
        break;
         case 2: cout<<"enter coloumn number whose sum you want to find:\n";
        cin>>c;
             if(c-1>m)cout<<"Invalid coloumn number";
        for(i=0;i<m;i++)
        sor+=a[i][c-1];
        cout<<"Sum of elements in coloumn is:"<<" "<<sor;
        break;
    }
}