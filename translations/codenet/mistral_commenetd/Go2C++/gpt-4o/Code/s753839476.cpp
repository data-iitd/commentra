#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Function to calculate absolute difference between two float numbers
double AbsDiffDouble(double n1, double n2) {
    return fabs(n1 - n2);
}

int main() {
    // Initialize input variables
    int n;
    double t, a;

    // Read input values
    cin >> n >> t >> a;

    // Initialize variables for heights and minimum difference
    vector<double> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    double minDiff = AbsDiffDouble(t - heights[0] * 0.006, a);
    int minIdx = 0;

    // Iterate through the remaining heights and find the minimum difference
    for (int i = 1; i < n; ++i) {
        // Calculate the difference between the target and the height
        double diff = AbsDiffDouble(t - heights[i] * 0.006, a);

        // Update minimum difference and index if the current difference is smaller
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i;
        }
    }

    // Print the result (1-based index)
    cout << minIdx + 1 << endl;

    return 0;
}

// <END-OF-CODE>
