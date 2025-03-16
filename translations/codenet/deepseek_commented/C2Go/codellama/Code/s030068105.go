package main

import (
	"fmt"
	"os"
)

func main() {
	var n int // Declare an integer variable to store the size of the array
	var data []int // Declare a slice to store an array of integers

	fmt.Scanln(&n) // Read an integer value for n from the standard input
	data = make([]int, n) // Allocate memory for an array of integers with size n

	// Read n integers from the standard input and store them in the allocated array
	for i := 0; i < n; i++ {
		fmt.Scanln(&data[i])
	}

	max := 0 // Initialize max to 0 (assuming the first element is the maximum initially)
	index := 0 // Initialize index to 0 (assuming the first element is the maximum initially)

	// Iterate through the array to find the maximum value and its index
	for i := 0; i < n; i++ {
		if data[i] > max {
			max = data[i]
			index = i // Update the index of the maximum value
		}
	}

	a := 0 // Initialize a variable to store the sum of elements excluding the maximum value

	// Iterate through the array again, excluding the element at the index of the maximum value, and sum up the remaining elements
	for i := 0; i < n; i++ {
		if i != index {
			a += data[i]
		}
	}

	// Compare the sum of the remaining elements (a) with the maximum value (max)
	if a > max {
		fmt.Println("Yes") // Print "Yes" if the sum of remaining elements is greater than the maximum value
	} else {
		fmt.Println("No") // Print "No" otherwise
	}
}

