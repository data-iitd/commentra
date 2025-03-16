#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// Define a lambda function to read a list of integers from input
auto I = []() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    return a;
};
// Define a lambda function to read a single line of input as a string
auto IS = []() {
    string s;
    getline(cin, s);
    return s;
};
// Define a lambda function to read a single integer from input
auto IN = []() {
    int n;
    cin >> n;
    return n;
};
// Define a lambda function to read a single float from input
auto IF = []() {
    double n;
    cin >> n;
    return n;
};

int main() {
    // Read the number of intervals
    int n = IN();

    // Initialize the index for the result
    int id = 0;

    // Read the first interval's bounds
    int l, r;
    cin >> l >> r;

    // Iterate through the remaining intervals
    for (int i = 1; i < n; i++) {
        // Read the current interval's bounds
        int li, ri;
        cin >> li >> ri;

        // Check if the current interval completely contains the previous one
        if (li <= l && r <= ri)
            id = i;  // Update the index to the current interval
        // Check if the current interval overlaps with the previous one
        else if (li < l || r < ri)
            id = n;  // Mark as overlapping by setting id to n

        // Update the bounds of the union of intervals
        l = min(l, li);  // Update the left bound
        r = max(r, ri);  // Update the right bound
    }

    // Print the result: -1 if no valid interval found, otherwise print the 1-based index of the interval
    cout << (id == n ? -1 : id + 1) << endl;

    return 0;
}

