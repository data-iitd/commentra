#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 5;

int main() {
    // Create a variable for the number of pairs
    int n;
    cin >> n;

    // Initialize two vectors to store the pairs
    vector<int> a(n), b(n);

    // Initialize left to infinity and right to zero
    int left = INF, right = 0;

    // Read the pairs and determine the minimum and maximum values
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read the first element of the pair
        cin >> b[i]; // Read the second element of the pair

        // Update left to the minimum value found in a
        left = min(left, a[i]);
        // Update right to the maximum value found in b
        right = max(right, b[i]);
    }

    // Check for a pair that matches the left and right bounds
    for (int i = 0; i < n; i++) {
        // If the current pair matches the min and max values
        if (left == a[i] && right == b[i]) {
            // Print the index (1-based) and exit
            cout << (i + 1) << endl;
            return 0;
        }
    }

    // If no matching pair is found, print -1
    cout << -1 << endl;

    return 0;
}

// <END-OF-CODE>
