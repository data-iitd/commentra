#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Initialize variables for the number of pairs (n) and the minimum score (s)
    int n, s;
    cin >> n >> s;

    // Initialize a variable to keep track of the maximum sum of pairs
    int max_sum = 0;

    // Loop through each pair of integers
    while (n-- > 0) {
        // Read the two integers f and t
        int f, t;
        cin >> f >> t;
        // Update max_sum if the sum of f and t is greater than the current max_sum
        max_sum = max(max_sum, f + t);
    }

    // Print the maximum value between max_sum and s
    cout << max(max_sum, s) << endl;

    return 0;
}

// <END-OF-CODE>
