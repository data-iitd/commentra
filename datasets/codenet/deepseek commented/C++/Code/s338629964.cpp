#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;

// Define constants for modular arithmetic
#define MOD2 1000000007
#define MOD 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)

// Type definitions for convenience
typedef long long Int;
typedef pair<Int, Int> P;

// Arrays for factorials and their modular inverses
Int fact[1100000];
Int revfact[1100000];
Int rev[1100000];

// Function to initialize factorials and their inverses
void init(){
    Int m = MOD; // Set the modulus
    fact[0] = 1; // Base case for factorial
    revfact[0] = 1; // Base case for inverse factorial
    rev[0] = 0; // Not used
    rev[1] = 1; // Inverse of 1 is 1
    
    // Precompute factorials and their modular inverses
    for(int i = 1; i < 1100000; i++){
        fact[i] = fact[i-1] * i % m; // Compute factorial
        if(i > 1) 
            rev[i] = MOD / i * (MOD - rev[MOD % i]) % MOD; // Compute modular inverse
        revfact[i] = revfact[i-1] * rev[i] % MOD; // Compute inverse factorial
    }
}

// 2D array for storing combinations
Int comb[1100][1100];

// Function to compute n choose k (combinations)
Int nCk(Int n, Int k){
    if(n < k) return 0; // If n < k, return 0
    if(comb[n][k] != 0) return comb[n][k]; // Return cached result if available
    Int &res = comb[n][k]; // Reference to store result
    return res = fact[n] * revfact[n-k] % MOD * revfact[k] % MOD; // Compute combinations
}

// Function to compute modular exponentiation
Int mod_pow(Int x, Int a, Int m = MOD){
    if(a == 0) return 1; // Base case
    Int res = mod_pow(x, a / 2, m); // Recursive call
    res = res * res % m; // Square the result
    if(a % 2) res *= x; // If a is odd, multiply by x
    return res % m; // Return result modulo m
}

// Function to compute modular inverse using Fermat's Little Theorem
Int inv(Int x, Int m = MOD){
    return mod_pow(x, m-2, m); // Inverse is x^(m-2) mod m
}

// Global variables for input and output
Int aall, ball; // Total sums of arrays a and b
Int n, ans; // Number of elements and final answer
Int a[440], b[440]; // Input arrays
Int dp[440][440][2][2]; // Dynamic programming table

int main(){
    init(); // Initialize factorials and inverses
    cin >> n; // Read the number of elements
    
    // Read input arrays and compute their total sums
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        aall += a[i]; // Sum of array a
        ball += b[i]; // Sum of array b
    }

    // Initialize the dynamic programming table
    dp[0][0][0][0] = 1; // Base case for DP
    for(int i = 1; i <= n; i++){
        int id = i % 2; // Current index for alternating DP
        // Iterate over possible sums and counts
        for(int asum = aall; asum >= 0; asum--){
            for(int cnt = 0; cnt <= ball; cnt++){
                for(int p = 0; p < 2; p++){
                    if(asum - a[i-1] < 0) continue; // Skip if sum is not feasible
                    Int pw = 1; // Power variable for combinations
                    // Iterate over possible uses of b[i-1]
                    for(int use = 0; use < b[i-1]; use++){
                        if(cnt - use >= 0){
                            Int tmp = nCk(cnt, use) % MOD * pw % MOD; // Compute combinations
                            // Update DP table based on previous states
                            dp[asum][cnt][p][0] += dp[asum - a[i-1]][cnt - use][p^1][0] * tmp % MOD;
                            dp[asum][cnt][p][1] += dp[asum - a[i-1]][cnt - use][p^1][1] * tmp % MOD;
                        }
                        else break; // Break if not enough count
                        pw = pw * a[i-1] % MOD; // Update power for next use
                    }
                    // Handle the case where we use one more from b[i-1]
                    if(cnt - b[i-1] + 1 >= 0)
                        dp[asum][cnt][p][1] += dp[asum - a[i-1]][cnt - b[i-1] + 1][p^1][0] * nCk(cnt, b[i-1] - 1) % MOD * pw % MOD;
                    // Apply modulo to keep values within bounds
                    dp[asum][cnt][p][0] %= MOD;
                    dp[asum][cnt][p][1] %= MOD;
                }
            }
        }
    }

    // Final computation of the answer
    for(int asum = 0; asum <= aall; asum++){
        Int rev_asum_pow = 1; // Initialize power for the current sum
        for(int cnt = 0; cnt <= ball; cnt++){
            rev_asum_pow = rev_asum_pow * rev[asum] % MOD; // Update power for the sum
            for(int p = 0; p < 2; p++){
                // Compute contribution to the answer based on DP values
                Int x = dp[asum][cnt][p][1] * rev_asum_pow % MOD * (cnt + 1) % MOD * aall % MOD * rev[asum] % MOD;
                if(p == 1) ans += x; // Add if p is 1
                else ans -= x; // Subtract if p is 0
                ans %= MOD; // Ensure answer is within bounds
            }
        }
    }
    
    // Adjust answer if negative
    if(ans < 0) ans += MOD;
    cout << ans << endl; // Output the final answer
    
    return 0; // End of program
}
