package main

import (
	"fmt"
)

func subtract(a, b int) int {
	// Check if 'a' is greater than 'b'
	if a > b {
		total := 0 // Initialize total to accumulate results
		// Loop until either 'a' or 'b' becomes zero
		for a > 0 && b > 0 {
			// Add the integer division of 'a' by 'b' to total
			total += a / b
			// Update 'a' to the remainder of 'a' divided by 'b'
			a = a % b
			// If 'a' is still greater than zero, calculate further
			if a > 0 {
				// Add the integer division of 'b' by 'a' to total
				total += b / a
				// Update 'b' to the remainder of 'b' divided by 'a'
				b = b % a
			}
		}
		return total // Return the accumulated total
	}

	// Check if 'a' is less than 'b'
	if a < b {
		total := 0 // Initialize total to accumulate results
		// Loop until either 'a' or 'b' becomes zero
		for a > 0 && b > 0 {
			// Add the integer division of 'b' by 'a' to total
			total += b / a
			// Update 'b' to the remainder of 'b' divided by 'a'
			b = b % a
			// If 'b' is still greater than zero, calculate further
			if b > 0 {
				// Add the integer division of 'a' by 'b' to total
				total += a / b
				// Update 'a' to the remainder of 'a' divided by 'b'
				a = a % b
			}
		}
		return total // Return the accumulated total
	}

	// If 'a' is equal to 'b', return 1
	if a == b {
		return 1
	}

	return 0 // Default return (should not reach here)
}

func main() {
	var n int
	fmt.Scan(&n) // Read an integer input 'n' which represents the number of pairs
	results := make([]int, n) // Initialize a slice to store results

	// Loop to read 'n' pairs of integers
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b) // Read a pair of integers
		results[i] = subtract(a, b) // Call the subtract function and store the result
	}

	// Loop to print each result stored in the slice
	for _, result := range results {
		fmt.Println(result)
	}
}

// <END-OF-CODE>
