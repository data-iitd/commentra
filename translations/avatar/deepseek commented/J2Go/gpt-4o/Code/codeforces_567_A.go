package main

import (
	"fmt"
)

func main() {
	var a int
	fmt.Scan(&a) // Reading the size of the array from the user
	ar := make([]int, a) // Initializing the array with the size read from the user

	// Filling the array with integers read from the user
	for i := 0; i < len(ar); i++ {
		fmt.Scan(&ar[i])
	}

	// Calculating the minimum and maximum differences between consecutive elements of the array
	for i := 0; i < len(ar); i++ {
		max := max(ar[i]-ar[0], ar[len(ar)-1]-ar[i]) // Calculating the maximum difference
		var min int
		if i == 0 {
			min = ar[i+1] - ar[i] // Calculating the minimum difference for the first element
		} else if i == len(ar)-1 {
			min = ar[i] - ar[i-1] // Calculating the minimum difference for the last element
		} else {
			min = min(ar[i]-ar[i-1], ar[i+1]-ar[i]) // Calculating the minimum difference for other elements
		}
		fmt.Println(min, max) // Displaying the minimum and maximum differences
	}
}

// Helper function to calculate maximum
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// Helper function to calculate minimum
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
