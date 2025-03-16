package main

import (
	"fmt"
	"math/big"
)

const MOD = 1_000_000_007
const M = 1_000_000
const Nsq = 1_000

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize a 2D slice to store factorial values
	fact := make([][]int64, Nsq)
	for i := range fact {
		fact[i] = make([]int64, Nsq)
	}

	// Set the first factorial value
	fact[0][0] = 1

	// Compute factorial values for columns
	for n := 1; n < Nsq; n++ {
		fact[0][n] = (fact[0][n-1] * int64(n)) % MOD
	}

	// Compute factorial values for rows
	for n := 1; n < Nsq; n++ {
		for m := 0; m < Nsq; m++ {
			fact[n][m] = (fact[n-1][Nsq-1] * fact[0][m]) % MOD
		}
	}

	// Flatten the factorial array to 1D
	factFlat := make([]int64, Nsq*Nsq)
	for i := 0; i < Nsq; i++ {
		for j := 0; j < Nsq; j++ {
			factFlat[i*Nsq+j] = fact[i][j]
		}
	}

	// Create an array of indices from 0 to N-1
	j := make([]int, N)
	for i := 0; i < N; i++ {
		j[i] = i
	}

	// Calculate modular inverses of numbers from 1 to N
	inv := make([]int64, N)
	for i := 0; i < N; i++ {
		inv[i] = modInverse(int64(i+1), MOD)
	}

	// Compute cumulative sum of inverses and take modulo
	for i := 1; i < N; i++ {
		inv[i] = (inv[i] + inv[i-1]) % MOD
	}

	// Calculate temporary values based on the cumulative inverses
	temp := make([]int64, N)
	for i := 0; i < N; i++ {
		temp[i] = (inv[j[i]] + inv[N-1-j[i]] - 1 + MOD) % MOD
	}

	// Compute the final answer by multiplying A with temp and summing the result
	ans := int64(0)
	for i := 0; i < N; i++ {
		ans = (ans + (A[i] * temp[i]) % MOD) % MOD
	}

	// Multiply the answer by the factorial of N and take modulo
	ans = (ans * factFlat[N]) % MOD

	// Print the final answer
	fmt.Println(ans)
}

// Function to calculate modular inverse using Fermat's Little Theorem
func modInverse(a, m int64) int64 {
	return pow(a, m-2, m)
}

// Function to calculate (base^exp) % mod
func pow(base, exp, mod int64) int64 {
	result := int64(1)
	base = base % mod
	for exp > 0 {
		if exp%2 == 1 {
			result = (result * base) % mod
		}
		exp = exp >> 1
		base = (base * base) % mod
	}
	return result
}
