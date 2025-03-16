#include <iostream> // Importing the iostream library for input/output operations
#include <vector> // Importing the vector library for dynamic arrays

using namespace std; // Using the standard namespace

int main() {
    long mod = 1e9 + 7; // Define the modulo constant
    int n, k; // Declare the integer variables n and k
    cin >> n >> k; // Read the integer n and k from input

    vector<int> len; // Create a vector to store segment lengths
    int l = 1; // Initialize the starting point of the segment
    while (l <= n) {
        int r = n / (n / l); // Calculate the ending point of the segment
        len.push_back(r - l + 1); // Add the length of the segment to the vector
        l = r + 1; // Move to the next segment
    }

    int q = len.size(); // Store the size of the len vector in q
    vector<long> dp(k * (q + 1)); // Initialize the dp vector with sufficient size

    // Calculate the prefix sums of the lengths and store them in the dp vector
    for (int j = 1; j <= q; j++) {
        dp[j] = len[j - 1] + dp[j - 1];
    }

    // Main loop to calculate the dynamic programming values for k iterations
    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= q; j++) {
            dp[i * (q + 1) + j] = dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * len[j - 1];
            dp[i * (q + 1) + j] %= mod; // Ensure the value does not exceed the modulo
        }
    }

    // Print the result stored in the dp vector
    cout << dp[k * (q + 1) - 1] << endl;
    return 0;
}

