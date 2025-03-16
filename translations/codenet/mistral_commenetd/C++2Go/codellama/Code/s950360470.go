package main

import (
	"fmt"
	"math"
)

// Constants
const MOD = 1e9 + 7 //1000000007                                                    // Modulus value

// Helper functions
// a^n
func pow(a, n int) int {
	res := 1 // Initialize result
	for n > 0 { // While n is greater than 0
		if n&1 == 1 { // If n is odd, multiply result with base
			res *= a
		}
		a *= a // Square the base
		n >>= 1 // Divide n by 2
	}
	return res // Return the final result
}

// a^n % mod
func mod_pow(a, n, mod int) int {
	res := 1 // Initialize result
	for n > 0 { // While n is greater than 0
		if n&1 == 1 { // If n is odd, multiply result with base and take modulo
			res = (res * a) % MOD
		}
		a = (a * a) % MOD // Square the base and take modulo
		n >>= 1 // Divide n by 2
	}
	return res // Return the final result
}

// a^(-1) % mod (only if : a % p != 0)
func mod_inv(a, mod int) int {
	return mod_pow(a, mod-2, mod) // Calculate the modular inverse of 'a'
}

// nCk % mod
func mod_nCk(n, k, mod int) int {
	if n == 0 || k == 0 {
		return 1 // Base case: nC0 = kC0 = 1
	}

	p := 1 // Initialize p
	for i := n - k + 1; i <= n; i++ { // Calculate p = nC(n-k+1)
		p = (p * i) % MOD
	}

	q := 1 // Initialize q
	for i := 2; i <= k; i++ { // Calculate q = k!
		q = (q * i) % MOD
	}

	q = mod_inv(q, MOD) // Calculate q^(-1) modulo 'mod'
	return (p * q) % MOD // Return the final result: nCk = p * q
}

func main() {
	var n, k int // Initialize variables n and k to read input values
	fmt.Scan(&n, &k) // Read input values for n and k from the standard input

	fmt.Println(mod_nCk(k, n, MOD)) // Print the result of nCk modulo 'MOD'
}

