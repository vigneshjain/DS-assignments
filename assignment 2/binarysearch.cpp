#include <iostream>
using namespace std;

int main() {
  int a[] =
      {
          1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 24, 25, 36, 658, 989,
      },
      i, start, end, mid, key, flag = 0, pos;
  int n = sizeof(a) / sizeof(a[0]);
  cout << "Enter the element you want to find:\n";
  cin >> key;
  start = 0, end = n - 1;
  while (start <= end) {
    mid = (start + end) / 2;
    if (a[mid] == key) {
      cout << "element found at " << mid + 1 << " position.";
      flag = 1;
      break;
    } else if (key < a[mid]) {
      end = mid - 1;
    } else
      start = mid + 1;
  }
  if (flag == 0) {
    cout << "Element not found!";
  }
}