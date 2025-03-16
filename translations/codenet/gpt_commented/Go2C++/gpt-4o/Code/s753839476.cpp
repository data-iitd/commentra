#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Function to calculate the absolute difference between two float numbers
double AbsDiff(double n1, double n2) {
    return fabs(n1 - n2);
}

int main() {
    // Initialize input/output handling
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the number of heights, target temperature, and actual temperature
    int n;
    double t, a;
    cin >> n >> t >> a;

    // Read the heights into a vector
    vector<double> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    // Initialize minimum difference and index for tracking the closest height
    double minDiff = AbsDiff(t - heights[0] * 0.006, a);
    int minIdx = 0;

    // Iterate through the heights to find the one with the minimum temperature difference
    for (int i = 1; i < n; ++i) {
        double diff = AbsDiff(t - heights[i] * 0.006, a);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i; // Update the index of the closest height
        }
    }

    // Output the 1-based index of the closest height
    cout << minIdx + 1 << endl;

    return 0;
}

// <END-OF-CODE>
