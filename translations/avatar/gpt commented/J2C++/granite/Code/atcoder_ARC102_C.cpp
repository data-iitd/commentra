
#include <iostream>
#include <vector>

using namespace std;

// Define a constant for the modulus value
const int mod = 998244353;
// Declare a 2D vector to store binomial coefficients
vector<vector<long long>> nchoosek;

int main() {
    // Initialize the nchoosek vector to store binomial coefficients up to 4000
    nchoosek.resize(4001);
    for (int i = 0; i < nchoosek.size(); i++) {
        nchoosek[i].resize(4001);
    }

    // Set base cases for binomial coefficients: C(n, 0) = C(n, n) = 1
    for (int i = 0; i < nchoosek.size(); i++) {
        nchoosek[i][0] = nchoosek[i][i] = 1;
    }

    // Compute binomial coefficients using dynamic programming
    for (int i = 2; i < nchoosek.size(); i++) {
        for (int j = 1; j < i; j++) {
            // C(i, j) = C(i-1, j) + C(i-1, j-1)
            nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % mod;
        }
    }

    // Read the values of k and n from input
    int k, n;
    cin >> k >> n;

    // Iterate through the range of 2 to 2*k
    for (int i = 2; i <= 2 * k; i++) {
        int pairs;
        // Calculate the number of pairs based on the current index i
        if (i > k) {
            pairs = k - i / 2; // More pairs than k
        } else {
            pairs = (i - 1) / 2; // Fewer pairs than k
        }

        // Calculate the number of active elements remaining
        int active = k - 2 * pairs;
        if (i % 2 == 0) active -= 1; // Adjust active count for even i

        long long times2 = 1; // Initialize multiplier for choices
        long long total = 0; // Initialize total count

        // Calculate total combinations for the current number of pairs
        for (int j = 0; j <= pairs; j++) {
            // Calculate the number of ways to choose j pairs
            long long choice = times2 * nchoosek[pairs][j] % mod;
            times2 = times2 * 2 % mod; // Update multiplier for the next iteration

            // Skip if there are not enough active elements
            if (active + j - 1 < 0) continue;

            // Add combinations to the total based on active elements
            total += choice * nchoosek[n + active - 1][active + j - 1];

            // If i is even, add additional combinations
            if (i % 2 == 0) {
                total += choice * nchoosek[n + active - 2][active + j - 1];
            }

            // Ensure total remains within modulus
            total %= mod;
        }

        // Output the total combinations for the current i
        cout << total << endl;
    }

    return 0;
}

