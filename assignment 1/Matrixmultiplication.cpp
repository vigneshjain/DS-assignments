#include <iostream>
using namespace std;

int main() {
    int a[10][10], b[10][10], c[10][10];
    int n, m, p, q, i, j, k;

    cout << "Give dimensions of first array (rows cols):\n";
    cin >> n >> m;
    cout << "Give elements:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Give dimensions of second array (rows cols):\n";
    cin >> p >> q;
    cout << "Give elements:\n";
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            cin >> b[i][j];
        }
    }

    if (m != p) {
        cout << "Matrix multiplication not possible.\n";
        return 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < q; j++) {
            c[i][j] = 0;
            for (k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "Matrix multiplication result:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < q; j++) {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
}
