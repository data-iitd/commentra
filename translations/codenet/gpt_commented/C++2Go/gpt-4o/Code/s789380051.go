package main

import (
	"fmt"
)

const MOD = 1000000007 // Define a constant for modulo operation

// Function to compute (x^n) % MOD using modular exponentiation
func modPow(x, n int64) int64 {
	ans := int64(1) // Initialize result
	for n > 0 { // Loop until n becomes 0
		if n&1 == 1 { // If n is odd
			ans = (ans * x) % MOD // Multiply ans by x and take modulo
		}
		x = (x * x) % MOD // Square x and take modulo
		n >>= 1 // Divide n by 2
	}
	return ans // Return the result
}

// Function to compute combination C(n, r) % MOD using modular arithmetic
func combS(n, r int64) int64 {
	tmpN := int64(1) // Temporary variable for numerator
	tmpD := int64(1) // Temporary variable for denominator
	var ans int64 // Variable to store the final answer
	for i := int64(1); i <= r; i++ { // Loop to calculate numerator and denominator
		tmpN = (tmpN * (n + 1 - i)) % MOD // Calculate numerator
		tmpD = (tmpD * i) % MOD // Calculate denominator
		ans = (tmpN * modPow(tmpD, MOD-2)) % MOD // Calculate combination using modular inverse
	}

	return ans // Return the combination result
}

func main() {
	var n, a, b int64 // Variables to store the total number of elements and subset sizes
	var ans int64 = 1 // Initialize answer variable

	// Input the values of n, a, and b
	fmt.Scan(&n, &a, &b)

	// Calculate 2^n - 1 (total subsets excluding the empty set)
	ans = modPow(2, n) - 1

	// Calculate C(n, a) and subtract from ans
	tmpND := combS(n, a)
	ans = (ans - tmpND + MOD) % MOD // Subtract combinations of size a

	// Calculate C(n, b) and subtract from ans
	tmpND = combS(n, b)
	ans = (ans - tmpND + MOD) % MOD // Subtract combinations of size b

	// Output the final result
	fmt.Println(ans)
}

// <END-OF-CODE>
