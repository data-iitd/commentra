package main

import (
	"fmt"
)

func solve() {
	// Initialize answer to 0
	var ans int64 = 0
	
	// Read input for number of nodes n
	var n int
	fmt.Scan(&n)
	
	// Calculate contribution of each node to the answer
	for i := 1; i <= n; i++ {
		// Contribution of i-th node is i * (n-i+1)
		ans += int64(i) * int64(n-i+1)
	}
	
	// Subtract contribution of edges
	for i := 1; i < n; i++ {
		// Read input for two nodes u and v
		var u, v int
		fmt.Scan(&u, &v)
		
		// Find maximum and minimum of u and v
		a := max(u, v)
		b := min(u, v)
		
		// Subtract contribution of edge (u,v) from the answer
		ans -= int64(b) * int64(n-a+1)
	}
	
	// Print the answer
	fmt.Println(ans)
}

// Helper function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Helper function to find minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	// Set number of test cases to 1 for simplicity
	var t int = 1
	
	// Solve the problem for each test case
	for t > 0 {
		solve()
		t--
	}
}

// <END-OF-CODE>
