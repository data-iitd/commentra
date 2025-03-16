
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

<<<<<<< HEAD
// Function to solve the problem
func solve() {
	// Initialize answer to 0
	var ans int64 = 0

=======
// <START-OF-CODE>

func main() {
>>>>>>> 98c87cb78a (data updated)
	// Read input for number of nodes n
	var n int
	fmt.Scanf("%d\n", &n)

	// Calculate contribution of each node to the answer
<<<<<<< HEAD
	for i := 1; i <= n; i++ {
		// Contribution of i-th node is i * (n-i+1)
		ans += int64(i) * int64(n-i+1)
=======
	ans := 0
	for i := 1; i <= n; i++ {
		// Contribution of i-th node is i * (n-i+1)
		ans += i * (n-i+1)
>>>>>>> 98c87cb78a (data updated)
	}

	// Subtract contribution of edges
	for i := 1; i < n; i++ {
		// Read input for two nodes u and v
		var u, v int
		fmt.Scanf("%d %d\n", &u, &v)

		// Find maximum and minimum of u and v
		a := max(u, v)
		b := min(u, v)

		// Subtract contribution of edge (u,v) from the answer
<<<<<<< HEAD
		ans -= int64(b) * int64(n-a+1)
=======
		ans -= b * (n-a+1)
>>>>>>> 98c87cb78a (data updated)
	}

	// Print the answer
	fmt.Printf("%d\n", ans)
}

<<<<<<< HEAD
// Utility function to find maximum of two numbers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find minimum of two numbers
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

=======
// 
>>>>>>> 98c87cb78a (data updated)
