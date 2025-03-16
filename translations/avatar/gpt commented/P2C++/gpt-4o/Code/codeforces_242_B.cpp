#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read a single integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a pair of integers from input
pair<int, int> readInterval() {
    int l, r;
    cin >> l >> r;
    return {l, r};
}

int main() {
    // Read the number of intervals
    int n = readInt();

    // Initialize the index for the result
    int id = 0;

    // Read the first interval's bounds
    auto [l, r] = readInterval();

    // Iterate through the remaining intervals
    for (int i = 1; i < n; ++i) {
        // Read the current interval's bounds
        auto [li, ri] = readInterval();

        // Check if the current interval completely contains the previous one
        if (li <= l && r <= ri) {
            id = i;  // Update the index to the current interval
        }
        // Check if the current interval overlaps with the previous one
        else if (li < l || r < ri) {
            id = n;  // Mark as overlapping by setting id to n
        }

        // Update the bounds of the union of intervals
        l = min(l, li);  // Update the left bound
        r = max(r, ri);  // Update the right bound
    }

    // Print the result: -1 if no valid interval found, otherwise print the 1-based index of the interval
    cout << (id == n ? -1 : id + 1) << endl;

    return 0;
}

// <END-OF-CODE>
