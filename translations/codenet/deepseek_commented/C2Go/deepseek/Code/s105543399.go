package main

import (
	"fmt"
)

func main() {
	var n, a, m, M, c int64 // Declare variables to store input, current number, min, max, sum, and loop index
	c = 0 // Initialize sum to 0
	m = 100000000
	M = -100000000
	fmt.Scan(&n) // Read the number of elements

	// Loop through each element
	for i := int64(1); i <= n; i++ {
		fmt.Scan(&a) // Read the current number
		if a > M {
			M = a // Update maximum if current number is greater
		}
		if a < m {
			m = a // Update minimum if current number is smaller
		}
		c = c + a // Add current number to sum
	}

	fmt.Printf("%d %d %d\n", m, M, c) // Print the minimum, maximum, and sum of the numbers
}

