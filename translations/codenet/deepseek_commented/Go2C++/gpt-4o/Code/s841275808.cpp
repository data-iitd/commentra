#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

// Function to read an integer from standard input.
int ScanInt() {
    int i;
    cin >> i;
    return i;
}

int main() {
    // Reads the number of elements N.
    int N = ScanInt();
    
    // Initializes vectors X and Y to store N integers.
    vector<int> X(N), Y(N);
    
    // Reads N integers into vector X and copies them to vector Y.
    for (int i = 0; i < N; i++) {
        X[i] = ScanInt();
        Y[i] = X[i];
    }
    
    // Sorts vector Y in ascending order.
    sort(Y.begin(), Y.end());
    
    // Calculates the two middle values of the sorted vector Y.
    int m1 = Y[N / 2 - 1];
    int m2 = Y[N / 2];
    
    // For each element in vector X, prints the corresponding median value.
    for (int i = 0; i < N; i++) {
        if (X[i] <= m1) {
            cout << m2 << endl;
        } else {
            cout << m1 << endl;
        }
    }
    
    return 0;
}

// Helper function to return the maximum of two integers.
int Max(int a, int b) {
    return (a < b) ? b : a;
}

// Helper function to return the minimum of two integers.
int Min(int a, int b) {
    return (a > b) ? b : a;
}

// Helper function to return the absolute value of an integer.
int Abs(int a) {
    return (a < 0) ? -a : a;
}

// <END-OF-CODE>
