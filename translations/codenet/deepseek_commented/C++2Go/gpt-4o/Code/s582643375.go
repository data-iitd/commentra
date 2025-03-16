package main

import (
	"fmt"
)

const mod = 1e9 + 7
const NMAX = 1000010

var fac [NMAX]int64
var finv [NMAX]int64
var inv [NMAX]int64

// Initialize factorial, inverse factorial, and inverse arrays
func init() {
	fac[0] = 1
	fac[1] = 1
	finv[0] = 1
	finv[1] = 1
	inv[1] = 1
	for i := 2; i < NMAX; i++ {
		fac[i] = fac[i-1] * int64(i) % mod
		inv[i] = mod - inv[mod%i]*int64(mod/i)%mod
		finv[i] = finv[i-1] * inv[i] % mod
	}
}

// Calculate the binomial coefficient C(n, k)
func C(n, k int) int64 {
	if n < k || n < 0 || k < 0 {
		return 0
	}
	return fac[n] * (finv[k] * finv[n-k] % mod) % mod
}

// Main function logic
func main() {
	init()
	var X, Y int
	fmt.Scan(&X, &Y)
	// Check if the sum of X and Y is divisible by 3
	if (X+Y)%3 != 0 {
		fmt.Println(0)
		return
	}
	// Calculate the number of steps needed to reach the target point
	n := (X + Y) / 3
	// Calculate the number of steps needed to reach the target point from the most upper point
	k := 2*(n-1) - Y + 1 // y = 2xより最も上にくる点からどれだけ離れているか。
	// Output the number of ways to reach the target point
	fmt.Println(C(n-1, k-1))
}

// <END-OF-CODE>
