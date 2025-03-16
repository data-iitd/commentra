#include <iostream>
#include <vector>

void run() {
    // Read the number of elements (n) and the target value (k)
    int n, k;
    std::cin >> n >> k;

    // Declare a vector to store the elements
    std::vector<int> a(n);

    // Read n elements into the vector a
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Allocate memory for the dynamic programming array dp
    std::vector<int> dp(k + 1, 0);

    // Iterate from 1 to k to fill the dp array
    for (int i = 1; i <= k; i++) {
        // Initialize the win flag to 0
        int win = 0;

        // Check each element in the vector a to see if it can be subtracted from i
        for (int j = 0; j < n && a[j] <= i; j++) {
            if (dp[i - a[j]] == 0) {
                // If the resulting value is zero, set win to 1
                win = 1;
            }
        }

        // Set dp[i] to the win flag
        dp[i] = win;
    }

    // Print the result based on the value of dp[k]
    std::cout << (dp[k] ? "First" : "Second") << std::endl;
}

int main() {
    // Call the run function to execute the game strategy
    run();
    return 0;
}

// <END-OF-CODE>
