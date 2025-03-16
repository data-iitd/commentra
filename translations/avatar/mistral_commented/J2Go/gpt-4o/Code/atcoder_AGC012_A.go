package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array from the standard input
	array := make([]int, 3*n) // Creating an integer slice of size 3 times the number of elements

	// Initializing the array with input values
	for i := 0; i < len(array); i++ {
		fmt.Scan(&array[i]) // Reading each element into the array
	}

	// Sorting the array in ascending order
	sort.Ints(array)

	head := len(array) - 2 // Index of the last element to be considered in the current iteration
	var res int64 = 0 // Result variable to store the sum of the last two elements in each subarray

	// Calculating the sum of the last two elements in each subarray of size n and adding it to the result
	for i := 0; i < n; i++ {
		res += int64(array[head]) // Adding the last element of the current subarray to the result
		head -= 2 // Decreasing the index of the last element by 2 to consider the next subarray
	}

	// Printing the result
	fmt.Println(res)
}

// <END-OF-CODE>
