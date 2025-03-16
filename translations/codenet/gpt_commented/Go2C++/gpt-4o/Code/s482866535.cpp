#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

// Function to read the next integer from the input stream.
int getNextInt(istringstream &iss) {
    int value;
    iss >> value; // Read the next integer from the stream.
    return value; // Return the integer value.
}

int main(int argc, char *argv[]) {
    // Determine the input source: standard input or a file specified as a command-line argument.
    ifstream file;
    istream *input = &cin; // Default to standard input.

    if (argc > 1) {
        file.open(argv[1]); // Open the file if a filename is provided.
        input = &file; // Use the file stream for input.
    }

    // Read the number of elements.
    int n;
    *input >> n;

    vector<int> mm(n + 1); // Create a vector to hold the input values.
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // Create a 2D vector for dynamic programming.

    // Read the input values into the mm vector.
    for (int i = 0; i < n; i++) {
        *input >> mm[i]; // Read the first value.
        *input >> mm[i + 1]; // Read the second value.
    }

    // Perform dynamic programming to calculate the minimum cost.
    for (int l = 2; l <= n; l++) { // l is the length of the subproblem.
        for (int i = 1; i <= n - l + 1; i++) { // i is the starting index of the subproblem.
            int j = i + l - 1; // j is the ending index of the subproblem.
            dp[i][j] = numeric_limits<int>::max(); // Initialize to a large value.
            for (int k = i; k <= j - 1; k++) { // k is the partition point.
                // Calculate the cost of multiplying the matrices.
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                // Update the dp table with the minimum cost found.
                dp[i][j] = min(dp[i][j], d);
            }
        }
    }

    // Output the minimum cost of multiplying the entire sequence of matrices.
    cout << dp[1][n] << endl;

    // Close the file if it was opened.
    if (file.is_open()) {
        file.close();
    }

    return 0;
}

// <END-OF-CODE>
