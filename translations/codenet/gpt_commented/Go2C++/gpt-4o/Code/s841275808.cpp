#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read an integer from standard input
int ScanInt() {
    int i;
    cin >> i; // Read the next integer
    return i; // Return the integer
}

int main() {
    // Read the number of elements
    int N = ScanInt();
    // Initialize vectors to hold the original values and a sorted copy
    vector<int> X(N), Y(N);
    
    // Read N integers into vector X and copy them to vector Y
    for (int i = 0; i < N; i++) {
        X[i] = ScanInt();
        Y[i] = X[i];
    }
    
    // Sort the vector Y to find the median values
    sort(Y.begin(), Y.end());
    // Calculate the two middle values (medians) for even-sized arrays
    int m1 = Y[N / 2 - 1]; // First median
    int m2 = Y[N / 2];     // Second median
    
    // For each element in X, print the appropriate median based on its value
    for (int i = 0; i < N; i++) {
        if (X[i] <= m1) {
            cout << m2 << endl; // If X[i] is less than or equal to m1, print m2
        } else {
            cout << m1 << endl; // Otherwise, print m1
        }
    }
    
    return 0; // Return success
}

// Max function to return the maximum of two integers
int Max(int a, int b) {
    return (a < b) ? b : a; // Return b if a is less than b
}

// Min function to return the minimum of two integers
int Min(int a, int b) {
    return (a > b) ? b : a; // Return b if a is greater than b
}

// Abs function to return the absolute value of an integer
int Abs(int a) {
    return (a < 0) ? -a : a; // If a is negative, return -a; otherwise return a
}

// <END-OF-CODE>
