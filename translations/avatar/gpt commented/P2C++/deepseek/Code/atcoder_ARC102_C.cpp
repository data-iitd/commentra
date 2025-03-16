#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define dprint(...) // Define a debug print function (currently does nothing)

typedef long long ll;

// Function to compute combinations modulo 'mod'
ll cmb(int n, int r, ll mod, const vector<ll>& g1, const vector<ll>& g2) {
    // Return 0 if r is out of bounds
    if (r < 0 || r > n) {
        return 0;
    }
    // Use symmetry property of combinations
    r = min(r, n - r);
    // Calculate combination using precomputed factorials and inverses
    return g1[n] * g2[r] % mod * g2[n - r] % mod;
}

// Function to compute kumiawase (combinations with repetition)
ll kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1, 998244353, g1, g2);
}

// Function to solve the main problem for a given n
ll solve(int n, int K, const vector<ll>& g1, const vector<ll>& g2) {
    assert(n <= K + 1); // Ensure n is within valid range
    ll ans = 0; // Initialize answer
    int kumi = (n - 1) / 2; // Calculate half of n-1

    // Iterate over possible values of p
    for (int p = 0; p <= kumi; ++p) {
        if (p > N) { // Break if p exceeds N
            break;
        }
        // Update answer with contributions from current p
        ans += (1LL << p) * cmb(kumi, p, 998244353, g1, g2) % 998244353 * kumiawase(N - p, p + (K - kumi * 2 - int(n % 2 == 0))) % 998244353;
        ans %= 998244353;
        
        // If n is even, consider the case where p is used one less
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += (1LL << p) * cmb(kumi, p, 998244353, g1, g2) % 998244353 * kumiawase(N - p - 1, p + (K - kumi * 2 - int(n % 2 == 0))) % 998244353;
            ans %= 998244353;
        }
    }
    return ans; // Return the computed answer
}

int main() {
    int K, N;
    cin >> K >> N;

    // Set modulo value and maximum value for precomputation
    const ll mod = 998244353;
    const int __N = 8000;

    // Precompute factorials and inverse factorials
    vector<ll> g1 = {1, 1}; // g1 will hold factorials
    vector<ll> g2 = {1, 1}; // g2 will hold inverse factorials
    vector<ll> inverse = {0, 1}; // inverse will hold modular inverses

    // Fill g1, g2, and inverse arrays
    for (int i = 2; i <= __N; ++i) {
        g1.push_back(g1.back() * i % mod); // Compute factorial
        inverse.push_back(-inverse[mod % i] * (mod / i) % mod); // Compute modular inverse using Fermat's Little Theorem
        g2.push_back(g2.back() * inverse.back() % mod); // Compute inverse factorial
    }

    // List to store answers for each i
    vector<ll> ans;

    // Iterate over the range to compute results for each i
    for (int i = 2; i <= 2 * K; ++i) {
        if (i <= K + 1) {
            // Solve for i and store the result
            ll tmp = solve(i, K, g1, g2) % 998244353;
            ans.push_back(tmp); // Append result to answers list
            cout << tmp << endl; // Print the result
        } else {
            // For i greater than K+1, use previously computed results
            cout << ans[i - K - 1] << endl; // Print the corresponding result from the answers list
        }
    }

    return 0;
}
