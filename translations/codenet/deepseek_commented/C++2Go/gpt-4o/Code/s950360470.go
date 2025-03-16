package main

import (
	"fmt"
)

const MOD = 1e9 + 7 // Define a constant for modulo operation

// Function to calculate a^n % mod
func modPow(a, n, mod int64) int64 {
	res := int64(1) // Initialize result
	for n > 0 { // Loop until n becomes 0
		if n&1 == 1 {
			res = res * a % mod // If n is odd, multiply result by a modulo mod
		}
		a = a * a % mod // Square a modulo mod
		n >>= 1 // Divide n by 2
	}
	return res // Return the result
}

// Function to calculate a^(-1) % mod (only if a % mod != 0)
func modInv(a, mod int64) int64 {
	return modPow(a, mod-2, mod) // Use Fermat's little theorem
}

// Function to calculate nCk % mod
func modNCk(n, k int64, mod int64) int64 {
	if n == 0 || k == 0 {
		return 1 // Base case: nCk is 1 if n or k is 0
	}
	p := int64(1) // Initialize numerator
	q := int64(1) // Initialize denominator
	for i := n - k + 1; i <= n; i++ { // Calculate numerator
		p = (p * i) % mod
	}
	for i := int64(2); i <= k; i++ { // Calculate denominator
		q = (q * i) % mod
	}
	q = modInv(q, mod) // Calculate inverse of denominator
	return (p * q) % mod // Return the result
}

func main() {
	var n, k int64
	fmt.Scan(&n, &k) // Read values of n and k
	fmt.Println(modNCk(k, n, MOD)) // Calculate and print nCk % MOD
}

// <END-OF-CODE>
