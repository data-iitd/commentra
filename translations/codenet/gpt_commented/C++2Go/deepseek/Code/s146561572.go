package main

import (
	"fmt"
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
		a := max(u, v) // Determine the maximum node
		b := min(u, v) // Determine the minimum node
		ans -= int64(b) * int64(n-a+1) // Subtract the contribution of the edge
	}

	// Output the final answer
	fmt.Println(ans)
}

func main() {
	var t int
	fmt.Scan(&t) // Read the number of test cases
	for t > 0 {
		solve() // Call the solve function for each test case
		t--
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

