#include <iostream>
using namespace std;

int main() {
int d[]={1,2,3,4,5,6,7,8,9,10},i,j,k=0,m=0,n=0;
for(i=0;i<4;i++){
    for(j=0;j<4;j++){
        if(j==0){
            cout<<d[k]<<"  ";
            k++;
        }
        else if(j==1&& i>0) {
        cout<<d[4+m]<<"  ";
        m++;
        }
        else if(j==2&& i>1) {
        cout<<d[7+n]<<"  ";
        n++;}
        else if(j==3&& i>2) {
        cout<<d[9]<<"  ";
        m++;
        }
        else {
        cout<<0<<"  ";
        }
        }

    
        cout<<"\n";
    
 }
}

