#include <iostream>
#include <vector>
using namespace std;

// Define a constant for modulo
const int mod = 998244353;
const int __N = 8000;

// Precompute factorials and inverse factorials
vector<long long> g1(__N + 1, 1), g2(__N + 1, 1), inverse(__N + 1, 0);

void precompute() {
    inverse[1] = 1;
    for (int i = 2; i <= __N; ++i) {
        g1[i] = g1[i - 1] * i % mod; // Compute factorial
        inverse[i] = (-inverse[mod % i] * (mod / i)) % mod; // Compute modular inverse
        g2[i] = g2[i - 1] * inverse[i] % mod; // Compute inverse factorial
    }
}

// Function to compute combinations modulo 'mod'
long long cmb(int n, int r) {
    if (r < 0 || r > n) return 0; // Return 0 if r is out of bounds
    r = min(r, n - r); // Use symmetry property of combinations
    return g1[n] * g2[r] % mod * g2[n - r] % mod; // Calculate combination
}

// Function to compute kumiawase (combinations with repetition)
long long kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1);
}

// Function to solve the main problem for a given n
long long solve(int n, int K, int N) {
    if (n > K + 1) return 0; // Ensure n is within valid range
    long long ans = 0; // Initialize answer
    int kumi = (n - 1) / 2; // Calculate half of n-1

    // Iterate over possible values of p
    for (int p = 0; p <= kumi; ++p) {
        if (p > N) break; // Break if p exceeds N
        // Update answer with contributions from current p
        ans += (1LL << p) * cmb(kumi, p) % mod * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0))) % mod;
        ans %= mod; // Ensure ans is within mod

        // If n is even, consider the case where p is used one less
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += (1LL << p) * cmb(kumi, p) % mod * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0))) % mod;
            ans %= mod; // Ensure ans is within mod
        }
    }

    return ans; // Return the computed answer
}

int main() {
    // Read input values K and N from user
    int K, N;
    cin >> K >> N;

    // Precompute factorials and inverse factorials
    precompute();

    // List to store answers for each i
    vector<long long> ans;

    // Iterate over the range to compute results for each i
    for (int i = 2; i <= 2 * K; ++i) {
        if (i <= K + 1) {
            // Solve for i and store the result
            long long tmp = solve(i, K, N) % mod;
            ans.push_back(tmp); // Append result to answers list
            cout << tmp << endl; // Print the result
        } else {
            // For i greater than K+1, use previously computed results
            cout << ans[ans.size() - i + K] << endl; // Print the corresponding result from the answers list
        }
    }

    return 0;
}

// <END-OF-CODE>
