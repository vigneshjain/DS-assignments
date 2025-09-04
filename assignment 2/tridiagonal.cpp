#include <iostream>
#define MAX 4;
using namespace std;

int main() {
  int d[] =
      {
          1,
          2,
          3,
          4,
      },
      u[] = {1, 2, 3}, l[] = {1, 2, 3}, i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (i == j)
        cout << d[i] << "  ";
      else if (i == j + 1)
        cout << u[i-1] << "  ";
      else if (i == j - 1)
        cout << l[i] << "  ";
      else
        cout << 0 << "  ";
    }
    cout << "\n";
  }
}