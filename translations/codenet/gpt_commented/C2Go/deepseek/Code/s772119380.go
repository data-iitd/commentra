package main

import (
	"fmt"
)

func main() {
	// Declare an array to hold up to 1000 integers and variables for size and counters
	var a [1000]int
	var n, i, j, d int

	// Read the number of elements to be sorted
	fmt.Scan(&n)

	// Read the elements into the array
	for i = 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Perform a bubble sort on the array
	for i = 0; i < n; i++ {
		// Inner loop for comparing adjacent elements
		for j = n - 1; j >= i+1; j-- {
			// If the current element is less than the previous one, swap them
			if a[j] < a[j-1] {
				a[j], a[j-1] = a[j-1], a[j]
				d++ // Increment the swap counter
			}
		}
	}

	// Print the sorted array
	fmt.Print(a[0]) // Print the first element
	for i = 1; i < n; i++ {
		fmt.Print(" ", a[i]) // Print the remaining elements
	}

	// Print the total number of swaps made during sorting
	fmt.Println()
	fmt.Println(d)
}

