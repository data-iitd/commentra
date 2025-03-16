
package main

import (
	"fmt"
)

// Define constants for modular arithmetic
const MOD2 = 1000000007
const MOD = 998244353
const INF = (1 << 30) - 1
const LINF = (1 << 60)
const EPS = 1e-10

// Type definitions for convenience
type Int int
type P struct {
	x, y Int
}

// Arrays for factorials and their modular inverses
var fact [1100000]Int
var revfact [1100000]Int
var rev [1100000]Int

// Function to initialize factorials and their inverses
func init() {
	m := MOD // Set the modulus
	fact[0] = 1 // Base case for factorial
	revfact[0] = 1 // Base case for inverse factorial
	rev[0] = 0 // Not used
	rev[1] = 1 // Inverse of 1 is 1

	// Precompute factorials and their modular inverses
	for i := 1; i < 1100000; i++ {
		fact[i] = fact[i-1] * Int(i) % m // Compute factorial
		if i > 1 {
			rev[i] = MOD / Int(i) * (MOD - rev[MOD%Int(i)]) % MOD // Compute modular inverse
		}
		revfact[i] = revfact[i-1] * rev[i] % MOD // Compute inverse factorial
	}
}

// 2D array for storing combinations
var comb [1100][1100]Int

// Function to compute n choose k (combinations)
func nCk(n, k Int) Int {
	if n < k {
		return 0 // If n < k, return 0
	}
	if comb[n][k] != 0 {
		return comb[n][k] // Return cached result if available
	}
	res := comb[n][k] // Reference to store result
	return res = fact[n] * revfact[n-k] % MOD * revfact[k] % MOD // Compute combinations
}

// Function to compute modular exponentiation
func mod_pow(x, a, m Int) Int {
	if a == 0 {
		return 1 // Base case
	}
	res := mod_pow(x, a/2, m) // Recursive call
	res = res * res % m // Square the result
	if a%2 != 0 {
		res *= x // If a is odd, multiply by x
	}
	return res % m // Return result modulo m
}

// Function to compute modular inverse using Fermat's Little Theorem
func inv(x, m Int) Int {
	return mod_pow(x, m-2, m) // Inverse is x^(m-2) mod m
}

// Global variables for input and output
var aall, ball Int
var n, ans Int
var a [440]Int
var b [440]Int
var dp [440][440][2][2]Int

func main() {
	init() // Initialize factorials and inverses
	fmt.Scan(&n) // Read the number of elements

	// Read input arrays and compute their total sums
	for i := 0; i < int(n); i++ {
		fmt.Scan(&a[i], &b[i])
		aall += a[i] // Sum of array a
		ball += b[i] // Sum of array b
	}

	// Initialize the dynamic programming table
	dp[0][0][0][0] = 1 // Base case for DP
	for i := 1; i <= n; i++ {
		id := i % 2 // Current index for alternating DP
		// Iterate over possible sums and counts
		for asum := aall; asum >= 0; asum-- {
			for cnt := 0; cnt <= ball; cnt++ {
				for p := 0; p < 2; p++ {
					if asum-a[i-1] < 0 {
						continue // Skip if sum is not feasible
					}
					pw := 1 // Power variable for combinations
					// Iterate over possible uses of b[i-1]
					for use := 0; use < b[i-1]; use++ {
						if cnt-use >= 0 {
							tmp := nCk(cnt, use) % MOD * pw % MOD // Compute combinations
							// Update DP table based on previous states
							dp[asum][cnt][p][0] += dp[asum-a[i-1]][cnt-use][p^1][0] * tmp % MOD
							dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-use][p^1][1] * tmp % MOD
						} else {
							break // Break if not enough count
						}
						pw = pw * a[i-1] % MOD // Update power for next use
					}
					// Handle the case where we use one more from b[i-1]
					if cnt-b[i-1]+1 >= 0 {
						dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-b[i-1]+1][p^1][0] * nCk(cnt, b[i-1]-1) % MOD * pw % MOD
					}
					// Apply modulo to keep values within bounds
					dp[asum][cnt][p][0] %= MOD
					dp[asum][cnt][p][1] %= MOD
				}
			}
		}
	}

	// Final computation of the answer
	for asum := 0; asum <= aall; asum++ {
		rev_asum_pow := 1 // Initialize power for the current sum
		for cnt := 0; cnt <= ball; cnt++ {
			rev_asum_pow = rev_asum_pow * rev[asum] % MOD // Update power for the sum
			for p := 0; p < 2; p++ {
				// Compute contribution to the answer based on DP values
				x := dp[asum][cnt][p][1] * rev_asum_pow % MOD * (cnt + 1) % MOD * aall % MOD * rev[asum] % MOD
				if p == 1 {
					ans += x // Add if p is 1
				} else {
					ans -= x // Subtract if p is 0
				}
				ans %= MOD // Ensure answer is within bounds
			}
		}
	}

	// Adjust answer if negative
	if ans < 0 {
		ans += MOD
	}
	fmt.Println(ans) // Output the final answer

	// 