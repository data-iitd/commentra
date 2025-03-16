package main

import (
	"fmt"
)

func main() {
	var t int
	fmt.Scan(&t) // Read the number of test cases from the input

	for i := 0; i < t; i++ {
		var n int
		fmt.Scan(&n) // Read the number of elements in the array

		// Print the maximum left sum
		fmt.Println(maxLeft(n))
	}
}

// Function to calculate the maximum sum of elements to the left of a given index
func maxLeft(n int) int {
	// Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
	return n - 2
}

