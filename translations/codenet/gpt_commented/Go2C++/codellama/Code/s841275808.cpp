
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Create a new scanner to read input from standard input
    int N;
    cin >> N;
    // Initialize slices to hold the original values and a sorted copy
    vector<int> X(N);
    vector<int> Y(N);
    
    // Read N integers into slice X and copy them to slice Y
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        Y[i] = X[i];
    }
    
    // Sort the slice Y to find the median values
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
    return 0;
}

