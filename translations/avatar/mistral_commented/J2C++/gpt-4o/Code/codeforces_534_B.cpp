#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays
#include <algorithm> // Including the algorithm library for the max function

using namespace std; // Using the standard namespace

int main() {
    int v1, v2, t, d; // Declaring input variables
    cin >> v1 >> v2 >> t >> d; // Reading input values from the user

    vector<vector<long long>> dp(t - 1, vector<long long>(1150, LLONG_MIN)); // Creating a 2D vector dp initialized to minimum long long value

    // Initializing the first row of the dp table with the given value
    for (int i = 0; i < t - 1; i++) {
        dp[i][v1] = v1; // Setting the value of the cell (i, v1) to v1
    }

    long long sum = 0; // Initializing a variable sum to 0

    // Filling the dp table using dynamic programming
    for (int i = 1; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            for (int x = 0; x <= d; x++) {
                if (j + x < 1150) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + x] + j); // Filling the current cell with the maximum value
                }
            }
            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + j); // Filling the current cell with the maximum value
                }
            }
        }
        sum += dp[i][1149]; // Adding the value of the last cell of the current row to the sum
    }

    long long ans = LLONG_MIN; // Initializing a variable ans with minimum long long value

    // Finding the maximum value that can be obtained by jumping from any cell in the last but one row to the last row
    for (int i = t - 2; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            if (abs(j - v2) <= d) { // Checking if the absolute difference between j and v2 is less than or equal to d
                ans = max(ans, dp[i][j] + v2); // Updating the value of ans with the maximum of itself
            }
        }
    }

    cout << ans << endl; // Printing the final answer
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
