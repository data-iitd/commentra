#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Helper function to read the next integer from the input.
int getNextInt() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    ss >> num;
    return num;
}

// Helper function to read the next string from the input.
string getNextString() {
    string line;
    getline(cin, line);
    return line;
}

int main() {
    // Determine the input source: standard input or a file specified as a command-line argument.
    // This part is not applicable in C++ as it doesn't support file input directly from command-line arguments.

    // Read the number of elements.
    int n = getNextInt();
    vector<int> mm(n + 1); // Create a vector to hold the input values.
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // Create a 2D vector for dynamic programming.

    // Read the input values into the mm vector.
    for (int i = 0; i < n; i++) {
        mm[i] = getNextInt(); // Read the first value.
        mm[i + 1] = getNextInt(); // Read the second value.
    }

    // Perform dynamic programming to calculate the minimum cost.
    for (int l = 2; l <= n; l++) { // l is the length of the subproblem.
        for (int i = 1; i <= n - l + 1; i++) { // i is the starting index of the subproblem.
            int j = i + l - 1; // j is the ending index of the subproblem.
            for (int k = i; k <= j - 1; k++) { // k is the partition point.
                // Calculate the cost of multiplying the matrices.
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                // Update the dp table with the minimum cost found.
                if (dp[i][j] == 0 || dp[i][j] > d) {
                    dp[i][j] = d;
                }
            }
        }
    }

    // Output the minimum cost of multiplying the entire sequence of matrices.
    cout << dp[1][n] << endl;

    return 0;
}
