#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a function to read an integer
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Define a function to read two integers
pair<int, int> readPair() {
    int a, b;
    cin >> a >> b;
    return {a, b};
}

int main() {
    // Read the number of test cases
    int n = readInt();

    // Initialize id variable to 0
    int id = 0;

    // Read left and right boundary values for the first test case
    auto [l, r] = readPair();

    // Iterate through the remaining test cases
    for (int i = 1; i < n; i++) {
        // Read left and right boundary values for the current test case
        auto [li, ri] = readPair();

        // Check if the current test case overlaps with the previously defined boundary values
        if (li <= l && r <= ri) {
            // Update id variable to the index of the current test case
            id = i;
        } 
        // If the current test case does not overlap, keep id as n
        else if (li < l || r < ri) {
            id = n;
        }

        // Update boundary values based on the current test case
        l = min(l, li);
        r = max(r, ri);
    }

    // Print the index of the test case that satisfies the condition, or -1 if no such test case exists
    cout << (id == n ? -1 : id + 1) << endl;

    return 0;
}

// <END-OF-CODE>
