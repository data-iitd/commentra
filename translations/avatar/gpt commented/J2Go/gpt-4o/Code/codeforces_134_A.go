package main

import (
	"fmt"
)

func main() {
	// Create a variable to read input from the user
	var n int
	// Read the number of elements in the array
	fmt.Scan(&n)

	// Initialize a slice to hold the integers and a variable to store the sum
	arr := make([]int, n)
	sum := 0

	// Read the integers into the slice and calculate the sum
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
		sum += arr[i] // Accumulate the sum of the elements
	}

	// Initialize a counter for valid indices and a slice for output
	c := 0
	var indices []int

	// Check each element to see if it can be the "removed" element
	for i := 0; i < n; i++ {
		// Check if removing arr[i] results in the average of the remaining elements being equal to arr[i]
		if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] {
			c++ // Increment the count of valid indices
			indices = append(indices, i+1) // Append the 1-based index to the slice
		}
	}

	// Output the count of valid indices
	fmt.Println(c)

	// Output the indices of valid elements
	for _, index := range indices {
		fmt.Print(index, " ")
	}
	fmt.Println() // Print a newline at the end
}

// <END-OF-CODE>
