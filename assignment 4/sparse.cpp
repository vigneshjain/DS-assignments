#include <iostream>
using namespace std;

void make_sparse(int sparse[100][3], int m1[4][4]) {
    sparse[0][0] = 4;
    sparse[0][1] = 4;
    int k        = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; ++j) {
            if (m1[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = m1[i][j];
                k++;
            }
        }
    }
    sparse[0][2] = k - 1;
}

void display_sparse(int sparse[100][3]) {
    int n = sparse[0][2] + 1;
    for (int i = 0; i < n; ++i) {
        cout << sparse[i][0] << " ";
        cout << sparse[i][1] << " ";
        cout << sparse[i][2] << " ";
        cout << endl;
    }
}

int get_sparse(int sparse[100][3], int row, int col) {
    int n = sparse[0][2] + 1;
    int i = 1;

    int res = 0;
    while (i < n && sparse[i][0] < row) {
        ++i;
    }

    while (i < n && sparse[i][0] == row && sparse[i][1] < col) {
        ++i;
    }

    if (i < n && sparse[i][0] == row && sparse[i][1] == col) {
        res = sparse[i][2];
    }

    return res;
}

void add_sparse(int sparse1[100][3], int sparse2[100][3]) {
    int result[100][3] = {0};
    if (sparse1[0][0] != sparse2[0][0] || sparse1[0][1] != sparse2[0][1]) {
        cout << "Can't add with diff dimensions" << endl;
        return;
    }
    result[0][0] = sparse1[0][0];
    result[0][1] = sparse1[0][1];
    int k        = 1;
    for (int i = 0; i < result[0][0]; ++i) {
        for (int j = 0; j < result[0][1]; ++j) {
            int sum = get_sparse(sparse1, i, j) + get_sparse(sparse2, i, j);
            if (sum != 0) {
                result[k][0] = i;
                result[k][1] = j;
                result[k][2] = sum;
                k++;
            }
        }
    }

    result[0][2] = k - 1;
    display_sparse(result);
}

void transpose_sparse(int sparse[10][3]) {
    int trans[100][3] = {0};

    trans[0][0] = sparse[0][1];
    trans[0][1] = sparse[0][0];
    trans[0][2] = sparse[0][2];

    int k = 1;
    // Iterate over all possible columns in the original sparse matrix
    for (int i = 0; i < sparse[0][1]; ++i) {
        // For each column, find all entries in the sparse matrix that belong to
        // that column
        for (int j = 1; j <= sparse[0][2]; ++j) {
            if (sparse[j][1] == i) {
                trans[k][0] = sparse[j][1];
                trans[k][1] = sparse[j][0];
                trans[k][2] = sparse[j][2];
                k++;
            }
        }
    }

    display_sparse(trans);
}

void multiply_sparse(int sparse1[100][3], int sparse2[100][3]) {
    int result[100][3] = {0};
    if (sparse1[0][1] != sparse2[0][0]) {
        cout << "Can't multiply with diff row and col dimensions" << endl;
        return;
    }

    result[0][0] = sparse1[0][0];
    result[0][1] = sparse2[0][1];

    int k = 1;
    for (int i = 0; i < result[0][0]; ++i) {
        for (int j = 0; j < result[0][1]; ++j) {
            int sum = 0;
            for (int x = 0; x < sparse1[0][1]; ++x) {
                sum += get_sparse(sparse1, i, x) * get_sparse(sparse2, x, j);
            }
            if (sum != 0) {
                result[k][0] = i;
                result[k][1] = j;
                result[k][2] = sum;
                k++;
            }
        }
    }

    result[0][2] = k - 1;
    display_sparse(result);
}

int main(int argc, char** argv) {
    int sparse1[100][3] = {0};
    int sparse2[100][3] = {0};
    int m1[4][4]        = {0};
    int m2[4][4]        = {0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; ++j) {
            if (j % 2 == 0) m1[i][j] = j;
            else m1[i][j] = 0;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; ++j) {
            if (j % 2 == 0) m2[i][j] = j;
            else m2[i][j] = 0;
        }
    }

    make_sparse(sparse1, m1);
    //   display_sparse(sparse1);

    make_sparse(sparse2, m2);
    //   display_sparse(sparse2);

    add_sparse(sparse1, sparse2);
    transpose_sparse(sparse1);
    multiply_sparse(sparse1, sparse2);

    return 0;
}