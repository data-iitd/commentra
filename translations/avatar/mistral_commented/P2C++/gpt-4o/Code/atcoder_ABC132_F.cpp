#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    // Read input values for n and k
    long long n, k;
    cin >> n >> k;

    // Initialize a vector 'coef' to store coefficients
    vector<long long> coef;

    // Calculate coefficients for n up to its square root
    for (long long i = 1; i * i <= n; ++i) {
        coef.push_back(n / i - n / (i + 1));
    }

    // Add remaining coefficients to the list
    coef.insert(coef.end(), n - accumulate(coef.begin(), coef.end(), 0LL), 1);

    // Reverse the list 'coef'
    reverse(coef.begin(), coef.end());

    // Initialize a 2D vector 'dp' to store intermediate results
    int nn = coef.size();
    vector<vector<long long>> dp(k + 1, vector<long long>(nn, 0));

    // Initialize the first row of dp with 1 at index 0
    dp[0][0] = 1;

    // Calculate dp[i][j] for i from 1 to k and j from nn-1 to 0
    for (int i = 1; i <= k; ++i) {
        long long tmp = 0;
        // Iterate through the reverse list 'coef' from j = nn-1 to j = 0
        for (int j = nn - 1; j >= 0; --j) {
            // Update 'tmp' with the sum of dp[i-1][j] and the product of coef[j] and tmp
            tmp = (tmp + dp[i - 1][j]) % mod;
            tmp = (tmp + coef[j]) % mod;
            // Update dp[i][j] with the product of coef[j] and tmp
            dp[i][j] = coef[j] * tmp % mod;
        }
    }

    // Calculate the final answer by summing up dp[k]
    long long answer = 0;
    for (int j = 0; j < nn; ++j) {
        answer = (answer + dp[k][j]) % mod;
    }

    cout << answer << endl;

    return 0;
}

// <END-OF-CODE>
