
#include <iostream>
#include <vector>
using namespace std;

// Define modulo value and maximum value for precomputation
const int mod = 998244353;
const int __N = 8000;

// Precompute factorials and inverse factorials
vector<int> g1 = {1, 1};  // g1 will hold factorials
vector<int> g2 = {1, 1};  // g2 will hold inverse factorials
vector<int> inverse = {0, 1};  // inverse will hold modular inverses

// Function to compute factorials and inverse factorials
void precompute() {
    for (int i = 2; i <= __N; i++) {
        g1.push_back((g1.back() * i) % mod);  // Compute factorial
        inverse.push_back((-inverse[mod % i] * (mod / i)) % mod);  // Compute modular inverse using Fermat's Little Theorem
        g2.push_back((g2.back() * inverse.back()) % mod);  // Compute inverse factorial
    }
}

// Function to compute combinations with repetition
int cmb(int n, int r) {
    if (r < 0 || r > n) return 0;  // Return 0 if r is out of bounds
    r = min(r, n - r);  // Use symmetry property of combinations
    return (g1[n] * g2[r] * g2[n - r]) % mod;  // Calculate combination using precomputed factorials and inverses
}

// Function to compute kumiawase (combinations with repetition)
int kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1);
}

// Function to solve the main problem for a given n
int solve(int n) {
    int ans = 0;  // Initialize answer
    int kumi = (n - 1) / 2;  // Calculate half of n-1

    // Iterate over possible values of p
    for (int p = 0; p <= kumi; p++) {
        if (p > N) break;  // Break if p exceeds N
        // Update answer with contributions from current p
        ans += (1 << p) * cmb(kumi, p) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)));

        // If n is even, consider the case where p is used one less
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += (1 << p) * cmb(kumi, p) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)));
        }
    }

    return ans % mod;  // Return the computed answer
}

int main() {
    precompute();  // Precompute factorials and inverse factorials

    int K, N;  // Read input values K and N
    cin >> K >> N;

    vector<int> ans;  // List to store answers for each i

    // Iterate over the range to compute results for each i
    for (int i = 2; i <= 2 * K; i++) {
        if (i <= K + 1) {
            // Solve for i and store the result
            int tmp = solve(i);
            ans.push_back(tmp);  // Append result to answers list
            cout << tmp << endl;  // Print the result
        } else {
            // For i greater than K+1, use previously computed results
            cout << ans[i - K - 1] << endl;  // Print the corresponding result from the answers list
        }
    }

    return 0;
}

