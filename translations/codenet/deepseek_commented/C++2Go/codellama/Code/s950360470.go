package main

import (
	"fmt"
	"math"
)

// Function to calculate a^n
func pow(a, n int) int {
	res := 1 // Initialize result
	for n > 0 { // Loop until n becomes 0
		if n&1 == 1 { // If n is odd, multiply result by a
			res *= a
		}
		a *= a // Square a
		n >>= 1 // Divide n by 2
	}
	return res // Return the result
}

// Function to calculate a^n % mod
func mod_pow(a, n, mod int) int {
	res := 1 // Initialize result
	for n > 0 { // Loop until n becomes 0
		if n&1 == 1 { // If n is odd, multiply result by a modulo mod
			res = res * a % mod
		}
		a = a * a % mod // Square a modulo mod
		n >>= 1 // Divide n by 2
	}
	return res // Return the result
}

// Function to calculate a^(-1) % mod (only if a % mod != 0)
func mod_inv(a, mod int) int {
	return mod_pow(a, mod-2, mod) // Use Fermat's little theorem: a^(mod-2) % mod is a^-1 % mod
}

// Function to calculate nCk % mod
func mod_nCk(n, k, mod int) int {
	if n == 0 || k == 0 {
		return 1 // Base case: nCk is 1 if n or k is 0
	}
	p := 1 // Initialize p
	q := 1 // Initialize q
	for i := n - k + 1; i <= n; i++ { // Calculate numerator
		p = (p * i) % mod
	}
	for i := 2; i <= k; i++ { // Calculate denominator
		q = (q * i) % mod
	}
	q = mod_inv(q, mod) // Calculate inverse of denominator
	return (p * q) % mod // Return the result
}

func main() {
	var n, k int
	fmt.Scan(&n, &k) // Read values of n and k
	fmt.Println(mod_nCk(k, n, int(math.Pow(10, 9)+7))) // Calculate and print nCk % MOD
}

