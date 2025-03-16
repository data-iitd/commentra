package main

import (
	"fmt"
)

func main() {
	// Reading the number of elements to be inputted
	var a int
	fmt.Scan(&a)
	
	// Initializing an array to hold the input integers
	ar := make([]int, a)
	
	// Variables to hold the maximum and minimum differences
	var max, min int
	
	// Loop to read integers into the array
	for i := 0; i < a; i++ {
		fmt.Scan(&ar[i]) // Reading each integer into the array
	}
	
	// Loop to calculate and print the min and max differences for each element
	for i := 0; i < a; i++ {
		// Calculating the maximum difference from the first and last elements
		max = maxInt(ar[i] - ar[0], ar[a - 1] - ar[i])
		
		// Calculating the minimum difference based on the position of the current element
		if i == 0 {
			// If it's the first element, compare with the second element
			min = ar[i + 1] - ar[i]
		} else if i == a - 1 {
			// If it's the last element, compare with the second last element
			min = ar[i] - ar[i - 1]
		} else {
			// For middle elements, compare with both neighbors
			min = minInt(ar[i] - ar[i - 1], ar[i + 1] - ar[i])
		}
		
		// Printing the minimum and maximum differences for the current element
		fmt.Println(min, max)
	}
}

// Helper function to find the maximum of two integers
func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Helper function to find the minimum of two integers
func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

