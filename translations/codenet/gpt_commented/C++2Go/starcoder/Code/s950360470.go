package main

import (
	"fmt"
	"math"
)

// Function to compute a raised to the power n (a^n)
func pow(a, n int) int {
	res := 1 // Initialize result to 1
	for ; n > 0; n >>= 1 { // Loop until n becomes 0
		if n&1 == 1 {
			res *= a
		}
		a *= a
	}
	return res
}

// Function to compute a raised to the power n modulo mod (a^n % mod)
func mod_pow(a, n, mod int) int {
	res := 1 // Initialize result to 1
	for ; n > 0; n >>= 1 { // Loop until n becomes 0
		if n&1 == 1 {
			res = res * a % mod
		}
		a = a * a % mod
	}
	return res
}

// Function to compute modular multiplicative inverse of a modulo mod (a^(-1) % mod)
// This function assumes that a is not divisible by mod
func mod_inv(a, mod int) int {
	return mod_pow(a, mod-2, mod) // Use Fermat's Little Theorem to compute inverse
}

// Function to compute n choose k modulo mod (nCk % mod)
func mod_nCk(n, k, mod int) int {
	if n == 0 || k == 0 {
		return 1
	}
	p := 1
	q := 1
	for i := n - k + 1; i <= n; i++ {
		p = (p * i) % mod
	}
	for i := 2; i <= k; i++ {
		q = (q * i) % mod
	}
	q = mod_inv(q, mod)
	return (p * q) % mod
}

func main() {
	var n, k int
	fmt.Scanf("%d %d", &n, &k)
	fmt.Println(mod_nCk(k, n, int(math.Pow10(9)+7)))
}

