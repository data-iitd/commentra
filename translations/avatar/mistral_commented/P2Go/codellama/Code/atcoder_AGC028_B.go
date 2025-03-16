// Import required libraries
package main

import (
	"fmt"
	"math"
)

// Define constant value
const MOD = 1000000007

// Define function main
func main() {
	// Read input number of elements N
	var N int
	fmt.Scan(&N)

	// Define a constant value for the size of the 2D array A
	M := 1000000

	// Initialize 2D NumPy array A with given size and input data
	A := make([][]int, N)
	for i := 0; i < N; i++ {
		A[i] = make([]int, 1)
		fmt.Scan(&A[i][0])
	}

	// Define a constant value for the size of the 2D array fact
	Nsq := 1000

	// Initialize 2D NumPy array fact with given size and initial value 1
	fact := make([][]int, Nsq)
	for i := 0; i < Nsq; i++ {
		fact[i] = make([]int, Nsq)
		fact[i][0] = 1
	}

	// Calculate factorial for each cell in the 2D array fact using a loop
	for n := 1; n < Nsq; n++ {
		for i := 0; i < Nsq; i++ {
			fact[i][n] = (fact[i][n - 1] * fact[i][n - 1]) % MOD
		}
	}

	// Transpose the 2D array fact and calculate factorial for each cell in the new rows
	for n := 1; n < Nsq; n++ {
		for i := 0; i < Nsq; i++ {
			fact[n][i] = (fact[n - 1][i] * fact[n - 1][Nsq - 1]) % MOD
		}
	}

	// Flatten the 2D array fact into a 1D NumPy array
	fact = flatten(fact)

	// Initialize NumPy array j with given size
	j := make([]int, N)
	for i := 0; i < N; i++ {
		j[i] = i
	}

	// Calculate the inverse of each element in the array inv using a list comprehension
	inv := make([]int, N)
	for i := 0; i < N; i++ {
		inv[i] = int(math.Pow(float64(i + 1), MOD - 2)) % MOD
	}

	// Calculate cumulative sum of the array inv
	inv = cumsum(inv)

	// Calculate temporary array temp using elements from j and inv
	temp := make([]int, N)
	for i := 0; i < N; i++ {
		temp[i] = (inv[j[i]] + inv[N - 1 - j[i]] - 1) % MOD
	}

	// Calculate the answer ans using given formula
	ans := 0
	for i := 0; i < N; i++ {
		ans += (A[i][0] * temp[i]) % MOD
	}

	// Modulo the answer ans with given constant value MOD
	ans %= MOD

	// Multiply the answer ans with the last element of fact array
	ans *= fact[N]

	// Modulo the answer ans with given constant value MOD
	ans %= MOD

	// Print the answer ans
	fmt.Println(ans)
}

// Define function flatten to flatten a 2D array into a 1D array
func flatten(fact [][]int) []int {
	// Initialize a 1D array with given size
	flat := make([]int, len(fact) * len(fact[0]))

	// Flatten the 2D array fact into a 1D array
	for i := 0; i < len(fact); i++ {
		for j := 0; j < len(fact[0]); j++ {
			flat[i*len(fact[0])+j] = fact[i][j]
		}
	}

	// Return the flattened 1D array
	return flat
}

// Define function cumsum to calculate cumulative sum of an array
func cumsum(arr []int) []int {
	// Initialize a 1D array with given size
	cum := make([]int, len(arr))

	// Calculate cumulative sum of the array arr
	for i := 0; i < len(arr); i++ {
		cum[i] = (arr[i] + cum[i - 1]) % MOD
	}

	// Return the cumulative sum array
	return cum
}

// 