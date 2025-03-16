package main

import (
	"fmt"
)

const (
	N   = 200000 + 10
	K   = 2000000 + 10
	MOD = 1000000007
	INF = 1000000005
	INF64 = 2e18
)

// Function to solve the problem
func solve() {
	var ans int64 = 0 // Initialize the answer variable
	var n int
	fmt.Scan(&n) // Read the number of nodes

	// Calculate the contribution of each node to the answer
	for i := 1; i <= n; i++ {
		ans += int64(i) * int64(n-i+1) // Contribution of node i
	}

	// Adjust the answer based on the edges between nodes
	for i := 1; i < n; i++ {
		var u, v int
		fmt.Scan(&u, &v) // Read the edge connecting nodes u and v
		a := max(u, v)   // Determine the maximum node
		b := min(u, v)   // Determine the minimum node
		ans -= int64(b) * int64(n-a+1) // Subtract the contribution of the edge
	}

	// Output the final answer
	fmt.Println(ans)
}

// Helper function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Helper function to get the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var t int // Variable to hold the number of test cases
	// fmt.Scan(&t) // Uncomment to read the number of test cases
	t = 1 // For now, we will just run one test case
	for t > 0 {
		solve() // Call the solve function for each test case
		t--
	}
}

// <END-OF-CODE>
