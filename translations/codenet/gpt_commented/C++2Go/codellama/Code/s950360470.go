package main

import (
	"fmt"
	"math"
)

// Function to compute a raised to the power n (a^n)
func pow(a, n int) int {
	res := 1 // Initialize result to 1
	for n > 0 { // Loop until n becomes 0
		if n&1 == 1 { // If n is odd, multiply result by a
			res *= a
		}
		a *= a // Square the base
		n >>= 1 // Divide n by 2
	}
	return res // Return the computed power
}

// Function to compute a raised to the power n modulo mod (a^n % mod)
func mod_pow(a, n, mod int) int {
	res := 1 // Initialize result to 1
	for n > 0 { // Loop until n becomes 0
		if n&1 == 1 { // If n is odd, multiply result by a and take modulo
			res = res * a % mod
		}
		a = a * a % mod // Square the base and take modulo
		n >>= 1 // Divide n by 2
	}
	return res // Return the computed power modulo
}

// Function to compute modular multiplicative inverse of a modulo mod (a^(-1) % mod)
// This function assumes that a is not divisible by mod
func mod_inv(a, mod int) int {
	return mod_pow(a, mod-2, mod) // Use Fermat's Little Theorem to compute inverse
}

// Function to compute n choose k modulo mod (nCk % mod)
func mod_nCk(n, k, mod int) int {
	if n == 0 || k == 0 { // Base case: nC0 = 1
		return 1
	}
	p, q := 1, 1 // Initialize numerator (p) and denominator (q)

	// Calculate the numerator for nCk
	for i := n - k + 1; i <= n; i++ {
		p = (p * i) % mod // Multiply terms from (n-k+1) to n and take modulo
	}

	// Calculate the denominator for nCk
	for i := 2; i <= k; i++ {
		q = (q * i) % mod // Multiply terms from 1 to k and take modulo
	}

	q = mod_inv(q, mod) // Compute the modular inverse of the denominator
	return (p * q) % mod // Return the result of nCk modulo
}

func main() {
	var n, k int // Declare variables for n and k
	fmt.Scan(&n, &k) // Read values of n and k from input
	fmt.Println(mod_nCk(k, n, int(math.Pow10(9)+7))) // Compute and print nCk modulo 1000000007
}

