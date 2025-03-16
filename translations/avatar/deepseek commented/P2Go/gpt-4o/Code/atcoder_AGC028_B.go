package main

import (
	"fmt"
	"math/big"
)

const MOD = 1_000_000_007 // Define the modulo constant
const M = 1_000_000       // Define a constant for the factorial table size
const Nsq = 1_000        // Define a constant for the size of the factorial table

func main() {
	var N int
	fmt.Scan(&N) // Read the size of the array

	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read the array elements
	}

	// Initialize the factorial table
	fact := make([]int64, Nsq*Nsq)
	fact[0] = 1

	// Compute the factorial table
	for n := 1; n < Nsq; n++ {
		fact[n*Nsq] = (fact[(n-1)*Nsq] * int64(n)) % MOD // fact[n] = n! % MOD
		for m := 1; m < Nsq; m++ {
			fact[n*Nsq+m] = (fact[n*Nsq+m-1] * fact[(n-1)*Nsq+m]) % MOD // Row-wise multiplication
		}
	}

	// Compute the inverse factorial values
	inv := make([]int64, N)
	for i := 0; i < N; i++ {
		inv[i] = modInverse(int64(i+1), MOD) // Compute inverse using Fermat's Little Theorem
	}

	// Compute the temporary value
	temp := make([]int64, N)
	for j := 0; j < N; j++ {
		temp[j] = (inv[j] + inv[N-1-j] - 1 + MOD) % MOD // Ensure non-negative
	}

	// Compute the final answer
	ans := int64(0)
	for j := 0; j < N; j++ {
		ans = (ans + (A[j] * temp[j]) % MOD) % MOD
	}

	// Multiply the final answer with the factorial of N
	ans = (ans * fact[N]) % MOD

	// Print the final answer
	fmt.Println(ans)
}

// modInverse computes the modular inverse of a under modulo m using Fermat's Little Theorem
func modInverse(a, m int64) int64 {
	return pow(a, m-2, m)
}

// pow computes (x^y) % p using iterative method
func pow(x, y, p int64) int64 {
	res := int64(1) // Initialize result
	x = x % p       // Update x if it is more than or equal to p
	for y > 0 {
		if y&1 == 1 { // If y is odd, multiply x with result
			res = (res * x) % p
		}
		y = y >> 1 // y = y / 2
		x = (x * x) % p // Change x to x^2
	}
	return res
}
