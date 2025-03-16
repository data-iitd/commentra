package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements

	a := make([]int, n) // Create slice a
	b := make([]int, n) // Create slice b
	sum := 0            // Initialize sum

	// Read n integers into slice a
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Read n integers into slice b
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
		if a[i] > b[i] { // Check if a[i] is greater than b[i]
			sum += a[i] - b[i] // Add the difference to sum
		}
	}

	// Output the sum
	fmt.Println(sum)
}

// <END-OF-CODE>
