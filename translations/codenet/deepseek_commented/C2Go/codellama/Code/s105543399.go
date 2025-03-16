package main

import "fmt"

func main() {
	var n, a, m, M, c, b, i int64 // Declare variables to store input, current number, min, max, sum, and loop index
	c = 0                         // Initialize sum to 0
	m = 100000000                 // Initialize minimum to a large positive value
	M = -100000000                // Initialize maximum to a large negative value
	fmt.Scanf("%d", &n)           // Read the number of elements

	// Loop through each element
	for i = 1; i <= n; i++ {
		fmt.Scanf("%d", &a) // Read the current number
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

