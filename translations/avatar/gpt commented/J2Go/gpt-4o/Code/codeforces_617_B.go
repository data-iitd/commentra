package main

import (
	"fmt"
)

func main() {
	// Reading an integer n from user input, which represents the number of elements
	var n int
	fmt.Scan(&n)

	// Initializing a slice to store the indices of elements that are equal to 1
	var arr []int

	// Looping through the input values to find indices of elements equal to 1
	for i := 0; i < n; i++ {
		var value int
		fmt.Scan(&value)
		// If the input value is 1, add the current index to the slice
		if value == 1 {
			arr = append(arr, i)
		}
	}

	// Checking if the slice of indices is empty
	if len(arr) == 0 {
		// If the slice is empty, print 0
		fmt.Println(0)
	} else {
		// If the slice is not empty, initialize a result variable to 1
		result := int64(1)

		// Calculate the product of the differences between consecutive indices
		for i := 1; i < len(arr); i++ {
			result *= int64(arr[i] - arr[i-1])
		}

		// Print the final result
		fmt.Println(result)
	}
}

// <END-OF-CODE>
