package main

import (
	"fmt"
)

const mod = 1e9 + 7
const NMAX = 1000010

var fac [NMAX]int64
var finv [NMAX]int64
var inv [NMAX]int64

// Function to initialize factorials and their inverses
func init() {
	fac[0], fac[1] = 1, 1
	finv[0], finv[1] = 1, 1
	inv[1] = 1

	for i := 2; i < NMAX; i++ {
		fac[i] = fac[i-1] * int64(i) % mod
		inv[i] = mod - inv[mod%i]*int64(mod/i)%mod
		finv[i] = finv[i-1] * inv[i] % mod
	}
}

// Function to compute binomial coefficient C(n, k)
func C(n, k int) int64 {
	if n < k || n < 0 || k < 0 {
		return 0
	}
	return fac[n] * (finv[k] * finv[n-k] % mod) % mod
}

func main() {
	// Initialize factorials and inverses
	init()

	// Read input values for X and Y
	var X, Y int
	fmt.Scan(&X, &Y)

	// Check if the sum of X and Y is divisible by 3
	if (X+Y)%3 != 0 {
		fmt.Println(0) // If not, output 0 and exit
		return
	}

	// Calculate n based on the sum of X and Y
	n := (X + Y) / 3 + 1

	// Calculate k based on the relationship to the line y = 2x
	k := 2*(n-1) - Y + 1 // Determine how far the point is from the topmost point

	// Output the result of the binomial coefficient C(n-1, k-1)
	fmt.Println(C(n-1, k-1))
}

// <END-OF-CODE>
