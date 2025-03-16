package main

import (
	"fmt"
)

func main() {
	// Reading the number of elements to be inputted
	var a int
	fmt.Scan(&a)

	// Initializing a slice to hold the input integers
	ar := make([]int, a)

	// Loop to read integers into the slice
	for i := 0; i < a; i++ {
		fmt.Scan(&ar[i]) // Reading each integer into the slice
	}

	// Loop to calculate and print the min and max differences for each element
	for i := 0; i < a; i++ {
		// Calculating the maximum difference from the first and last elements
		max := max(ar[i]-ar[0], ar[a-1]-ar[i])

		// Variable to hold the minimum difference
		var min int

		if i == 0 {
			// If it's the first element, compare with the second element
			min = ar[i+1] - ar[i]
		} else if i == a-1 {
			// If it's the last element, compare with the second last element
			min = ar[i] - ar[i-1]
		} else {
			// For middle elements, compare with both neighbors
			min = min(ar[i]-ar[i-1], ar[i+1]-ar[i])
		}

		// Printing the minimum and maximum differences for the current element
		fmt.Println(min, max)
	}
}

// Function to calculate the maximum of two integers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// Function to calculate the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// <END-OF-CODE>
