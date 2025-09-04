#include <iostream>
using namespace std;

int main(){
struct Element {
    int row, col, val;
};

struct SparseMatrix {
    int rows, cols, terms;
    Element data[20];   // max 20 non-zero elements
};

// Print Sparse
void printSparse(SparseMatrix s) {
    for (int i = 0; i < s.terms; i++) {
        cout << "(" << s.data[i].row << "," << s.data[i].col << ")=" << s.data[i].val << " ";
    }
    cout << "\n";
}

// Transpose
SparseMatrix transpose(SparseMatrix s) {
    SparseMatrix t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.terms = s.terms;
    int k=0;
    for (int c=0; c<s.cols; c++) {
        for (int i=0; i<s.terms; i++) {
            if (s.data[i].col == c) {
                t.data[k].row = s.data[i].col;
                t.data[k].col = s.data[i].row;
                t.data[k].val = s.data[i].val;
                k++;
            }
        }
    }
    return t;
}}

// // Addition
// SparseMatrix add(SparseMatrix a, SparseMatrix b) {
//     SparseMatrix c;
//     c.rows=a.rows; c.cols=a.cols;
//     int i=0,j=0,k=0;
//     while(i<a.terms && j<b.terms){
//         if(a.data[i].row==b.data[j].row && a.data[i].col==b.data[j].col){
//             int sum=a.data[i].val+b.data[j].val;
//             if(sum!=0){
//                 c.data[k++]={a.data[i].row,a.data[i].col,sum};
//             }
//             i++; j++;
//         }
//         else if(a.data[i].row<b.data[j].row || 
//            (a.data[i].row==b.data[j].row && a.data[i].col<b.data[j].col)){
//             c.data[k++]=a.data[i++];
//         }
//         else c.data[k++]=b.data[j++];
//     }
//     while(i<a.terms) c.data[k++]=a.data[i++];
//     while(j<b.terms) c.data[k++]=b.data[j++];
//     c.terms=k;
//     return c;
// }

// // Multiplication (simple O(n^2))
// SparseMatrix multiply(SparseMatrix a, SparseMatrix b) {
//     SparseMatrix c;
//     c.rows=a.rows; c.cols=b.cols; c.terms=0;
//     for(int i=0;i<a.rows;i++){
//         for(int j=0;j<b.cols;j++){
//             int sum=0;
//             for(int k=0;k<a.terms;k++){
//                 if(a.data[k].row==i){
//                     for(int l=0;l<b.terms;l++){
//                         if(b.data[l].col==j && b.data[l].row==a.data[k].col){
//                             sum+=a.data[k].val*b.data[l].val;
//                         }
//                     }
//                 }
//             }
//             if(sum!=0){
//                 c.data[c.terms++]={i,j,sum};
//             }
//         }
//     }
//     return c;
// }

// int main() {
//     SparseMatrix A={3,3,3,{{0,0,5},{0,2,8},{1,1,3}}};
//     SparseMatrix B={3,3,2,{{0,0,1},{1,1,4}}};
    
//     cout<<"Transpose of A: "; printSparse(transpose(A));
//     cout<<"A+B: "; printSparse(add(A,B));
//     cout<<"A*B: "; printSparse(multiply(A,B));
// }
