#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to compute combinations modulo 'mod'
long long cmb(int n, int r, long long mod) {
    // Return 0 if r is out of bounds
    if (r < 0 || r > n)
        return 0;
    // Use symmetry property of combinations
    r = min(r, n - r);
    // Calculate combination using precomputed factorials and inverses
    return g1[n] * g2[r] * g2[n - r] % mod;
}

// Function to compute kumiawase (combinations with repetition)
long long kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1, mod);
}

// Function to solve the main problem for a given n
long long solve(int n) {
    assert(n <= K + 1);  // Ensure n is within valid range
    long long ans = 0;  // Initialize answer
    int kumi = (n - 1) / 2;  // Calculate half of n-1

    // Iterate over possible values of p
    for (int p = kumi + 1; p <= N; p++) {
        // Update answer with contributions from current p
        ans += 2LL * p * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - int(n % 2 == 0)));

        // If n is even, consider the case where p is used one less
        if (n % 2 == 0 && N - p - 1 >= 0)
            ans += 2LL * p * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - int(n % 2 == 0)));
    }

    return ans;  // Return the computed answer
}

// List to store answers for each i
vector<long long> ans;

// Main function
int main() {
    // Read input values K and N from user
    int K, N;
    cin >> K >> N;

    // Define a debug print function (currently does nothing)
    auto dprint = [](auto... x) { return (void)((cout << ... << x) << endl); };

    // Set modulo value and maximum value for precomputation
    long long mod = 998244353;
    int __N = 8000;

    // Precompute factorials and inverse factorials
    vector<long long> g1 = {1, 1};  // g1 will hold factorials
    vector<long long> g2 = {1, 1};  // g2 will hold inverse factorials
    vector<long long> inverse = {0, 1};  // inverse will hold modular inverses

    // Fill g1, g2, and inverse arrays
    for (int i = 2; i <= __N; i++) {
        g1.push_back((g1.back() * i) % mod);  // Compute factorial
        inverse.push_back((-inverse[mod % i] * (mod / i)) % mod);  // Compute modular inverse using Fermat's Little Theorem
        g2.push_back((g2.back() * inverse.back()) % mod);  // Compute inverse factorial
    }

    // Iterate over the range to compute results for each i
    for (int i = 2; i <= 2 * K + 1; i++) {
        if (i <= K + 1) {
            // Solve for i and store the result
            long long tmp = solve(i) % 998244353;
            ans.push_back(tmp);  // Append result to answers list
            cout << tmp << endl;  // Print the result
        } else {
            // For i greater than K+1, use previously computed results
            cout << ans[i - K - 2] << endl;  // Print the corresponding result from the answers list
        }
    }

    return 0;
}

