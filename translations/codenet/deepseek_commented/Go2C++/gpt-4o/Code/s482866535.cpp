#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to compute the minimum number of matrix multiplications.
int matrixChainOrder(const vector<int>& dimensions) {
    int n = dimensions.size() - 1; // Number of matrices
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Use dynamic programming to compute the minimum number of multiplications.
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = numeric_limits<int>::max(); // Initialize to a large value
            for (int k = i; k <= j - 1; k++) {
                int d = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                dp[i][j] = min(dp[i][j], d);
            }
        }
    }

    return dp[1][n];
}

int main(int argc, char* argv[]) {
    // Read the number of matrices.
    int n;
    cin >> n;

    // Initialize vector for matrix dimensions.
    vector<int> dimensions(2 * n); // To store dimensions

    // Read matrix dimensions into the dimensions vector.
    for (int i = 0; i < n; i++) {
        cin >> dimensions[i];
        cin >> dimensions[i + 1];
    }

    // Compute and print the minimum number of multiplications.
    cout << matrixChainOrder(dimensions) << endl;

    return 0;
}

// <END-OF-CODE>
