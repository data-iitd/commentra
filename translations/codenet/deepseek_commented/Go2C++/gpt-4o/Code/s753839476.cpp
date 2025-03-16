#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to calculate the absolute difference between two float numbers.
double AbsDiffFloat64(double n1, double n2) {
    return fabs(n1 - n2);
}

int main() {
    int n;
    double t, a;

    // Read values for n, t, and a.
    cin >> n >> t >> a;
    vector<double> heights(n);

    // Read a list of heights.
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    double minDiff = AbsDiffFloat64(t - heights[0] * 0.006, a); // Calculate the initial minimum difference.
    int minIdx = 0; // Initialize the index of the minimum difference.

    // Iterate through the heights starting from the second element.
    for (int i = 1; i < n; ++i) {
        double diff = AbsDiffFloat64(t - heights[i] * 0.006, a); // Calculate the difference for the current height.
        if (diff < minDiff) { // Update the minimum difference and index if a smaller difference is found.
            minDiff = diff;
            minIdx = i;
        }
    }

    cout << minIdx + 1 << endl; // Print the index (plus one for 1-based indexing).
    return 0;
}

// <END-OF-CODE>
