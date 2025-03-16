package main

import (
	"fmt"
)

func main() {
	// Declare variables for the number of elements (n), number of inputs (m), and the starting point (x)
	var n, m, x int
	// Initialize a slice to keep track of the presence of numbers (size 105 to accommodate possible values)
	a := make([]int, 105)

	// Read the values of n, m, and x from standard input
	fmt.Scanf("%d %d %d", &n, &m, &x)

	// Read m numbers from input and mark their presence in the slice 'a'
	for i := 0; i < m; i++ {
		var temp int
		// Read a number and set the corresponding index in slice 'a' to 1
		fmt.Scanf("%d", &temp)
		a[temp] = 1
	}

	// Initialize counters for the number of present elements to the right (ansr) and left (ansl) of x
	ansl, ansr := 0, 0

	// Count how many numbers are present from x to n (right side)
	for i := x; i <= n; i++ {
		ansr += a[i] // Increment ansr if a[i] is 1 (indicating presence)
	}

	// Count how many numbers are present from x to 0 (left side)
	for i := x; i >= 0; i-- {
		ansl += a[i] // Increment ansl if a[i] is 1 (indicating presence)
	}

	// Output the minimum of the counts from both sides
	fmt.Println(min(ansl, ansr))
}

// Helper function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
