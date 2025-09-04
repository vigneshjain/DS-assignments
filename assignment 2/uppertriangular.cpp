#include <iostream>
using namespace std;

int main() {
int d[]={1,2,3,4,5,6,7,8,9,10},i,j,k=0;
for(i=0;i<4;i++){
    for(j=0;j<4;j++){
        if(i<=j){
            cout<<d[k]<<"  ";
            k++;
        }
        else {
        cout<<0<<"  ";
        }
    }
        cout<<"\n";
    
 }
}
