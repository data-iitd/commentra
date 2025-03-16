package main

import (
	"fmt"
)

func main() {
	var k int // Variable to hold the number of elements
	var min, max uint64 // Variables to hold the minimum and maximum values
	fmt.Scan(&k) // Read the number of elements

	// Declare a slice to hold the input values
	a := make([]uint64, k)

	// Read the input values into the slice
	for i := 0; i < k; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize max and min values
	max = 3
	min = 2

	// Check if the last element is not equal to 2
	if a[k-1] != 2 {
		fmt.Println(-1) // Output -1 if the condition is met
		return // Exit the program
	}

	// Iterate through the slice from the second last element to the first
	for i := k - 2; i >= 0; i-- {
		// If the current element is greater than max, output -1
		if a[i] > max {
			fmt.Println(-1) // Output -1 if the condition is met
			return // Exit the program
		} else {
			// Update max based on the current element
			max = ((max / a[i]) + 1) * a[i] - 1
			// Adjust min to be a multiple of the current element if necessary
			if min%a[i] != 0 {
				min = ((min / a[i]) + 1) * a[i]
			}
		}

		// Check if the updated max is less than or equal to min
		if max <= min {
			fmt.Println(-1) // Output -1 if the condition is met
			return // Exit the program
		}
	}

	// Output the final min and max values
	fmt.Printf("%d %d\n", min, max)

	return // Exit the program successfully
}

// <END-OF-CODE>
