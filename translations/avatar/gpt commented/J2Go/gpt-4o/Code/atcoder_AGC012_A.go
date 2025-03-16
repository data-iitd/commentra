package main

import (
	"fmt"
	"sort"
)

func main() {
	// Reading the integer n which determines the size of the array
	var n int
	fmt.Scan(&n)

	// Initializing a slice of size 3*n to hold the input values
	array := make([]int, 3*n)

	// Filling the slice with user input values
	for i := 0; i < len(array); i++ {
		fmt.Scan(&array[i])
	}

	// Sorting the slice in ascending order
	sort.Ints(array)

	// Setting the head pointer to the second last element of the sorted slice
	head := len(array) - 2

	// Initializing a variable to accumulate the result
	var res int64 = 0

	// Looping n times to sum up the required elements from the sorted slice
	for i := 0; i < n; i++ {
		res += int64(array[head]) // Adding the current element pointed by head to the result
		head -= 2                // Moving the head pointer two positions to the left for the next iteration
	}

	// Printing the final result
	fmt.Println(res)
}

// <END-OF-CODE>
