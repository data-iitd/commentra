
package main

import (
	"fmt"
	"math"
)

// Function to solve the problem
func solve() {
	// Initialize answer to 0
	ans := 0

	// Read input for number of nodes n
	var n int
	fmt.Scan(&n)

	// Calculate contribution of each node to the answer
	for i := 1; i <= n; i++ {
		// Contribution of i-th node is i * (n-i+1)
		ans += i * (n-i+1)
	}

	// Subtract contribution of edges
	for i := 1; i < n; i++ {
		// Read input for two nodes u and v
		var u, v int
		fmt.Scan(&u, &v)

		// Find maximum and minimum of u and v
		a := int(math.Max(float64(u), float64(v)))
		b := int(math.Min(float64(u), float64(v)))

		// Subtract contribution of edge (u,v) from the answer
		ans -= b * (n - a + 1)
	}

	// Print the answer
	fmt.Println(ans)
}

func main() {
	// Set number of test cases to 1 for simplicity
	t := 1

	// Solve the problem for each test case
	for t > 0 {
		solve()
		t--
	}
}

