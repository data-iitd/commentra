package main

import (
	"fmt"
	"sort"
)

// Function to compare two integers for sort.Slice
func compare(i, j int) bool {
	return i > j
}

func main() {
	array := make([]int, 10)
	// Initialize an array of 10 integers

	for i := 0; i < 10; i++ {
		// Iterate through the array to read 10 integers
		fmt.Scan(&array[i])
		// Read an integer from the user and store it in the array
	}

	sort.Slice(array, func(i, j int) bool {
		return array[i] > array[j]
	})
	// Sort the array using the sort.Slice function and the compare function

	for i := 0; i < 3; i++ {
		// Iterate through the first three elements of the sorted array
		fmt.Println(array[i])
		// Print the first three sorted integers
	}
}
