package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the size of the array
	arr := make([]int, n) // Create an array of size n
	sum := 0 // Initialize sum to 0

	// Read n integers from the user and store them in the array arr, while updating the sum
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
		sum += arr[i]
	}

	c := 0 // Initialize count of valid elements to remove
	var indices []string // Create a slice to store the indices of valid elements

	// Iterate through the array arr to find elements that can be removed
	for i := 0; i < n; i++ {
		// Check if removing the current element keeps the average unchanged
		if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] {
			c++ // Increment the count
			indices = append(indices, fmt.Sprintf("%d", i+1)) // Append the index (plus one) to the slice
		}
	}

	// Print the count of valid elements and the indices of these elements
	fmt.Println(c)
	fmt.Println(strings.Join(indices, " "))
}

// <END-OF-CODE>
