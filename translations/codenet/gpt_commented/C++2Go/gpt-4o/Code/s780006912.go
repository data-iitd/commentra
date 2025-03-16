package main

import (
	"fmt"
)

func main() {
	// Declare an integer variable to hold the number of elements
	var n int
	// Declare a slice to hold up to 100 integers
	array := make([]int, 100)

	// Read the number of elements from the user
	fmt.Scan(&n)

	// Input the elements into the array
	for i := 0; i < n; i++ {
		fmt.Scan(&array[i])
	}

	// Initialize a variable to hold the sum of products
	sum := 0

	// Calculate the sum of products of all unique pairs of elements in the array
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			sum += array[i] * array[j] // Add the product of the pair to the sum
		}
	}

	// Output the final sum of products
	fmt.Println(sum)
}

// <END-OF-CODE>
