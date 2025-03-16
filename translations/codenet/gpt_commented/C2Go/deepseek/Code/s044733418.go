package main

import (
	"fmt"
	"sort"
)

// Function to compare two integers for sorting
func compare(a, b interface{}) int {
	// Convert the interface values to int
	ai := a.(int)
	bi := b.(int)
	// Return the difference between b and a for descending order
	return bi - ai
}

func main() {
	// Declare an array of integers and a variable for iteration
	var array [10]int

	// Read 10 integers from standard input into the array
	for i := 0; i < 10; i++ {
		fmt.Scan(&array[i])
	}

	// Sort the array in descending order using sort.Slice and the compare function
	sort.Slice(array[:], func(i, j int) bool {
		return compare(array[i], array[j]) > 0
	})

	// Print the first 3 elements of the sorted array
	for i := 0; i < 3; i++ {
		fmt.Println(array[i])
	}
}

