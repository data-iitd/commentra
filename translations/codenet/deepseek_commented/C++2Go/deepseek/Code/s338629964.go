package main

import (
	"fmt"
	"math"
)

// Define constants for modular arithmetic
const MOD2 = 1000000007
const MOD = 998244353
const INF = (1 << 30) - 1
const LINF = 1 << 60
const EPS = 1e-10

// Type definitions for convenience
type Int = int64
type P = struct {
	x, y Int
}

// Arrays for factorials and their modular inverses
var fact = make([]Int, 1100000)
var revfact = make([]Int, 1100000)
var rev = make([]Int, 1100000)

// Function to initialize factorials and their inverses
func init() {
	m := MOD // Set the modulus
	fact[0] = 1
	revfact[0] = 1
	rev[0] = 0
	rev[1] = 1
	
	// Precompute factorials and their modular inverses
	for i := 1; i < 1100000; i++ {
		fact[i] = fact[i-1] * Int(i) % m
		if i > 1 {
			rev[i] = MOD / Int(i) * (MOD - rev[MOD % Int(i)]) % MOD
		}
		revfact[i] = revfact[i-1] * rev[i] % MOD
	}
}

// 2D array for storing combinations
var comb = make([][]Int, 1100)
for i := range comb {
	comb[i] = make([]Int, 1100)
}

// Function to compute n choose k (combinations)
func nCk(n, k Int) Int {
	if n < k {
		return 0
	}
	if comb[n][k] != 0 {
		return comb[n][k]
	}
	var res Int = fact[n] * revfact[n-k] % MOD * revfact[k] % MOD
	comb[n][k] = res
	return res
}

// Function to compute modular exponentiation
func modPow(x, a, m Int) Int {
	if a == 0 {
		return 1
	}
	res := modPow(x, a/2, m)
	res = res * res % m
	if a % 2 != 0 {
		res = res * x % m
	}
	return res
}

// Function to compute modular inverse using Fermat's Little Theorem
func inv(x, m Int) Int {
	return modPow(x, m-2, m)
}

// Global variables for input and output
var aall, ball Int
var n, ans Int
var a = make([]Int, 440)
var b = make([]Int, 440)
var dp = make([][][][]Int, 440)
for i := range dp {
	dp[i] = make([][][]Int, 440)
	for j := range dp[i] {
		dp[i][j] = make([][]Int, 2)
		for k := range dp[i][j] {
			dp[i][j][k] = make([]Int, 2)
		}
	}
}

func main() {
	init() // Initialize factorials and inverses
	fmt.Scan(&n) // Read the number of elements
	
	// Read input arrays and compute their total sums
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i], &b[i])
		aall += a[i]
		ball += b[i]
	}

	// Initialize the dynamic programming table
	dp[0][0][0][0] = 1
	for i := 1; i <= n; i++ {
		id := i % 2
		for asum := aall; asum >= 0; asum-- {
			for cnt := 0; cnt <= ball; cnt++ {
				for p := 0; p < 2; p++ {
					if asum - a[i-1] < 0 {
						continue
					}
					pw := Int(1)
					for use := 0; use < b[i-1]; use++ {
						if cnt - use >= 0 {
							tmp := nCk(cnt, use) % MOD * pw % MOD
							dp[asum][cnt][p][0] += dp[asum - a[i-1]][cnt - use][p^1][0] * tmp % MOD
							dp[asum][cnt][p][1] += dp[asum - a[i-1]][cnt - use][p^1][1] * tmp % MOD
						} else {
							break
						}
						pw = pw * a[i-1] % MOD
					}
					if cnt - b[i-1] + 1 >= 0 {
						dp[asum][cnt][p][1] += dp[asum - a[i-1]][cnt - b[i-1] + 1][p^1][0] * nCk(cnt, b[i-1] - 1) % MOD * pw % MOD
					}
					dp[asum][cnt][p][0] %= MOD
					dp[asum][cnt][p][1] %= MOD
				}
			}
		}
	}

	// Final computation of the answer
	for asum := 0; asum <= aall; asum++ {
		revAsumPow := Int(1)
		for cnt := 0; cnt <= ball; cnt++ {
			revAsumPow = revAsumPow * inv(asum) % MOD
			for p := 0; p < 2; p++ {
				x := dp[asum][cnt][p][1] * revAsumPow % MOD * (cnt + 1) % MOD * aall % MOD * inv(asum) % MOD
				if p == 1 {
					ans += x
				} else {
					ans -= x
				}
				ans %= MOD
			}
		}
	}
	
	if ans < 0 {
		ans += MOD
	}
	fmt.Println(ans)
}

