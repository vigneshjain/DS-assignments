#include <iostream>
using namespace std;

int main() {
    int d[]={1,2,3,4,5,6,7,8,9,10}; 
    int n=4;  
    int k=0;

    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<=j){         
                cout<<d[k]<<" ";
                k++;
            }
            else{              
                cout<<d[(j*n - (j*(j-1))/2) + (i-j)]<<" ";
            }
        }
        cout<<endl;
    }
}
