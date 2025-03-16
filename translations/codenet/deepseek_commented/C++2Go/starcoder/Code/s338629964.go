<<<<<<< HEAD

import (
	"fmt"
	"math/big"
=======
package main

import (
	"fmt"
	"math"
>>>>>>> 98c87cb78a (data updated)
)

// Define constants for modular arithmetic
const MOD2 = 1000000007
const MOD = 998244353
<<<<<<< HEAD
const INF = int((1 << 30) - 1)
=======
const INF = int(1e9)
>>>>>>> 98c87cb78a (data updated)
const LINF = int(1e18)
const EPS = 1e-10

// Type definitions for convenience
type Int = int64
<<<<<<< HEAD
type P = struct{
	x, y int
}
=======
>>>>>>> 98c87cb78a (data updated)

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
		fact[i] = fact[i-1] * Int(i) % m
		if i > 1 {
			rev[i] = m / Int(i) * (m - rev[m%Int(i)]) % m
		}
		revfact[i] = revfact[i-1] * rev[i] % m
	}
}

// 2D array for storing combinations
var comb [1100][1100]Int

// Function to compute n choose k (combinations)
func nCk(n, k int) Int {
	if n < k {
		return 0
	}
	if comb[n][k]!= 0 {
		return comb[n][k]
	}
	var res Int
	res = fact[n] * revfact[n-k] % MOD * revfact[k] % MOD
<<<<<<< HEAD
	return comb[n][k] = res
=======
	return res
>>>>>>> 98c87cb78a (data updated)
}

// Function to compute modular exponentiation
func mod_pow(x, a Int) Int {
	if a == 0 {
		return 1
	}
	res := mod_pow(x, a/2)
	res = res * res % MOD
	if a%2 == 1 {
		res *= x
	}
	return res % MOD
}

// Function to compute modular inverse using Fermat's Little Theorem
func inv(x, m Int) Int {
	return mod_pow(x, m-2, m)
}

// Global variables for input and output
var aall, ball Int
var n, ans Int
var a [440]Int
var b [440]Int
var dp [440][440][2][2]Int

func main() {
	init() // Initialize factorials and inverses
	fmt.Scanf("%d", &n) // Read the number of elements

	// Read input arrays and compute their total sums
	for i := 0; i < n; i++ {
		fmt.Scanf("%d %d", &a[i], &b[i])
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
						continue
					}
					pw := 1 // Power variable for combinations
					// Iterate over possible uses of b[i-1]
					for use := 0; use < b[i-1]; use++ {
						if cnt-use >= 0 {
							tmp := nCk(cnt, use) % MOD * pw % MOD
							// Update DP table based on previous states
							dp[asum][cnt][p][0] += dp[asum-a[i-1]][cnt-use][p^1][0] * tmp % MOD
							dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-use][p^1][1] * tmp % MOD
						} else {
							break
						}
						pw = pw * a[i-1] % MOD
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
			rev_asum_pow = rev_asum_pow * rev[asum] % MOD
			for p := 0; p < 2; p++ {
				// Compute contribution to the answer based on DP values
				x := dp[asum][cnt][p][1] * rev_asum_pow % MOD * (cnt+1) % MOD * aall % MOD * rev[asum] % MOD
				if p == 1 {
					ans += x
				} else {
					ans -= x
				}
				ans %= MOD
			}
		}
	}

	// Adjust answer if negative
	if ans < 0 {
		ans += MOD
	}
	fmt.Println(ans) // Output the final answer
}

