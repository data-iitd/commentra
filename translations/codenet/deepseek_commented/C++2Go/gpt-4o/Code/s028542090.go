package main

import (
	"fmt"
)

func main() {
	var k int // Declare an integer variable to store the number of elements
	var min, max uint64 // Declare variables to store the minimum and maximum values
	fmt.Scan(&k) // Read the number of elements from the standard input

	a := make([]uint64, k) // Create a slice to store up to k elements

	for i := 0; i < k; i++ {
		fmt.Scan(&a[i]) // Read the elements of the slice from the standard input
	}

	max, min = 3, 2 // Initialize the maximum and minimum values

	if a[k-1] != 2 { // Check if the last element of the slice is not 2
		fmt.Println(-1) // Output -1 and terminate the program
		return
	}

	for i := k - 2; i >= 0; i-- { // Iterate through the slice in reverse order
		if a[i] > max { // Check if the current element is greater than the current maximum
			fmt.Println(-1) // Output -1 and terminate the program
			return
		} else {
			max = ((max / a[i]) + 1) * a[i] - 1 // Update the maximum value
			if min%a[i] != 0 { // Check if min is not a multiple of the current element
				min = ((min / a[i]) + 1) * a[i] // Update the minimum value
			}
		}

		if max <= min { // Check if the maximum value is not greater than the minimum value
			fmt.Println(-1) // Output -1 and terminate the program
			return
		}
	}

	fmt.Printf("%d %d\n", min, max) // Output the minimum and maximum values
}

// <END-OF-CODE>
