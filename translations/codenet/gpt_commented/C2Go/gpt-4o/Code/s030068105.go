package main

import (
	"fmt"
)

func main() {
	// Declare a variable for the number of elements
	var n int

	// Read the number of elements from user input
	fmt.Scan(&n)

	// Allocate a slice for 'n' integers
	data := make([]int, n)

	// Read 'n' integers from user input into the allocated slice
	for i := 0; i < n; i++ {
		fmt.Scan(&data[i])
	}

	// Initialize variables to find the maximum value and its index
	max := data[0]
	index := 0

	// Find the maximum value in the slice and its index
	for i := 1; i < n; i++ {
		if data[i] > max {
			max = data[i]
			index = i
		}
	}

	// Initialize a variable to calculate the sum of all elements except the maximum
	sum := 0

	// Calculate the sum of all elements excluding the maximum value
	for i := 0; i < n; i++ {
		if i != index {
			sum += data[i]
		}
	}

	// Compare the sum of the other elements with the maximum value and print the result
	if sum > max {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
