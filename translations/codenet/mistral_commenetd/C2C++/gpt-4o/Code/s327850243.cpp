#include <iostream>
#include <vector>

using namespace std;

// Declare variables
int m, n;
vector<vector<int>> A(100, vector<int>(100));
vector<int> B(100);
vector<int> S(100, 0);

int main() {
    // Read the dimensions of the matrices from user
    cin >> m >> n;

    // Comments for the for loop: Read the elements of matrix A row-wise
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            cin >> A[i][j];
        }
        // Read the last element of the row
        cin >> A[i][n - 1];
    }

    // Comments for the for loop: Read the elements of vector B
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    // Comments for the for loop: Perform element-wise multiplication of matrices A and B, and store the result in vector S
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            S[i] += A[i][j] * B[j];
        }
    }

    // Comments for the for loop: Print the elements of vector S
    for (int i = 0; i < m; i++) {
        cout << S[i] << endl;
    }

    // The program ends with a return statement with value 0
    return 0;
}

// <END-OF-CODE>
