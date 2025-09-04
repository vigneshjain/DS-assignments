#include <iostream>
using namespace std;
int main() {
  int d[] =
      {
          1,
          2,
          3,
      },
      i, j, n = 3;

  cout << "Matrix   succesfully!\n"; 
  for (i = 0; i < n; i++) { 
    for (j = 0; j < n; j++) {
      if (i == j) 
        cout << d[i] << "\t";
      else
        cout << 0 << "\t";
    } 
      cout << "\n";

  }
}