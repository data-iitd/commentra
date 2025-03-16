#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

// Function to read the next integer from the input stream
int getNextInt(istream &input) {
    int value;
    input >> value;
    return value;
}

// Main function to read input and process it
int main(int argc, char *argv[]) {
    // Open the standard input stream if no file is provided as an argument
    istream *input = &cin;
    if (argc > 1) {
        // Open the file provided as an argument and use it as the input stream
        ifstream file(argv[1]);
        input = &file;
    }

    // Read the number of test cases from the input
    int n = getNextInt(*input);

    // Initialize a vector to store the prefix sum of squares of elements
    vector<int> mm(n + 1, 0);

    // Initialize a 2D vector to store the dynamic programming table
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Read the elements and their prefix sum of squares from the input
    for (int i = 0; i < n; i++) {
        // Read the next integer as the current element
        mm[i + 1] = getNextInt(*input);
        // Read the next integer as the next element's prefix sum of square
        mm[i + 1] += mm[i] * mm[i];
    }

    // Process the dynamic programming table for all subarrays of given size
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            // Iterate through all subarrays of the current subarray
            for (int k = i; k <= j - 1; k++) {
                // Calculate the sum of squares of elements in the current subarray
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                // Update the dynamic programming table if a larger sum is found
                if (dp[i][j] == 0 || dp[i][j] > d) {
                    dp[i][j] = d;
                }
            }
        }
    }

    // Print the result for the given input
    cout << dp[1][n] << endl;

    // End of the code
    return 0;
}
