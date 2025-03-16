package main

import (
	"fmt"
)

func main() {
	var n int
	// Read the number of elements
	fmt.Scan(&n)

	// Read the list of integers
	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
	}

	// Calculate the sum of the list
	x := 0
	for _, value := range w {
		x += value
	}

	// Initialize a slice to store indices
	d := []int{}

	// Iterate through each element in the list
	for i := 0; i < n; i++ {
		// Check if removing the current element results in an average equal to the current element
		if (x-w[i])/(n-1) == w[i] {
			// If the condition is met, append the 1-based index to the slice
			d = append(d, i+1)
		}
	}

	// Print the number of valid indices found
	fmt.Println(len(d))

	// Print the valid indices as a space-separated string
	for i, index := range d {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(index)
	}
	fmt.Println()
}

// <END-OF-CODE>
