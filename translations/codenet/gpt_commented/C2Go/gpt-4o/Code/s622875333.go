package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n, r, i, j, p, c int
	a := make([]int, 100)
	b := make([]int, 100)

	// Infinite loop to continuously accept input until a termination condition is met
	for {
		// Read the values of n and r from the user
		fmt.Scan(&n, &r)

		// Check for the termination condition (both n and r are zero)
		if n == 0 && r == 0 {
			break
		}

		// Initialize array a with values from n down to 1
		for i = 0; i < n; i++ {
			a[i] = n - i // Fill array a with decreasing values starting from n
		}

		// Process r operations as specified by the user
		for i = 0; i < r; i++ {
			// Copy current state of array a to array b
			for j = 0; j < n; j++ {
				b[j] = a[j] // Save the current configuration of a into b
			}

			// Read the values of p and c for the current operation
			fmt.Scan(&p, &c)

			// Update the first c elements of array a based on the values from array b
			for j = 0; j < c; j++ {
				a[j] = b[p-1+j] // Move elements from b to a based on p and c
			}

			// Shift the remaining elements in array a
			for j = c; j < c+p-1; j++ {
				a[j] = b[j-c] // Continue filling a with the remaining elements from b
			}
		}

		// Output the first element of array a after all operations
		fmt.Println(a[0])
	}
}

// <END-OF-CODE>
