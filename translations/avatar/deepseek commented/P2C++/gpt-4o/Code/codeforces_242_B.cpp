#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read an integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a pair of integers from input
pair<int, int> readPair() {
    int x, y;
    cin >> x >> y;
    return {x, y};
}

int main() {
    // Read the number of elements
    int n = readInt();

    // Initialize variables to track the best candidate interval
    int id = 0;
    auto [l, r] = readPair();

    // Process each interval
    for (int i = 1; i < n; ++i) {
        auto [li, ri] = readPair();
        // Check if the current interval completely covers the best candidate interval
        if (li <= l && r <= ri) {
            id = i;
        }
        // Check if the current interval overlaps with the best candidate interval
        else if (li < l || r < ri) {
            id = n;
        }
        // Update the boundaries of the best candidate interval
        l = min(l, li);
        r = max(r, ri);
    }

    // Output the result
    cout << (id == n ? -1 : id + 1) << endl;

    return 0;
}

// <END-OF-CODE>
