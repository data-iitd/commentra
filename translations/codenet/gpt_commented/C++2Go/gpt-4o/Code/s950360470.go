package main

import (
	"fmt"
)

const MOD = 1e9 + 7 // Define a constant for modulo operation (1000000007)

// Function to compute a raised to the power n (a^n)
func pow(a, n int64) int64 {
	res := int64(1) // Initialize result to 1
	for n > 0 {     // Loop until n becomes 0
		if n&1 == 1 {
			res *= a // If n is odd, multiply result by a
		}
		a *= a // Square the base
		n >>= 1 // Divide n by 2
	}
	return res // Return the computed power
}

// Function to compute a raised to the power n modulo mod (a^n % mod)
func modPow(a, n, mod int64) int64 {
	res := int64(1) // Initialize result to 1
	for n > 0 {     // Loop until n becomes 0
		if n&1 == 1 {
			res = res * a % mod // If n is odd, multiply result by a and take modulo
		}
		a = a * a % mod // Square the base and take modulo
		n >>= 1 // Divide n by 2
	}
	return res // Return the computed power modulo
}

// Function to compute modular multiplicative inverse of a modulo mod (a^(-1) % mod)
// This function assumes that a is not divisible by mod
func modInv(a, mod int64) int64 {
	return modPow(a, mod-2, mod) // Use Fermat's Little Theorem to compute inverse
}

// Function to compute n choose k modulo mod (nCk % mod)
func modNCk(n, k int, mod int64) int64 {
	if n == 0 || k == 0 {
		return 1 // Base case: nC0 = 1
	}
	p := int64(1) // Initialize numerator (p)
	q := int64(1) // Initialize denominator (q)

	// Calculate the numerator for nCk
	for i := n - k + 1; i <= n; i++ {
		p = (p * int64(i)) % mod // Multiply terms from (n-k+1) to n and take modulo
	}

	// Calculate the denominator for nCk
	for i := 2; i <= k; i++ {
		q = (q * int64(i)) % mod // Multiply terms from 1 to k and take modulo
	}

	q = modInv(q, mod) // Compute the modular inverse of the denominator
	return (p * q) % mod // Return the result of nCk modulo
}

func main() {
	var n, k int // Declare variables for n and k
	fmt.Scan(&n, &k) // Read values of n and k from input
	fmt.Println(modNCk(k, n, MOD)) // Compute and print nCk modulo MOD
}

// <END-OF-CODE>
