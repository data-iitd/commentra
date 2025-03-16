#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of elements and the array of integers from input
    int n;
    cin >> n;
    vector<int64_t> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    // Initialize variables to store the maximum sum and a temporary sum
    int64_t m = 0, f = 0;

    // Create a boolean vector to track used indices
    vector<bool> u(n, false);

    // Iterate through possible values of c from 1 to n-2
    for (int c = 1; c < n - 1; ++c) {
        f = 0; // Reset the temporary sum for each c

        // Iterate to find pairs of indices based on the current value of c
        for (int k = 0; c < n - 1 - k * c; ++k) {
            u[k * c] = true; // Mark the current index as used

            // Break if the corresponding index is already used
            if (u[n - 1 - k * c]) { break; }

            // Calculate the sum of the elements at the current indices
            f += s[n - 1 - k * c] + s[k * c];

            // Update the maximum sum if the current sum is greater
            if (m < f) { m = f; }
        }

        // Reset the used indices for the next iteration of c
        for (int k = 0; k * c < n - 1; ++k) { u[k * c] = false; }
    }

    // Print the maximum sum found
    cout << m << endl;

    return 0;
}
