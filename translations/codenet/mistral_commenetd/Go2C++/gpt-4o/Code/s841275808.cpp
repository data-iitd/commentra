#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read an integer from the input
int ScanInt() {
    int i;
    cin >> i;
    return i;
}

// Function to find the maximum of two integers
int Max(int a, int b) {
    return (a < b) ? b : a;
}

// Function to find the minimum of two integers
int Min(int a, int b) {
    return (a > b) ? b : a;
}

// Function to find the absolute value of an integer
int Abs(int a) {
    return (a < 0) ? -a : a;
}

int main() {
    // Read the number of elements in the array from the input
    int N = ScanInt();
    // Allocate memory for two vectors X and Y of size N
    vector<int> X(N), Y(N);

    // Read N integers from the input and store them in X and Y vectors
    for (int i = 0; i < N; i++) {
        X[i] = ScanInt();
        // Store the current element of X in Y vector for sorting
        Y[i] = X[i];
    }

    // Sort the Y vector in ascending order
    sort(Y.begin(), Y.end());

    // Find the median of Y vector
    int m1 = Y[N / 2 - 1];
    int m2 = Y[N / 2];

    // Iterate through each element of X vector and print the corresponding median value
    for (int i = 0; i < N; i++) {
        if (X[i] <= m1) {
            // If X[i] is smaller than m1, print m2 as the answer
            cout << m2 << endl;
        } else {
            // If X[i] is greater than m1, print m1 as the answer
            cout << m1 << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
