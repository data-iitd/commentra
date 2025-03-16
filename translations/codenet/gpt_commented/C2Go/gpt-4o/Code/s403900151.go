package main

import (
	"fmt"
)

func main() {
	// Declare variables for input values and loop counters
	var n, r, p, c int
	var i, j, k int
	a := make([]int, 51) // Slice to hold values
	b := make([]int, 51) // Temporary slice to hold values

	// Infinite loop to continuously accept input until a termination condition is met
	for {
		// Read the values of n (number of elements) and r (number of operations)
		_, err := fmt.Scanf("%d %d", &n, &r)
		if err != nil {
			break
		}

		// Check for termination condition: if both n and r are zero, exit the loop
		if n == 0 && r == 0 {
			break
		}

		// Initialize slice a with values from 1 to n
		for i = 0; i < n; i++ {
			a[i] = i + 1
		}

		// Process each operation
		for i = 0; i < r; i++ {
			// Read the values of p (number of elements to move) and c (number of elements to copy)
			fmt.Scanf("%d %d", &p, &c)

			// Copy elements from a to b
			for j = 0; j < c; j++ {
				b[j] = a[n-p-c+j+1]
			}

			// Shift elements in slice a to make space for the new elements
			for j = 0; j < p-1; j++ {
				a[n-p-c+j+1] = a[n-p+j+1]
			}

			// Insert the copied elements from b back into slice a
			for j = n - p - c + 1, k = 0; k < c; j, k = j+1, k+1 {
				a[j] = b[k]
			}

			/*
			Uncomment the following lines to debug and print the current state of slice a
			for j := 0; j < n; j++ {
				fmt.Println(a[j])
			}
			fmt.Println("---")
			*/
		}

		// Print the last element of slice a after all operations are completed
		fmt.Println(a[n-1])
	}
}
