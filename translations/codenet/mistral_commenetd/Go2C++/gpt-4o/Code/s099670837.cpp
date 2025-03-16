#include <iostream>
using namespace std;

// Variables declaration
int n, ans = 0;
const int arraySize = 101;

// 2D array declaration
int a[arraySize][arraySize];

// Recursive function to find the maximum sum of a sub-matrix
void findAns(int i, int j, int sum) {
    // Base case: if we have reached the last cell and the sum is greater than the current answer, update the answer
    if (i == 1 && j == n - 1) {
        ans = sum + a[i][j];
        return;
    }
    // Base case: if we have reached the first row, recursively call the function for the next cell and add the current cell value to the sum
    if (i == 0) {
        findAns(i + 1, j, sum + a[i][j]);
        return;
    }
    // Recursively call the function for the next cell and add the current cell value to the sum
    if (j + 1 < n) {
        findAns(i, j + 1, sum + a[i][j]);
        return;
    }
}

int main() {
    // Read the number of rows and columns from the standard input
    cin >> n;

    // Read the elements of the matrix from the standard input
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Call the recursive function to find the maximum sum of a sub-matrix
    findAns(0, 0, 0);

    // Print the maximum sum of a sub-matrix
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
