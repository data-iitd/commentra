package main

import (
	"fmt"
)

// Constants for large values and mathematical constants
const INF = 1001001001001001
const inf = 1000000007
const MOD = 1000000007
const PI = 3.1415926535897932

// Function to update the minimum value
func chmin(a *int, b int) {
	if *a > b {
		*a = b
	}
}

// Function to update the maximum value
func chmax(a *int, b int) {
	if *a < b {
		*a = b
	}
}

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the input values and a slice for prefix sums
	a := make([]int, n)
	acc := make([]int, n+1)

	// Read input values and compute prefix sums modulo MOD
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		acc[i+1] = acc[i] + a[i] // Update prefix sum
		acc[i+1] %= MOD // Ensure the prefix sum is within MOD
	}

	// Initialize the answer variable
	var ans int

	// Calculate the final answer using the prefix sums
	for i := 0; i < n; i++ {
		ans += a[i] % MOD * (MOD + acc[n] - acc[i+1]) % MOD // Update answer based on current element and remaining sum
		ans %= MOD // Ensure the answer is within MOD
	}

	// Output the final result
	fmt.Println(ans)
}

