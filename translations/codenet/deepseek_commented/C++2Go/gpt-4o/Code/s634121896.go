package main

import (
	"fmt"
	"math"
)

const (
	MOD   = 1e9 + 7
)

func solve() {
	var n int
	fmt.Scan(&n) // Input number of elements
	nums := make([]int, n) // Slice to store the elements
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i]) // Input each element
	}

	// Dynamic programming array to store results
	dp := make([]int64, n+1)
	dp[0] = 1 // Base case: one way to select zero elements
	kek := make(map[int]int64) // Map to store the last occurrence of each number
	prev := make(map[int]int) // Map to store the previous index of each number

	// Fill the dynamic programming array
	for i := 1; i <= n; i++ {
		if prev[nums[i-1]] != i-1 {
			dp[i] = (dp[i-1] + kek[nums[i-1]]) % MOD
		} else {
			dp[i] = dp[i-1] % MOD
		}
		kek[nums[i-1]] = dp[i] // Update the last occurrence
		prev[nums[i-1]] = i // Update the previous index
	}

	fmt.Println(dp[n]) // Output the result
}

func main() {
	var q int = 1 // Number of queries
	// Uncomment the following line to read the number of queries
	// fmt.Scan(&q)
	for i := 0; i < q; i++ {
		solve() // Solve the problem for each query
	}
}

// <END-OF-CODE>
