package main

import (
	"fmt"
)

// Constants
const MOD = 1e9 + 7 // 1000000007

// Helper functions

// pow calculates a^n
func pow(a, n int64) int64 {
	res := int64(1) // Initialize result
	for n > 0 {     // While n is greater than 0
		if n&1 == 1 {
			res *= a // If n is odd, multiply result with base
		}
		a *= a // Square the base
		n >>= 1 // Divide n by 2
	}
	return res // Return the final result
}

// modPow calculates a^n % mod
func modPow(a, n, mod int64) int64 {
	res := int64(1) // Initialize result
	for n > 0 {     // While n is greater than 0
		if n&1 == 1 {
			res = (res * a) % mod // If n is odd, multiply result with base and take modulo
		}
		a = (a * a) % mod // Square the base and take modulo
		n >>= 1 // Divide n by 2
	}
	return res // Return the final result
}

// modInv calculates a^(-1) % mod (only if a % p != 0)
func modInv(a, mod int64) int64 {
	return modPow(a, mod-2, mod) // Calculate the modular inverse of 'a'
}

// modNCk calculates nCk % mod
func modNCk(n, k int64, mod int64) int64 {
	if n == 0 || k == 0 {
		return 1 // Base case: nC0 = kC0 = 1
	}

	p := int64(1) // Initialize p
	q := int64(1) // Initialize q
	for i := n - k + 1; i <= n; i++ { // Calculate p = nC(n-k+1)
		p = (p * i) % mod
	}

	for i := int64(2); i <= k; i++ { // Calculate q = k!
		q = (q * i) % mod
	}

	q = modInv(q, mod) // Calculate q^(-1) modulo 'mod'
	return (p * q) % mod // Return the final result: nCk = p * q
}

func main() {
	var n, k int64 // Initialize variables n and k to read input values
	fmt.Scan(&n, &k) // Read input values for n and k from the standard input

	fmt.Println(modNCk(n, k, MOD)) // Print the result of nCk modulo 'MOD'
}

// <END-OF-CODE>
